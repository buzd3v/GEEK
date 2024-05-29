#include "Camera.h"

void Camera::UpdateCameraVector() {
  // calculate the new Front vector
  glm::vec3 world_up =
      glm::vec3(glm::sin(glm::radians(roll)), glm::cos(glm::radians(roll)), 0);

  glm::vec3 direction;
  direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  direction.y = sin(glm::radians(pitch));
  direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  Front = glm::normalize(direction);
  Right = glm::normalize(glm::cross(world_up, Front));
  Up = glm::cross(Front, Right);
}

glm::mat4 Camera::GetViewMatrix() {
  return glm::lookAt(Position, Position + Front, Up);
}
