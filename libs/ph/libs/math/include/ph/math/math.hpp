#pragma once
namespace ph::math
{


//template <typename T, typename enable_if<is_arithmetic<T>::value, T>::type = 0>
//struct Number
//{
//
//      Number (const T& number) : m_number (number)
//      {
//
//      }
//
//private:
//       T m_number;
//};


template <typename... T>
struct Vector
{
      Vector (const T&... t) : m_vec (t...), m_size (sizeof...(T))
      {
            
      }
      
      
      
private:
      tuple<T...> m_vec;
      size_t m_size;
};





struct BaseConstructor { BaseConstructor(int=0) {} };
class RealNumber; class Complex;

class Number {
      friend class RealNumber; friend class Complex;
public:
      Number ();
      Number & operator = (const Number &n);
      Number (const Number &n); virtual ~Number();
      virtual Number operator + (Number const &n) const; void swap (Number &n) throw ();
      static Number makeReal (double r);
      static Number makeComplex (double rpart, double ipart);
protected:
      Number (BaseConstructor);
private:
      void redefine (Number *n);
      virtual Number complexAdd (Number const &n) const; virtual Number realAdd (Number const &n) const;
      Number *rep;
      short referenceCount;
};



class Complex : public Number {
public:
      friend class RealNumber; friend class Number;

      Complex (double d, double e); Complex (const Complex &c); virtual ~Complex ();
      virtual Number operator + (Number const &n) const; virtual Number realAdd (Number const &n) const; virtual Number complexAdd (Number const &n) const;
      double rpart, ipart;
};
class RealNumber : public Number {
public:
      friend class Complex; friend class Number;

      RealNumber (double r);
      RealNumber (const RealNumber &r); virtual ~RealNumber ();
      virtual Number operator + (Number const &n) const;
      virtual Number realAdd (Number const &n) const; virtual Number complexAdd (Number const &n) const;
      double val;
};













































































}


namespace std
{
template <>
void swap (ph::math::Number & n1, ph::math::Number & n2) {
      n1.swap (n2); }
}
