#pragma once
namespace ph::metaprogramming
{


////////////////////////////////////////////////////////////////
/// @brief Print a tuple
////////////////////////////////////////////////////////////////
template <class... A>
ostream& operator<< (ostream& os, const tuple<A...>& t)
{
      os << "{ ";
      apply([&os](const auto&... i){((os << i << " "), ...);}, t);
      os << "}";
      return os;
}



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

template<class F>
struct S;

template <class Fun, class... Params>
struct S<Fun (Params...)>
{
      using s = decltype(declval<Fun>());
};

////////////////////////////////////////////////////////////////
/// @brief takes a function and creates a tuple with params
////////////////////////////////////////////////////////////////
template <class F>
struct make_tuple_of_params;

template <class Fun, class... Params>
struct make_tuple_of_params<Fun (Params...)>
{
      using params = std::tuple<Params...>;
      using ret = decltype(declval<Fun(Params...)>());
//      using ret = typename std::invoke_result_t<Fun, Params...>;
//      using ret =  std::invoke_result<Fun, Params...>;
//      using r = typename std::invoke_result<Fun, Params...>::type;
//      static constexpr std::invoke_result_t<Fun, Params...> s;
//      using r = typename ret::type;
//      using returns = std::tuple
};

template <class F>
struct make_tuple_of_returns;

template <class Fun, class... Params>
struct make_tuple_of_returns<Fun (Params...)>
{
      using params = std::tuple<Params...>;
      using ret = std::result_of<Fun(Params...)>;
//      using r = decltype(Fun(Params...));
      //      using returns = std::tuple
};




////////////////////////////////////////////////////////////////
/// @brief create a tuple with N elements of type T
////////////////////////////////////////////////////////////////
template <typename T, size_t N>
class make_tuple_of_n {
      template <typename = std::make_index_sequence<N>>
      struct impl;
      
      template <size_t... Is>
      struct impl<std::index_sequence<Is...>> {
            template <size_t >
            using wrap = T;
            
            using type = std::tuple<wrap<Is>...>;
      };
      
public:
      using type = typename impl<>::type;
};





////////////////////////////////////////////////////////////////
/// @brief string =
///           dispatch_params (string (int, int),
///                            {1, 2});
////////////////////////////////////////////////////////////////
template <class Function,
          class... Params,
          std::size_t... I>
decltype(auto) dispatch_params (Function function,
                      const std::tuple<Params...>& params,
                      std::index_sequence<I...>)
{
      return function(get<I>(params)...);
}



template <class Function,
          class... Args,
          class... Params>
decltype(auto) dispatch_params (Function function (Args...),
                      const std::tuple<Params...>& params)
{
      static_assert(is_same<tuple<Args...>, tuple<Params...>>::value,
                    "wrong parameters");
      
      return dispatch_params(function,
                             params,
                             make_index_sequence<sizeof...(Params)>());
}






////////////////////////////////////////////////////////////////
/// @brief {"hej", "ok", "ja"} =
///           dispatch_paramtuples (string (int, int),
///                                 {{1, 2}, {3, 4}, {4, 5}});
///
/// @param function to call for every
////////////////////////////////////////////////////////////////
template <class Function,
          class... ParamsTuple,
          size_t... paramsTupleCount>
decltype(auto) dispatch_paramtuples (Function function,
                                     const tuple<ParamsTuple...>& paramsTuples,
                                     index_sequence<paramsTupleCount...>)
{
      return make_tuple(
                        dispatch_params(
                                        function,
                                        get<paramsTupleCount>(paramsTuples))...);
}


template <class Function,
          template<class...> class ParamsTuple,
          class... ParamsTuples>
decltype(auto) dispatch_paramtuples (Function function,
                     const ParamsTuple<ParamsTuples...>& paramsTuples)
{
      return dispatch_paramtuples(function,
                                  paramsTuples,
                                  make_index_sequence<sizeof...(ParamsTuples)>());
}





template <class Function, Function func>
struct function
{
      typedef integral_constant<Function, func> m_func;
      
      template <size_t Q>
      using params = typename make_tuple_of_n<typename make_tuple_of_params<Function>::params, Q>::type;// paramsTuple;
      
      template <size_t Q>
      using returns = typename make_tuple_of_n<typename make_tuple_of_params<Function>::ret, Q>::type;
      
      template <template<class...> class ParamsTuple,
                class... ParamsTuples>
      auto operator() (const ParamsTuple<ParamsTuples...>& paramsTuples)
      {
            return dispatch_paramtuples (func, paramsTuples);
      }
};



template<class T>
struct Y;

template <class Ret, class... Args>
struct Y<Ret(Args...)>
{
//      typedef Ret(*_f)(Args...);
//      static constexpr Ret(*function)(Args...);
      
//      static constexpr auto s = T();
//      static constexpr T q = t;
//      using ret = typename make_tuple_of_params<T>::ret;
};

template <class Func>
struct Z : public Y<decay_t<Func>>
{
      
};

//template <class T>
//struct X;



template <class Fun>
struct Q;

template <class Ret, class... Args>
struct Q<Ret(Args...)>
{
      using ret = Ret;
      
};

template <auto _func, typename _Func = decltype(_func), typename Func = decay_t<_Func>, auto func = _func>
struct fun
{
//      using Func = typename decay<decltype(func)>::type;
      typedef integral_constant<decltype(func), func> m_func;
      
//      template <size_t Q>
//      using params =

//      template <size_t Q>
//      using params = typename make_tuple_of_n<typename make_tuple_of_params<Func>::params, Q>::type;// paramsTuple;

      template <size_t Q>
      using returns = typename make_tuple_of_n<typename make_tuple_of_params<Func>::ret, Q>::type;

      template <template<class...> class ParamsTuple,
      class... ParamsTuples>
      auto operator() (const ParamsTuple<ParamsTuples...>& paramsTuples)
      {
            return dispatch_paramtuples (func, paramsTuples);
      }
};



































































//struct S {
//      double operator()(char, int&);
//      float operator()(int) { return 1.0;}
//};

//std::result_of<S(char, int&)>::type d = 3.14; // d has type double
//std::result_of<decltype(&printTwoNumbers)(int, int)>::type d1 = 3.14; // d has type double
//std::invoke_result<decltype(printTwoNumbers),int, int> d2;


}
