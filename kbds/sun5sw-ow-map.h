/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the default keymap of the Sun type 5 Swedish keyboard
 * as interpreted by OpenWindows 3.0.   By Magnus Hammerin <magnush@isy.liu.se>
 */

static const struct default_keycode_map sun5sw_ow_map [] = {

  /* these have keycodes but no keysyms in the default map */
  {   9, 0,		{ 0 }},	/* Dim, Quiet */
  {  11, 0,		{ 0 }},	/* Bright, Loud */
  {  52, 0,		{ 0 }},	/* DeGauss, SoundOff */
  {  55, 0,		{ 0 }},	/* Power */


  {   8, 0,		{ XK_F11, XK_F11, XK_Cancel }},
  {  10, 0,		{ XK_F12, XK_F12, XK_Redo }},
  {  12, 0,		{ XK_F1 }},
  {  13, 0,		{ XK_F2 }},
  {  14, 0,		{ XK_F10 }},
  {  15, 0,		{ XK_F3 }},
  {  16, 0,		{ SunXK_F36 }},
  {  17, 0,		{ XK_F4 }},
  {  18, 0,		{ SunXK_F37 }},
  {  19, 0,		{ XK_F5 }},
  {  20, Mod2Mask,	{ XK_Mode_switch }},
  {  21, 0,		{ XK_F6 }},
  {  23, 0,		{ XK_F7 }},
  {  24, 0,		{ XK_F8 }},
  {  25, 0,		{ XK_F9 }},
  {  26, Mod4Mask,	{ XK_Alt_L }},
  {  27, 0,		{ XK_Up }},
  {  28, 0,		{ XK_F21,	XK_F21, XK_Pause, XK_Break }},
  {  29, 0,		{ XK_F22, XK_F22, XK_Print, SunXK_Sys_Req }},
  {  30, 0,		{ XK_F23, XK_F23, XK_Scroll_Lock }},
  {  31, 0,		{ XK_Left }},
  {  32, Mod5Mask,	{ XK_F13, XK_F13, SunXK_Props }},
  {  33, 0,		{ XK_F14, XK_F14, XK_Undo }},
  {  34, 0,		{ XK_Down }},
  {  35, 0,		{ XK_Right }},
  {  36, 0,		{ XK_Escape }},
  {  37, 0,		{ XK_1,	XK_exclam }},
  {  38, 0,		{ XK_2,	XK_quotedbl,	XK_at }},
  {  39, 0,		{ XK_3,	XK_numbersign,	XK_sterling }},
  {  40, 0,		{ XK_4,	XK_currency,	XK_dollar }},
  {  41, 0,		{ XK_5,	XK_percent }},
  {  42, 0,		{ XK_6,	XK_ampersand }},
  {  43, 0,		{ XK_7,	XK_slash,	XK_braceleft }},
  {  44, 0,		{ XK_8,	XK_parenleft,	XK_bracketleft }},
  {  45, 0,		{ XK_9,	XK_parenright,	XK_bracketright }},
  {  46, 0,		{ XK_0,	XK_equal,	XK_braceright }},
  {  47, 0,		{ XK_plus,	XK_question, XK_backslash}},
  {  48, 0,		{ SunXK_FA_Acute, SunXK_Dead_Grave }},
  {  49, 0,		{ XK_section,	XK_onehalf }},
  {  50, 0,		{ XK_BackSpace }},
  {  51, 0,		{ XK_Insert }},
  {  53, 0,		{ XK_F25,	XK_F25, XK_KP_Divide }},
  {  54, 0,		{ XK_F26,	XK_F26, XK_KP_Multiply }},
  {  56, 0,		{ XK_F15, XK_F15, SunXK_Front }},
  {  57, 0,		{ XK_Delete,	XK_Delete,	XK_KP_Separator }},
  {  58, 0,		{ XK_F16, XK_F16, SunXK_Copy}},
  {  59, 0,		{ XK_Home }},
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
  {  71, 0,		{ XK_Aring }},
  {  72, 0,		{ SunXK_FA_Diaeresis, XK_asciicircum, XK_asciitilde }},
  {  73, 0,		{ XK_Delete }},
  {  74, 0,		{ XK_Multi_key }},
  {  75, 0,		{ XK_F27, XK_F27,	XK_KP_7, XK_Home }},
  {  76, 0,		{ XK_Up,	XK_F28, XK_KP_8 }},
  {  77, 0,		{ XK_F29,	XK_F29, XK_KP_9, XK_Prior }},
  {  78, 0,		{ XK_F24, XK_F24,	XK_KP_Subtract }},
  {  79, 0,		{ XK_F17, XK_F17, SunXK_Open }},
  {  80, Mod5Mask,	{ XK_F18, XK_F18, SunXK_Paste }},
  {  81, 0,		{ XK_End }},
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
  {  93, 0,		{ XK_Odiaeresis }},
  {  94, 0,		{ XK_Adiaeresis }},
  {  95, 0,		{ XK_apostrophe,	XK_asterisk, XK_grave }},
  {  96, 0,		{ XK_Return }},
  {  97, 0,		{ XK_KP_Enter,	XK_KP_Enter }},
  {  98, 0,		{ XK_Left, XK_F30,	XK_KP_4 }},
  {  99, 0,		{ XK_F31,	XK_F31, XK_KP_5 }},
  { 100, 0,		{ XK_Right, XK_F32,	XK_KP_6 }},
  { 101, 0,		{ XK_Insert,	XK_Insert,	XK_KP_0 }},
  { 102, 0,		{ XK_F19, XK_F19, XK_Find }},
  { 103, 0,		{ XK_Prior }},
  { 104, Mod5Mask,	{ XK_F20, XK_F20, SunXK_Cut }},
  { 105, Mod3Mask,	{ XK_Num_Lock,	XK_Num_Lock }},
  { 106, ShiftMask,	{ XK_Shift_L }},
  { 107, 0,		{ XK_Z }},
  { 108, 0,		{ XK_X }},
  { 109, 0,		{ XK_C }},
  { 110, 0,		{ XK_V }},
  { 111, 0,		{ XK_B }},
  { 112, 0,		{ XK_N }},
  { 113, 0,		{ XK_M }},
  { 114, 0,		{ XK_comma,	XK_semicolon }},
  { 115, 0,		{ XK_period,	XK_colon }},
  { 116, 0,		{ XK_minus,	XK_underscore }},
  { 117, ShiftMask,	{ XK_Shift_R }},
  { 119, 0,		{ XK_F33,	XK_F33, XK_KP_1, XK_End }},
  { 120, 0,		{ XK_Down, XK_F34,	XK_KP_2 }},
  { 121, 0,		{ XK_F35,	XK_F35, XK_KP_3, XK_Next }},
  { 125, 0,		{ XK_Help,	XK_Help }},
  { 126, LockMask,	{ XK_Caps_Lock }},
  { 127, Mod1Mask,	{ XK_Meta_L }},
  { 128, 0,		{ XK_space }},
  { 129, Mod1Mask,	{ XK_Meta_R }},
  { 130, 0,		{ XK_Next }},
  { 131, 0,		{ XK_less, XK_greater, XK_bar }},
  { 132, 0,		{ XK_KP_Add,	XK_KP_Add }}
  };
