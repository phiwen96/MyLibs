#pragma once
namespace ph::math
{



template <typename... T>
struct is_arith
{
      static constexpr bool value = std::conjunction_v<std::is_arithmetic<T>...> && (!std::is_same_v<T, char> && ...);
};

















































































}



