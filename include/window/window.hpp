#ifndef _VULKAN_EXPERIMENT_WINDOW_HPP
#define _VULKAN_EXPERIMENT_WINDOW_HPP

#define GFLW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

using string = std::string;

namespace ve {

class VeWindow {
public:
  VeWindow(int w, int h, const string &name);
  ~VeWindow();
  
  bool ShouldClose() { return glfwWindowShouldClose(m_window); }

private:
  /* Private Methods */
  void InitWindow(); 

  /* Private Members */
  const int m_width;
  const int m_height;

  string m_windowName;
  GLFWwindow *m_window;


public:
};

}

#endif // _VULKAN_EXPERIMENT_WINDOW_HPP
