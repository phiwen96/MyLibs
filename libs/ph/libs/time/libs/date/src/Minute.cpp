#include <ph/time/date/Minute.hpp>

namespace ph::time{
Minute::Minute() : Minute([]{
      std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();
      std::time_t time_now_t = std::chrono::system_clock::to_time_t(time_now);
      std::tm now_tm = *std::localtime(&time_now_t);
      return now_tm;
}()){
      
}
Minute::Minute(int minute) : m_Minute(minute){
      
}
Minute::Minute(const std::tm& now) : m_Minute(now.tm_min){
      
}
Minute::Minute(Minute&& other) : Minute(){
      swap(*this, other);
}
Minute::Minute(const Minute& other) : m_Minute(other.m_Minute){
      
}
void swap(Minute& first, Minute& second){
      using std::swap;
      swap(first.m_Minute, second.m_Minute);
}
Minute& Minute::operator=(Minute other){
      swap(*this, other);
      return *this;
}
ostream& operator<<(ostream& os, const Minute& Minute){
      os << Minute.m_Minute;
      return os;
}
void Minute::update(std::tm &now){
      m_Minute = now.tm_min;
}
bool operator==(const Minute& first, const Minute& second){
      return first.m_Minute == second.m_Minute;
}
Minute& Minute::operator++(int){
      ++m_Minute;
      return *this;
}
}
