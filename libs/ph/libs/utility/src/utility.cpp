#include <ph/utility/utility.hpp>



namespace ph::utility::file{


std::mutex mtx;

template <>
auto read<const char*> (const char* file) -> const char* {
      std::lock_guard<std::mutex> lock (mtx);
      std::ifstream f (file);
      
      std::string line, text;
      while (getline(f, line)) {
            text += line + "\n";
      }
      f.close();
      const char* s = text.c_str();
      return s;
}

template <>
auto read<std::string> (const char* file) -> std::string {
      std::lock_guard<std::mutex> lock (mtx);
      std::ifstream f (file);
      
      std::string line, text;
      while (getline(f, line)) {
            text += line + "\n";
      }
      f.close();
      return text;
}

template <>
auto read<nlohmann::json> (const char* file) -> nlohmann::json {
      return nlohmann::json::parse(read<std::string>(file));
}

//      template <>
//      auto read<nlohmann::json> (const char* file) -> nlohmann::json {
//                  lock_guard<mutex> lock (mtx);
//            ifstream i (file);
//            nlohmann::json j1;
//            i >> j1;
//            return j1;
//      }

template <>
auto write (const char* file, const std::string& from) -> void {
      std::lock_guard<std::mutex> lock (mtx);
      std::ofstream ff(file);
      ff << from;
      ff.close();
}

template <>
auto write (const char* file, const char*& from) -> void {
      std::lock_guard<std::mutex> lock (mtx);
      std::ofstream f (file);
      f << from;
      f.close();
}

template <>
auto write (const char* file, const nlohmann::json& from) -> void {
      std::lock_guard<std::mutex> lock (mtx);
      ph::utility::file::write(file, from.dump());
}


}


// namespace ph::utility{




namespace ph::utility{



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



// }