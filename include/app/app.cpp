#include "app.hpp"
#include "GLFW/glfw3.h"

namespace ve {

void App::Run() {
  while (!m_veWindow.ShouldClose()) {
    glfwPollEvents();
  }
}

}
