namespace Geek
{
	// keycode
  enum class KeyCode {
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
  enum class MOUSEBUTTON 
  {
    RMB,
    LMB,
    MIDDLE
  };
};