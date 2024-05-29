#pragma once

#include "Prerequisites.h"

enum class Camera_Movement {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  ROTATE_LEFT,
  ROTATE_RIGHT,
  ROTATE_UP,
  ROTATE_DOWN
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;
const glm::vec3 WORLD_DEFAULT_UP = glm::vec3(0, 1, 0);

class Camera {
 public:
  // CAMERA ATTRIBUTES

  glm::vec3 Position;
  glm::vec3 Front;
  glm::vec3 Up;
  glm::vec3 Right;
  glm::vec3 WorldUp;

  // euler angles
  float pitch, yaw, roll;  // pitch is around z , yaw is y and roll is z_axis

  float zoom = ZOOM;

  // cam options
  float MovementSpeed, MouseSen, Zoom;

  Camera()
      : Position(glm::vec3(0, 3, 3)), pitch(-45.f), yaw(-90.f), roll(0) {
    UpdateCameraVector();
  }

  glm::mat4 GetViewMatrix();
  void ProcessInput(Camera_Movement command, float deltaTime);
  void UpdateCameraVector();
  void SetZoomRatio(float value) { 
    zoom = value;
  }
 private:
};
