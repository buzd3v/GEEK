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

void Camera::ProcessInput(Camera_Movement command, float deltaTime) 
{
  auto speed = SPEED * deltaTime;
  auto sen = SENSITIVITY * deltaTime;
  switch (command) {
    case Camera_Movement::FORWARD:
      Position = Position + speed * Front; 
      break;
    case Camera_Movement::BACKWARD:
      Position = Position - speed * Front;
      break;
    case Camera_Movement::LEFT:
      Position = Position - speed * glm::normalize(glm::cross(Up,Front));
      break;
    case Camera_Movement::RIGHT:
      Position = Position + speed * glm::normalize(glm::cross(Up, Front));
      break;
    case Camera_Movement::ROTATE_LEFT:
      yaw += sen;
      break;
    case Camera_Movement::ROTATE_RIGHT:
      yaw -= sen;
      break;
    case Camera_Movement::ROTATE_UP:
      pitch += sen;
      break;
    case Camera_Movement::ROTATE_DOWN:
      pitch -= sen;
      break;
    default:
      break;
  }
}
