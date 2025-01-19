#ifndef _VULKAN_EXPERIMENT_DEVICE_HPP
#define _VULKAN_EXPERIMENT_DEVICE_HPP

#include "../window/window.hpp"
#include <string>
#include <vector>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

template <typename... Args> using vector = std::vector<Args...>;

namespace ve {

struct SwapChainSupportDetails {
  VkSurfaceCapabilitiesKHR capabilities;
  vector<VkSurfaceFormatKHR> formats;
  vector<VkPresentModeKHR> presentModes;
};

struct QueueFamilyIndices {};

class VeDevice {};

} // namespace ve

#endif // _VULKAN_EXPERIMENT_DEVICE_HPP
