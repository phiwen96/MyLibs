#pragma once


class Station {
public:
      Station (const char* name) : m_name (name)
      {
            
      }
      friend ostream& operator<< (ostream& os, const Station& s)
      {
            os << s.m_name;
            return os;
      }
      
private:
      const char* m_name;
      
};
