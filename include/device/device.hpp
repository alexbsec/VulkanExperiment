#ifndef _VULKAN_EXPERIMENT_DEVICE_HPP
#define _VULKAN_EXPERIMENT_DEVICE_HPP

#include "../window/window.hpp"
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

struct QueueFamilyIndices {
  uint32_t graphicsFamily;
  uint32_t presentFamily;
  bool graphicsFamilyHasValue = false;
  bool presentFamilyHasValue = false;
  bool IsComplete() { return graphicsFamilyHasValue && presentFamilyHasValue; }
};

class VeDevice {
public:
// Validation layer for debugging
#ifdef NDEBUG
  const bool enableValidationLayer = false;
#else
  const bool enableValidationLayer = true;
#endif

  VeDevice(VeWindow &window);
  ~VeDevice();

  // Not copyable or movable
  VeDevice(const VeDevice &) = delete;
  void operator=(const VeDevice &) = delete;
  VeDevice(VeDevice &&) = delete;
  VeDevice &operator=(VeDevice &&) = delete;

  VkCommandPool GetCommandPool() { return m_commandPool; }
  VkDevice GetDevice() { return m_device; }
  VkQueue GraphicsQueue() { return m_graphicsQueue; }
  VkQueue PresentQueue() { return m_presentQueue; }

  SwapChainSupportDetails GetSwapChainSupport() {
    return QuerySwapChainSupport(m_physicalDevice);
  }
  uint32_t FindMemoryType(uint32_t typeFilter,
                          VkMemoryPropertyFlags properties);
  QueueFamilyIndices FindPhysicalQueueFamilies() {
    return FindQueueFamilies(m_physicalDevice);
  }
  VkFormat FindSupportedFamilies(const vector<VkFormat> &canditates,
                                 VkImageTiling tiling,
                                 VkFormatFeatureFlags features);

  // Buffer helper functions
  void CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage,
                    VkMemoryPropertyFlags properties, VkBuffer &buffer,
                    VkDeviceMemory &bufferMemory);
  VkCommandBuffer BeginSingleTimeCommands();
  void EndSingleTimeCommands(VkCommandBuffer commandBuffer);
  void CopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
  void CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width,
                         uint32_t height, uint32_t layerCount);

  void CreateImageWithInfo(const VkImageCreateInfo &imageInfo,
                           VkMemoryPropertyFlags properties, VkImage &image,
                           VkDeviceMemory &imageMemory);

  VkPhysicalDeviceProperties properties;

private:
  void CreateInstance();
  void SetupDebugMessenger();
  void CreateSurface();
  void PickPhysicalDevice();
  void CreateLogicalDevice();
  void CreateCommandPool();

  // Helper functions
  bool IsDeviceSuitable(VkPhysicalDevice device);
  vector<const char *> GetRequiredExtensions();
  bool CheckValidationLayerSupport();
  QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
  void PopulateDebugMessengerCreateInfo(
      VkDebugUtilsMessengerCreateInfoEXT &createInfo);
  void HasGLFWRequiredInstanceExtensions();
  bool CheckDeviceExtensionsSupport(VkPhysicalDevice device);
  SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);

  // Private variables
  VkInstance m_instance;
  VkDebugUtilsMessengerEXT m_debugMessenger;
  VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
  VeWindow &window;
  VkCommandPool m_commandPool;

  VkDevice m_device;
  VkSurfaceKHR m_surface;
  VkQueue m_graphicsQueue;
  VkQueue m_presentQueue;

  const vector<const char *> m_validationLayers = {
      "VK_LAYER_KHRONOS_validation"};
  const vector<const char *> m_deviceExtensions = {
      VK_KHR_SWAPCHAIN_EXTENSION_NAME};
};

} // namespace ve

#endif // _VULKAN_EXPERIMENT_DEVICE_HPP
