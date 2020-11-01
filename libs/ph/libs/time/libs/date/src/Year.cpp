#include <ph/time/date/Year.hpp>
using namespace std;
namespace ph::time{
Year::Year() : Year([]{
      std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();
      std::time_t time_now_t = std::chrono::system_clock::to_time_t(time_now);
      std::tm now_tm = *std::localtime(&time_now_t);
      return now_tm;
}()){
      
}
Year::Year(int year) : m_Year(year){
      
}
Year::Year(const std::tm& now) : m_Year(now.tm_year + 1900){

}
Year::Year(Year&& other) : Year(){
      swap(*this, other);
}
Year::Year(const Year& other) : m_Year(other.m_Year){
      
}
void swap(Year& first, Year& second){
      using std::swap;
      swap(first.m_Year, second.m_Year);
}
Year& Year::operator=(Year other){
      swap(*this, other);
      return *this;
}
ostream& operator<<(ostream& os, const Year& year){
      os << year.m_Year;
      return os;
}
void Year::update(std::tm &now){
      m_Year = now.tm_year;
}
bool operator==(const Year& first, const Year& second){
      return first.m_Year == second.m_Year;
}
Year& Year::operator++(int){
      ++m_Year;
      return *this;

      
}
}
