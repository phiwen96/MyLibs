#include <test/main.hpp>
#include <ph/math/math.hpp>
#include <ph/math/point.hpp>
#include <ph/math/point.hpp>
//#include <ph/math/vector.hpp>
#include <ph/math/plane.hpp>
#include <ph/math/line.hpp>
#include <ph/math/matrix.hpp>
#include <vector>
#include <ph/time/timer/Timer.hpp>
#include <array>
#include <thread>



int random (int f, int l)
{
      std::random_device dev;
      std::mt19937 rng(dev());
      std::uniform_int_distribution<std::mt19937::result_type> dist6(f,l); // distribution in range [1, 6]
      
//      std::cout << dist6(rng) << std::endl;
      return dist6(rng);
}









template <size_t... N, size_t... M, class... U>//, typename = enable_if_t<sizeof...(U) == A>>
void Ma (U(&&...u)[N][M]) //: m_t (new T[A]{move(u)...})
{
            
}

template <size_t... N, size_t... M, size_t... Q, class... U>//, typename = enable_if_t<sizeof...(U) == A>>
void Ma2 (U(&&... u)[N][M][Q]) //: m_t (new T[A]{move(u)...})
{
      
}
template <typename T>
std::enable_if_t<std::rank<T>::value == 1>
printDimensions(const T& a)
{
      std::cout << std::extent<T>::value;
}

template <typename T>
std::enable_if_t<std::rank<T>::value != 1>
printDimensions(const T& a)
{
      std::cout << std::extent<T>::value << "x";
      printDimensions(a[0]);
}

      
using namespace ph::math;




//template<class elem_t, std::size_t... dim>
//struct m
//{
//      int data[dim...];
//      template<size_t ... n>
//      constexpr m(const elem_t (&...list)[n]) //: data{}
//      {
////            auto pos = &data[0];
////            ((pos = std::copy(list, list + n, pos)), ...);
//      }
//
//
//};



//template<typename ... elem_t, size_t ... n>
//m(const elem_t (&...list)[n]) -> m<std::common_type_t<elem_t...>, sizeof...(n), (n * ...) / sizeof...(n)>;


template<class T, size_t ... n> struct A;

template<class T, size_t n >
struct A<T, n>
{
      using type = T[n];
//      type data;
      
//      T& operator[](unsigned i) {
//            cout << "A<T, n>" << endl;
//            return data[i];
//      }
      
};

template<class T, size_t m, size_t ... n >
struct A<T, m, n...>
{
      using _1d = typename A<T, n...>::type;
      using type = _1d[m];
      
      typename A<T, n...>::type data[m];
      
      typename A<T, n...>::type& operator[](unsigned i) {
            cout << "A<T, m, n...>" << endl;
            return data[i];
      }
      
//      template <class... U>
      A (typename A<T, n...>::type (&& a)[m]) {
            
      }
};
template <class T, size_t...> struct dim;
template <class T, size_t n> struct dim<T, n> {
      using type = T[n];
      constexpr static int dimenstions = 1;
      type m_m;
};





template <class T, size_t n, size_t... m>
struct dim<T, n, m...> {
      using Base = dim<T, m...>;
      using type = typename dim<T, m...>::type[n];
      constexpr static int dimenstions = 1 + dim<T, m...>::dimenstions;
//      dim<T, m...> m_data[n]
      typename Base::type m_data[n];
      
};







// template <class... T, size_t... N>
// dim(T (&&...u)[N]) -> dim<common_type_t<T...>, N...>;

// template <class... T, size_t... N, size_t... M>
// dim(T (&&...)[N][M]) -> dim<common_type_t<T...>, N..., M...>;

// template <class... T, size_t... N, size_t... M, size_t... O>
// dim(T (&&...)[N][M][O]) -> dim<common_type_t<T...>, N..., M..., O...>;

// template <class... T, size_t... N, size_t... M, size_t... O, size_t... P>
// dim(T (&&...)[N][M][O][P]) -> dim<common_type_t<T...>, N..., M..., O..., P...>;

// template <class... T, size_t... N, size_t... M, size_t... O, size_t... P, size_t... R>
// dim(T (&&...)[N][M][O][P][R]) -> dim<T..., N..., M..., O..., P..., R...>;

// template <class... T, size_t... N, size_t... M, size_t... O, size_t... P, size_t... R, size_t... Q>
// dim(T (&&...)[N][M][O][P][R][Q]) -> dim<T..., N..., M..., O..., P..., R..., Q...>;

