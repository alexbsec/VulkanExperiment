#ifndef _VULKAN_EXPERIMENT_APP_HPP
#define _VULKAN_EXPERIMENT_APP_HPP

#include "include/pipeline/pipeline.hpp"
#include "include/window/window.hpp"
namespace ve {

class App {
public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  void Run();

private:
  VeWindow m_veWindow{WIDTH, HEIGHT, "Vulkan Experiment"};
  VePipeline m_vePipeline{"shaders/simple_shader.vert.spv",
                          "shaders/simple_shader.frag.spv"};
};

} // namespace ve

#endif // _VULKAN_EXPERIMENT_APP_HPP
