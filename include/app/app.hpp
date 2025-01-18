#ifndef _VULKAN_EXPERIMENT_APP_HPP
#define _VULKAN_EXPERIMENT_APP_HPP

#include "include/window/window.hpp"
namespace ve {

class App {
public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;
  
  void Run();

private:
  VeWindow m_veWindow{WIDTH, HEIGHT, "Vulkan Experiment"};
};

}

#endif  // _VULKAN_EXPERIMENT_APP_HPP
