// #define STB_IMAGE_IMPLEMENTATION
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <stb_image.h>

#include <chrono>
#include <iostream>
#include <vector>

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "glm/glm.hpp"
#include "Material/Camera.h"
#include "Material/Shader.h"
#include "Prerequisites.h"
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_button_callback(GLFWwindow* window, int button, int action,
                           int mods);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
int mouse_button_pressed = 0;
bool firstMouse = true;
float lastX = 400;
float lastY = 300;
float deltaTime = 0;

// lighting
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
std::vector<float> vertices = {

    -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  -1.0f, 0.5f,  -0.5f, -0.5f,
    0.0f,  0.0f,  -1.0f, 0.5f,  0.5f,  -0.5f, 0.0f,  0.0f,  -1.0f,
    0.5f,  0.5f,  -0.5f, 0.0f,  0.0f,  -1.0f, -0.5f, 0.5f,  -0.5f,
    0.0f,  0.0f,  -1.0f, -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  -1.0f,

    -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  1.0f,  0.5f,  -0.5f, 0.5f,
    0.0f,  0.0f,  1.0f,  0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  -0.5f, 0.5f,  0.5f,
    0.0f,  0.0f,  1.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  1.0f,

    -0.5f, 0.5f,  0.5f,  -1.0f, 0.0f,  0.0f,  -0.5f, 0.5f,  -0.5f,
    -1.0f, 0.0f,  0.0f,  -0.5f, -0.5f, -0.5f, -1.0f, 0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f, 0.0f,  0.0f,  -0.5f, -0.5f, 0.5f,
    -1.0f, 0.0f,  0.0f,  -0.5f, 0.5f,  0.5f,  -1.0f, 0.0f,  0.0f,

    0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.5f,  0.5f,  -0.5f,
    1.0f,  0.0f,  0.0f,  0.5f,  -0.5f, -0.5f, 1.0f,  0.0f,  0.0f,
    0.5f,  -0.5f, -0.5f, 1.0f,  0.0f,  0.0f,  0.5f,  -0.5f, 0.5f,
    1.0f,  0.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, -0.5f, 0.0f,  -1.0f, 0.0f,  0.5f,  -0.5f, -0.5f,
    0.0f,  -1.0f, 0.0f,  0.5f,  -0.5f, 0.5f,  0.0f,  -1.0f, 0.0f,
    0.5f,  -0.5f, 0.5f,  0.0f,  -1.0f, 0.0f,  -0.5f, -0.5f, 0.5f,
    0.0f,  -1.0f, 0.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  -1.0f, 0.0f,

    -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  -0.5f,
    0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  -0.5f, 0.5f,  0.5f,
    0.0f,  1.0f,  0.0f,  -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f};

std::vector<float> texCoords = {
    0.0f, 0.0f,  // lower-left corner
    1.0f, 0.0f,  // lower-right corner
    0.5f, 1.0f   // top-center corner
};

std::vector<unsigned int> indices = {0, 1, 3, 1, 2, 3};
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width
  // and height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
}

Camera camera;

