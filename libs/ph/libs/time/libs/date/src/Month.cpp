#include <ph/time/date/Month.hpp>

namespace ph::time{
      
Month::Month() : Month([]{
      std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();
      std::time_t time_now_t = std::chrono::system_clock::to_time_t(time_now);
      std::tm now_tm = *std::localtime(&time_now_t);
      return now_tm;
}()){

}
Month::Month(int month) : m_Month(month){

}
Month::Month(const std::tm& now) : m_Month(now.tm_mon + 1){

}
Month::Month(Month&& other) : Month(){
      swap(*this, other);

}
Month::Month(const Month& other) : m_Month(other.m_Month){

}
void swap(Month& first, Month& second){
      using std::swap;
      swap(first.m_Month, second.m_Month);
}
Month& Month::operator=(Month other){
      swap(*this, other);
      return *this;
}
Month& Month::operator=(int&& month){
      m_Month=(int&&)month;
      return *this;
}
ostream& operator<<(ostream& os, const Month& month){
      os << month.m_Month;
      return os;
}
void Month::update(std::tm &now){
      m_Month = now.tm_mon;
}
bool operator==(const Month& first, const Month& second){
      return first.m_Month == second.m_Month;
}
Month& Month::operator++(int){
      ++m_Month;
      return *this;
}
}
