#pragma once
#include <iostream>
using namespace std;



class t {
public:
      t();
      t(t&&) noexcept;
      t(const t&);
      
      ~t();
      
      friend void swap(t&, t&);
      t& operator=(t);
      
      friend ostream& operator<<(ostream&, const t&);
      
      t& operator/=(const t&);
      t& operator*=(const t&);
      t& operator+=(const t&);
      t& operator-=(const t&);
      
      friend t operator/(t, const t&);
      friend t operator*(t, const t&);
      friend t operator+(t, const t&);
      friend t operator-(t, const t&);
      
      t& operator++();
      t& operator--();
      
      t operator++(int);
      t operator--(int);
      
//      t& operator=(t);
      
      bool operator==(const t&);
      bool operator!=(const t&);
      
private:
      
};
