#include <string>
#include <vector>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

namespace gs {
class Instance {
public:
  Instance();
  ~Instance();

 void appendExtension(const std::string &extension);

private: // functions
  uint32_t getExtenctionsPropertiesCount();
  std::vector<VkExtensionProperties> getExtenctionsPropertiesList();

  bool checkExtensionsSupport();

private: // variables
  VkInstance instance;

  std::vector<VkExtensionProperties> extensionsProperties;
  
};
} // namespace gs