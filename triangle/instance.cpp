#include "instance.h"

#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <vector>

const std::vector<const char *> activatedInstanceExtensionsNames = {
    VK_EXT_DEBUG_UTILS_EXTENSION_NAME};

namespace gs {
Instance::Instance() {
  uint32_t instanceExtensionsPropertiesCount = 0;

  if (vkEnumerateInstanceExtensionProperties(
          nullptr, &instanceExtensionsPropertiesCount, nullptr) != VK_SUCCESS)
    throw std::runtime_error(
        "failed to get instance extensions properties count");

  std::vector<VkExtensionProperties> instanceExtensionsProperties(
      instanceExtensionsPropertiesCount);

  if (vkEnumerateInstanceExtensionProperties(
          nullptr, &instanceExtensionsPropertiesCount,
          instanceExtensionsProperties.data()) != VK_SUCCESS)
    throw std::runtime_error("failed to get instance extensions properties");

  uint32_t validatedInstanceExtensionsCount = 0;
  for (auto &instanceExtensionProperties : instanceExtensionsProperties)
    for (auto &activatedInstanceExtensionName :
         activatedInstanceExtensionsNames)
      if (strcmp(instanceExtensionProperties.extensionName,
                 activatedInstanceExtensionName) == 0)
        validatedInstanceExtensionsCount++;

  if (validatedInstanceExtensionsCount !=
      activatedInstanceExtensionsNames.size())
    throw std::runtime_error("not all Vulkan enabled instance extensions supported!");


}

Instance::~Instance() {}

Instance::


} // namespace gs