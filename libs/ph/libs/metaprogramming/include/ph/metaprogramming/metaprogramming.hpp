#pragma once
namespace ph::metaprogramming
{




////////////////////////////////////////////////////////////////
/// @brief Get compile-time size of for example tuple<int, char>
///
/// Since the nature of List parameter is unknown,
/// we cant give Size a proper definition
////////////////////////////////////////////////////////////////
template <class List>
struct Size;

template <template <typename...> typename List, typename... Elements>
struct Size<List<Elements...>> : std::integral_constant<size_t, sizeof...(Elements)>
{};






////////////////////////////////////////////////////////////////
/// @brief add an element to an existing type container
////////////////////////////////////////////////////////////////
template <class List, class New>
struct push_back;

template <template <class...> class List, class... Elements, class New>
struct push_back<List<Elements...>, New>
{
      using type = List<Elements..., New>;
};


//////////////////////////////////////////////////////////////////////////////
/// @brief pop first element in a type container
/// @example pop_front<tuple<int, string, char>>::type t1 = {"hej", 'g'};
//////////////////////////////////////////////////////////////////////////////
template <typename List>
struct pop_front;

template <template <class...> class List, class Head, class... Tail>
struct pop_front<List<Head, Tail...>>
{
      using type = List<Tail...>;
};

////////////////////////////////////////////////////////////////
/// @brief pop empty type container is OK, does nothing
/// @example pop_front<tuple<>>::type t3 = {};
////////////////////////////////////////////////////////////////
template <template <class...> class List>
struct pop_front<List<>>
{
      using type = List<>;
};




////////////////////////////////////////////////////////////////
/// @brief change type container for elements
/// @example using my_variant = rename<boost::variant
///                                 , std::tuple<int, short>
///                                 >;
////////////////////////////////////////////////////////////////
template <template<class...> class Container
      , class List
      >
struct rename;

template <template <class...> class Container
      , template <class...> class List
      , class... Elements
      >
struct rename<Container, List<Elements...>>
{
      using type = Container<Elements...>;
};


////////////////////////////////////////////////////////////////
/// @brief concatenate two different (or same) type containers
/// @example using concated = concat<std::tuple<int, string>,
///               std::tuple<string, char>>::type;
////////////////////////////////////////////////////////////////
template <typename First, typename Second>
struct concat;

template <template <class...> class First, typename... FirstElements
      , template <class...> class Second, typename... SecondElements
      >
struct concat<First<FirstElements...>, Second<SecondElements...>>
{
      using type = First<FirstElements..., SecondElements...>;
};





















































































}
