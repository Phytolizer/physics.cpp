#pragma once

#include <glm/glm.hpp>
#include <string_view>

struct Shader
{
  private:
    int m_shaderProgramId;
    std::string m_vertexSource;
    std::string m_fragmentSource;
    std::string m_filePath;

  public:
    explicit Shader(std::string_view filePath);

    void compile();
    void use();
    void detach();

    void uploadMat4(std::string_view uniformName, glm::mat4 matrix);
};
