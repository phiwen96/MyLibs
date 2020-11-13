#pragma once
#include <ph/testing/testing.hpp>
#include <ph/aspects/aspects.hpp>
#include <ph/utility/utility.hpp>
using namespace ph::utility;

namespace ph::aspects
{


struct Testing : ph::testing::Testing
{
      virtual void run () override
      {
            
            AW3(Visualizing, Locking, Logging, vector <int> *) X (new vector<int>);
            //...
            X->push_back (10); // Note use of -> operator instead of . operator X->push_back (20);
            
      }
      
      
      
private:
      
};







}
