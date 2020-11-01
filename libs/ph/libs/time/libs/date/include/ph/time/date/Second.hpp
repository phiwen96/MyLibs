#pragma once
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;




namespace ph::time{
class Second{
      int m_Second;
      
public:
      Second();
      Second(int);
      Second(const std::tm& now);
      Second(Second&& other);
      Second(const Second& other);
      friend void swap(Second& first, Second& second);
      Second& operator=(Second other);
      friend std::ostream& operator<<(std::ostream& os, const Second& Second);
      void update(std::tm& now);
      friend bool operator==(const Second& first, const Second& second);
      Second& operator++(int);
};
}
