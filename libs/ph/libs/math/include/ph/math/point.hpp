#pragma once
#include <iostream>
#include <pthread.h>
#include <thread>
#include <initializer_list>
#include <optional>
#include <tuple>
#include <string>
#include <regex>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <array>



namespace ph::math
{






template<typename Head, typename... Tail>
class Point
{
      inline static constexpr bool areSame_v = std::conjunction_v<std::is_same<Head,Tail>...>;
      inline static constexpr bool areArithemetic_v = conjunction_v<is_arithmetic<Tail>...>;
      using Self = Point<Head, Tail...>;
      
      
      
public:
      static constexpr size_t dim = sizeof...(Tail) + 1;
      typedef integral_constant<size_t, sizeof...(Tail) + 1> m_size;

      Point (const Head& head, const Tail&... tail) : m_coordinates {head, tail...} //, m_dimension (sizeof...(Tail)+1)
      {
            static_assert(areSame_v, "oops");
            static_assert(is_arithmetic_v<Head>, "oops");
      }
      
      friend ostream& operator<< (ostream& os, const Point& p)
      {
            os << "{ ";
            for (const auto& i : p.m_coordinates)
                  os << i << " ";
            os << "}";
            return os;
      }
      
      Head& operator[] (const size_t& i)
      {
            return m_coordinates[i];
      }
      
      constexpr size_t dimension () const
      {
            return m_size::value;
      }
      
      template <class T, class... U>
      Point& operator+=(const Point<T, U...>& other)
      {
            static_assert(dim == sizeof...(U) + 1);
            
//            assert(dimension() == other.dimension());
            for(int i = 0; i < dimension(); ++i)
            {
                  m_coordinates[i] += other.m_coordinates[i];
            }
            
            return *this; // return the result by reference
      }
      
      // friends defined inside class body are inline and are hidden from non-ADL lookup
      friend Point operator+(Point lhs,        // passing lhs by value helps optimize chained a+b+c
                         const Point& rhs) // otherwise, both parameters may be const references
      {
            lhs += rhs; // reuse compound assignment
            return lhs; // return the result by value (uses move constructor)
      }
      
      
      
      
      
      
private:
      vector<Head> m_coordinates;
      template <class T, class... U>
      friend class Point;
      
};















}
