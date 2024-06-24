#pragma once

#include <iostream>
#include <sid.h>
#include <unordered_map>
#include <functional>

namespace Geek
{
	// keycode
  enum class KeyCode {

    //none
    NONE = 0,

    // Alphabets
    KEYCODE_A, KEYCODE_B, KEYCODE_C, KEYCODE_D, KEYCODE_E, KEYCODE_F, KEYCODE_G,
    KEYCODE_H, KEYCODE_I, KEYCODE_J, KEYCODE_K, KEYCODE_L, KEYCODE_M, KEYCODE_N,
    KEYCODE_O, KEYCODE_P, KEYCODE_Q, KEYCODE_R, KEYCODE_S, KEYCODE_T, KEYCODE_U,
    KEYCODE_V, KEYCODE_W, KEYCODE_X, KEYCODE_Y, KEYCODE_Z,

    // Numbers
    NUM_0, NUM_1, NUM_2, NUM_3, NUM_4,
    NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,

    // Function keys
    KEYCODE_F1, KEYCODE_F2, KEYCODE_F3, KEYCODE_F4, KEYCODE_F5, KEYCODE_F6,
    KEYCODE_F7, KEYCODE_F8, KEYCODE_F9, KEYCODE_F10, KEYCODE_F11, KEYCODE_F12,

    // Special keys
    ESCAPE, ENTER, SPACE, TAB, BACKSPACE, SHIFT, CTRL, ALT, CAPS_LOCK,

    // Arrow keys
    ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT,

    // Other common keys
    INSERT, DELETE, HOME, END, PAGE_UP, PAGE_DOWN,

    // Punctuation keys
    COMMA, PERIOD, SLASH, SEMICOLON, QUOTE, LEFT_BRACKET,
    RIGHT_BRACKET, BACKSLASH, MINUS, EQUAL
  };

  //for mouse button
  enum class MouseButton
  {
    NONE = 0,
    RMB,
    LMB,
    MIDDLE,
  };


