#pragma once






namespace ph::utility::file{
// using namespace std;

extern std::mutex mtx;


template <typename To>
auto read (const char* file) -> To {
      throw std::runtime_error("not defined");
}


template <typename From>
auto write (const char* file, From from) -> void {
      throw std::runtime_error("not defined");
}

}


namespace ph::utility {

template <typename... T>
std::ostream& operator<< (std::ostream& os, const std::tuple<T...>& t)
{
      apply([&os](auto&&... args){((os << args << std::endl), ...);}, t);
      return os;
}


template<typename... U>
std::ostream& operator << (std::ostream& os, const std::vector<U...>& v)
{
      for(auto i = v.begin(); i != v.end(); ++i){
            os << "\t" << (*i) << std::endl;
      }
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
