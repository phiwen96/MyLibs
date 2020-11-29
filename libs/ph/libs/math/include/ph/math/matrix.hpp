#pragma once
using namespace std;
namespace ph::math
{








class Refcount
{
protected:
      int count = 0;
};

template <size_t N1, size_t... N2>
class Mat{
      int bajs;
      
public:
      template <class, class, size_t...> class Dim;
      
      template <class D, class T, size_t A> class Dim<D, T, A>{
            T* m_t;
      public:
            Dim() : m_t(new T[A]{0})
            {
                  
            }
            
//            template <class... U, typename = enable_if_t<sizeof...(U) == A>>
            Dim (T (&&u) [A]) : m_t (move(u))
            {
                  
            }
            
            template <size_t Q, class... U>//, typename = enable_if_t<sizeof...(U) == A>>
            Dim (U (&&... u)[Q][A]) : m_t (new T[A]{u...})
            {
//                  cout << sizeof...(B) + 1 << endl;
            }
            
            
            
            
            
            
       
            
            auto operator[] (int i)
            {
                  return m_t[i];
            }
            
            const auto& operator[] (int i) const
            {
                  return *m_t[i];
            }
            
            friend ostream& operator<< (ostream& os, Dim const& d)
            {
                  for (int i = 0; i < A; ++i) {
                        os << d.m_t[i] << " ";
                  }
                  return os;
            }
      };
      
      template <class D, class T, size_t A, size_t... B>
      class Dim<D, T, A, B...>
      {
            using M = Dim<Dim<D, T, A, B...>, T, B...>;
            M* m_dim;
          
            
      public:

            
            Dim ( ) : m_dim(new M[A]{})
            {
                  
            }
            
            template <size_t N, class... U>//, typename = enable_if_t<sizeof...(U) == A>>
            Dim (U (&&... u)[N]) : m_dim (new M[A]{move(u)...})
            {
                  
            }
            
            
            
//            template <size_t Q, class... U>//, typename = enable_if_t<sizeof...(U) == A>>
//            Dim (U (&&... u)[Q][A]) : m_dim (new M[A]{u...})
//            {
//                  cout << sizeof...(B) + 1 << endl;
//            }
            
            
            
            auto operator[] (int i)
            {
                  return m_dim[i];
            }
            
            const auto& operator[] (int i) const
            {
                  return m_dim[i];
            }
            
            friend ostream& operator<< (ostream& os, Dim const& d)
            {
                  for (int i = 0; i < A; ++i) {
                        os << d.m_dim[i] << " ";
                  }
                  return os;
            }
            

            
            
            
      };
      
      
      
      template <class T, class... U> class Matrix;
      
      template <class T>
      class Matrix<T> : public Dim<Matrix<T>, T, N1, N2...> // : public Dim<Matrix<T>, T*, N2..., N1>
      {
            using Base = Dim<Matrix<T>, T, N1, N2...>;
            using Base::Base;
      public:
            
            template <size_t Q, class... U>//, typename = enable_if_t<sizeof...(U) == A>>
            Matrix (U (&&... u)[Q][N1]) //(new M[A]{u...})
            {
                  
                  cout << Q << " x " << N1 << endl;
                        (([&](auto a){
                              for (int i = 0; i < Q; ++i) {
                                    for (int j = 0; j < N1; ++j) {
                                          cout << u[i][j];
                                    }
                                    cout << endl;
                              }
                              cout << endl;
                        }(u)),...);
                  
                  
//                  cout << sizeof...(B) + 1 << endl;
            }
            
            
            

      };
      
      
};


template <size_t Y, size_t X, class T>
class Matrix : public Refcount
{
      template <size_t A, class U>
      using Row = Matrix<1, A, U>;
      
      template <size_t A, class U>
      using Column = Matrix<A, 1, U>;
      
      
      
      
      template <size_t, size_t, class>
      friend class Matrix;
      
      
      
      
      T** m_elements;
      unsigned int m_y;
      unsigned int m_x;
      
public:
      
      
      
