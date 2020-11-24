#pragma once
namespace ph::math
{
using namespace std;





//template<size_t X, typename T>
//class Row;
//
//template<size_t Y, typename T>
//class Column;






template <size_t Y, size_t X, class T>
class Matrix//<Y, X, T>
{
      template <size_t A, class U>
      using Row = Matrix<1, A, U>;
      
      template <size_t A, class U>
      using Column = Matrix<A, 1, U>;

      
      
      template <size_t, size_t, class>
      friend class Matrix;
      
//      template <size_t A, class B>
//      using Row = Matrix<1, A, B>;
      
//      template <size_t A, class B>
//      using Column = Matrix<A, 1, B>;
//
      
      
      
      Row<X, T>* m_rows;
      unsigned int m_y;
      unsigned int m_x;
      
public:
      
      template <class U = T, typename = enable_if_t<is_convertible_v<T, U>>>
      Matrix<X, Y, U> transpose ()
      {
            Row<Y, U>* r = new Row<Y, U>[X]{};
            
            for (int x = 0; x < m_x; ++x)
            {
                  for (int y = 0; y < m_y; ++y)
                  {
                        r[x][y] = (U const&) m_rows[y][x];
                  }
            }
            
            return Matrix<X, Y, U> (r);
            
            
            
//            T** m = new T*[X]{[0 ... X - 1] = new T[Y]{}};
//
//            for (int x = 0; x < m_x; ++x) {
//                  for (int y = 0; y < m_y; ++y) {
////                        cout << m_rows[y][x] << " ";
////                        r[y][x] = m_rows[x][y];
//                  }
////                  cout << endl;
//            }
            
//            for (int x = 0; x < m_x; ++x) {
//                  cout << r[x] << endl;
//            }
            
            
            
      }
      
      template <size_t r, size_t k, class T0, size_t p, class T1>
      friend Matrix<r, p, T0> operator * (Matrix<r, k, T0> lhs, Matrix<k, p, T1> rhs)
      {
            cout << "r = " << r << endl << "k = " << k << endl << "p = " << p << endl;
            cout << lhs << endl << rhs << endl;
            Matrix<r, p, T0> res;
            cout << res << endl;
            
            for(int y = 0; y < r; ++y)
            {
                  for(int x = 0; x < p; ++x)
                  {
                        cout << res[y][x] << endl;
                        for(int i = 0; i < k; ++i)
                        {
                              res[y][x] += (lhs[y][i] * rhs[i][x]);
//                              res[r][p] += 2;
//                              res[r][p] += (lhs[y][i] * rhs[x][i]);
                        }
//                        for(int i = 0; i < )
//                        res[y][x] =
                  }
            }
            
            return res;
      }
      
      Row<X, T>& operator[] (int i)
      {
            assert (i >= 0 && i < Y);
            return m_rows[i];
      }
      
      Column<Y, T> column (int c) const
      {
            assert (c >= 0 && c < X);
            Column<Y, T> r;
            for (int i = 0; i < m_y; ++i) {
                  r[i] = m_rows[i][c];
            }
            return r;
      }
      
      Row<X, T> row (int i) const
      {
            assert (i >= 0 && i < Y);
            return m_rows[i];
      }
      
      
      
      Matrix (Row<X, T>* rows) : m_rows (rows), m_x (X), m_y (Y)
      {
            
      }
      
      Matrix () : m_rows (new Row<X, T>[Y]{}), m_y (Y), m_x (X)
      {

      }
      
