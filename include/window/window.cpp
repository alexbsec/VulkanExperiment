#include "window.hpp"
#include "GLFW/glfw3.h"

namespace ve {

VeWindow::VeWindow(int w, int h, const string &name)
    : m_width(w), m_height(h), m_windowName(name) {
  InitWindow();
}

VeWindow::~VeWindow() {
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

void VeWindow::InitWindow() {
  glfwInit();

  // We disable the OpenGL api since we are using
  // vulkan
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

  // We also disable the resizing of the window
  // since we are going to handle resizing elsewhere
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  m_window = glfwCreateWindow(m_width, m_height, m_windowName.c_str(), nullptr,
                              nullptr);
}

} // namespace ve
