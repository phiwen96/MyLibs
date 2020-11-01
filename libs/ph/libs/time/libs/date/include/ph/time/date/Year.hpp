#pragma once
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

namespace ph::time{
class Year{
      int m_Year;
      
public:
      Year();
      Year(int);
      Year(const std::tm& now);
      Year(Year&& other);
      Year(const Year& other);
      friend void swap(Year& first, Year& second);
      Year& operator=(Year other);
      friend std::ostream& operator<<(std::ostream& os, const Year& year);
      void update(std::tm& now);
      friend bool operator==(const Year& first, const Year& second);
      Year& operator++(int);
};
}
