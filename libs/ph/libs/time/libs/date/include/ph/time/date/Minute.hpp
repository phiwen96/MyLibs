#pragma once
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
namespace ph::time{
class Minute{
      int m_Minute;
      
public:
      Minute();
      Minute(int);
      Minute(const std::tm& now);
      Minute(Minute&& other);
      Minute(const Minute& other);
      friend void swap(Minute& first, Minute& second);
      Minute& operator=(Minute other);
      friend std::ostream& operator<<(std::ostream& os, const Minute& Minute);
      void update(std::tm& now);
      friend bool operator==(const Minute& first, const Minute& second);
      Minute& operator++(int);
};
}
