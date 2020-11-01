#pragma once
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
namespace ph::time{
class Month{
      int m_Month;
      
public:
      Month();
      Month(int);
      Month(const std::tm& now);
      Month(Month&& other);
      Month(const Month& other);
      friend void swap(Month& first, Month& second);
      Month& operator=(Month other);
      Month& operator=(int&&);
      friend std::ostream& operator<<(std::ostream& os, const Month& month);
      void update(std::tm& now);
      friend bool operator==(const Month& first, const Month& second);
      Month& operator++(int);
};
}
