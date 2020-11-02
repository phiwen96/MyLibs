#include <ph/metaprogramming/test.hpp>
#include <ph/metaprogramming/metaprogramming.hpp>




namespace ph::metaprogramming
{

void Testing::run ()
{
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



