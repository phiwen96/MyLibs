// #pragma once


// template <template <typename...> typename Tuple, typename... T>
// class Machine
// {
// public:
      
//       template <typename Indices = index_sequence_for<T...>>
//       Machine (const Tuple<T...>& stations) : m_stations (stations), m_size (sizeof...(T)), m_seq (Indices{})
//       {
//             ((cout << get), ...);
//       }
      
// private:
//       Tuple<T...> m_stations;
//       size_t m_size;
//       decltype(index_sequence_for<T...>{}) m_seq;
      
// };
