#pragma once

namespace ph::vulkan {



template <class T>
struct Construct : public T
{
      Construct(){}
      ~Construct(){}
};

template<> Construct<VkApplicationInfo>::Construct() : VkApplicationInfo{
      .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
      .pNext = nullptr,
      .pApplicationName = "appname",
      .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
      .pEngineName = "noname",
      .engineVersion = VK_MAKE_VERSION(1, 0, 0),
      .apiVersion = VK_API_VERSION_1_2
}{
      
}

template<> Construct<VkInstanceCreateInfo>::Construct() : VkInstanceCreateInfo{
      .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
      .pNext = nullptr,
      .flags = 0,
      .pApplicationInfo = nullptr,
      .enabledLayerCount = 0,
      .ppEnabledLayerNames = nullptr,
      .enabledExtensionCount = 0,
      .ppEnabledExtensionNames = nullptr
}{

}



template <class T>
struct Base
{
      
protected:
      Base ()
      {
            throw runtime_error("use constructor Base (T* t)");
      }
      Base (T* t) : base(t)
      {

      }
      template <class A>
      void update ()
      {
            
      }
      
      template <class A>
      void notify ()
      {
            base -> template update<A> ();
      }
//
      T* base;
};







template <class T, class B>
struct Lurad : public T, public virtual B
{
      using B::base;
      
      template <class A>
      void update ()
      {
            
      }
};




template <class...>
struct Element;


template <class...> struct Imp;

template <class T, class U>
struct Element<T, Base<U>> : public virtual Base<U>, public Lurad<T, Base<U>>
{
//      using Base<U>::base;
      
      
     
      
//      operator T ()
//      {
//            return Update<T, U>::template Construct<T>;
//      }
      
      
      
private:
//      Construct<T> t;
};




template <class T, class... U>
struct Imp<T, U...> : public Element<T, Base<Imp<T, U...>>>, public Element<U, Base<Imp<T, U...>>>...
{
      using Self = Imp<T, U...>;
      
      Imp () : Base<Self> (this)
      {

      }
      
      template <class A>
      void update ()
      {
            Element<T, Base<Imp<T, U...>>>::template update<A> ();
            (Element<U, Base<Imp<T, U...>>>::template update<A> (), ...);
      }
      
};

template<class...> struct Tuple;

template<class T, class... U>
struct Tuple<T, U...>
{
      
      template <class A> operator A ()
      {
            imp.template update<A> ();
            return (A) imp;
      }
      
private:
      Imp<T, U...> imp;
};



template<class T>
struct Tuple<T>
{
      
};







































template <class B>
struct Lurad<VkInstanceCreateInfo, B> : public VkInstanceCreateInfo, public virtual B
{
      Lurad() : VkInstanceCreateInfo{
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pNext = nullptr,
            .flags = 0,
            .pApplicationInfo = nullptr,
            .enabledLayerCount = 0,
            .ppEnabledLayerNames = nullptr,
            .enabledExtensionCount = 0,
            .ppEnabledExtensionNames = nullptr
      }
      {
            
      }
      
      operator VkInstance ()
      {
            B::template notify<VkInstanceCreateInfo> ();
            
            VkInstance instance;
            if (vkCreateInstance(this, nullptr, &instance) != VK_SUCCESS)
            {
                  throw runtime_error("failed to create instance!");
            }
            return (VkInstance&&) instance;
      }
      
      
      
      
};



template<class B>
struct Lurad<VkApplicationInfo, B> : public VkApplicationInfo, virtual public B
{
      using B::base;
      
      Lurad(): VkApplicationInfo{
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pNext = nullptr,
            .pApplicationName = "appname",
            .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
            .pEngineName = "noname",
            .engineVersion = VK_MAKE_VERSION(1, 0, 0),
            .apiVersion = VK_API_VERSION_1_2
      }
      {
            
      }
      
      template <class A>
      void update ()
      {
            
      }
      
      //template <class A> operator A();
      //ännu bättre
      //operator vkapplicationinfo ();
      
      template<>
      void update<VkInstanceCreateInfo> ()
      {
            ((VkInstanceCreateInfo*)base)->pApplicationInfo = this;
      }
      
};
















}
