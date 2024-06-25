#pragma once

#include <iostream>
#include <Core/Hash.h>
#include <unordered_map>
#include <GLFW/glfw3.h>
#include <Core/Alias.h>

namespace Geek
{
	// keycode
  enum class KeyCode : u16  {

    //none
    NONE = 0,

    // Alphabets
    KEYCODE_A = 65, KEYCODE_B, KEYCODE_C, KEYCODE_D, KEYCODE_E, KEYCODE_F, KEYCODE_G,
    KEYCODE_H, KEYCODE_I, KEYCODE_J, KEYCODE_K, KEYCODE_L, KEYCODE_M, KEYCODE_N,
    KEYCODE_O, KEYCODE_P, KEYCODE_Q, KEYCODE_R, KEYCODE_S, KEYCODE_T, KEYCODE_U,
    KEYCODE_V, KEYCODE_W, KEYCODE_X, KEYCODE_Y, KEYCODE_Z,

    // Numbers
    NUM_0 = 48, NUM_1, NUM_2, NUM_3, NUM_4,
    NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,

    // Function keys
    KEYCODE_F1 = 290, KEYCODE_F2, KEYCODE_F3, KEYCODE_F4, KEYCODE_F5, KEYCODE_F6,
    KEYCODE_F7, KEYCODE_F8, KEYCODE_F9, KEYCODE_F10, KEYCODE_F11, KEYCODE_F12,

    // Special keys
    ESCAPE = 256, ENTER, TAB, BACKSPACE, INSERT, DELETE,

    // Arrow keys
    ARROW_RIGHT, ARROW_LEFT, ARROW_DOWN, ARROW_UP,

    // Other common keys
    PAGE_UP, PAGE_DOWN, HOME, END,

    // Punctuation keys
    SPACE = 32,
    APOSTROPHE = 39,
    COMMA = 44, MINUS, PERIOD, SLASH, 
    SEMICOLON = 59, 
    EQUAL = 61,
    QUOTE, 
    LEFT_BRACKET = 91,
    BACKSLASH,
    RIGHT_BRACKET
  };

  //for mouse button
  enum class MouseButton
  {
    NONE = 99,
    LMB = 0,
    RMB,
    MIDDLE,
  };

  enum class Modifier : u8
  {
    NONE = 0x0,
    SHIFT = GLFW_MOD_SHIFT,
    CONTROL = GLFW_MOD_CONTROL,
    ALT = GLFW_MOD_ALT,
    SUPER = GLFW_MOD_SUPER,
    CAPSLOCK = GLFW_MOD_CAPS_LOCK,
    NUMLOCK = GLFW_MOD_NUM_LOCK
  };

  enum class KeyState : u8
  {
    RELEASE = 0,
    PRESS,
    REPEAT,
    NONE
  };
  

