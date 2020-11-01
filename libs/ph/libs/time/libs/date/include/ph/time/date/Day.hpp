#pragma once
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

namespace ph::time{
class Day{
      int m_Day;
public:
      Day();
      Day(int);
      Day(const std::tm& now);
      Day(Day&& other);
      Day(const Day& other);
      friend void swap(Day& first, Day& second);
      Day& operator=(Day other);
      friend std::ostream& operator<<(std::ostream& os, const Day& day);
      void update(std::tm& now);
      friend bool operator==(const Day& first, const Day& second);
      Day& operator++(int);
};
}
