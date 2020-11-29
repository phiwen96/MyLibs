#pragma once



namespace ph::vulkan {

template <class...>
class _count;

template <class...>
struct __data;

template <class...>
struct _data;

template <class...>
struct Support;






template <>
class _count<>
{
      ////////////////////////////////////////////////////////////////
      /// @brief FUNCTIONS
      ////////////////////////////////////////////////////////////////
      _count ();
      ~_count ();
      
      ////////////////////////////////////////////////////////////////
      /// @brief DATA
      ////////////////////////////////////////////////////////////////
      uint32_t* m_count;
      
      template <class... T> friend class _count;
};





template <class T, class... U>
class __data<T, U...> : public _count<T, U...>
{
      friend class _data<T, U...>;
      using count = _count<T, U...>;
      using count::m_count;
      
      ////////////////////////////////////////////////////////////////
      /// @brief FUNCTIONS
      ////////////////////////////////////////////////////////////////
      template <class... A>
      __data (A const&... a);
      
      ~__data ();
      
      operator std::vector<T>();
      
      
      ////////////////////////////////////////////////////////////////
      /// @brief DATA
      ////////////////////////////////////////////////////////////////
      T* m_data;
};





template <class T, class... U>
struct Support<T, U...> : public _data<T, U...>
{
      using data = _data<T, U...>;
      using data::data;
      
      
};







template <>
struct Support<>
{
      template <class T>
            requires is_default_constructible_v<Support<T>>
      operator std::vector<T> () {
            return Support<T> {};
      }
};



Support (VkInstance) -> Support<VkInstance>;





















//#include "../../../src/_support.hpp"
template <class T> struct Foo{Foo(){cout<<"kiss"<<endl;}};
//struct BBB{};
}
