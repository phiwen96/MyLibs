#pragma once
namespace ph::metaprogramming
{


template <typename SizeType, class List>
struct Size;

template <typename SizeType, template <typename...> typename List, typename... Elements>
struct Size<SizeType, List<Elements...>> : std::integral_constant<size_t, sizeof...(Elements)>
{};















































}
