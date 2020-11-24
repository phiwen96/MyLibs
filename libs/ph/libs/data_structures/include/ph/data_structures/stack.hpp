#pragma once

namespace ph::data_structures
{






template <class T, size_t N>
class Stack
{
      T** m_elements{new T*[N]};
      size_t m_currentsize{0};
      static constexpr size_t m_maxsize{N};
      
      
public:
      bool empty () const
      {
            return m_currentsize == 0;
      }
      
      void push (const T& t)
      {
            assert(m_currentsize != m_maxsize);
            m_elements[m_currentsize] = new T(t);
            m_currentsize++;
      }
      
      void pop ()
      {
            assert(m_currentsize > 0);
            m_currentsize--;
            delete m_elements[m_currentsize];
      }
      
      
      
      
      
      
      
      friend ostream& operator<< (ostream& os, const Stack& s)
      {
            for(int i = 0; i < s.m_currentsize; ++i)
                  os << *s.m_elements[i] << " ";
            
            for(int i = s.m_currentsize; i < s.m_maxsize; ++i)
                  os << "NULL ";
            return os;
            
            
      }
};











}
