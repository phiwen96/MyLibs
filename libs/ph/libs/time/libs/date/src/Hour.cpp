#include <ph/time/date/Hour.hpp>

namespace ph::time{
Hour::Hour() : Hour([]{
      std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();
      std::time_t time_now_t = std::chrono::system_clock::to_time_t(time_now);
      std::tm now_tm = *std::localtime(&time_now_t);
      return now_tm;
}()){
      
}
Hour::Hour(int hour) : m_Hour(hour){
      
}
Hour::Hour(const std::tm& now) : m_Hour(now.tm_hour){
      
}
Hour::Hour(Hour&& other) : Hour(){
      swap(*this, other);
}
Hour::Hour(const Hour& other) : m_Hour(other.m_Hour){
      
}
void swap(Hour& first, Hour& second){
      using std::swap;
      swap(first.m_Hour, second.m_Hour);
}
Hour& Hour::operator=(Hour other){
      swap(*this, other);
      return *this;
}
ostream& operator<<(ostream& os, const Hour& Hour){
      os << Hour.m_Hour;
      return os;
}
void Hour::update(std::tm &now){
      m_Hour = now.tm_hour;
}
bool operator==(const Hour& first, const Hour& second){
      return first.m_Hour == second.m_Hour;
}
Hour& Hour::operator++(int){
      ++m_Hour;
      return *this;
}
}
