#include "include/app/app.hpp"
#include <cstdlib>
#include <exception>
#include <print>

using std::println;

int main() {
  ve::App app{};

  try {
    app.Run();
  } catch (const std::exception &e) {
    println("Error: {}", e.what());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