      template <class... U, typename = enable_if_t<sizeof...(U) == Y>>// && conjunction_v<is_convertible_v<U, T>...>>>
      Matrix( U(&&...list)[X]) : m_rows (new Row<X, T>[Y]{move(list)...}), m_x (X), m_y (Y)
      {
           
      }
      
      
      friend std::ostream& operator<< (std::ostream& os, const Matrix<Y, X, T>& m)
      {
//            int xx = 0;
////            os << "-";
//            for (; xx < m.m_x; ++xx) {
//                  os << " ";
//            }
            
            
            os << "\n";
            for (int y = 0; y < m.m_y; ++y) {
//                  os << "| ";
                  os << m.m_rows[y];
//                  os << "|";
                  os << "\n";
            }
            return os;
      }
};












//template <size_t X, class T>
//class Matrix<1, X, T>
//{
//      //      template <class U>
//      //      using Row = _Matrix<1, X, U>;
////      using Self = Matrix<X, T>;
//
//      template <size_t A, size_t N, class U>
//      friend class Matrix;
//
//      T* m_t;
//      unsigned int m_x;
//
//public:
//      T& operator[] (int i)
//      {
//            assert(i >= 0 && i < m_x);
//            return m_t[i];
//      }
//
//      T get (int i)
//      {
//            assert(i >= 0 && i < m_x);
//            return m_t[i];
//      }
//
//      template <class U>
//      Matrix& operator+= (Matrix<1, X, U> const& other)
//      {
//            for (int i = 0; i < m_x; ++i)
//            {
//                  m_t[i] += (T const&) other.m_t[i];
//            }
//            return *this;
//      }
//
//      template <class U>
//      Matrix& operator-= (Matrix<1, X, U> const& other)
//      {
//            for (int i = 0; i < m_x; ++i)
//            {
//                  m_t[i] -= (T const&) other.m_t[i];
//            }
//            return *this;
//      }
//
//      template <class S, typename = enable_if_t<is_scalar_v<S> == true && is_convertible_v<S, T>>>
//      Matrix& operator*= (S const& s)
//      {
//            for (int i = 0; i < m_x; ++i)
//            {
//                  m_t[i] *= (T const&) s;
//            }
//            return *this;
//      }
//
//      template <class S, typename = enable_if_t<is_scalar_v<S> == true && is_convertible_v<S, T>>>
//      Matrix& operator/= (S const& s)
//      {
//            for (int i = 0; i < m_x; ++i) {
//                  m_t[i] /= (T const&) s;
//            }
//            return *this;
//      }
//
//
//      template <class U>
//      friend Matrix<1, X, U> operator + (Matrix<1, X, U> lhs, Matrix<1, X, T> const& rhs)
//      {
//            lhs += rhs;
//            return lhs;
//      }
//
//      template <class U>
//      friend Matrix<1, X, U> operator - (Matrix<1, X, U> lhs, Matrix<1, X, T> const& rhs)
//      {
//            lhs -= rhs;
//            return lhs;
//      }
//
//      template <class S, typename = enable_if_t<is_scalar_v<S> == true && is_convertible_v<S, T>>>
//      friend Matrix<1, X, T> operator * (Matrix<1, X, T> lhs, S const& s)
//      {
//            lhs *= s;
//            return lhs;
//      }
//
//      template <class S, typename = enable_if_t<is_scalar_v<S> == true && is_convertible_v<S, T>>>
//      friend Matrix<1, X, T> operator / (Matrix<1, X, T> lhs, S const& s)
//      {
//            lhs /= s;
//            return lhs;
//      }
//
//
//
//      Matrix () : m_x (X), m_t (new T[X]{})
//      {
//
//      }
//
//      //      template <class U>
//      //      Row(initializer_list<U> m) : m_t(m.begin()), m_x (X)
//      //      {
//      //
//      //      }
//
//      template <class... U, typename = enable_if_t< sizeof...(U) == X && conjunction_v<is_convertible<U, T>...>>>
//      Matrix (U const&... tail) : m_t (new T[1 + X]{(T const&)tail...}), m_x (X)
//      {
//
//      }
//
//      //      template <class... U, typename = enable_if_t< sizeof...(U) + 1 == X && conjunction_v<is_convertible<U, T>...>>>
//      //      Row (T const& head, U const&... tail) : m_t (new T[1 + X]{head, (T const&)tail...}), m_x (X)
//      //      {
//      //
//      //      }
//
//
//      Matrix (Matrix&& other) : m_t (nullptr), m_x (0)
//      {
//            swap (*this, other);
//      }
//
//      Matrix (Matrix const& other) : m_t (new T[X]{}), m_x (X)
//      {
//            for (int i = 0; i < X; ++i) {
//                  m_t[i] = other.m_t[i];
//            }
//      }
//
//      template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
//      Matrix (Matrix<1, X, U> const& other) : m_t (new T[X]{}), m_x (X)
//      {
//            for (int i = 0; i < X; ++i) {
//                  m_t[i] = (T const&) other.m_t[i];
//            }
//      }
//
//      //      template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
//      //      Row (U* u) : m_t (new T[X]{}), m_x (X)
//      //      {cout << "yay" << endl;
//      //            for (int i = 0; i < X; ++i) {
//      //                  m_t[i] = (T const&) u[i];
//      //            }
//      //      }
//
//      template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
//      Matrix ( U(&&u) [X]) : m_t ((U*&&)u), m_x (X)
//      {
//            //            for (int i = 0; i < X; ++i) {
//            //                  m_t[i] = (T const&) u[i];
//            //            }
//      }
//
//      //      template <class U>
//      //      operator Row<X, U> const& ()
//      //      {
//      //            U* u = new U[X]{};
//      //            for (int i = 0; i < X; ++i) {
//      //                  u[i] = (U const&) m_t[i];
//      //            }
//      //            cout << "2: " << endl;
//      //            return Row<X, U> (u);
//      //      }
//
//      friend std::ostream& operator<< (std::ostream& os, const Matrix& m)
//      {
//            for (int x = 0; x < m.m_x; ++x) {
//                  os << (const T&)m.m_t[x] << " ";
//            }
//            return os;
//      }
//
//      friend void swap (Matrix& lhs, Matrix& rhs)
//      {
//            using std::swap;
//            swap (lhs.m_t, rhs.m_t);
//            swap (lhs.m_x, rhs.m_x);
//      }
//
//};





template <size_t N, class T>
class Dim1
{
protected:
      