      T** col (int x)
      {
            int i = 0;
            T** r = new T*[Y]{[0 ... Y - 1] = &m_elements[i++][x]};
            return r;
      }
      
      
//      template <class U = T, typename = enable_if_t<is_convertible_v<T, U>>>
//      Matrix<X, Y, U> transpose () const
//      {
//
//            Row<Y, U>* r = new Row<Y, U>[X]{};
//
//            for (int x = 0; x < m_x; ++x)
//            {
//                  for (int y = 0; y < m_y; ++y)
//                  {
//                        r[x][y] = (U const&) m_rows[y][x];
//                  }
//            }
//
//            return Matrix<X, Y, U> (r);
//      }
      
//      template <size_t r, size_t k, class T0, size_t p, class T1>
//      friend Matrix<r, p, T> operator * (Matrix<r, k, T0> lhs, Matrix<k, p, T1> const& rhs)
//      {
//
//            Matrix<r, p, T0> res;
//            auto a = rhs.transpose();
//
//
//
//            for(int y = 0; y < r; ++y)
//            {
//                  for(int x = 0; x < p; ++x)
//                  {
//
//                        res[y][x] = lhs.row(y) * rhs.column(x);
//                  }
//            }
//
//            return res;
//      }
      
//      Row<X, T>& operator[] (int i)
//      {
//            // assert (i >= 0 && i < Y);
//            return m_rows[i];
//      }
      
//      Row<X, T> const& operator[] (int i) const
//      {
//            // assert (i >= 0 && i < Y);
//            return m_rows[i];
//      }
//
//      Column<Y, T> column (int c) const
//      {
//            // assert (c >= 0 && c < X);
//            Column<Y, T> r;
//            for (int i = 0; i < m_y; ++i) {
//                  r[i] = m_rows[i][c];
//            }
//            return r;
//      }
//
//      Row<X, T> row (int i) const
//      {
//            // assert (i >= 0 && i < Y);
//            return m_rows[i];
//      }
      
      
      
//      Matrix<1, X, T>* begin ()
//      {
//            return m_rows;
//      }
//
//      Matrix<1, X, T>* end ()
//      {
//            return m_rows + m_x - 1;
//      }
      
      
      
//      Matrix (Row<X, T>* rows) : m_rows (rows), m_x (X), m_y (Y)
//      {
//
//      }
      
//      Matrix () : m_elements (new T*[Y]{[0 ... Y - 1] = new T[X]{}}), m_y (Y), m_x (X)
//      {
//
//      }
      
      
      
      template <class... U, typename = enable_if_t<sizeof...(U) == Y>>// && conjunction_v<is_convertible_v<U, T>...>>>
      Matrix( U(&&...list)[X]) : m_elements (new T*[Y]{move(list)...}), m_x (X), m_y (Y)
      {
//            cout << "kuk" << endl;
      }
      
//      template <class... U, typename = enable_if_t<sizeof...(U) == Y>>// && conjunction_v<is_convertible_v<U, T>...>>>
//      Matrix( U(&&...list)[X]) : m_elements (new T*[Y]{move(list)...}), m_x (X), m_y (Y)
//      {
//            //            cout << "kuk" << endl;
//      }
      
//      template <class U = T, typename = enable_if_t<is_convertible_v<U, T>>>
//      operator Matrix<X, Y, U> ()
//      {
//            Row<Y, U>* r = new Row<Y, U>[X]{};
//
//            for (int x = 0; x < m_x; ++x)
//            {
//                  for (int y = 0; y < m_y; ++y)
//                  {
//                        r[x][y] = (U const&) m_rows[y][x];
//                  }
//            }
//            return move(r);
//      }
      
      
      
      
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
                  for (int x = 0; x < m.m_x; ++x) {
                        os << m.m_elements[y][x] << " ";
                  }
                  
                  //                  os << "|";
                  os << "\n";
            }
            return os;
      }
};








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
            // std::assert(i >= 0 && i < m_n);
            return m_t[i];
      }
      
      T const& operator[] (int i) const
      {
            // std::assert(i >= 0 && i < m_n);
            return m_t[i];
      }
      
      
      
      
      T get (int i)
      {
            // assert(i >= 0 && i < m_n);
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
//            cout << "hi" << endl;
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
      Dim1 (Dim1<N, U>&& other) : m_t (new T[N]{}), m_n (N)
      {
            for (int i = 0; i < N; ++i) {
                  m_t[i] = move(other.m_t[i]);
            }
      }
      
      
      
      template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
      Dim1 (U (&&u) [N]) : m_t (move(u)), m_n (N)
      {
            
      }
      
      
      
      // template <class U, typename = enable_if_t<is_convertible_v<U, T>>>
      // Dim1 (U (&&u) [N]) : m_t (new T[N]{}), m_n (N)
      // {cout << "hi2" << endl;
      //       for (int i = 0; i < N; ++i)
      //       {
      //             std::swap(m_t[i], u[i]);
      //       }
      // }
      
      
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
            // lhs -= rhs;
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
      
      template <class T1, size_t k = X>
      friend T operator * (Matrix lhs, Matrix<k, 1, T1> const& rhs)
      {
            T res {};
            for(int i = 0; i < k; ++i)
            {
                  res += lhs[i] * rhs[i];
            }
            return res;
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
      
      template <class T1, size_t k = Y>
      friend T operator * (Matrix lhs, Matrix<1, k, T1> const& rhs)
      {
            T res {};
            for(int i = 0; i < k; ++i)
            {
                  res += lhs[i] * rhs[i];
            }
            return res;
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







//template <class T>
//class Matrix<1, 1, T>
//{
//private:
//      T m_t;
//
//public:
//      Matrix (T&& t) : m_t ((T&&) t)
//      {
//
//      }
//
//      Matrix (T const& t) : m_t (t)
//      {
//
//      }
//
//      Matrix& operator+= (T const& t)
//      {
//            m_t += t;
//            return *this;
//      }
//
//      operator T ()
//      {
//            return m_t;
//      }
//
//      friend ostream& operator<< (ostream& os, Matrix const& m)
//      {
//            os << m.m_t;
//            return os;
//      }
//};
