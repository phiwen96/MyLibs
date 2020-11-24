#pragma once

namespace ph::data_structures
{



template <class T>
class Linked_list
{
public:
      struct Node
      {
            T t;
            Node* next;
            Node* previous;
      };
  
      
      
      
      void insert (T const & t)
      {
            Node* node = new Node;
            node-> t = t;
            
            // point new node's next to current head
            node->next = m_head;
            
            // if current head != nullptr, point head's previous to new node
            if ( m_head != nullptr ) {
                  m_head->previous = node;
            }
            
            // point new node's previous to nullptr
            node->previous = nullptr;
            
            // set head to new node
            m_head = node;
      }
      
      void remove (T const& t)
      {
            for (Node* i = m_head; i != nullptr; i = i -> next) {
                  
            }
      }
      
      friend ostream& operator<< (ostream& os, const Linked_list& l)
      {
            if ( l.m_head == nullptr ) {
                  return os;
            }
            auto start = l.m_head;
            auto i = start;
            os << i->t << " ";
            i = i-> next;
            while (i != start && i != nullptr) {
                  os << i->t << " ";
                  i = i-> next;
            }
            return os;
      }
      
private:
      Node* m_head{nullptr};
};





}
