#include <ph/metaprogramming/test.hpp>
#include <ph/metaprogramming/metaprogramming.hpp>
#include <ph/metaprogramming/typelist.hpp>
using namespace std;




namespace ph::metaprogramming
{

int sum (int i, int j)
{
      return i + j;
}

template<typename T>
void printDecayedType()
{
      using A = typename decay<T>::type;
//      using A = T;
      std::cout << "Parameter type: " << typeid(A).name() << '\n';
      std::cout << "- is int:     " << std::is_same<A,int>::value << '\n';
      std::cout << "- is const:   " << std::is_const<A>::value << '\n';
      std::cout << "- is pointer: " << std::is_pointer<A>::value << '\n';
}

constexpr int print(){
//      cout << "HELLO" << endl;
      return 0;
}

template<int n>
struct constN
{
      constN() { std::cout << n << '\n'; }
};

const char* kiss()
{
      return "hej";
}

template <int N>
constexpr int size (char const(&a)[N])
{
      return N;
}

template <int t>
struct Loop
{
      static constexpr long long value = 10 + Loop<t-1>::value;
};

template<>
struct Loop<1>
{
      static constexpr long long value = 10;
};

constexpr long long sum(int s)
{
      long long ret = 0;
      for (int i = 0; i < s; ++i) {
            ret++;
      }
      return ret;
}
// repeatedly determine in which half of a [lo, hi] interval the square root of x is located,
// until the interval is reduced to just one value:






//struct S {
//      double operator()(char, int&);
//      float operator()(int) { return 1.0;}
//};

void Testing::run ()
{
      
      
      
      //      // tuple ( tuple (double, double), tuple (double, double), tuple (double, double), tuple (double, double) )
      //      make_tuple_of_n<make_tuple_of_params<decltype(sum)>::params, 4>::type paramsTuple;
      //
      //      // tuple ( tuple (const char*), tuple (const char*), tuple (const char*), tuple (const char*) )
      //      make_tuple_of_n<make_tuple_of_params<decltype(sum)>::return_type, 4>::type returnTuple;
      

//      std::invoke_result<decltype(sum),int, int>::type d2 = 7;
//
//
//
//      //      using F = function<decltype(sum), sum>;
//      using F = function<decltype(sum), sum>;
//      F::params<3> p = {{0, 2}, {3, 4}, {5, 6}};
//      auto r = F()(p);
//      cout << r << endl;
//
//
//      Q<decltype(kiss)>::ret a = "km";
//
//
//
//
//      test_Size ();
//      test_push_back ();
//      test_rename ();
//      test_concat ();
      test_typelist();
}


void Testing::test_typelist()
{
//      int i = 2;
//      using mylist = Typelist<int, bool, const char*>;
//      static_assert(is_same_v<ith<0, mylist>::type, int>);
//      static_assert(is_same_v<ith<1, mylist>, bool>);
//      static_assert(is_same_v<ith<2, mylist>::type, const char*>);
//
//      static_assert(is_same_v<pop_front<mylist>::type, Typelist<bool, const char*>>);
//
//
      
//      static_assert(is_same_v<pop<1, mylist>::type, Typelist<int, const char*>>);

}

void Testing::test_Size ()
{
      ////////////////////////////////////////////////////////////////
      /// @brief get size of arbitrary type container
      ////////////////////////////////////////////////////////////////
      constexpr size_t s = Size<tuple<int, float, void>>::value;
      static_assert(s == 3, "expected s = 3");
}

void Testing::test_push_back ()
{
      push_back<tuple<int, float, char>, string>::type q = {2, 3.0f, 'g', "hejsan"};
}

void Testing::test_pop_front ()
{
      
      ////////////////////////////////////////////////////////////////
      /// @brief pop arbitrary type container
      ////////////////////////////////////////////////////////////////
      pop_front<tuple<int, string, char>>::type t1 = {"hej", 'g'};
      
      ////////////////////////////////////////////////////////////////
      /// @brief pop container with just one parameter
      ////////////////////////////////////////////////////////////////
      pop_front<tuple<int>>::type t2 = {};
      
      ////////////////////////////////////////////////////////////////
      /// @brief pop empty type container
      ////////////////////////////////////////////////////////////////
//      pop_front<tuple<>>::type t3 = {};
      
}

void Testing::test_rename ()
{
      using my_type = rename<std::variant, std::tuple<int, std::string>>::type;
      static_assert(std::is_same<std::variant<int, std::string>, my_type>::value == 1, "expected theese types are the same");
}

void Testing::test_concat ()
{
      using concated = concat<std::tuple<int, string>, std::tuple<string, char>>::type;
      static_assert(std::is_same<concated, std::tuple<int, string, string, char>>::value == 1, "expected theese types are the same");
}

}





//      cout << get<0>(s) << endl;
//      cout << tuple_size<decltype(s)>::value << endl;
//      std::result_of<S(char, int&)>::type d = 3.14; // d has type double
//      std::result_of<decltype(&printTwoNumbers)(int, int)>::type d1 = 3.14; // d has type double
//      std::invoke_result<decltype(printTwoNumbers),int, int> d2;
