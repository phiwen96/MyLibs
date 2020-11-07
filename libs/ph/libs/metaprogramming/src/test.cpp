#include <ph/metaprogramming/test.hpp>
#include <ph/metaprogramming/metaprogramming.hpp>




namespace ph::metaprogramming
{

int sum (int i, int j)
{
      return i + j;
}

struct S {
      double operator()(char, int&);
      float operator()(int) { return 1.0;}
};

void Testing::run ()
{
//      {summa1, summa2, summa3} = sum {{4,5}, {4,6}, {4, 6}};
      
      make_tuple_of_params<decltype(sum)>::params s;
      
      
      
      // tuple ( tuple (double, double), tuple (double, double), tuple (double, double), tuple (double, double) )
      make_tuple_of_n<make_tuple_of_params<decltype(sum)>::params, 4>::type paramsTuple;
      
      // tuple ( tuple (const char*), tuple (const char*), tuple (const char*), tuple (const char*) )
      make_tuple_of_n<make_tuple_of_params<decltype(sum)>::return_type, 4>::type returnTuple;
      
      
//      dispatch_params(printTwoNumbers, make_tuple(1,2));
      
      auto i = dispatch_paramtuples(sum, make_tuple(make_tuple(1,2), make_tuple(3,4)));
      cout << i << endl;
      
      
      
      tuple<tuple<int,int>,tuple<int,int>,tuple<int,int>> a = {{1,2}, {3,4}, {5,6}};
      
      auto i2 = dispatch_paramtuples(sum, a);
      cout << i2 << endl;
      
//      execute<decltype(printTwoNumbers), 3>::paramsTuples ss = {{1,2}, {3,4}, {5,6}};
      
      
//      auto returnT = dispatch_params(printTwoNumbers, a);
//      cout << get<0>(returnT) << endl;
//      auto returnT2 = dispatch_params(printTwoNumbers, make_tuple(4));
      
      
//      cout << get<0>(s) << endl;
//      cout << tuple_size<decltype(s)>::value << endl;
//      std::result_of<S(char, int&)>::type d = 3.14; // d has type double
//      std::result_of<decltype(&printTwoNumbers)(int, int)>::type d1 = 3.14; // d has type double
//      std::invoke_result<decltype(printTwoNumbers),int, int> d2;

      make_tuple_of_n<int, 10>::type q;
//      execute<decltype(printTwoNumbers), 3> K;
//      execute<decltype(printTwoNumbers), 3>::paramsTuples sss = {{0, 2}, {3, 4}, {5, 6}};
//      auto ii = execute<decltype(printTwoNumbers), 3>()(printTwoNumbers, sss);
//      cout << ii << endl;
//      auto iii = execute<decltype(printTwoNumbers), printTwoNumbers, 3>()({{0, 2}, {3, 4}, {5, 6}});
      auto k = execute<decltype(sum), sum>
//      auto iii = execute<decltype(sum), sum, 3>()({{0, 2}, {3, 4}, {5, 6}});
//      cout << iii << endl;
      
//      sum(5);
      
      
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