      template <size_t A, class U>
      friend class Dim1;
      
      T* m_t;
      unsigned int m_n;
      
public:
      T& operator[] (int i)
      {
            assert(i >= 0 && i < m_n);
            return m_t[i];
      }
      
      T get (int i)
      {
            assert(i >= 0 && i < m_n);
            return m_t[i];
      }
      
      template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
      Dim1& operator+= (Dim1<N, U> const& other)
      {
            for (int i = 0; i < m_n; ++i)
            {
                  m_t[i] += (T const&) other.m_t[i];
            }
            return *this;
      }
      
      template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
      Dim1& operator-= (Dim1<N, U> const& other)
      {
            for (int i = 0; i < m_n; ++i)
            {
                  m_t[i] -= (T const&) other.m_t[i];
            }
            return *this;
      }
      
      template <class S, typename = enable_if_t<is_scalar_v<S> == true && is_convertible_v<S, T>>>
      Dim1& operator*= (S const& s)
      {
            for (int i = 0; i < m_n; ++i)
            {
                  m_t[i] *= (T const&) s;
            }
            return *this;
      }
      
      template <class S, typename = enable_if_t<is_scalar_v<S> == true && is_convertible_v<S, T>>>
      Dim1& operator/= (S const& s)
      {
            for (int i = 0; i < m_n; ++i) {
                  m_t[i] /= (T const&) s;
            }
            return *this;
      }
      
      template <class S, typename = enable_if_t<is_scalar_v<S> == true && is_convertible_v<S, T>>>
      friend Dim1 operator * (Dim1 lhs, S const& s)
      {
            lhs *= s;
            return lhs;
      }
      
      template <class S, typename = enable_if_t<is_scalar_v<S> == true && is_convertible_v<S, T>>>
      friend Dim1 operator / (Dim1 lhs, S const& s)
      {
            lhs /= s;
            return lhs;
      }
      
      
      
      Dim1 () : m_n (N), m_t (new T[N]{})
      {
            
      }
      
      template <class... U, typename = enable_if_t< sizeof...(U) == N && conjunction_v<is_convertible<U, T>...>>>
      Dim1 (U const&... tail) : m_t (new T[1 + N]{(T const&)tail...}), m_n (N)
      {
            
      }
      
      Dim1 (Dim1&& other) : m_t (nullptr), m_n (0)
      {
            swap (*this, other);
      }
      
      Dim1 (Dim1 const& other) : m_t (new T[N]{}), m_n (N)
      {
            for (int i = 0; i < N; ++i) {
                  m_t[i] = other.m_t[i];
            }
      }
      
      template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
      Dim1 (Dim1<N, U> const& other) : m_t (new T[N]{}), m_n (N)
      {
            for (int i = 0; i < N; ++i) {
                  m_t[i] = (T const&) other.m_t[i];
            }
      }
      
      template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
      Dim1 ( U(&&u) [N]) : m_t (new T[N]{}), m_n (N)
      {
            for (int i = 0; i < N; ++i) {
                  swap(m_t[i], u[i]);
            }
      }
      
      template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
      Dim1 (const U(&u) [N]) : m_t (new T[N]{}), m_n (N)
      {
            for (int i = 0; i < N; ++i) {
                  m_t[i] = (T const&) u[i];
            }
      }

      
      friend void swap (Dim1& lhs, Dim1& rhs)
      {
            using std::swap;
            swap (lhs.m_t, rhs.m_t);
            swap (lhs.m_n, rhs.m_n);
      }
      
};




template <class D, size_t N, class T>
struct MxM {
      
