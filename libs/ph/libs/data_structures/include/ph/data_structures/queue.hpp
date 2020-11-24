#pragma once

namespace ph::data_structures
{

template <class T, size_t N>
class Queue
{
      T** m_elements{new T*[N]};
      size_t m_head{0};
      size_t m_tail{0};
      static constexpr size_t m_maxsize{N};
      
public:
      void enqueue (const T& t)
      {
            m_elements[m_tail] = new T(t);
            if ( m_tail == m_maxsize - 1 ) {
                  m_tail = 0;
            } else
            {
                  m_tail++;
            }
      }
      
      T dequeue ()
      {
            T t = *m_elements[m_head];
            delete m_elements[m_head];
            if ( m_head == m_maxsize - 1 ) {
                  m_head = 0;
            } else
            {
                  m_head++;
            }
            return t;
      }
      
      
      
      
      
      
      friend ostream& operator<< (ostream& os, const Queue& s)
      {
            for(int i = 0; i < s.m_head; ++i)
            os << "NULL ";
            for(int i = s.m_head; i < s.m_tail; ++i)
            os << *s.m_elements[i] << " ";
            
            

            for(int i = s.m_tail + 1; i < s.m_maxsize; ++i)
            os << "NULL ";
            return os;
      }
      
};



}
