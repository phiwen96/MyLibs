#include <ph/vulkan/info.hpp>
#include <iostream>

void ph::vulkan::Example::run() {
    Info<VkInstanceCreateInfo, VkApplicationInfo> t1
            {
                    {
                            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                            .flags = {},
                            .pApplicationInfo = nullptr,
                            .enabledLayerCount = 0,
                            .ppEnabledLayerNames = nullptr,
                            .enabledExtensionCount = 0,
                            .ppEnabledExtensionNames = nullptr
                    },
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
    VkInstance i = t1;
}
