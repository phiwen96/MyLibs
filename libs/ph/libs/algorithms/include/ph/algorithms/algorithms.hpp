#pragma once
#include <ph/data_structures/data_structures.hpp>
namespace ph::algorithms
{



////////////////////////////////////////////////////////////////
/// @brief
///
/// @example { 5 2 4 6 1 3 } = { 1 2 3 4 5 6 }
///
///  The algorithm sorts the input numbers in place: it
///  rearranges the numbers within the array A, with at most a
///  constant number of them stored outside the array at any
///  time. The input array A contains the sorted output
///  sequence when the INSERTION-SORT procedure is finished.
////////////////////////////////////////////////////////////////

template <class CompFunc, template <class...> class List, class E, class... Elements>
void insertion_sort (List<E, Elements...>& A, CompFunc compFunc )
{
      for (int j = 1; j < A.size (); ++j)
      {
            auto key = A [j];
            auto i = j - 1;
            
            // while (i >= 0 && A [i] > key)
            while (i >= 0 && compFunc (A [i], key))
            {
                  A [i + 1] = A [i];
                  --i;
            }
            
            A [i + 1] = key;
      }
}


template <template <class...> class List, class... Elements, class CompFunc>
void selection_sort (List<Elements...>& A, CompFunc compFunc)
{
      for (int j = 0; j < A.size() - 1; ++j)
      {
            auto key = A [j];
            
            for (int i = j + 1; i < A.size(); ++i)
            {
                  if ( auto candidate = A [i]; compFunc (candidate, key) ) {
                        A [i] = key;
                        key = candidate;
                  }
            }
            A [j] = key;
      }
}




















































































}
