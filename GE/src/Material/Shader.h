
#pragma once
#include <string>

#include "Prerequisites.h"

class Shader {
 public:
  unsigned int ID;
  // constructor reads and builds the shader
  Shader(const char* vertexPath, const char* fragmentPath);
  // use/activate the shader
  void use();
  // utility uniform functions
  void setBool(const std::string& name, bool value) const;
  void setInt(const std::string& name, int value) const;
  void setFloat(const std::string& name, float value) const;
  void setMat4(const std::string& name, glm::mat4 value) const;
  void setVec3(const std::string& name, glm::vec3 value) const;
};