  static std::unordered_map<std::string, KeyCode, StringHash, StringEqual> KeyCodeHashMap = {
    {"KEYCODE_A", KeyCode::KEYCODE_A},
    {"KEYCODE_B", KeyCode::KEYCODE_B},
    {"KEYCODE_C", KeyCode::KEYCODE_C},
    {"KEYCODE_D", KeyCode::KEYCODE_D},
    {"KEYCODE_E", KeyCode::KEYCODE_E},
    {"KEYCODE_F", KeyCode::KEYCODE_F},
    {"KEYCODE_G", KeyCode::KEYCODE_G},
    {"KEYCODE_H", KeyCode::KEYCODE_H},
    {"KEYCODE_I", KeyCode::KEYCODE_I},
    {"KEYCODE_J", KeyCode::KEYCODE_J},
    {"KEYCODE_K", KeyCode::KEYCODE_K},
    {"KEYCODE_L", KeyCode::KEYCODE_L},
    {"KEYCODE_M", KeyCode::KEYCODE_M},
    {"KEYCODE_N", KeyCode::KEYCODE_N},
    {"KEYCODE_O", KeyCode::KEYCODE_O},
    {"KEYCODE_P", KeyCode::KEYCODE_P},
    {"KEYCODE_Q", KeyCode::KEYCODE_Q},
    {"KEYCODE_R", KeyCode::KEYCODE_R},
    {"KEYCODE_S", KeyCode::KEYCODE_S},
    {"KEYCODE_T", KeyCode::KEYCODE_T},
    {"KEYCODE_U", KeyCode::KEYCODE_U},
    {"KEYCODE_V", KeyCode::KEYCODE_V},
    {"KEYCODE_W", KeyCode::KEYCODE_W},
    {"KEYCODE_X", KeyCode::KEYCODE_X},
    {"KEYCODE_Y", KeyCode::KEYCODE_Y},
    {"KEYCODE_Z", KeyCode::KEYCODE_Z},

    // Numbers
    {"NUM_0", KeyCode::NUM_0},
    {"NUM_1", KeyCode::NUM_1},
    {"NUM_2", KeyCode::NUM_2},
    {"NUM_3", KeyCode::NUM_3},
    {"NUM_4", KeyCode::NUM_4},
    {"NUM_5", KeyCode::NUM_5},
    {"NUM_6", KeyCode::NUM_6},
    {"NUM_7", KeyCode::NUM_7},
    {"NUM_8", KeyCode::NUM_8},
    {"NUM_9", KeyCode::NUM_9},

    // Function keys
    {"KEYCODE_F1", KeyCode::KEYCODE_F1},
    {"KEYCODE_F2", KeyCode::KEYCODE_F2},
    {"KEYCODE_F3", KeyCode::KEYCODE_F3},
    {"KEYCODE_F4", KeyCode::KEYCODE_F4},
    {"KEYCODE_F5", KeyCode::KEYCODE_F5},
    {"KEYCODE_F6", KeyCode::KEYCODE_F6},
    {"KEYCODE_F7", KeyCode::KEYCODE_F7},
    {"KEYCODE_F8", KeyCode::KEYCODE_F8},
    {"KEYCODE_F9", KeyCode::KEYCODE_F9},
    {"KEYCODE_F10", KeyCode::KEYCODE_F10},
    {"KEYCODE_F11", KeyCode::KEYCODE_F11},
    {"KEYCODE_F12", KeyCode::KEYCODE_F12},

    // Special keys
    {"ESCAPE", KeyCode::ESCAPE},
    {"ENTER", KeyCode::ENTER},
    {"SPACE", KeyCode::SPACE},
    {"TAB", KeyCode::TAB},
    {"BACKSPACE", KeyCode::BACKSPACE},

    // Arrow keys
    {"ARROW_UP", KeyCode::ARROW_UP},
    {"ARROW_DOWN", KeyCode::ARROW_DOWN},
    {"ARROW_LEFT", KeyCode::ARROW_LEFT},
    {"ARROW_RIGHT", KeyCode::ARROW_RIGHT},

    // Other common keys
    {"INSERT", KeyCode::INSERT},
    {"DELETE", KeyCode::DELETE},
    {"HOME", KeyCode::HOME},
    {"END", KeyCode::END},
    {"PAGE_UP", KeyCode::PAGE_UP},
    {"PAGE_DOWN", KeyCode::PAGE_DOWN},

    // Punctuation keys
    {"COMMA", KeyCode::COMMA},
    {"PERIOD", KeyCode::PERIOD},
    {"SLASH", KeyCode::SLASH},
    {"SEMICOLON", KeyCode::SEMICOLON},
    {"QUOTE", KeyCode::QUOTE},
    {"LEFT_BRACKET", KeyCode::LEFT_BRACKET},
    {"RIGHT_BRACKET", KeyCode::RIGHT_BRACKET},
    {"BACKSLASH", KeyCode::BACKSLASH},
    {"MINUS", KeyCode::MINUS},
    {"EQUAL", KeyCode::EQUAL},
    {"NONE", KeyCode::NONE}
  };
  static std::unordered_map<std::string, MouseButton, StringHash, StringEqual> MouseButtonHashMap = {
    {"RMB", MouseButton::RMB},
    {"LMB", MouseButton::LMB},
    {"MIDDLE", MouseButton::MIDDLE},
    {"NONE", MouseButton::NONE}
  };
  #define GET_ENUM(enumClassName, enumValueName) enumClassName##HashMap[enumValueName]

  



};