#pragma once

namespace Geek {

class Application
{
public:
  /**
   * \brief Start the game. Should be called in your main.cpp
   */
  static void Start();

  /**
   * \brief Exit the game, can be called anywhere
   */
  static void Exit();
};

} // namespace Geek
