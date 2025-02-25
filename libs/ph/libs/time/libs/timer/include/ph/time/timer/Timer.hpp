#pragma once
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
namespace ph::time{


      
class Timer {
public:
      
      // clears the timer
      Timer(const char* msg) : m_msg(msg), m_start(system_clock::time_point::min()) {
            Start();
      }
      
      ~Timer(){
            
            cout << m_msg << ": " << GetMs() << " ms" << endl;
      }
      
      // clears the timer
      void Clear(){
            m_start = system_clock::time_point::min();
      }
      
      // returns true if the timer is running
      bool IsStarted() const{
            return (m_start != system_clock::time_point::min());
      }
      
      // start the timer
      void Start(){
            m_start = std::chrono::system_clock::now();
      }
      
      // get the number of milliseconds since the timer was started
      unsigned long GetMs(){
            if (IsStarted()) {
                  system_clock::duration diff;
                  diff = system_clock::now() - m_start;
                  return (unsigned) (duration_cast<milliseconds>(diff).count());
            }
            return 0;
      }
      
private:
      std::chrono::system_clock::time_point m_start;
      const char* m_msg;
};
}




