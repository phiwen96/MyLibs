#pragma once
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

#include "Year.hpp"
#include "Month.hpp"
#include "Day.hpp"
#include "Hour.hpp"
#include "Minute.hpp"
#include "Second.hpp"

namespace ph::time{

class Date{
public:
      Year& year();
      Month& month();
      Day& day();
      Hour& hour();
      Minute& minute();
      Second& second();
      
      void update();
      
      Date(int year, int month, int day, int hour, int minute, int second);
      Date();
      Date(Date&& other);
      Date(const Date& other);
      friend void swap(Date& first, Date& second);
      Date& operator=(Date other);
      friend std::ostream& operator<<(std::ostream& os, const Date& date);
      friend bool operator==(const Date& first, const Date& second);
      
private:
      Year m_Year;
      Month m_Month;
      Day m_Day;
      Hour m_Hour;
      Minute m_Minute;
      Second m_Second;
      
      Date(const std::tm& now);
};
}
