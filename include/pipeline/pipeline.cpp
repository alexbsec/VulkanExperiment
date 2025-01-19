#include "pipeline.hpp"
#include <fstream>
#include <print>
#include <stdexcept>

namespace ve {

VePipeline::VePipeline(const string &vertFilePath, const string &fragFilePath) {
  CreateGraphicsPipeline(vertFilePath, fragFilePath);
}

vector<char> VePipeline::ReadFile(const string &filepath) {
  std::ifstream file(filepath, std::ios::ate | std::ios::binary);
  if (!file.is_open()) {
    throw std::runtime_error(
        "VePipeline::Readfile error: failed to open file at " + filepath +
        ". Have the shaders been compiled?");
  }

  size_t fileSize = static_cast<size_t>(file.tellg());
  vector<char> buffer(fileSize);

  file.seekg(0);
  file.read(buffer.data(), fileSize);

  file.close();
  return buffer;
}

void VePipeline::CreateGraphicsPipeline(const string &vertFilePath,
                                        const string &fragFilePath) {
  vector<char> vertCode = ReadFile(vertFilePath);
  vector<char> fragCode = ReadFile(fragFilePath);

  std::println("Vertex Shader Code Size: {}", vertCode.size());
  std::println("Fragment Shader Code Size: {}", fragCode.size());
}

} // namespace ve
