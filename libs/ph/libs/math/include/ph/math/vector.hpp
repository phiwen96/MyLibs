#pragma once
#include <ph/math/point.hpp>
#include <ph/math/definitions.h>
#include <math.h>

namespace ph::math
{


//template <class Point, class Magnitude = double>
//template <class Point>
template <class... T>
class vector
{
//      template <class... T>
//      using Point = point<T...>;
      typedef std::integral_constant<size_t, sizeof...(T)> m_size;
      
public:
//      vector (const Magnitude& magnitude, const Point& unit_vector) : m_magnitude ((const double&)magnitude), m_unit_vector (unit_vector)
//      {
//            
//      }
      
//      template <class M, class V>
      
      
      
      vector (const vector& other) : m_magnitude (other.m_magnitude), m_unit_vector (other.m_unit_vector)
      {

      }
      
//      template <class M, class V>
//      vector (vector<M, V>&& other) : m_magnitude ((double&&)other.m_magnitude), m_unit_vector ((Point&&)other.m_unit_vector)
//      {
//
//      }
      vector (const point<T...>& p) : m_magnitude (p.magnitude()), m_unit_vector (p / m_magnitude)
      {
            
      }
      
//      template <class... T>
      vector (double&& head, T&&... t) : vector (point<T...>((double&&)head, (T&&)t...))
      {
            
      }
      
      
      
//      vector& operator= (vector other)
//      {
//            swap(m_unit_vector, other.m_unit_vector);
////            swap(m_magnitude, other.m_magnitude);
//            return *this;
//      }
      
//      template<typename Head, typename... Tail>
//      vector (const Head& head, const Tail&... tail) : vector ({head, tail...})
//      {
//
//      }
      
     
      constexpr size_t size () const
      {
            return m_size::value;
      }
      
      double magnitude () const
      {
            return m_magnitude;
      }
      
      point<T...> unit_vector () const
      {
            return m_unit_vector;
      }
      
      template <class... U>
      vector crossproduct (const vector<U...>& second)
      {
            static_assert(sizeof...(T) == sizeof...(U));
            return *this;
      }
      
      
      ////////////////////////////////////////////////////////////////
      /// @brief dotproduct of two vectors u and v
      ///
      ///   u • v = u1 v1 + u2 v2 + ... + un vn
      ////////////////////////////////////////////////////////////////
      template <class... U>
      friend double dotproduct (const vector<T...>& uu, const vector<U...>& vv)
      {
            static_assert(sizeof...(T) == sizeof...(U));
            
            auto u = uu.position_vector();
            auto v = vv.position_vector();
            
            double s = 0;
            
            for (int i = 0; i < u.size(); ++i)
            {
                  s += u[i] * v[i];
            }
            
            return s;
      }
      
      ////////////////////////////////////////////////////////////////
      /// @brief angle between two vectors
      ///
      ///                u • v
      ///    ø = arccos -------
      ///               |u| |v|
      ///
      ////////////////////////////////////////////////////////////////
      template <class... U>
      friend int angle (const vector<T...>& u, const vector<U...>& v)
      {
            static_assert(sizeof...(T) == sizeof...(U));
            return acos (dotproduct (u, v) / (u.magnitude() * v.magnitude())) * 180 / PI;
      }
      
      ////////////////////////////////////////////////////////////////
      /// @brief project a vector u onto another vector v
      ///
      ///         | u • v |
      /// u_v =   |-------| v
      ///         |     2 |
      ///         |  |v|  |
      ///
      ////////////////////////////////////////////////////////////////
      template <class... U>
      friend vector<T...> projection (const vector<T...>& u, vector<U...> v)
      {
            static_assert(sizeof...(T) == sizeof...(U));
            v *= (dotproduct (u, v) / pow(v.magnitude(), 2) );
            return v;
      }
      
      
      
//      template <class... T>
      point<T...> position_vector () const // ortsvektor
      {
            return m_unit_vector * m_magnitude;
      }
      
