#pragma once


//#include <ph/math/vector.hpp>
//#include <ph/u
namespace ph::math
{






template<typename... T>
class point
{
//      inline static constexpr bool areSame_v = std::conjunction_v<std::is_same<Head,Tail>...>;
      inline static constexpr bool areArithemetic_v = std::conjunction_v<std::is_arithmetic<T>...>;
      using Self = point<T...>;
      typedef std::integral_constant<size_t, sizeof...(T) + 1> m_size;
//      template <class T, class... U>
//      friend class point;
      

      
public:
      

      point (double&& head, T&&... tail) : m_coordinates {(double&&)head, (double&&)tail...} //, m_size (sizeof...(Tail)+1)
      {
//            static_assert(areSame_v, "oops");
//            static_assert(std::is_arithmetic_v<Head>, "oops");
      }
      
//      point (double&& head, Tail&&... tail) : m_coordinates {head, static_cast<double>((Tail&&)tail)...} //, m_size (sizeof...(Tail)+1)
//      {
////            static_assert(areSame_v, "oops");
////            static_assert(std::is_arithmetic_v<Head>, "oops");
//      }
      
//      template <class U...>
      point (const point<T...>& other) : m_coordinates (other.m_coordinates)
      {
      }
      
      point (point<T...>&& other) : m_coordinates ((std::vector<double>&&) other.m_coordinates)
      {
            
      }
      
      
//      point (const vector<T...>& vec) : point (vec.position_vector())
//      {
//
//      }
      
      
//      template <class M, class P>
//      operator ph::math::vector<Self> ()
//      {
//            return vector (magnitude(), *this/magnitude());
//      }
      
      double magnitude () const
      {
            double s (0);
    
            for (int i = 0; i < m_size::value; ++i) {
                  s += pow (m_coordinates[i], 2);
            }
            return sqrt (s);
      }
      
//      template <class...U>
      point& operator= (point<T...> other)
      {
            static_assert_same_dimension (*this, other);
            swap(m_coordinates, other.m_coordinates);
            return *this;
      }
      
      
      
      friend std::ostream& operator<< (std::ostream& os, const point& p)
      {
//            os << m_coordinates;
            os << "( ";
            for (const auto& i : p.m_coordinates)
                  os << i << " ";
            os << ")";
            return os;
      }
      
      double& operator[] (const size_t& i)
      {
            return m_coordinates[i];
      }
      
      template <class A>
      auto get (size_t i) -> A
      {
            return (A)m_coordinates[i];
      }
      
      constexpr size_t size () const
      {
            return m_size::value;
      }
      
      template <class... U>
      bool operator== (const point<U...>& other ) const
      {
            static_assert_same_dimension (*this, other);
            for(int i = 0; i < size(); ++i)
            {
                  if ( m_coordinates[i] != other.m_coordinates[i] )
                  {
                        return false;
                  }
            }
            return true;
      }
      
      template <class... U>
      bool operator!= (const point<U...>& other ) const
      {
            return ! *this == other;
      }
      
      template <class... U>
      point& operator+=(const point<U...>& other)
      {
            static_assert_same_dimension (*this, other);
            
            for(int i = 0; i < size(); ++i)
            {
                  m_coordinates[i] += other.m_coordinates[i];
            }
            
            return *this;
      }
      
      template <class... U>
      point& operator-=(const point<U...>& other)
      {
            static_assert_same_dimension (*this, other);
            
            for(int i = 0; i < size(); ++i)
            {
                  m_coordinates[i] -= other.m_coordinates[i];
            }
            
            return *this;
      }
      
//      template <class Number>//, typename std::enable_if<std::is_arithmetic<Number>::value>::type = 0>
      point& operator*= (const double& scalar)
      {
            
            for (int i = 0; i < size(); ++i)
            {
                  m_coordinates[i] *= scalar;
            }
            return *this;
      }
      
//      template <class Number>//, typename std::enable_if<std::is_arithmetic<Number>::value>::type = 0>
      point& operator/= (const double& scalar)
      {
            
            for (int i = 0; i < size(); ++i)
            {
                  m_coordinates[i] /= scalar;
            }
            return *this;
      }
      
//      template <class Number>//, typename std::enable_if<std::is_arithmetic<Number>::value>::type = 0>
      
      friend point<T...> operator* (point<T...> p, const double& n)
      {
            p *= (double)n;
            return p;
      }
      
//      template <class Number>//, typename std::enable_if<std::is_arithmetic<Number>::value>::type = 0>
//      template <class... U>
      friend point<T...> operator/ (point<T...> p, const double& n)
      {
            p /= (double)n;
            return p;
      }
      
      template <class... U>
      friend point<T...> operator+ (point<T...> first, const point<U...>& second)
      {
            static_assert_same_dimension (first, second);
            first += second;
            return first;
      }
      
      template <class... U>
      friend point<T...> operator- (point<T...> first, const point<U...>& second)
      {
            static_assert_same_dimension (first, second);
            first -= second;
            return first;
      }
      
      template <class... U>
      // friends defined inside class body are inline and are hidden from non-ADL lookup
      friend point<T...> operator+(point<T...> lhs,        // passing lhs by value helps optimize chained a+b+c
                         const point<U...>& rhs) // otherwise, both parameters may be const references
      {
            lhs += rhs; // reuse compound assignment
            return lhs; // return the result by value (uses move constructor)
      }
      
      
      
      
      
      
private:
      std::vector<double> m_coordinates;
      
      template <class U, class... V, class X, class... Y>
      friend void static_assert_same_dimension (const point<U, V...>& first, const point<X, Y...>& second)
      {
            static_assert(sizeof...(V) == sizeof...(Y));
      }
      
      template <class... U>
      friend class vector;
};















}
