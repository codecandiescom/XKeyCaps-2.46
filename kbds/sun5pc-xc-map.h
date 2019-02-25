/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994 
 *  by Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the default keymap of the Sun type 5 PC-style keyboard
 * as interpreted by X Consortium R4 and R5 servers.
 * By Carl Witty <cwitty@ai.mit.edu> and Sylvain Meunier <meunier@inf.enst.fr>.
 */

static const struct default_keycode_map sun5pc_xc_map [] = {

  /* these have keycodes but no keysyms in the default map */
  {   9, 0,		{ 0 }},	/* Dim, Quiet */
  {  11, 0,		{ 0 }},	/* Bright, Loud */
  {  20, 0,		{ 0 }},	/* Alt Graph, to right of Compose */
  {  27, 0,		{ 0 }},	/* UpArrow */
  {  31, 0,		{ 0 }},	/* LeftArrow */
  {  34, 0,		{ 0 }},	/* DownArrow */
  {  35, 0,		{ 0 }},	/* DownArrow */
  {  51, 0,		{ 0 }},	/* Insert */
  {  55, 0,		{ 0 }},	/* Power */
  {  59, 0,		{ 0 }},	/* Home */
  {  81, 0,		{ 0 }},	/* End */
  { 103, 0,		{ 0 }},	/* Page Up */
  { 130, 0,		{ 0 }},	/* Page Down */


  {   8, 0,		{ XK_F11 }},
  {  10, 0,		{ XK_F12 }},
  {  12, 0,		{ XK_F1 }},
  {  13, 0,		{ XK_F2 }},
  {  14, 0,		{ XK_F10 }},
  {  15, 0,		{ XK_F3 }},
  {  16, 0,		{ XK_F11 }},
  {  17, 0,		{ XK_F4 }},
  {  18, 0,		{ XK_F12 }},
  {  19, 0,		{ XK_F5 }},
  {  21, 0,		{ XK_F6 }},
  {  23, 0,		{ XK_F7 }},
  {  24, 0,		{ XK_F8 }},
  {  25, 0,		{ XK_F9 }},
  {  26, 0,		{ XK_Alt_L }},
  {  28, 0,		{ XK_F21,	XK_Pause }},
  {  29, 0,		{ XK_F22 }},
  {  30, 0,		{ XK_F23 }},
  {  32, Mod3Mask,	{ XK_F13 }},
  {  33, 0,		{ XK_F14 }},
  {  36, 0,		{ XK_Escape }},
  {  37, 0,		{ XK_1,	XK_exclam }},
  {  38, 0,		{ XK_2,	XK_at }},
  {  39, 0,		{ XK_3,	XK_numbersign }},
  {  40, 0,		{ XK_4,	XK_dollar }},
  {  41, 0,		{ XK_5,	XK_percent }},
  {  42, 0,		{ XK_6,	XK_asciicircum }},
  {  43, 0,		{ XK_7,	XK_ampersand }},
  {  44, 0,		{ XK_8,	XK_asterisk }},
  {  45, 0,		{ XK_9,	XK_parenleft }},
  {  46, 0,		{ XK_0,	XK_parenright }},
  {  47, 0,		{ XK_minus,	XK_underscore }},
  {  48, 0,		{ XK_equal,	XK_plus }},
  {  49, 0,		{ XK_grave,	XK_asciitilde }},
  {  50, 0,		{ XK_BackSpace }},
  {  52, 0,		{ XK_F24,	XK_KP_Equal }},
  {  53, 0,		{ XK_F25,	XK_KP_Divide }},
  {  54, 0,		{ XK_F26,	XK_KP_Multiply }},
  {  56, 0,		{ XK_F15 }},
  {  57, 0,		{ XK_Delete,	XK_KP_Decimal }},
  {  58, 0,		{ XK_F16 }},
  {  60, 0,		{ XK_Tab }},
  {  61, 0,		{ XK_Q }},
  {  62, 0,		{ XK_W }},
  {  63, 0,		{ XK_E }},
  {  64, 0,		{ XK_R }},
  {  65, 0,		{ XK_T }},
  {  66, 0,		{ XK_Y }},
  {  67, 0,		{ XK_U }},
  {  68, 0,		{ XK_I }},
  {  69, 0,		{ XK_O }},
  {  70, 0,		{ XK_P }},
  {  71, 0,		{ XK_bracketleft,	XK_braceleft }},
  {  72, 0,		{ XK_bracketright,	XK_braceright }},
  {  73, 0,		{ XK_Delete }},
  {  74, 0,		{ XK_Multi_key }},
  {  75, 0,		{ XK_F27,	XK_KP_7 }},
  {  76, 0,		{ XK_Up,	XK_KP_8 }},
  {  77, 0,		{ XK_F29,	XK_KP_9 }},
  {  78, 0,		{ XK_KP_Subtract,	XK_KP_Subtract }},
  {  79, 0,		{ XK_F17 }},
  {  80, Mod3Mask,	{ XK_F18 }},
  {  83, ControlMask,	{ XK_Control_L }},
  {  84, 0,		{ XK_A }},
  {  85, 0,		{ XK_S }},
  {  86, 0,		{ XK_D }},
  {  87, 0,		{ XK_F }},
  {  88, 0,		{ XK_G }},
  {  89, 0,		{ XK_H }},
  {  90, 0,		{ XK_J }},
  {  91, 0,		{ XK_K }},
  {  92, 0,		{ XK_L }},
  {  93, 0,		{ XK_semicolon,	XK_colon }},
  {  94, 0,		{ XK_apostrophe,	XK_quotedbl }},
  {  95, 0,		{ XK_backslash,	XK_bar }},
  {  96, 0,		{ XK_Return }},
  {  97, 0,		{ XK_KP_Enter,	XK_KP_Enter }},
  {  98, 0,		{ XK_Left,	XK_KP_4 }},
  {  99, 0,		{ XK_F31,	XK_KP_5 }},
  { 100, 0,		{ XK_Right,	XK_KP_6 }},
  { 101, 0,		{ XK_Insert,	XK_KP_0 }},
  { 102, 0,		{ XK_F19 }},
  { 104, Mod3Mask,	{ XK_F20 }},
  { 105, Mod2Mask,	{ XK_Num_Lock,	XK_Num_Lock }},
  { 106, ShiftMask,	{ XK_Shift_L }},
  { 107, 0,		{ XK_Z }},
  { 108, 0,		{ XK_X }},
  { 109, 0,		{ XK_C }},
  { 110, 0,		{ XK_V }},
  { 111, 0,		{ XK_B }},
  { 112, 0,		{ XK_N }},
  { 113, 0,		{ XK_M }},
  { 114, 0,		{ XK_comma,	XK_less }},
  { 115, 0,		{ XK_period,	XK_greater }},
  { 116, 0,		{ XK_slash,	XK_question }},
  { 117, ShiftMask,	{ XK_Shift_R }},
  { 118, 0,		{ XK_Linefeed }},
  { 119, 0,		{ XK_F33,	XK_KP_1 }},
  { 120, 0,		{ XK_Down,	XK_KP_2 }},
  { 121, 0,		{ XK_F35,	XK_KP_3 }},
  { 125, 0,		{ XK_Help,	XK_Help }},
  { 126, LockMask,	{ XK_Caps_Lock }},
  { 127, Mod1Mask,	{ XK_Meta_L }},
  { 128, 0,		{ XK_space }},
  { 129, Mod1Mask,	{ XK_Meta_R }},
  { 132, 0,		{ XK_KP_Add,	XK_KP_Add }}
  };
