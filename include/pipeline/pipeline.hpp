#ifndef _VULKAN_EXPERIMENT_PIPELINE_HPP
#define _VULKAN_EXPERIMENT_PIPELINE_HPP

#include <string>
#include <vector>

using string = std::string;

template <typename... Args> using vector = std::vector<Args...>;

namespace ve {

class VePipeline {
public:
  VePipeline(const string &vertFilePath, const string &fragFilePath);

private:
  static vector<char> ReadFile(const string &filepath);
  void CreateGraphicsPipeline(const string &vertFilePath,
                              const string &fragFilePath);
};

} // namespace ve

#endif // _VULKAN_EXPERIMENT_PIPELINE_HPP