      template <class U, typename = enable_if_t<is_convertible_v<U, D>>>
      friend D operator + (D lhs, U const& rhs)
      {
            //D& lhs = l.asDerived();
            lhs += rhs;
            return lhs;
      }
      
      
//      is_scalar_v<S> == true && 
      template <class U>//, typename = enable_if_t<is_convertible_v<U, D>>>
      friend D operator - (D lhs, U const& rhs)
      {
            //D& lhs = l.asDerived();
            lhs -= rhs;
            return lhs;
      }
      
//      template <class S, typename = enable_if_t<is_scalar_v<S> == true && is_convertible_v<S, T>>>
//      friend Dim1 operator / (D lhs, S const& s)
//      {
//
//      }
//
//      template <class U>//, typename = enable_if_t<is_convertible_v<U, D>>>
//      friend D operator - (D lhs, U const& rhs)
//      {
//            //D& lhs = l.asDerived();
//            lhs -= (T const&)rhs;
//            return lhs;
//      }
      
private:
      D& asDerived ()
      {
            return *static_cast<D*>(this);
      }
//      operator D& ()
//      {
//            return *static_cast<D*>(this);
//      }
};







template <size_t X, class T>
class Matrix<1, X, T> : public Dim1<X, T>, public MxM<Matrix<1, X, T>, X, T>//public MxM<X, T, Matrix<1, X, T>> // Row
{
      using Self = Matrix<1, X, T>;
      using Base = Dim1<X, T>;
      using Base::Base;
      using Base::operator*=;
      using Base::operator/=;
      using Base::operator+=;
      
      template <size_t, size_t, class U>
      friend class Matrix;
      friend class MxM<Matrix<1, X, T>, X, T>;
      
      template <class U>
      using Column = Matrix<X, 1, U>;
      
      
      
public:
      friend std::ostream& operator<< (std::ostream& os, const Self& m)
      {
            for (int x = 0; x < m.m_n; ++x) {
                  os << (const T&)m.m_t[x] << " ";
            }
            return os;
      }
      
      template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
      Self operator*= (Column<U> const& other)
      {
            for (int x = 0; x < X; ++x) {
                  Base::m_t[x] *= other.m_t[x];
            }
      }
      
      template <class U = T, typename = enable_if_t<is_convertible_v<T, U>>>
      operator Column<U> ()
      {
            U u[X]{};
            for (int i = 0; i < X; ++i) {
                  u[i] = (U const&) Base::m_t[i];
            }
            return (U (&&)[X])u;
      }
      
//      template <class U = T, typename = enable_if_t<is_convertible_v<T, U>>>
//      operator Column<U>&& () &&
//      {cout << "ja2222!" << endl;
//            return move(Base::m_t);
//      }
      
      template <class U = T, typename = enable_if_t<is_convertible_v<T, U>>>
      Column<U> transpose () const
      {
            return (Column<U>)*this;
      }
      
//      template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
//      friend Self operator + (Self lhs, Matrix<1, X, U> const& rhs)
//      {
//            lhs += rhs;
//            return lhs;
//      }
      
      
};



template <size_t Y, class T>
class Matrix<Y, 1, T> : public Dim1<Y, T> // Column
{
      using Self = Matrix<Y, 1, T>;
      using Base = Dim1<Y, T>;
      using Base::Base;
      
      template <class U>
      using Row = Matrix<1, Y, U>;
      
      template <size_t, size_t, class U>
      friend class Matrix;
      
public:
      friend std::ostream& operator<< (std::ostream& os, const Matrix& m)
      {
            for (int x = 0; x < m.m_n; ++x) {
                  os << (const T&)m.m_t[x] << endl;
            }
            return os;
      }
      
      template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
      Self operator*= (Matrix<1, Y, U> const& other)
      {
            for (int y = 0; y < Y; ++y) {
                  Base::m_t[y] *= other.m_t[y];
            }
      }
      
      template <class U = T, typename = enable_if_t<is_convertible_v<T, U>>>
      operator Row<U> ()
      {
            U u[Y]{};
            for (int i = 0; i < Y; ++i) {
                  u[i] = (U const&) Base::m_t[i];
            }
            return (U (&&)[Y])u;
      }
      
      template <class U = T, typename = enable_if_t<is_convertible_v<T, U>>>
      Row<U> transpose () const
      {
            return (Row<U>)*this;
      }
      
};

template <size_t X, class T>
using Row = Matrix<1, X, T>;

template <size_t Y, class T>
using Column = Matrix<Y, 1, T>;



}