      ////////////////////////////////////////////////////////////////
      /// @brief Takes a position vector (ortsvektor) and changes
      /// m_magnitude and m_unit_vector in respect to it.
      ////////////////////////////////////////////////////////////////
//      template <class P>
//      template <class... T>
      template <class... U>
      void position_vector (const point<U...>& pos_vector)
      {
            static_assert(sizeof...(T) == sizeof...(U));
            m_magnitude = pos_vector.magnitude ();
//            std::cout << ":" << m_magnitude << ":" << std::endl;
            m_unit_vector = pos_vector / m_magnitude;
      }
      
      template <class... U>
      vector& operator= (vector<U...> other)
      {
            static_assert(sizeof...(T) == sizeof...(U));
            swap(m_unit_vector, other.m_unit_vector);
            //            swap(m_magnitude, other.m_magnitude);
            return *this;
      }
      
      
      template <class... U>
      bool operator== (const vector<U...>& other) const
      {
            static_assert(sizeof...(T) == sizeof...(U));
            return m_unit_vector == other.m_unit_vector && m_magnitude == other.m_magnitude;
      }
      
      template <class... U>
      bool operator!= (const vector<U...>& other) const
      {
            static_assert(sizeof...(T) == sizeof...(U));
            return ! *this == other;
//            return false;
      }
      
      ////////////////////////////////////////////////////////////////
      /// @brief Add another vector
      ////////////////////////////////////////////////////////////////
//      template <class M, class P>
      template <class... U>
      vector& operator+= (const vector<U...>& other)
      {
            static_assert(sizeof...(T) == sizeof...(U));
            static_assert_same_dimension (*this, other);
            position_vector((other.m_unit_vector * other.m_magnitude) + (m_unit_vector * m_magnitude));
            return *this;
      }
      
      template <class... U>
      operator point<U...> ()
      {
            return m_unit_vector * m_magnitude;
      }
      
      template <class... U>
      operator const point<U...>& ()
      {
            return m_unit_vector * m_magnitude;
      }
      
//      template <class M, class P>
      template <class... U>
      vector& operator-= (const vector<U...>& other)
      {
            static_assert(sizeof...(T) == sizeof...(U));
            position_vector((m_unit_vector * m_magnitude) - (other.m_unit_vector * other.m_magnitude));
            return *this;
      }
      
//      template <class... U>
//      vector& operator*= (const vector& other)
//      {
//            static_assert(sizeof...(T) == sizeof...(U));
//      }
      
      ////////////////////////////////////////////////////////////////
      /// @brief Scalar multiplication of a vector
      ////////////////////////////////////////////////////////////////
//      template <class Number, typename std::enable_if<std::is_arithmetic<Number>::value>::type = 0>
      vector& operator*= (const double& scalar)
      {
            m_magnitude *= scalar;
            return *this;
      }
      
//      template <class T, class U, class V, class X>
      template <class... U>
      friend vector<T...> operator+ (vector<T...> first, const vector<U...>& second)
      {
            static_assert(sizeof...(T) == sizeof...(U));
            first += second;
            return first;
      }
      
//      template <class T, class U, class V, class X>
      template <class... U>
      friend vector<T...> operator- (vector<T...> first, const vector<U...>& second)
      {
            static_assert(sizeof...(T) == sizeof...(U));
            first -= second;
            return first;
      }
      
//      template <class T, class U, class V, class X>
      template <class... U>
      friend vector<T...> operator* (vector<T...> first, const vector<U...>& second)
      {
            static_assert(sizeof...(T) == sizeof...(U));
            first *= second;
            return first;
      }
      
//      constexpr size_t size () const
//      {
//            return m_size::value;
//      }
      
      friend std::ostream& operator<< (std::ostream& os, const vector& me)
      {
            point<T...> p = me.position_vector();
//            os << "magnitude:\n\t" << me.m_magnitude << "\n\n" << "unit vector:\n\t" << me.m_unit_vector;
//            os << "< " << me.m_unit_vector * me.m_magnitude << " >";
            os << "< ";
            for (size_t i = 0; i < m_size::value; ++i)
                  os << p.m_coordinates[i] << " ";
            os << ">";
            return os;
      }
      
      
private:
      double m_magnitude;
      point<T...> m_unit_vector;
      
      template <class... U>
      friend class vector;
      
      template <class... U, class... V>
      friend void static_assert_same_dimension (const vector<U...>& first, const vector<V...>& second)
      {
            static_assert(sizeof...(U) == sizeof...(V));
      }
      
      
      
};




}
