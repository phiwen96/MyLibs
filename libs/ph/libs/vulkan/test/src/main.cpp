#include <ph/vulkan/info.hpp>
//#include <ph/vulkan/support.hpp>
using namespace std;
using namespace ph::vulkan;
#include <ph/time/timer/Timer.hpp>






//template <>
//struct Supported<VkPhysicalDevice> : _Supported{
//
//};

//struct Instance {
//      VkInstance const& instance;
//      Instance (VkInstance const& instance) : instance (instance) {
//            
//      }
//      
//      operator std::vector<VkPhysicalDevice> () {
//            uint32_t count = 0;
//            vkEnumeratePhysicalDevices(instance, &count, nullptr);
//            std::vector<VkPhysicalDevice> devices (count);
//            vkEnumeratePhysicalDevices(instance, &count, devices.data());
//            return devices;
//      }
//};


//#include "../src/support.cpp"


int main() {
      
      
      auto vulkanInfo                     = Info<VkInstanceCreateInfo, VkApplicationInfo> {

            VkInstanceCreateInfo
            {
                  .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                  .flags = {},
                  .pApplicationInfo = nullptr,
                  .enabledLayerCount = 0,
                  .ppEnabledLayerNames = nullptr,
                  .enabledExtensionCount = 0,
                  .ppEnabledExtensionNames = nullptr
            },

            VkApplicationInfo
            {
                  .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                  .pNext = nullptr,
                  .pApplicationName = "hej",
                  .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
                  .pEngineName = "No Engine",
                  .engineVersion = VK_MAKE_VERSION(1, 0, 0),
                  .apiVersion = VK_API_VERSION_1_0
            }
      };
      auto setInstanceWindowExtensions    = InfoVisitor<VkInstanceCreateInfo&> {

            [](VkInstanceCreateInfo& createInfo)
            {
                  glfwInit();
                  uint32_t glfwExtensionCount = 0;
                  const char** glfwExtensions;

                  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
                  cout << "glfw " << glfwExtensionCount << endl;
                  createInfo.enabledExtensionCount = glfwExtensionCount;
                  createInfo.ppEnabledExtensionNames = glfwExtensions;
            }
      };
      VkInstance instance = vulkanInfo;
//      auto instance                       = (VkInstance) vulkanInfo (setInstanceWindowExtensions);
//      vector<VkPhysicalDevice> devices =   Support (instance);
//      auto ext = (vector<VkExtensionProperties>) Support();
//      auto devices2 =  (vector<VkPhysicalDevice>) Support ();
//      for(VkPhysicalDevice& i : devices)


     




//#include <ph/vulkan/support.cpp>





//      InfoVisitor<VkInstanceCreateInfo&, VkApplicationInfo&> b ([](VkInstanceCreateInfo&, VkApplicationInfo&){});

      return 0;
}
