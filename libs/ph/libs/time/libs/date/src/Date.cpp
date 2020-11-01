#include <ph/time/date/Date.hpp>












namespace ph::time{





Date::Date(const std::tm& now) : m_Year(now), m_Month(now), m_Day(now), m_Hour(now), m_Minute(now), m_Second(now){
     
}
void Date::update(){
      std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();
      std::time_t time_now_t = std::chrono::system_clock::to_time_t(time_now);
      std::tm now_tm = *std::localtime(&time_now_t);
      
      m_Year.update(now_tm);
      m_Month.update(now_tm);
      m_Day.update(now_tm);
      m_Hour.update(now_tm);
      m_Minute.update(now_tm);
      m_Second.update(now_tm);
}

Date::Date(int year, int month, int day, int hour, int minute, int second) : m_Year(year), m_Month(month), m_Day(day), m_Hour(hour), m_Minute(minute), m_Second(second)
{

}

Date::Date() : Date([]{
      std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();
      std::time_t time_now_t = std::chrono::system_clock::to_time_t(time_now);
      std::tm now_tm = *std::localtime(&time_now_t);
      return now_tm;
}()){
      
      
}
Date::Date(Date&& other) : Date(){
      swap(*this, other);
}
Date::Date(const Date& other) : m_Year(other.m_Year), m_Month(other.m_Month), m_Day(other.m_Day), m_Hour(other.m_Hour), m_Minute(other.m_Minute), m_Second(other.m_Second){
      
}
void swap(Date& first, Date& second){
      using std::swap;
      swap(first.m_Year, second.m_Year);
      swap(first.m_Month, second.m_Month);
      swap(first.m_Day, second.m_Day);
      swap(first.m_Hour, second.m_Hour);
      swap(first.m_Minute, second.m_Minute);
      swap(first.m_Second, second.m_Second);
}
Date& Date::operator=(Date other){
      swap(*this, other);
      return *this;
}
ostream& operator<<(ostream& os, const Date& date){
      os << "Year: " << date.m_Year << endl;
      os << "Month: " << date.m_Month << endl;
      os << "Day: " << date.m_Day << endl;
      os << "Hour: " << date.m_Hour << endl;
      os << "Minute: " << date.m_Minute << endl;
      os << "Second: " << date.m_Second << endl;
      return os;
}
bool operator==(const Date& first, const Date& second){
      return first.m_Year == second.m_Year &&
      first.m_Month == second.m_Month &&
      first.m_Day == second.m_Day &&
      first.m_Hour == second.m_Hour &&
      first.m_Minute == second.m_Minute &&
      first.m_Second == second.m_Second;
}
Year& Date::year(){
      return m_Year;
}
Month& Date::month(){
      return m_Month;
}
Day& Date::day(){
      return m_Day;
}
Hour& Date::hour(){
      return m_Hour;
}
Minute& Date::minute(){
      return m_Minute;
}
Second& Date::second(){
      return m_Second;
}


}