  static std::unordered_map<StringId, KeyCode> KeyCodeHashMap = {
    {SID("KEYCODE_A"), KeyCode::KEYCODE_A},
    {SID("KEYCODE_B"), KeyCode::KEYCODE_B},
    {SID("KEYCODE_C"), KeyCode::KEYCODE_C},
    {SID("KEYCODE_D"), KeyCode::KEYCODE_D},
    {SID("KEYCODE_E"), KeyCode::KEYCODE_E},
    {SID("KEYCODE_F"), KeyCode::KEYCODE_F},
    {SID("KEYCODE_G"), KeyCode::KEYCODE_G},
    {SID("KEYCODE_H"), KeyCode::KEYCODE_H},
    {SID("KEYCODE_I"), KeyCode::KEYCODE_I},
    {SID("KEYCODE_J"), KeyCode::KEYCODE_J},
    {SID("KEYCODE_K"), KeyCode::KEYCODE_K},
    {SID("KEYCODE_L"), KeyCode::KEYCODE_L},
    {SID("KEYCODE_M"), KeyCode::KEYCODE_M},
    {SID("KEYCODE_N"), KeyCode::KEYCODE_N},
    {SID("KEYCODE_O"), KeyCode::KEYCODE_O},
    {SID("KEYCODE_P"), KeyCode::KEYCODE_P},
    {SID("KEYCODE_Q"), KeyCode::KEYCODE_Q},
    {SID("KEYCODE_R"), KeyCode::KEYCODE_R},
    {SID("KEYCODE_S"), KeyCode::KEYCODE_S},
    {SID("KEYCODE_T"), KeyCode::KEYCODE_T},
    {SID("KEYCODE_U"), KeyCode::KEYCODE_U},
    {SID("KEYCODE_V"), KeyCode::KEYCODE_V},
    {SID("KEYCODE_W"), KeyCode::KEYCODE_W},
    {SID("KEYCODE_X"), KeyCode::KEYCODE_X},
    {SID("KEYCODE_Y"), KeyCode::KEYCODE_Y},
    {SID("KEYCODE_Z"), KeyCode::KEYCODE_Z},

    // Numbers
    {SID("NUM_0"), KeyCode::NUM_0},
    {SID("NUM_1"), KeyCode::NUM_1},
    {SID("NUM_2"), KeyCode::NUM_2},
    {SID("NUM_3"), KeyCode::NUM_3},
    {SID("NUM_4"), KeyCode::NUM_4},
    {SID("NUM_5"), KeyCode::NUM_5},
    {SID("NUM_6"), KeyCode::NUM_6},
    {SID("NUM_7"), KeyCode::NUM_7},
    {SID("NUM_8"), KeyCode::NUM_8},
    {SID("NUM_9"), KeyCode::NUM_9},

    // Function keys
    {SID("KEYCODE_F1"), KeyCode::KEYCODE_F1},
    {SID("KEYCODE_F2"), KeyCode::KEYCODE_F2},
    {SID("KEYCODE_F3"), KeyCode::KEYCODE_F3},
    {SID("KEYCODE_F4"), KeyCode::KEYCODE_F4},
    {SID("KEYCODE_F5"), KeyCode::KEYCODE_F5},
    {SID("KEYCODE_F6"), KeyCode::KEYCODE_F6},
    {SID("KEYCODE_F7"), KeyCode::KEYCODE_F7},
    {SID("KEYCODE_F8"), KeyCode::KEYCODE_F8},
    {SID("KEYCODE_F9"), KeyCode::KEYCODE_F9},
    {SID("KEYCODE_F10"), KeyCode::KEYCODE_F10},
    {SID("KEYCODE_F11"), KeyCode::KEYCODE_F11},
    {SID("KEYCODE_F12"), KeyCode::KEYCODE_F12},

    // Special keys
    {SID("ESCAPE"), KeyCode::ESCAPE},
    {SID("ENTER"), KeyCode::ENTER},
    {SID("SPACE"), KeyCode::SPACE},
    {SID("TAB"), KeyCode::TAB},
    {SID("BACKSPACE"), KeyCode::BACKSPACE},
    {SID("SHIFT"), KeyCode::SHIFT},
    {SID("CTRL"), KeyCode::CTRL},
    {SID("ALT"), KeyCode::ALT},
    {SID("CAPS_LOCK"), KeyCode::CAPS_LOCK},

    // Arrow keys
    {SID("ARROW_UP"), KeyCode::ARROW_UP},
    {SID("ARROW_DOWN"), KeyCode::ARROW_DOWN},
    {SID("ARROW_LEFT"), KeyCode::ARROW_LEFT},
    {SID("ARROW_RIGHT"), KeyCode::ARROW_RIGHT},

    // Other common keys
    {SID("INSERT"), KeyCode::INSERT},
    {SID("DELETE"), KeyCode::DELETE},
    {SID("HOME"), KeyCode::HOME},
    {SID("END"), KeyCode::END},
    {SID("PAGE_UP"), KeyCode::PAGE_UP},
    {SID("PAGE_DOWN"), KeyCode::PAGE_DOWN},

    // Punctuation keys
    {SID("COMMA"), KeyCode::COMMA},
    {SID("PERIOD"), KeyCode::PERIOD},
    {SID("SLASH"), KeyCode::SLASH},
    {SID("SEMICOLON"), KeyCode::SEMICOLON},
    {SID("QUOTE"), KeyCode::QUOTE},
    {SID("LEFT_BRACKET"), KeyCode::LEFT_BRACKET},
    {SID("RIGHT_BRACKET"), KeyCode::RIGHT_BRACKET},
    {SID("BACKSLASH"), KeyCode::BACKSLASH},
    {SID("MINUS"), KeyCode::MINUS},
    {SID("EQUAL"), KeyCode::EQUAL},
    {SID("NONE"), KeyCode::NONE}
  };

  static std::unordered_map<StringId, MouseButton> MouseButtonHashMap = {
    {SID("RMB"), MouseButton::RMB},
    {SID("LMB"), MouseButton::LMB},
    {SID("MIDDLE"), MouseButton::MIDDLE},
    {SID("NONE"), MouseButton::NONE}
  };


  #define GET_ENUM(enumClassName, enumValueName) enumClassName##HashMap[enumValueName]



};