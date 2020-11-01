#pragma once
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
namespace ph::time{
class Hour{
      int m_Hour;
      
public:
      Hour();
      Hour(int);
      Hour(const std::tm& now);
      Hour(Hour&& other);
      Hour(const Hour& other);
      friend void swap(Hour& first, Hour& second);
      Hour& operator=(Hour other);
      friend std::ostream& operator<<(std::ostream& os, const Hour& Hour);
      void update(std::tm& now);
      friend bool operator==(const Hour& first, const Hour& second);
      Hour& operator++(int);
};
}
