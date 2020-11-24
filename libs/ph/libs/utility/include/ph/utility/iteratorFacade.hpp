#pragma once
#include <algorithm>
#include <iterator>
#include <vector>
namespace ph::utility
{

// `friend' this class to allow IteratorFacade access to core iterator
// operations:
class IteratorFacadeAccess {
      // only IteratorFacade can use these definitions
      template <typename Derived, typename Value, typename Category,
      typename Reference, typename Distance>
      friend class IteratorFacade;
      
      // required of all iterators:
      template <typename Reference, typename Iterator>
      static Reference dereference(Iterator const& i) {
            return i.dereference();
      }
      //...
      // required of bidirectional iterators:
      template <typename Iterator>
      static void decrement(Iterator& i) {
            return i.decrement();
      }
      
      // required of random-access iterators:
      template <typename Iterator, typename Distance>
      static void advance(Iterator& i, Distance n) {
            return i.advance(n);
      }
      //...
};

template<typename Derived, typename Value, typename Category,
typename Reference = Value&, typename Distance = std::ptrdiff_t>
class IteratorFacade
{
public:
      using value_type = typename std::remove_const<Value>::type;
      using reference = Reference;
      using pointer = Value*;
      using difference_type = Distance; using iterator_category = Category;
      // input iterator interface:
      reference operator *() const { return asDerived().dereference();}
//      pointer operator ->() const { ... }
      Derived& operator ++() { asDerived().increment();return asDerived(); }
      Derived operator ++(int) { Derived result(asDerived()); asDerived().increment(); return result; }
      friend bool operator== (IteratorFacade const& lhs, IteratorFacade const& rhs) { return lhs.asDerived().equals(rhs.asDerived()); }
      
      // bidirectional iterator interface:
//      Derived& operator --() { ... }
//      Derived operator --(int) { ... }
      // random access iterator interface:
//      reference operator [](difference_type n) const { ... }
//      Derived& operator +=(difference_type n) { ... }

//      friend difference_type operator -(IteratorFacade const& lhs, IteratorFacade const& rhs) { ... }
//      friend bool operator <(IteratorFacade const& lhs, IteratorFacade const& rhs) { ... }



private:
      Derived& asDerived() {
            return *static_cast<Derived*>(this);
      }
      Derived const& asDerived() const {
            return *static_cast<Derived const*>(this);
      }

};




struct Person {
      std::string firstName;
      std::string lastName;
      
      friend std::ostream& operator<<(std::ostream& strm, Person const& p) {
            return strm << p.lastName << ", " << p.firstName;
      }
};




template <typename Iterator, typename T>
class ProjectionIterator : public IteratorFacade<
                              ProjectionIterator<Iterator, T>, T,
                              typename std::iterator_traits<Iterator>::iterator_category, T&,
                              typename std::iterator_traits<Iterator>::difference_type>
{
      using Base = typename std::iterator_traits<Iterator>::value_type;
      using Distance = typename std::iterator_traits<Iterator>::difference_type;
      
      Iterator iter;
      T Base::*member;
      
      friend class IteratorFacadeAccess;
      //... // implement core iterator operations for IteratorFacade
public:
      ProjectionIterator(Iterator iter, T Base::*member)
      : iter(iter), member(member) {}
};

template <typename Iterator, typename Base, typename T>
auto project(Iterator iter, T Base::*member) {
      return ProjectionIterator<Iterator, T>(iter, member);
}





}