// template <class... _T, size_t... A, size_t... B, size_t... C, size_t... D, size_t... E, size_t... F, size_t... G >
// dim(_T (&&...)[A][B][C][D][E][F][G]) -> dim<_T..., A..., B..., C..., D..., E..., F..., G...>;
//
//template <class T, typename = enable_if_t<std::rank_v<T> != 0>>
//dim(T) -> dim<T, std::rank_v<T>>;
//

template<class T, size_t N>
dim(array<T, N>) -> dim<T, N>;
//
template <class T, class... U>
dim(T, U...) -> dim<common_type_t<T, U...>, sizeof...(U)+1>;

template <typename T, std::size_t>
using getType = T;

template <typename T, std::size_t ... Is>
auto getDim (std::index_sequence<Is...>)
-> dim<getType<T, Is>...>;

template <typename T, std::size_t N>
using proDim = decltype(getDim<T>(std::make_index_sequence<N>{}));

//template <std::size_t ... Dims, typename ... Ts>
//dim ( Ts (&&...arr)[Dims] ) -> dim<proDim<Ts, Dims>...>;



template <class T, class U, class... V>
struct Bajs {
      Bajs (T, U){}
};

template <typename... Ts>
struct y
{
      using values_t = std::tuple<Ts...>;
      
      values_t values;
      
      constexpr y (Ts const & ... vs) : values({ vs... })
      { }
};

template <typename T, std::size_t>
using getType = T;

template <typename T, std::size_t ... Is>
auto getY (std::index_sequence<Is...>)
-> y<getType<T, Is>...>;

template <typename T, std::size_t N>
using proY = decltype(getY<T>(std::make_index_sequence<N>{}));

template <std::size_t ... Dims, typename ... Ts>
y ( Ts const (&...arr)[Dims] ) -> y<proY<Ts, Dims>...>;


template <size_t n, class...> struct B;
template <size_t n, class T>
struct B<n, T> {
      constexpr inline static int m_i = n;
      T t;
      auto operator[](int i){
            return t;
      }
};

// template <size_t n, size_t f, class T, class... U>
// struct B<n, T, U...> : B<n+1, U...>{
//       using L = decay_t<T>;
//       constexpr inline static int m_i = n;
//       L t;
      
//       auto operator[](int i) //-> decltype( (i == m_i) ? t : B<n+1, U...>::operator[] (i))
//       {
//             return (i == m_i) ? t : B<n+1, U...>::operator[] (i);
//       }
// };

template <size_t n, class T, class... U>
struct B<n, T, U...> : B<n+1, U...>{
      using L = decay_t<T>;
      constexpr inline static int m_i = n;
      L t;
      
      auto operator[](int i) //-> decltype( (i == m_i) ? t : B<n+1, U...>::operator[] (i))
      {
            return (i == m_i) ? t : B<n+1, U...>::operator[] (i);
      }
};

template<class... T>
B(T...) -> B<0, T...>;
template <size_t n, class... T>
B(T..., char const(&)[n]) -> B<1, const char*>;
//template <size_t N, class T>
//B(T(&&u)[N]) -> B<T[N]>;


