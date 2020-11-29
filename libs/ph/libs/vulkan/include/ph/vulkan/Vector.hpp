#pragma once

#include <iostream>
#include <type_traits>
#include <vulkan_core.hpp>
namespace ph::vulkan{

using namespace std;



struct QueueFamilyIndex
{
      uint32_t index;
      bool graphics;
      bool compute;
      friend ostream& operator<< (ostream& os, const QueueFamilyIndex& index){
            os << "index: " << index.index << ", graphics: " << index.graphics << ", compute: " << index.compute;
            return os;
      }
};



template <class Element, class Number = uint32_t>
class Vector
{
      using Self = Vector<Element, Number>;
      // typedef uint32_t Number;
      
      /////////////////////////
      /// DATA
      ////////////////////////
      Element* elements;
      Number count;
      using Base = Self;
      
      
public:
      
      
      template <class T>
      Vector (const T&)
      {
            throw runtime_error("No constructor defined for this type");
      }
      
      Vector (Self&& other) : Vector ()
      {
            swap (*this, other);
      }
      
      Vector (const Self& other) : elements (new Element[other.count]), count(other.count)
      {
            elements += count - 1;
            for(Element* currOther = other.elements + count - 1; currOther >= other.elements; --currOther)
            {
                  *elements = *currOther;
                  elements--;
            }
      }
      
      Vector (Number& size) : elements (new Element [size]), count (size)
      {
      }
      Vector () :
      elements (nullptr),
      count (0)
      {
      }
      virtual ~Vector ()
      {
            // delete [] elements;
      }
      Self& operator= (Self other)
      {
            swap (*this, other);
            return *this;
      }
      
      
      friend void swap (Self& first, Self& second)
      {
            using std::swap;
            swap (first.elements, second.elements);
            swap (first.count, second.count);
      }
      
      
      operator Element* ()
      {
            return elements;
      }
      
      operator Number& ()
      {
            return count;
      }
      
      operator Number* ()
      {
            return &count;
      }
      
      
      template <class A>
      operator Vector<A> ()
      {
            throw runtime_error("Convert not defined for Vector<A>!");
      }
      
      // template <class A, class B>
      // operator Vector<Vector<A, B>, B> ()
      // {
      // throw runtime_error("Convert not defined for Vector<A, B>!");
      // }
      
      // template <class A>
      // operator A ()
      // {
      // throw runtime_error("Convert not defined for A!");
      // }
      
      
      
      void resize (int size) {
            delete [] elements;
            elements = new Element [size];
            count = size;
      }
      void resize () {
            
            delete [] elements;
            elements = new Element [count];
      }
      Element& operator[](int i)
      {
            return elements[i];
      }
      Element* data ()
      {
            return elements;
      }
      Number& size ()
      {
            return count;
      }
      friend ostream& operator<< (ostream& os, const Self& self)
      {
            if ( self.count == 0 )
            {
                  os << "{}";
                  return os;
            }
            os << "{ ";
            for (Element* element = self.elements; element < self.elements + self.count; ++element)
            {
                  // os << "\t";
                  os << "{";
                  self.out (os, *element);
                  os << "}";
                  if ( element + 1 < self.elements + self.count)
                  {
                        os << ", ";
                  }
            }
            os << " }";
            return os;
      }
      void foreach (function<void(Element&)> f)
      {
            for (Element* i = elements; i < elements + count; ++i)
            {
                  f (*elements);
            }
      }
      Vector& operator* (function<void(Element&, int i)> f)
      {
            for(Element* curr = elements; curr < elements + count; ++curr)
            {
                  f (*curr, curr - elements);
            }
            return *this;
      }
      Vector& operator* (function<void(Element&)> f)
      {
            for(Element* curr = elements; curr < elements + count; ++curr)
            {
                  f (*curr);
            }
            return *this;
      }
      Vector& operator* (function<void(Vector&)> f)
      {
            for(int i = count; i >= 0; i--)
            {
                  f (*this);
            }
            return *this;
      }
      Vector& operator* (function<void(void)> f)
      {
            for(int i = count; i >= 0; i--)
            {
                  f ();
            }
            return *this;
      }
      Vector& operator+=(Element&& newElement)
      {
            this->operator++();
            elements [count-1] = (Element&&) newElement;
            return *this;
      }
      Vector& operator-=(const Element& deleteElement)
      {
            Element* dstBegin = new Element [count];
            Element* dstEnd = dstBegin + count - 1;
            Element* dltBegin = dstBegin;
            for (Element* curr = elements + count - 1; curr >= elements; --curr)
            {
                  if ( *curr == deleteElement ) {
                        dltBegin++;
                  } else {
                        *dstEnd = (Element&&) *curr;
                        dstEnd--;
                  }
            }
            delete [] elements;
            if ( dltBegin > dstBegin ) {
                  elements = new Element [count - (dltBegin - dstBegin)];
                  elements += count - 1 - (dltBegin - dstBegin);
                  
                  for (dstEnd = dstBegin + count - 1; dstEnd >= dltBegin; --dstEnd)
                  {
                        *elements = (Element&&) *dstEnd;
                        elements--;
                  }
                  elements++;
                  delete [] dstBegin;
                  count -= dltBegin - dstBegin;
            } else
            {
                  elements = dstBegin;
            }
            
            return *this;
      }
      // template <Numeric T>
      // bool operator< (const T& t)
      // {
      // return count < t;
      // }
      
//      template <class T> requires is_arithmetic<T>::value
//      bool operator > (const T& t)
//      {
//            return count > t;
//      }
//
//      template <class T> requires is_arithmetic<T>::value
//      bool operator < (const T& t)
//      {
//            return count < t;
//      }
      
protected:
      Vector& operator++()
      {
            Element* newElements = new Element [count + 1];
            for (int i = 0; i < count; ++i)
            {
                  newElements[i] = (Element&&) elements[i];
            }
            delete [] elements;
            elements = newElements;
            count++;
            return *this;
      }
      
