#include <ph/time/date/Day.hpp>

namespace ph::time{
Day::Day() : Day([]{
      std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();
      std::time_t time_now_t = std::chrono::system_clock::to_time_t(time_now);
      std::tm now_tm = *std::localtime(&time_now_t);
      return now_tm;
}()){
      
}
Day::Day(int day) : m_Day(day){
      
}
Day::Day(const std::tm& now) : m_Day(now.tm_mday){
      
}
Day::Day(Day&& other) : Day(){
      swap(*this, other);
}
Day::Day(const Day& other) : m_Day(other.m_Day){
      
}
void swap(Day& first, Day& second){
      using std::swap;
      swap(first.m_Day, second.m_Day);
}
Day& Day::operator=(Day other){
      swap(*this, other);
      return *this;
}
ostream& operator<<(ostream& os, const Day& day){
      os << day.m_Day;
      return os;
}
void Day::update(std::tm &now){
      m_Day = now.tm_mday;
}
bool operator==(const Day& first, const Day& second){
      return first.m_Day == second.m_Day;
}
Day& Day::operator++(int){
      ++m_Day;
      return *this;
}
}
