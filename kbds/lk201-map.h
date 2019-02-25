/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the default keymap of the DEC LK201 keyboard.
 * This is very similar to the LK401, and possibly should be shared.
 * Note that under WreckWindows, the right-shift key generates Shift_L.
 */

static const struct default_keycode_map lk201_map [] = {
  {  86, 0,		{ XK_F1 }},
  {  87, 0,		{ XK_F2 }},
  {  88, 0,		{ XK_F3 }},
  {  89, 0,		{ XK_F4 }},
  {  90, 0,		{ XK_F5 }},
  { 100, 0,		{ XK_F6 }},
  { 101, 0,		{ XK_F7 }},
  { 102, 0,		{ XK_F8 }},
  { 103, 0,		{ XK_F9 }},
  { 104, 0,		{ XK_F10 }},
  { 113, 0,		{ XK_Escape,	XK_F11 }},
  { 114, 0,		{ XK_F12 }},
  { 115, 0,		{ XK_F13 }},
  { 116, 0,		{ XK_F14 }},
  { 124, 0,		{ XK_Help }},
  { 125, 0,		{ XK_Menu }},
  { 128, 0,		{ XK_F17 }},
  { 129, 0,		{ XK_F18 }},
  { 130, 0,		{ XK_F19 }},
  { 131, 0,		{ XK_F20 }},
  { 138, 0,		{ XK_Find }},
  { 139, 0,		{ XK_Insert }},
  { 140, 0,		{ DXK_Remove }},
  { 141, 0,		{ XK_Select }},
  { 142, 0,		{ XK_Prior }},
  { 143, 0,		{ XK_Next }},
  { 146, 0,		{ XK_KP_0 }},
  { 148, 0,		{ XK_KP_Decimal }},
  { 149, 0,		{ XK_KP_Enter }},
  { 150, 0,		{ XK_KP_1 }},
  { 151, 0,		{ XK_KP_2 }},
  { 152, 0,		{ XK_KP_3 }},
  { 153, 0,		{ XK_KP_4 }},
  { 154, 0,		{ XK_KP_5 }},
  { 155, 0,		{ XK_KP_6 }},
  { 156, 0,		{ XK_KP_Separator }},
  { 157, 0,		{ XK_KP_7 }},
  { 158, 0,		{ XK_KP_8 }},
  { 159, 0,		{ XK_KP_9 }},
  { 160, 0,		{ XK_KP_Subtract }},
  { 161, 0,		{ XK_KP_F1 }},
  { 162, 0,		{ XK_KP_F2 }},
  { 163, 0,		{ XK_KP_F3 }},
  { 164, 0,		{ XK_KP_F4 }},
  { 167, 0,		{ XK_Left }},
  { 168, 0,		{ XK_Right }},
  { 169, 0,		{ XK_Down }},
  { 170, 0,		{ XK_Up }},
  { 171, ShiftMask,	{ XK_Shift_R }},
  { 174, ShiftMask,	{ XK_Shift_L }},
  { 175, ControlMask,	{ XK_Control_L }},
  { 176, LockMask,	{ XK_Caps_Lock }},
  { 177, Mod1Mask,	{ XK_Multi_key }},
  { 188, 0,		{ XK_Delete }},
  { 189, 0,		{ XK_Return }},
  { 190, 0,		{ XK_Tab }},
  { 191, 0,		{ XK_grave,	XK_asciitilde }},
  { 192, 0,		{ XK_1,	XK_exclam }},
  { 193, 0,		{ XK_Q }},
  { 194, 0,		{ XK_A }},
  { 195, 0,		{ XK_Z }},
  { 197, 0,		{ XK_2,	XK_at }},
  { 198, 0,		{ XK_W }},
  { 199, 0,		{ XK_S }},
  { 200, 0,		{ XK_X }},
  { 201, 0,		{ XK_less,	XK_greater }},
  { 203, 0,		{ XK_3,	XK_numbersign }},
  { 204, 0,		{ XK_E }},
  { 205, 0,		{ XK_D }},
  { 206, 0,		{ XK_C }},
  { 208, 0,		{ XK_4,	XK_dollar }},
  { 209, 0,		{ XK_R }},
  { 210, 0,		{ XK_F }},
  { 211, 0,		{ XK_V }},
  { 212, 0,		{ XK_space }},
  { 214, 0,		{ XK_5,	XK_percent }},
  { 215, 0,		{ XK_T }},
  { 216, 0,		{ XK_G }},
  { 217, 0,		{ XK_B }},
  { 219, 0,		{ XK_6,	XK_asciicircum }},
  { 220, 0,		{ XK_Y }},
  { 221, 0,		{ XK_H }},
  { 222, 0,		{ XK_N }},
  { 224, 0,		{ XK_7,	XK_ampersand }},
  { 225, 0,		{ XK_U }},
  { 226, 0,		{ XK_J }},
  { 227, 0,		{ XK_M }},
  { 229, 0,		{ XK_8,	XK_asterisk }},
  { 230, 0,		{ XK_I }},
  { 231, 0,		{ XK_K }},
  { 232, 0,		{ XK_comma,	XK_comma }},
  { 234, 0,		{ XK_9,	XK_parenleft }},
  { 235, 0,		{ XK_O }},
  { 236, 0,		{ XK_L }},
  { 237, 0,		{ XK_period,	XK_period }},
  { 239, 0,		{ XK_0,	XK_parenright }},
  { 240, 0,		{ XK_P }},
  { 242, 0,		{ XK_semicolon,	XK_colon }},
  { 243, 0,		{ XK_slash,	XK_question }},
  { 245, 0,		{ XK_equal,	XK_plus }},
  { 246, 0,		{ XK_bracketright,	XK_braceright }},
  { 247, 0,		{ XK_backslash,	XK_bar }},
  { 249, 0,		{ XK_minus,	XK_underscore }},
  { 250, 0,		{ XK_bracketleft,	XK_braceleft }},
  { 251, 0,		{ XK_apostrophe,	XK_quotedbl }}
  };
