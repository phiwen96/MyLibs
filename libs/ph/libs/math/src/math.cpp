#include <ph/math/math.hpp>

namespace ph::math
{

/// Used only by the letters.
Number::Number (BaseConstructor)
: rep (0),
referenceCount (1)
{}
/// Used by user and static factory functions.
Number::Number ()
: rep (0),
referenceCount (0)
{}
/// Used by user and static factory functions.
Number::Number (const Number &n) : rep (n.rep),
referenceCount (0)
{
      cout << "Constructing a Number using Number::Number\n"; if (n.rep)
            n.rep->referenceCount++; }
Number Number::makeReal (double r)
{
      Number n;
      n.redefine (new RealNumber (r)); return n;
}
Number Number::makeComplex (double rpart, double ipart)
{
      Number n;
      n.redefine (new Complex (rpart, ipart)); return n;
}
Number::~Number() {
      if (rep && --rep->referenceCount == 0) delete rep;
}
Number & Number::operator = (const Number &n) {
      cout << "Assigning a Number using Number::operator=\n"; Number temp (n);
      this->swap (temp);
      return *this;
}
void Number::swap (Number &n) throw () {
      std::swap (this->rep, n.rep); }
Number Number::operator + (Number const &n) const {
      return rep->operator + (n); }
Number Number::complexAdd (Number const &n) const {
      return rep->complexAdd (n); }
Number Number::realAdd (Number const &n) const {
      return rep->realAdd (n); }
void Number::redefine (Number *n)
{
      if (rep && --rep->referenceCount == 0) delete rep;
      rep = n; }
Complex::Complex (double d, double e)
: Number (BaseConstructor()),
rpart (d),
ipart (e) {
      cout << "Constructing a Complex\n"; }
Complex::Complex (const Complex &c) : Number (BaseConstructor()),
rpart (c.rpart),ipart (c.ipart) {
      cout << "Constructing a Complex using Complex::Complex\n"; }
Complex::~Complex() {
      cout << "Inside Complex::~Complex()\n"; }
Number Complex::operator + (Number const &n) const {
      return n.complexAdd (*this); }
Number Complex::realAdd (Number const &n) const {
      cout << "Complex::realAdd\n";
      RealNumber const *rn = dynamic_cast <RealNumber const *> (&n); return Number::makeComplex (this->rpart + rn->val,
                                                                                                 this->ipart);
}
Number Complex::complexAdd (Number const &n) const {
      cout << "Complex::complexAdd\n";
      Complex const *cn = dynamic_cast <Complex const *> (&n); return Number::makeComplex (this->rpart + cn->rpart,
                                                                                           this->ipart + cn->ipart);
}
RealNumber::RealNumber (double r)
: Number (BaseConstructor()),
val (r) {
      cout << "Constructing a RealNumber\n"; }
RealNumber::RealNumber (const RealNumber &r) : Number (BaseConstructor()),
val (r.val) {
      cout << "Constructing a RealNumber using RealNumber::RealNumber\n"; }
RealNumber::~RealNumber() {
      cout << "Inside RealNumber::~RealNumber()\n"; }
Number RealNumber::operator + (Number const &n) const {
      return n.realAdd (*this); }
Number RealNumber::realAdd (Number const &n) const {
      cout << "RealNumber::realAdd\n";
      RealNumber const *rn = dynamic_cast <RealNumber const *> (&n); return Number::makeReal (this->val + rn->val);
}
Number RealNumber::complexAdd (Number const &n) const {
      cout << "RealNumber::complexAdd\n";
      Complex const *cn = dynamic_cast <Complex const *> (&n); return Number::makeComplex (this->val + cn->rpart, cn->ipart);
}








}
