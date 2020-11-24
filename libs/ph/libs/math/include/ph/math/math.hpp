#pragma once
namespace ph::math
{



template <typename... T>
struct is_arith
{
      static constexpr bool value = std::conjunction_v<std::is_arithmetic<T>...> && (!std::is_same_v<T, char> && ...);
};


template <class T>
class ObjectCounter
{
private:
      inline static std::size_t m_count = 0;
      
protected:
      ObjectCounter ()
      {
            m_count++;
      }
      
public:
      static std::size_t live ()
      {
            return m_count;
      }
};

template <class T>
class mathOperations
{
      
};











//template <class... T>
//class mathOperations<point<T...>>
//{
//public:
//      friend std::ostream& operator<< (std::ostream& os, const mathOperations& pp)
//      {
//            const point<T...>& p = (const point<T...>&) pp;
//            //            os << m_coordinates;
//            os << "( ";
//            for (const auto& i : p.m_coordinates)
//                  os << i << " ";
//            os << ")";
//            return os;
//      }
//};










//template<typename... T>
//class point
//{
//      static_assert(is_arith<T...>::value, "not arith");
//      using Self = point<T...>;
//      typedef std::integral_constant<size_t, sizeof...(T) + 1> m_size;
//
//public:
//      point (double&& head, T&&... tail) : m_coordinates {(double&&)head, (double&&)tail...} //, m_size (sizeof...(Tail)+1)
//      {
//
//      }
//
//      point (const point<T...>& other) : m_coordinates (other.m_coordinates)
//      {
//      }
//
//      point (point<T...>&& other) : m_coordinates ((std::vector<double>&&) other.m_coordinates)
//      {
//
//      }
//
//      double magnitude () const
//      {
//            double s (0);
//
//            for (int i = 0; i < m_size::value; ++i) {
//                  s += pow (m_coordinates[i], 2);
//            }
//            return sqrt (s);
//      }
//
//      point& operator= (point<T...> other)
//      {
//            static_assert_same_dimension (*this, other);
//            swap(m_coordinates, other.m_coordinates);
//            return *this;
//      }
//
//      double& operator[] (const size_t& i)
//      {
//            return m_coordinates[i];
//      }
//
//      template <class A>
//      auto get (size_t i) -> A
//      {
//            return (A)m_coordinates[i];
//      }
//
//      constexpr size_t size () const
//      {
//            return m_size::value;
//      }
//
//      template <class... U>
//      bool operator== (const point<U...>& other ) const
//      {
//            static_assert_same_dimension (*this, other);
//            for(int i = 0; i < size(); ++i)
//            {
//                  if ( m_coordinates[i] != other.m_coordinates[i] )
//                  {
//                        return false;
//                  }
//            }
//            return true;
//      }
//
//      template <class... U>
//      bool operator!= (const point<U...>& other ) const
//      {
//            return ! *this == other;
//      }
//
//      template <class... U>
//      point& operator+=(const point<U...>& other)
//      {
//            static_assert_same_dimension (*this, other);
//
//            for(int i = 0; i < size(); ++i)
//            {
//                  m_coordinates[i] += other.m_coordinates[i];
//            }
//
//            return *this;
//      }
//
//      template <class... U>
//      point& operator-=(const point<U...>& other)
//      {
//            static_assert_same_dimension (*this, other);
//
//            for(int i = 0; i < size(); ++i)
//            {
//                  m_coordinates[i] -= other.m_coordinates[i];
//            }
//
//            return *this;
//      }
//
//      point& operator*= (const double& scalar)
//      {
//
//            for (int i = 0; i < size(); ++i)
//            {
//                  m_coordinates[i] *= scalar;
//            }
//            return *this;
//      }
//
//      point& operator/= (const double& scalar)
//      {
//
//            for (int i = 0; i < size(); ++i)
//            {
//                  m_coordinates[i] /= scalar;
//            }
//            return *this;
//      }
//
//      friend point<T...> operator* (point<T...> p, const double& n)
//      {
//            p *= (double)n;
//            return p;
//      }
//
//      friend point<T...> operator/ (point<T...> p, const double& n)
//      {
//            p /= (double)n;
//            return p;
//      }
//
//      template <class... U>
//      friend point<T...> operator+ (point<T...> first, const point<U...>& second)
//      {
//            static_assert_same_dimension (first, second);
//            first += second;
//            return first;
//      }
//
//      template <class... U>
//      friend point<T...> operator- (point<T...> first, const point<U...>& second)
//      {
//            static_assert_same_dimension (first, second);
//            first -= second;
//            return first;
//      }
//
//      template <class... U>
//      friend point<T...> operator+(point<T...> lhs, const point<U...>& rhs)
//      {
//            lhs += rhs; // reuse compound assignment
//            return lhs; // return the result by value (uses move constructor)
//      }
//
//
//      friend std::ostream& operator<< (std::ostream& os, const point& p)
//      {
//            os << "( ";
//            for (const auto& i : p.m_coordinates)
//                  os << i << " ";
//            os << ")";
//            return os;
//      }
//
//
//private:
//      std::vector<double> m_coordinates;
//
//      template <class U, class... V, class X, class... Y>
//      friend void static_assert_same_dimension (const point<U, V...>& first, const point<X, Y...>& second)
//      {
//            static_assert(sizeof...(V) == sizeof...(Y));
//      }
//
//      template <class... U>
//      friend class vector;
//
//      friend class mathOperations<point<T...>>;
//};
























































}