      template<class T>
      void out (ostream& os, const T& element) const
      {
            os << element;
      }
      
      template<>
      void out <QueueFamilyIndex> (ostream& os, const QueueFamilyIndex& index) const{
            os << index;
      }
      
      
};



template <>
template <> Vector<VkPhysicalDevice>::Vector(const VkInstance& instance) : Vector ()
{
      vkEnumeratePhysicalDevices(instance, &count, nullptr);
      if ( count > 0 )
      {
            resize();
            vkEnumeratePhysicalDevices(instance, &count, elements);
      }
}

template <>
template <> Vector<VkQueueFamilyProperties>::Vector(const VkPhysicalDevice& physicalDevice) : Vector ()
{
      
      vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, nullptr);
      if ( count > 0 ) {
            resize();
            vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, elements);
      }
}







// DeviceVector::operator QueueVectors ()

template <>
template <>
void Vector<VkQueueFamilyProperties>::out (ostream& os, const VkQueueFamilyProperties& q) const
{
      os << "VkQueueFamilyProperties{ queueCount: " << q.queueCount << " }";
}


template <>
template <> Vector<VkPhysicalDevice>::operator Vector<Vector<VkQueueFamilyProperties>> ()
{
      using DeviceVector = Vector<VkPhysicalDevice>;
      using QueueVector = Vector<VkQueueFamilyProperties>;
      using QueueVectors = Vector<QueueVector>;
      QueueVectors queueVectors (count);
      
      queueVectors * [&physicalDevices = *this](QueueVector& queueVector, int i)
      {
            vkGetPhysicalDeviceQueueFamilyProperties(physicalDevices[i], queueVector, nullptr);
            if ( queueVector > 0 ) {
                  queueVector.resize();
                  vkGetPhysicalDeviceQueueFamilyProperties(physicalDevices[i], queueVector, queueVector);
            }
      };
      
      return queueVectors;
      
}

template <>
template <> Vector<VkPhysicalDevice>::operator Vector<VkPhysicalDeviceProperties> ()
{
      Vector<VkPhysicalDeviceProperties> deviceProperties (count);
      
      deviceProperties * [&physicalDevices = *this](VkPhysicalDeviceProperties& deviceProperties, int i)
      {
            vkGetPhysicalDeviceProperties (physicalDevices[i], &deviceProperties);
      };
      
      return deviceProperties;
}



// template <class... T>
// Vector(T&&... t) -> Vector<std::common_type_t<T...>, sizeof...(T)>;




}
