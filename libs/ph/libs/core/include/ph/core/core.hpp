#pragma once
namespace ph::core
{

template <typename... T>
std::ostream& operator<< (std::ostream& os, const std::tuple<T...>& t)
{
      apply([&os](auto&&... args){((os << args << std::endl), ...);}, t);
      return os;
}


template<typename... U>
std::ostream& operator << (std::ostream& os, const std::vector<U...>& v)
{
      os << "{ ";
      for(auto i = v.begin(); i != v.end(); ++i){
            os << (*i) << " ";
      }
      os << "}";
      //      throw std::runtime_error ("not defined");
      return os;
}


template <typename T>
bool isInteger (T) {
      throw std::runtime_error ("not defined");
}



template <typename T>
auto from_int (int i) -> T {
      throw std::runtime_error("not defined");
}


}