int main(int argc, char** argv) {
      
      
//       B b0 {1, 2, "hej"};
      
// //      cout << b0[1] << endl;
      
      
      
      
//       using T0 = decltype(y{ { 1, 2 }, { 'a', 'b', 'c' },
//             {1.0, 2.0, 3.0, 4.0} });
//       using T1 = y<y<int, int>, y<char, char, char>,
//       y<double, double, double, double>>;
      
//       static_assert( std::is_same_v<T0, T1> );
      
// //      dim d11 {{ { 1, 2 }, { 'a', 'b', 'c' }, {1.0, 2.0, 3.0, 4.0} }};
      
// //      dim d10 = {{1, 2}, {2, 3}};
//       y ii{ { 1, 2 }, { 'a', 'b', 'c' }, { 1, 1, 2 },
//             {1.0, 2.0, 3.0, 4.0} };
      
//       dim<std::tuple<int,string,double>, 10> d11;
      
//       dim<int,2,2> d6 {{ {1, 2}, {3, 5} }};
//       dim d9 = {{{{{1, 2}, {3, 5}}}, {{{1, 2}, {3, 5}}}}};
// //      dim d8 = {{{"hej", "kuk", "fitta"}, {9, 8, 7}}};
//       dim d7 = {{1, 2, 3}};
//       dim<int,3> d2 = {{1, 2, 3}};
//       dim<int, 3, 3> d0 = {{{ -7, 2, 3}, { 4, 5, 6}, { 4, 5, 6}}};
// //      B b1 {d2};
      
// //      dim<int, 3, 3> d1 ( { 1, 2, 3}, { 4, 5, 6}, { 4, 5, 6} );
// //      dim<int, 2, 3> d1 ( { 1, 3}, { 4, 5, 6} );
// //      dim<int, 2, 3> d2 ( { 1, 2, 3, 4}, { 4, 5, 6, 5} );
//       dim<int, 2, 3> d3 { {{ 1, 2, 3}, { 4, 5, 7}} };
//       dim<int, 2, 3, 3> d4 {{ {{ 1, 2, 3}, { 4, 5, 6}}, {{ 1, 2, 3}, { 4, 5, 6}}}};
      
//       dim<int, 2, 2, 2, 3> d5 {{ {{{ 1, 2, 3}, { 4, 5, 6}}, {{ 1, 2, 3}, { 4, 5, 6}}}, {{{ 1, 2, 3}, { 4, 5, 6}}, {{ 1, 2, 3}, { 4, 5, 6}}} }};
      
      
      
      
//       A<int, 2, 3> a5( {{ 1, 2, 3}, { 4, 5, 6}} );
// //      A<int, 2, 3> a5{ { { 1, 2, 3}, { 4, 5, 6} } };
// ////      std::cout << a5[1][2] << std::endl;
// //
// //      A<int, 1, 2, 3> a7{ { { { 1, 2, 3}, { 4, 5, 6 } } }};
// //      std::cout << a7[0][1][2] << std::endl;
// //      M<int, 1, 2> m1 ({{1, 2}, {1, 2}});
      
//       int i[2][3][3] = {{{1, 2, 3}, {1, 2}}, {{1, 2, 3}, {1, 2}}};
//      dim<int, 2, 3> d1 ( { 1.2, 2.2, 3.3}, { 4.4, 5.3, 6.2} );
      
//      dim<int, 3>::type d2 {2};
//      cout << d1 << endl;
      return 0;
   
//      M<int, 1, 2, 3>  mat{ { { { 1, 2, 3}, { 4, 5, 6 } } }};
      
      
      
  
      

      

      
//      Ma({1, 2, 3}, {1, 2, 3}, {1, 2});
//      Ma({{1,2}, {3,4}, {1,3}}, {{1,2}, {3,4}, {1,3}});
//      Ma2({{{1,2}, {3,4}, {1,3}}, {{1,2}, {3,4}, {1,3}}}, {{{1,2}, {3,4}, {1,3}}, {{1,2}, {3,4}, {1,3}}});
//
//
//
//      Matrix<2, 3, int> m1 = {{1, 2, 3}, {4, 5, 6}};
//      Matrix<3, 2, int> m2 = {{7, 8}, {9, 10}, {11, 12}};
//
//
//      Matrix<4, 2, int> m3 =
//      {
//            {1, 2},
//            {3, 4},
//            {5, 6},
//            {7, 8}
//      };
////      cout << m3 << endl;
//
//      auto r = m3.col(0);
//      *r[1] = 0;
////      cout << m3 << endl;
//
//      Mat<2, 3>::Matrix<int> m {{5,6,5},{4,4,4}};
//      Mat<2, 3, 2>::Matrix<int> mm {{{1, 2},{3, 4},{5, 6}},{{7, 8},{9, 10},{11, 12}}};
//
//      cout << m << endl;
//      cout << m << endl;
      
//      auto ii = new int[]{{5,6,5},{4,4,4}};
//      auto aa = {{{1, 2},{1, 2},{1, 2}},{{1, 2},{1, 2},{1, 2}}};
//      int** r = m3.row(0);
//      *r[0] = 0;
//      r[1] = new int(-11);
      
//      int***& r = m3.row(0);
//      r = new int**[4]{[0 ... 3] = new int*[4]{[0 ... 3] = new int[2]{}}};

      
      
      
      
      
      
      
//      Matrix<2, 4, int> m4 = {{9, 10, 11, 12}, {13, 14, 15, 16}};
//
//      Matrix<1, 3, int> m5 = {1, 2, 3};
//      Matrix<3, 1, int> m6 = {4, 5, 6};
//
//      Matrix<2, 2, int> m7 = {{1, 2}, {3, 4}};
//      Matrix<2, 2, int> m8 = {{5, 6}, {7, 8}};
//
//      Matrix<1000, 1000, int> m9 {};
//      cout << m9 << endl;
//      for(auto& i : m9)
//            i[0] += 1;
//      cout << m9 << endl;
      
      
      
      

      
//      int i = get_right_distribution<int>(1, 6)(gen);
//
//      auto float_dis = get_right_distribution(1.F, 6.F);
//      std::cout << float_dis(gen) << "\n";
      
      
      
//      auto i = m1 * m2;
//      cout << i << endl;
      
    

//      cout << i << endl;
      
      
      
//      cout << m1 << endl;
//      cout << m1_transposed << endl;
    return 0;
}






