#include <ph/core/core.hpp>

namespace ph::core {



template <>
inline bool isInteger(const std::string & s) {
      if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
      
      char * p;
      strtol(s.c_str(), &p, 10);
      
      return (*p == 0);
}

template <>
inline bool isInteger(const char* s) {
      return isInteger(std::string(s));
}

template <>
auto from_int (int i) -> const char* {
      //      static mutex mtx;
      //      lock_guard<mutex> lock (mtx);
      std::stringstream temp_str;
      temp_str<<(i);
      std::string str = temp_str.str();
      const char* cstr2 = str.c_str();
      return cstr2;
}






}
