/* xkeycaps, Copyright (c) 1991-1997 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the default keymap of the Tektronix XP217C keyboard,
 *_TEK_KEYBOARD_TYPE = "ibm101" (101-key North American Keyboard). 
 * Generated by Dan Glastonbury <dglaston@asc.corp.mot.com>
 *
 * Note: _TEK_KEYBOARD_TYPE = "ibm101"is also specified for Tektronix XP20 
 * keyboard. See tek101-map.h
 */

static const struct default_keycode_map tek101_c_map [] = {
  {  15, 0,		{ XK_F1 }},
  {  16, 0,		{ XK_Escape }},
  {  21, 0,		{ XK_Tab }},
  {  22, 0,		{ XK_grave,	XK_asciitilde }},
  {  23, 0,		{ XK_F2 }},
  {  25, ControlMask,	{ XK_Control_L }},
  {  26, ShiftMask,	{ XK_Shift_L }},
  {  27, 0,		{ XK_backslash,	XK_bar }},
  {  28, LockMask,	{ XK_Caps_Lock }},
  {  29, 0,		{ XK_Q }},
  {  30, 0,		{ XK_1,	XK_exclam }},
  {  31, 0,		{ XK_F3 }},
  {  33, Mod1Mask,	{ XK_Alt_L }},
  {  34, 0,		{ XK_Z }},
  {  35, 0,		{ XK_S }},
  {  36, 0,		{ XK_A }},
  {  37, 0,		{ XK_W }},
  {  38, 0,		{ XK_2,	XK_at }},
  {  39, 0,		{ XK_F4 }},
  {  41, 0,		{ XK_C }},
  {  42, 0,		{ XK_X }},
  {  43, 0,		{ XK_D }},
  {  44, 0,		{ XK_E }},
  {  45, 0,		{ XK_4,	XK_dollar }},
  {  46, 0,		{ XK_3,	XK_numbersign }},
  {  47, 0,		{ XK_F5 }},
  {  49, 0,		{ XK_space }},
  {  50, 0,		{ XK_V }},
  {  51, 0,		{ XK_F }},
  {  52, 0,		{ XK_T }},
  {  53, 0,		{ XK_R }},
  {  54, 0,		{ XK_5,	XK_percent }},
  {  55, 0,		{ XK_F6 }},
  {  57, 0,		{ XK_N }},
  {  58, 0,		{ XK_B }},
  {  59, 0,		{ XK_H }},
  {  60, 0,		{ XK_G }},
  {  61, 0,		{ XK_Y }},
  {  62, 0,		{ XK_6,	XK_asciicircum }},
  {  63, 0,		{ XK_F7 }},
  {  65, 0,		{ XK_Alt_R }},
  {  66, 0,		{ XK_M }},
  {  67, 0,		{ XK_J }},
  {  68, 0,		{ XK_U }},
  {  69, 0,		{ XK_7,	XK_ampersand }},
  {  70, 0,		{ XK_8,	XK_asterisk }},
  {  71, 0,		{ XK_F8 }},
  {  73, 0,		{ XK_comma,	XK_less }},
  {  74, 0,		{ XK_K }},
  {  75, 0,		{ XK_I }},
  {  76, 0,		{ XK_O }},
  {  77, 0,		{ XK_0,	XK_parenright }},
  {  78, 0,		{ XK_9,	XK_parenleft }},
  {  79, 0,		{ XK_F9 }},
  {  81, 0,		{ XK_period,	XK_greater }},
  {  82, 0,		{ XK_slash,	XK_question }},
  {  83, 0,		{ XK_L }},
  {  84, 0,		{ XK_semicolon,	XK_colon }},
  {  85, 0,		{ XK_P }},
  {  86, 0,		{ XK_minus,	XK_underscore }},
  {  87, 0,		{ XK_F10 }},
  {  90, 0,		{ XK_apostrophe,	XK_quotedbl }},
  {  91, 0,		{ XK_backslash,	XK_bar }},
  {  92, 0,		{ XK_bracketleft,	XK_braceleft }},
  {  93, 0,		{ XK_equal,	XK_plus }},
  {  94, 0,		{ XK_F11 }},
  {  95, 0,		{ XK_Print,	XK_Linefeed }},
  {  96, ControlMask,	{ XK_Control_R }},
  {  97, ShiftMask,	{ XK_Shift_R }},
  {  98, 0,		{ XK_Return }},
  {  99, 0,		{ XK_bracketright,	XK_braceright }},
  { 100, 0,		{ XK_backslash,	XK_bar }},
  { 101, 0,		{ XK_backslash,	XK_bar }},
  { 102, 0,		{ XK_F12 }},
  { 103, 0,		{ XK_Cancel }},
  { 104, 0,		{ XK_Down }},
  { 105, 0,		{ XK_Left }},
  { 106, 0,		{ TekXK_SetUp, XK_Pause }},
  { 107, 0,		{ XK_Up }},
  { 108, 0,		{ XK_Delete }},
  { 109, 0,		{ XK_End }},
  { 110, 0,		{ XK_BackSpace }},
  { 111, 0,		{ XK_Insert }},
  { 113, 0,		{ XK_KP_1,	XK_End }},
  { 114, 0,		{ XK_Right }},
  { 115, 0,		{ XK_KP_4,	XK_Left }},
  { 116, 0,		{ XK_KP_7,	XK_Home }},
  { 117, 0,		{ XK_Next }},
  { 118, 0,		{ XK_Home }},
  { 119, 0,		{ XK_Prior }},
  { 120, 0,		{ XK_KP_0,	XK_Insert }},
  { 121, 0,		{ XK_KP_Decimal,	XK_Delete }},
  { 122, 0,		{ XK_KP_2,	XK_Down }},
  { 123, 0,		{ XK_KP_5 }},
  { 124, 0,		{ XK_KP_6,	XK_Right }},
  { 125, 0,		{ XK_KP_8,	XK_Up }},
  { 126, 0,		{ XK_Num_Lock }},
  { 127, 0,		{ XK_KP_Divide }},
  { 129, 0,		{ XK_KP_Enter }},
  { 130, 0,		{ XK_KP_3,	XK_Next }},
  { 132, 0,		{ XK_KP_Add }},
  { 133, 0,		{ XK_KP_9,	XK_Prior }},
  { 134, 0,		{ XK_KP_Multiply }},
  { 140, 0,		{ XK_KP_Subtract }},
  { 147, 0,		{ XK_Meta_L }},
  { 148, 0,		{ XK_Meta_R }},
  { 149, 0,		{ XK_Menu }},
  { 247, 0,		{ XK_Break }},
  };
