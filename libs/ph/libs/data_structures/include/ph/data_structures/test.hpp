#pragma once
#include <ph/testing/testing.hpp>
#include <ph/data_structures/data_structures.hpp>
#include <ph/utility/utility.hpp>
#include <ph/data_structures/stack.hpp>
#include <ph/data_structures/queue.hpp>
#include <ph/data_structures/linked_list.hpp>
using namespace ph::utility;

namespace ph::data_structures
{

struct Testing : ph::testing::Testing
{
private:
      void stack ()
      {
            cout << "stack:" << endl;
            Stack<int, 10> s1;
            cout << "\t" << s1 << endl;
            s1.push(2);
            cout << "\t" << s1 << endl;
            s1.push(3);
            cout << "\t" << s1 << endl;
            s1.pop();
            cout << "\t" <<  s1 << endl << endl;
      }
      
      void queue ()
      {
            Queue<int, 10> q1;
            q1.enqueue(1);
            cout << "\t" << q1 << endl;
            q1.enqueue(2);
            cout << "\t" << q1 << endl;
            q1.dequeue();
            cout << "\t" << q1 << endl << endl;
      }
      
      void linked_list()
      {
            Linked_list<int> l1;
            cout << "\t" << l1 << endl;
            l1.insert(1);
            cout << "\t" << l1 << endl;
            l1.insert(2);
            cout << "\t" << l1 << endl;
            l1.insert(3);
            cout << "\t" << l1 << endl;
      }
      
public:
      virtual void run () override
      {
            stack();
            queue();
            linked_list();
      }
      
      
      
      
      

      
      
};




}
