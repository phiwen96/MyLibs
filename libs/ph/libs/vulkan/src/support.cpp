#include "_support.hpp"
namespace ph::vulkan {





_count<>::_count(): m_count (new uint32_t) {
      
}
_count<>::~_count () {
      delete m_count;
}
////////////////////////////////////////////////////

template<class T, class... U>
__data<T, U...>::operator std::vector<T> () {
      return {m_data, move(m_data) + *m_count};
}

template<class T, class... U>
template <class... A>
__data<T, U...>::__data (A const&... a) : count (a...), m_data (new T[*m_count]{}){
      
}

template<class T, class... U>
__data<T, U...>::~__data () {
      delete[] m_data;
}
////////////////////////////////////////////////////












template <>
class _count<VkPhysicalDevice, VkInstance> : public _count<> {
      friend class __data<VkPhysicalDevice, VkInstance>;
      using _count<>::m_count;
protected:
      
      _count (VkInstance const& instance) {
            vkEnumeratePhysicalDevices(instance, m_count, nullptr);
      }
};
////////////////////////////////////////////////////

template <>
class _count<VkExtensionProperties> : public _count<> {
      friend class __data<VkExtensionProperties>;
      using _count<>::m_count;
protected:
      _count () {
            vkEnumerateInstanceExtensionProperties(nullptr, m_count, nullptr);
      }
};
////////////////////////////////////////////////////

template <>
class _data<VkPhysicalDevice, VkInstance> : __data<VkPhysicalDevice, VkInstance> {
protected:
      friend class Support<VkInstance>;
      using data = __data<VkPhysicalDevice, VkInstance>;
      using data::operator vector<VkPhysicalDevice>;
      _data (VkInstance const& instance) : data (instance) {
            vkEnumeratePhysicalDevices(instance, data::m_count, data::m_data);
      }
};

////////////////////////////////////////////////////
template <>
class _data<VkExtensionProperties> : __data<VkExtensionProperties> {
protected:
      friend class Support<VkExtensionProperties>;
      friend class Support<>;
      using data = __data<VkExtensionProperties>;
      using data::operator vector<VkExtensionProperties>;
      _data () {
            vkEnumerateInstanceExtensionProperties(nullptr, data::m_count, data::m_data);
      }
};


template <>
class Support<VkInstance>{
      VkInstance const& m_instance;
      
public:
      Support (VkInstance const& instance) : m_instance (instance) {
            
      }
  
      template <class T>
      operator std::vector<T> () {
            return _data<T, VkInstance> (m_instance);
      }
};



}