void poll_event(GLFWwindow* window, float deltaTime);

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }
  unsigned int lightVAO, cubeVAO, VBO;
  glGenVertexArrays(1, &cubeVAO);
  glGenVertexArrays(1, &lightVAO);

  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
               vertices.data(), GL_STATIC_DRAW);

  glBindVertexArray(cubeVAO);
  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindVertexArray(lightVAO);
  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  Shader cubeShader("./ShaderFile/lightingShader.vert",
                    "./ShaderFile/lightingShader.frag");
  Shader lightCubeShader("./ShaderFile/light_cube.vert",
                         "./ShaderFile/light_cube.frag");

  glfwSetScrollCallback(window, scroll_callback);
  // Set the mouse button callback
  glfwSetMouseButtonCallback(window, mouse_button_callback);

  // Set the cursor position callback
  glfwSetCursorPosCallback(window, cursor_position_callback);
  // creating imgui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init();

  glEnable(GL_DEPTH_TEST);
  while (!glfwWindowShouldClose(window)) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();
    {
      static float f = 0.0f;
      static int counter = 0;

      ImGui::Begin("Camera info");  // Create a window called "Hello, world!"
                                    // and append into it.
      if (ImGui::BeginTable("Cam info", 2)) {
        ImGui::TableSetupColumn("Property");
        ImGui::TableSetupColumn("Value");
        ImGui::TableHeadersRow();

        ImGui::TableNextRow();

        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Position");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%f %f %f", camera.Position.x, camera.Position.y,
                    camera.Position.z);

        ImGui::TableNextRow();

        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Pitch");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%f", camera.pitch);

        ImGui::TableNextRow();

        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Yaw");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%f", camera.yaw);

        ImGui::TableNextRow();

        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Roll");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%f", camera.roll);
      }
      ImGui::EndTable();
      ImGui::End();
    }
    ImGui::Render();
    auto time_now = std::chrono::high_resolution_clock::now();
    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    poll_event(window, deltaTime);

    cubeShader.use();
    cubeShader.setVec3("objectColor", glm::vec3(1.f, .5f, .31f));
    cubeShader.setVec3("lightColor", glm::vec3(1.f, 1.f, 1.f));
    // glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glm::mat4 projection = glm::perspective(glm::radians(camera.zoom),
                                            (float)800 / 600, .1f, 100.f);

    glm::mat4 model = glm::mat4(1.f);
    cubeShader.setMat4("projection", projection);
    cubeShader.setMat4("view", camera.GetViewMatrix());
    cubeShader.setMat4("model", model);
    cubeShader.setVec3("lightPos", lightPos);

    glBindVertexArray(cubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    lightCubeShader.use();
 

    glm::mat4 lightModel = model;
    lightModel = glm::rotate(model, (float)glm::sin(glm::radians(glfwGetTime())),
                glm::vec3(7, 1, 0)); 
    lightModel = glm::translate(lightModel, lightPos);
    lightModel = glm::scale(lightModel, glm::vec3(.2f)); 

    lightCubeShader.setMat4("projection", projection);
    lightCubeShader.setMat4("view", camera.GetViewMatrix());
    lightCubeShader.setMat4("model", lightModel);


    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);

    auto time_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = (time_end - time_now);

    deltaTime = duration.count();
    // while(duration.count() < )
  }
  ImGui_ImplGlfw_Shutdown();
  ImGui_ImplOpenGL3_Shutdown();
  ImGui::DestroyContext();
  glfwTerminate();
  return 0;
}

void poll_event(GLFWwindow* window, float deltaTime) {
  glfwPollEvents();
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
    camera.ProcessInput(Camera_Movement::FORWARD, deltaTime);
  } else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    camera.ProcessInput(Camera_Movement::BACKWARD, deltaTime);
  } else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    camera.ProcessInput(Camera_Movement::LEFT, deltaTime);
  } else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    camera.ProcessInput(Camera_Movement::RIGHT, deltaTime);
  } else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
    camera.ProcessInput(Camera_Movement::ROTATE_CLOCK, deltaTime);
  } else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
    camera.ProcessInput(Camera_Movement::ROTATE_DECLOCK, deltaTime);
  }
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
  camera.zoom += yoffset;
}

void mouse_button_callback(GLFWwindow* window, int button, int action,
                           int mods) {
  if (button == GLFW_MOUSE_BUTTON_LEFT) {
    if (action == GLFW_PRESS)
      mouse_button_pressed = 1;
    else if (action == GLFW_RELEASE) {
      mouse_button_pressed = 0;
      firstMouse = true;
    }
  }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
  if (mouse_button_pressed) {
    xpos = static_cast<float>(xpos);
    ypos = static_cast<float>(ypos);

    if (firstMouse) {
      lastX = xpos;
      lastY = ypos;
      firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset =
        lastY - ypos;  // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    // std::cout << "MouseMove " << xoffset << std::endl;

    camera.ProcessMouseMovement(xoffset, yoffset, deltaTime);
  }
}
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
  float xpos = static_cast<float>(xposIn);
  float ypos = static_cast<float>(yposIn);

  if (firstMouse) {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }

  float xoffset = xpos - lastX;
  float yoffset =
      lastY - ypos;  // reversed since y-coordinates go from bottom tqo top

  lastX = xpos;
  lastY = ypos;

  camera.ProcessMouseMovement(xoffset, yoffset, deltaTime);
}