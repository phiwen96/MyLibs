#pragma once

namespace ph::metaprogramming
{









template <typename... Elements>
struct Typelist{};






template <class List>
struct front;

template <template <class...> class List, class T, class... U>
struct front<List<T, U...>>
{
      using type = T;
};

template <template <class...> class List, class T, class... U>
using front_t = typename front<List<T, U...>>::type;



template <size_t N, typename... T>
struct ith;

template <size_t N, template <typename...> typename List, typename... U>
struct ith<N, List<U...>> : public ith<N-1, pop_front<List<U...>>> {};

template <template <typename...> typename List, typename... U>
struct ith<0, List<U...>> : public front<List<U...>>
{
 
};





































}










//template <size_t N, class List>
//struct Kuk
//{
//
//};
//
//template <size_t N, template<class...> class List, class Head, class... Tail>
//struct Kuk<N, List<Head, Tail...>>
//{
//      using type = typename Kuk<N-1, List<Tail...>>::type;
//};
//
//template <template<class...> class List, class Head, class... Tail>
//struct Kuk<0, List<Head, Tail...>>
//{
//      using type = Head;
//};
