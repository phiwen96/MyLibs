#pragma once
namespace ph {

template <class Find, class... Rest>
struct exists_in {
      constexpr inline static bool value = []{
            if constexpr((std::is_same_v<Find, Rest> || ...)) {
                  return true;
            }
            return false;
      }();
};
template <class Find, class... Rest>
constexpr bool exists_in_v = exists_in<Find, Rest...>::value;

template <class...>
struct comes_before;

template <class First, class Second>
struct comes_before<First, Second> {
      constexpr inline static bool value = false;
};

template <class First, class Second, class T, class... U>
struct comes_before<First, Second, T, U...> {
      
      constexpr inline static bool value = []{
            if constexpr (std::is_same_v<Second, T>)
                  return false;
            return comes_before<First, Second, U...>::value;
      };
      //[]{
      //
      //            if constexpr((std::is_same_v<First, U> or ...)) {
      //                  return true;
      //            }
      //            return false;
      //      }();
};

template <class First, class Second, class... T>
constexpr bool comes_before_v = comes_before<First, Second, T...>::value;

template <size_t t, class...>
struct index;

template <size_t s, class Find>
struct index<s, Find> {
      constexpr inline static int value = -1;
};

template <size_t s, class Find, class T, class... U>
struct index<s, Find, T, U...> {
      constexpr inline static size_t value = []() -> size_t {
            if constexpr ( std::is_same_v<Find, T> ) {
                  return s;
            }
            return index<s + 1, Find, U...>::value;
      }();
};

template <class Find, class T, class... U>
constexpr int index_v = index<0, Find, T, U...>::value;


}
namespace ph::vulkan {

////////////////////////////////////////////////////////////////
/// @brief Use for specialization
////////////////////////////////////////////////////////////////
template <class...>
struct InfoVisitor;
template <>
struct InfoVisitor<>{
      
};

template <class T, class... U>
struct InfoVisitor<T, U...> 
{
      using Fun = void (*) (T, U...);

      
      Fun fun;
//      InfoVisitor<U...> v;
      InfoVisitor (Fun fun) : fun (move(fun)) {
            
      }
//      InfoVisitor (Fun2 fun) : v (fun) {
//
//      }

//      virtual void visit (T t) {
//
//      }
//      virtual void visit (U... u) {
//
//      }
      void visit (T t, U... u) {
            fun(t, u...);
//            v.visit(u...);
      }
//      void visit (U... u) {
//            InfoVisitor<U...>::visit(u...);
//            //            v.visit(u...);
//      }
};

//template <class T, class R>
//InfoVisitor(R r) -> InfoVisitor<T, decltype(r)>;



////////////////////////////////////////////////////////////////
/// @brief Helper class for A, Derived = Info
////////////////////////////////////////////////////////////////
template <class Derived, class T> struct B : T {
      B (T&& t) : T(move(t)) {
            
      }
      B (T const& t) : T(t) {
            
      }
      B () {
            
      }
      constexpr Derived* derived () {
            return static_cast<Derived*>(this);
      }
      
      template <class... U>
      Derived& operator() (InfoVisitor<T&, U&...>& visitor) {
            visitor.visit(static_cast<T&>(*this), static_cast<U&>(*derived())...);
            return *derived();
//            visitor.visit((T&)static_cast<T&>(*this));
      }
      
      
      Derived& operator() (void (*visitor)(T&)) {
            visitor(static_cast<T&>(*this));
            return *derived();
      }
      
//      template <class... U>
//      void operator() (void (*visitor)(T&, U&...)) {
//            visitor(static_cast<T&>(*this), (U)(*derived())...);
//      }
};

////////////////////////////////////////////////////////////////
/// @brief Use for specialization, Derived = Info
////////////////////////////////////////////////////////////////
template <class Derived, class T> struct A : B<Derived, T> {};

////////////////////////////////////////////////////////////////
/// @brief Helper class for Info
////////////////////////////////////////////////////////////////
template <class...> struct __Info;
template <class Derived> struct __Info<Derived> {};
template <class Derived, class T, class... U> struct __Info<Derived, T, U...> : A<Derived, T> {};







////////////////////////////////////////////////////////////////
/// @brief Main
////////////////////////////////////////////////////////////////
template <class... T>
class Info: public __Info<Info<T...>, T>... {

//      using __Info<Info<T...>, T>::operator()...;
      static_assert ( not (ph::index_v<VkApplicationInfo, T...> < ph::index_v<VkInstanceCreateInfo, T...>));
      
public:
      Info(T&&... t) : __Info<Info<T...>, T>{std::forward<T>(std::move(t))}... {
            
      }
      Info(T const&... t) : __Info<Info<T...>, T>{t}... {
            
      }
      Info () : __Info<Info<T...>, T>{}... {
            
      }
      
      
};
















////////////////////////////////////////////////////////////////
/// @brief Specializations
////////////////////////////////////////////////////////////////
template <class Derived> struct A<Derived, VkInstanceCreateInfo> : B<Derived, VkInstanceCreateInfo> {
      using B = B<Derived, VkInstanceCreateInfo>;
      using B::B;
      
      A () : B {
            {
                  .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                  .pApplicationInfo = nullptr,
                  .enabledLayerCount = 0,
                  .ppEnabledLayerNames = nullptr,
                  .enabledExtensionCount = 0,
                  .ppEnabledExtensionNames = nullptr
            }
      } {
            
      }
      
      operator VkInstance () {
            cout << ((VkInstanceCreateInfo*)this)->pApplicationInfo << endl;
            B::pApplicationInfo = B::derived();
            cout << ((VkInstanceCreateInfo*)this)->pApplicationInfo << endl;
            VkInstance instance {};
            
            if (vkCreateInstance(static_cast<const VkInstanceCreateInfo*>(this), nullptr, &instance) != VK_SUCCESS) {
                  throw std::runtime_error("failed to create instance!");
            }
            return instance;
      }
};
template <class Derived> struct A<Derived, VkApplicationInfo> : B<Derived, VkApplicationInfo> {
      using B = B<Derived, VkApplicationInfo>;
      using B::B;
      
      A () : B {
            {
                  .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
                  .pApplicationName = "App",
                  .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
                  .pEngineName = "No Engine",
                  .engineVersion = VK_MAKE_VERSION(1, 0, 0),
                  .apiVersion = VK_API_VERSION_1_0,
            }
      } {
            
      }
      
};














////////////////////////////////////////////////////////////////
/// @brief Info example
////////////////////////////////////////////////////////////////
struct Example {
      void run ();
      
};





}
