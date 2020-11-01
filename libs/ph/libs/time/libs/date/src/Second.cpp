#include <ph/time/date/Second.hpp>
using namespace std;
namespace ph::time{
Second::Second() : Second([]{
      std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();
      std::time_t time_now_t = std::chrono::system_clock::to_time_t(time_now);
      std::tm now_tm = *std::localtime(&time_now_t);
      return now_tm;
}()){
      
}
Second::Second(int second) : m_Second(second){
      
}
Second::Second(const std::tm& now) : m_Second(now.tm_sec){
      
}
Second::Second(Second&& other) : Second(){
      swap(*this, other);
}
Second::Second(const Second& other) : m_Second(other.m_Second){
      
}
void swap(Second& first, Second& second){
      using std::swap;
      swap(first.m_Second, second.m_Second);
}
Second& Second::operator=(Second other){
      swap(*this, other);
      return *this;
}
ostream& operator<<(ostream& os, const Second& Second){
      os << Second.m_Second;
      return os;
}
void Second::update(std::tm &now){
      m_Second = now.tm_sec;
}
bool operator==(const Second& first, const Second& second){
      return first.m_Second == second.m_Second;
}
Second& Second::operator++(int){
      ++m_Second;
      return *this;
}
}