//
//
//
//#include <test/main.hpp>
//#include <ph/math/math.hpp>
//#include <ph/math/point.hpp>
//#include <ph/math/point.hpp>
////#include <ph/math/vector.hpp>
//#include <ph/math/plane.hpp>
//#include <ph/math/line.hpp>
//#include <ph/math/matrix.hpp>
//#include <vector>
//#include <ph/time/timer/Timer.hpp>
//#include <array>
//
//
//
//int random (int f, int l)
//{
//      std::random_device dev;
//      std::mt19937 rng(dev());
//      std::uniform_int_distribution<std::mt19937::result_type> dist6(f,l); // distribution in range [1, 6]
//
//      //      std::cout << dist6(rng) << std::endl;
//      return dist6(rng);
//}
//
//
//
//
//
//
//
//
//
//template <size_t... N, size_t... M, class... U>//, typename = enable_if_t<sizeof...(U) == A>>
//void Ma (U(&&...u)[N][M]) //: m_t (new T[A]{move(u)...})
//{
//
//}
//
//template <size_t... N, size_t... M, size_t... Q, class... U>//, typename = enable_if_t<sizeof...(U) == A>>
//void Ma2 (U(&&... u)[N][M][Q]) //: m_t (new T[A]{move(u)...})
//{
//
//}
//
//
//
//using namespace ph::math;
//
//struct T{};
//
//
//
//
//
//
//
//
//
//template <class Edge>
//struct ListNode{
//      inline static int ant = 0;
//      int data;
//      Edge* edges;
//      ListNode* next;
//      int* key;
//      ListNode* parent;
//
//      ListNode (int const& data) : data(data), edges(nullptr), next (nullptr), key (nullptr), parent(nullptr){
//            ant++;
//      }
//      void push (Edge* edge){
//            if ( edges == nullptr ) {
//                  edges = edge;
//                  return;
//            }
//            auto i = edges;
//            while (i -> next != nullptr) {
//                  i = i -> next;
//            }
//            i -> next = edge;
//            //            edges.push_back(edge);
//      }
//      //      void push2 (Edge* edge){
//      //            edges.push_back(edge);
//      //            edge->node.push(new Edge(edge->weight, this));
//      //      }
//      friend ostream& operator<< (ostream& os, ListNode const& l){
//            os << l.data << " : ";
//            os << *l.edges << " ";
//            //            for (auto const& i : l.edges) {
//            //                  os << *i << " ";
//            //            }
//            if ( l.next != nullptr ) {
//                  os << endl;
//                  os << *l.next;
//            }
//            return os;
//      }
//
//};
//
//template <class Weight>
//struct Edge{
//      ListNode<Edge>* node;
//      Weight weight;
//      Edge* next;
//      Edge (Weight const& weight, ListNode<Edge>* node) : next(nullptr), weight(weight), node (node) {
//
//      }
//      friend ostream& operator<< (ostream& os, Edge const& l){
//            os << "[" << l.node->data << ", " << l.weight << "]";
//            if ( l.next != nullptr ) {
//                  os << *l.next;
//            }
//            return os;
//      }
//};
//
//using Edg = Edge<int>;
//using Node = ListNode<Edge<int>>;
//
//template <size_t n>
//Node* genGraph (int maxWeight) {
//      //      std::vector<ListNode<int, Edge<int, int>>*> l;
//      int k = 0;
//      Node* l = new Node[n]{[0 ... n - 1] = k++};
//      //      cout << l[0].data << endl;
//      l[0].next = &l[1];
//
//      //      for (int i = 0; i < n; ++i){
//      //            if ( i != 0 ) {
//      //
//      //            }
//      //      }
//      for (int i = 1; i < n; ++i) {
//            l[i-1].next = &l[i];
//            for (int j = 0; j < i; ++j) {
//                  int r = random(0, 1);
//                  if (r == 0) {
//                        int q = random(1, maxWeight);
//                        l[j].push(new Edg (q, &l[i]));
//                        l[i].push(new Edg (q, &l[j]));
//                  }
//
//            }
//      }
//      return l;
//}
//
//
//
//template <class T, size_t N>
//ostream& operator<< (ostream& os, std::array<T*, N> const& t){
//      for (int i = 0; i < N; ++i) {
//            os << *t[i] << " ";
//      }
//      return os;
//}
//
//template <class T>
//ostream& operator<< (ostream& os, std::vector<T*> const& t){
//      for (auto const& i : t) {
//            os << *i << " ";
//      }
//      return os;
//}
//
//template <class Data>
//Data* heap_maximum (std::vector<Data*>& A) {
//      return A.front();
//}
//
//template <class Data>
//Data* heap_extract_max (std::vector<Data*>& A) {
//      assert(A.size() >= 1);
//      Data* max = A.front();
//      A.front() = A.back();
//      A.pop_back();
//      max_heapify(A, 1);
//      return max;
//}
//
//template <class Data>
//void heap_increase_key (std::vector<Data*>& A, int i, Data* key) {
//      assert(A[i] == nullptr);
//      A[i] = key;
//      while (i > 0 and *A[i - 1] < *A[i]) {
//            swap (A[i], A[i - 1]);
//            --i;
//      }
//}
//
//template <class Data>
//void max_heap_insert (std::vector<Data*>& A, Data* key) {
//      A.resize(A.size() + 1);
//      heap_increase_key<Data> (A, A.size() - 1, key);
//}
//
//template <class Data>
//Data* heap_minimum (std::vector<Data*>& A) {
//      return A.front();
//}
//
//template <class Data>
//Data* heap_extract_min (std::vector<Data*>& A) {
//      assert(A.size() >= 1);
//      Data* max = A.front();
//      A.front() = A.back();
//      A.pop_back();
//      min_heapify(A, 1);
//      return max;
//}
//
//template <class Data>
//void heap_decrease_key (std::vector<Data*>& A, int i, Data* key) {
//      assert(A[i] == nullptr);
//      A[i] = key;
//      while (i > 0 and *A[i - 1] > *A[i]) {
//            swap (A[i], A[i - 1]);
//            --i;
//      }
//}
//
//template <class Data>
//void min_heap_insert (std::vector<Data*>& A, Data* key) {
//      A.resize(A.size() + 1);
//      heap_decrease_key<Data> (A, A.size() - 1, key);
//}
//
//
//
//template <class G>
//G* a_l_heap_minimum (G** A) {
//      return *A;
//}
//
//template <class G>
//G* a_l_heap_extract_min (G** A) {
//      //      assert(A.size() >= 1);
//
//      G* max = A[0];
//      A = &((*A[0]).next);
//      //      A[0]->next = nullptr;
//      //      cout << (**A).ant - 2 << endl;
//      //      A[(*A)->ant - 2]->next = nullptr;
//      //      cout << (**A).ant << endl;
//      (**A).ant--;
//      //      a_l_min_heapify(A, 1);
//      return max;
//}
//
//template <class G>
//void a_l_heap_decrease_key (G** A, int i, G* key) {
//      //      assert(A[i] == nullptr);
//      A[i] = key;
//      while (i > 0 and *A[i - 1] > *A[i]) {
//            swap (A[i], A[i - 1]);
//            --i;
//      }
//}
//
//template <class G>
//void a_l_min_heap_insert (G** A, G* key) {
//      //      A.resize(A.size() + 1);
//      a_l_heap_decrease_key<G> (A, (**A).ant - 1, key);
//}
//
//
//
//
//template <class Data, class Key>
//struct MinPrioQueueHeap{
//      std::vector<Data*> data;
//
//      void insert (Data* data) {
//
//      }
//      Data* maximum () {
//
//      }
//
//      void increase_key (Data* data, Key* key) {
//
//      }
//      MinPrioQueueHeap () {
//
//      }
//
//
//};
//
//template <class G>
//void print (G** g) {
//      G* i = g[0];
//      while (i != nullptr) {
//            cout << i->data << " key: ";
//            if ( i->key != nullptr ) {
//                  cout << *i->key << " ";
//            }
//            cout << "parent: ";
//            if ( i->parent != nullptr ) {
//                  cout << i->parent->data << endl;
//            }
//            cout << endl;
//            i = i->next;
//      }
//}
//
//
//
//
//int main(int argc, char** argv)
//{
//      int * i = new int{5};
//      std::vector<int*> v {new int{5}};
//      cout << v << endl;
//      min_heap_insert<int>(v, new int{4});
//      cout << v << endl;
//      min_heap_insert<int>(v, new int{7});
//      cout << v << endl;
//      min_heap_insert<int>(v, new int{8});
//      cout << v << endl;
//      min_heap_insert<int>(v, new int{1});
//      cout << v << endl;
//
//
//
//
//
//
//      auto Q = genGraph<10>(5);
//      Q->key = new int(0);
//
//
//
//
//      //      cout << *Q << endl;
//      //a_l_heap_extract_min(&Q);
//
//      //      cout << *Q << endl;
//      print(&Q);
//
//      auto q = Q;
//
//
//      while (q != nullptr) {
//            auto u = Q;
//
//
//
//            for (auto  i = q->edges; i != nullptr; i = i -> next) {
//
//            }
//            q = q->next;
//      }
//
//      return 0;
//
//      //      Ma({1, 2, 3}, {1, 2, 3}, {1, 2});
//      Ma({{1,2}, {3,4}, {1,3}}, {{1,2}, {3,4}, {1,3}});
//      Ma2({{{1,2}, {3,4}, {1,3}}, {{1,2}, {3,4}, {1,3}}}, {{{1,2}, {3,4}, {1,3}}, {{1,2}, {3,4}, {1,3}}});
//
//
//
//      Matrix<2, 3, int> m1 = {{1, 2, 3}, {4, 5, 6}};
//      Matrix<3, 2, int> m2 = {{7, 8}, {9, 10}, {11, 12}};
//
//
//      Matrix<4, 2, int> m3 =
//      {
//            {1, 2},
//            {3, 4},
//            {5, 6},
//            {7, 8}
//      };
//      //      cout << m3 << endl;
//
//      auto r = m3.col(0);
//      *r[1] = 0;
//      //      cout << m3 << endl;
//
//      Mat<2, 3>::Matrix<int> m {{5,6,5},{4,4,4}};
//      Mat<2, 3, 2>::Matrix<int> mm {{{1, 2},{3, 4},{5, 6}},{{7, 8},{9, 10},{11, 12}}};
//
//      cout << m << endl;
//      //      cout << m << endl;
//
//      //      auto ii = new int[]{{5,6,5},{4,4,4}};
//      //      auto aa = {{{1, 2},{1, 2},{1, 2}},{{1, 2},{1, 2},{1, 2}}};
//      //      int** r = m3.row(0);
//      //      *r[0] = 0;
//      //      r[1] = new int(-11);
//
//      //      int***& r = m3.row(0);
//      //      r = new int**[4]{[0 ... 3] = new int*[4]{[0 ... 3] = new int[2]{}}};
//
//
//
//
//
//
//
//
//      //      Matrix<2, 4, int> m4 = {{9, 10, 11, 12}, {13, 14, 15, 16}};
//      //
//      //      Matrix<1, 3, int> m5 = {1, 2, 3};
//      //      Matrix<3, 1, int> m6 = {4, 5, 6};
//      //
//      //      Matrix<2, 2, int> m7 = {{1, 2}, {3, 4}};
//      //      Matrix<2, 2, int> m8 = {{5, 6}, {7, 8}};
//      //
//      //      Matrix<1000, 1000, int> m9 {};
//      //      cout << m9 << endl;
//      //      for(auto& i : m9)
//      //            i[0] += 1;
//      //      cout << m9 << endl;
//
//
//
//
//
//
//      //      int i = get_right_distribution<int>(1, 6)(gen);
//      //
//      //      auto float_dis = get_right_distribution(1.F, 6.F);
//      //      std::cout << float_dis(gen) << "\n";
//
//
//
//      //      auto i = m1 * m2;
//      //      cout << i << endl;
//
//
//
//      //      cout << i << endl;
//
//
//
//      //      cout << m1 << endl;
//      //      cout << m1_transposed << endl;
//      return 0;
//}
