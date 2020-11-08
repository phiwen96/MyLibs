#include <ph/metaprogramming/test.hpp>
#include <ph/metaprogramming/metaprogramming.hpp>




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
      cout << a << endl;
      return N;
}


//struct S {
//      double operator()(char, int&);
//      float operator()(int) { return 1.0;}
//};

void Testing::run ()
{
      pr("hej");
//      printDecayedType<int>();
//      printDecayedType<int const>();
//      printDecayedType<int[7]>();
//      printDecayedType<int(int)>();
      
      
      constN<5> out1;
      return;
      
//      Y<decltype(sum)> q;
//      Y<decltype(sum)>::function(1, 2);
      
//      cout << q.q();
      //      {summa1, summa2, summa3} = sum {{4,5}, {4,6}, {4, 6}};
      
      //      make_tuple_of_params<decltype(sum)>::params s;
      //
      //
      //
      //      // tuple ( tuple (double, double), tuple (double, double), tuple (double, double), tuple (double, double) )
      //      make_tuple_of_n<make_tuple_of_params<decltype(sum)>::params, 4>::type paramsTuple;
      //
      //      // tuple ( tuple (const char*), tuple (const char*), tuple (const char*), tuple (const char*) )
      //      make_tuple_of_n<make_tuple_of_params<decltype(sum)>::return_type, 4>::type returnTuple;
      
      
      //      using F = execute<decltype(sum), sum>;
      //      F::paramsTuple<3> t = {{0, 2}, {3, 4}, {5, 6}};
      //      auto r = F()(t);
      //      cout << r << endl;
      
      
    
      std::invoke_result<decltype(sum),int, int>::type d2 = 7;
      
      
//      make_tuple_of_params<decltype(sum)>::ret::type a = 8;
//      make_tuple_of_params<decltype(sum)>::r::type a;// a = 8;
//      aa::type s;
      
      
      
      //      using F = function<decltype(sum), sum>;
      using F = function<decltype(sum), sum>;
      F::params<3> p = {{0, 2}, {3, 4}, {5, 6}};
      auto r = F()(p);
      cout << r << endl;
//      F::returns<3> r2 = {1, 2, 2};
      
//      using F2 = fun<sum>;
//      F2::params<3> p2 = {{0, 2}, {3, 4}, {5, 6}};
//      auto r3 = F2()(p);
//      cout << r3 << endl;
//      F2::returns<3> r4 = {1, 2, 2};
      
      
      Q<decltype(kiss)>::ret a = "km";
      
      
      
//      make_tuple_of_returns<decltype(sum)>::ret r2= {3};
      //      F::rets<3> s = {1, 2, 3};
      
      //      using P = F::parameters<decltype(p)>;
      //      auto i = F().run(p);
      
      
      
      
      
      
      
      test_Size ();
      test_push_back ();
      test_rename ();
      test_concat ();
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
      pop_front<tuple<>>::type t3 = {};
      
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
