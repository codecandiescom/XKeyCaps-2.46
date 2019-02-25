/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the default keymap of the NeXTstation non-ADB keyboard
 * for the co-Xist 3.0 X server.  By Eric Benson <eb@NeXT.com>.
 *
 * Note: this doesn't pass the "Write Output" test for correctness,
 * as described in defining.txt.  It still needs work.
 */

static const struct default_keycode_map NeXT_map [] = {
  {  11, 0,		{ XK_backslash,		XK_bar }},
  {  12, 0,		{ XK_bracketright,	XK_braceright }},
  {  13, 0,		{ XK_bracketleft,	XK_braceleft }},
  {  14, 0,		{ XK_I }},
  {  15, 0,		{ XK_O }},
  {  16, 0,		{ XK_P }},
  {  17, 0,		{ XK_Left }},
  {  19, 0,		{ XK_KP_0 }},
  {  20, 0,		{ XK_KP_Decimal }},
  {  21, 0,		{ XK_KP_Enter }},
  {  23, 0,		{ XK_Down }},
  {  24, 0,		{ XK_Right }},
  {  25, 0,		{ XK_KP_1 }},
  {  26, 0,		{ XK_KP_4 }},
  {  27, 0,		{ XK_KP_6 }},
  {  28, 0,		{ XK_KP_3 }},
  {  29, 0,		{ XK_KP_Add }},
  {  30, 0,		{ XK_Up }},
  {  31, 0,		{ XK_KP_2 }},
  {  32, 0,		{ XK_KP_5 }},
  {  35, 0,		{ XK_BackSpace }},
  {  36, 0,		{ XK_equal,	XK_plus }},
  {  37, 0,		{ XK_minus,	XK_underscore }},
  {  38, 0,		{ XK_8,	XK_asterisk }},
  {  39, 0,		{ XK_9,	XK_parenleft }},
  {  40, 0,		{ XK_0,	XK_parenright }},
  {  41, 0,		{ XK_KP_7 }},
  {  42, 0,		{ XK_KP_8 }},
  {  43, 0,		{ XK_KP_9 }},
  {  44, 0,		{ XK_KP_Subtract }},
  {  45, 0,		{ XK_KP_Multiply }},
  {  46, 0,		{ XK_grave,	XK_asciitilde }},
  {  47, 0,		{ XK_KP_Equal }},
  {  48, 0,		{ XK_KP_Divide }},
  {  50, 0,		{ XK_Return }},
  {  51, 0,		{ XK_apostrophe,	XK_quotedbl }},
  {  52, 0,		{ XK_semicolon,	XK_colon }},
  {  53, 0,		{ XK_L }},
  {  54, 0,		{ XK_comma,	XK_less }},
  {  55, 0,		{ XK_period,	XK_greater }},
  {  56, 0,		{ XK_slash,	XK_question }},
  {  57, 0,		{ XK_Z }},
  {  58, 0,		{ XK_X }},
  {  59, 0,		{ XK_C }},
  {  60, 0,		{ XK_V }},
  {  61, 0,		{ XK_B }},
  {  62, 0,		{ XK_M }},
  {  63, 0,		{ XK_N }},
  {  64, 0,		{ XK_space }},
  {  65, 0,		{ XK_A }},
  {  66, 0,		{ XK_S }},
  {  67, 0,		{ XK_D }},
  {  68, 0,		{ XK_F }},
  {  69, 0,		{ XK_G }},
  {  70, 0,		{ XK_K }},
  {  71, 0,		{ XK_J }},
  {  72, 0,		{ XK_H }},
  {  73, 0,		{ XK_Tab }},
  {  74, 0,		{ XK_Q }},
  {  75, 0,		{ XK_W }},
  {  76, 0,		{ XK_E }},
  {  77, 0,		{ XK_R }},
  {  78, 0,		{ XK_U }},
  {  79, 0,		{ XK_Y }},
  {  80, 0,		{ XK_T }},
  {  81, 0,		{ XK_Escape }},
  {  82, 0,		{ XK_1,	XK_exclam }},
  {  83, 0,		{ XK_2,	XK_at }},
  {  84, 0,		{ XK_3,	XK_numbersign }},
  {  85, 0,		{ XK_4,	XK_dollar }},
  {  86, 0,		{ XK_7,	XK_ampersand }},
  {  87, 0,		{ XK_6,	XK_asciicircum }},
  {  88, 0,		{ XK_5,	XK_percent }},
  { 126, ControlMask,	{ XK_Control_L }},
  { 127, ShiftMask,	{ XK_Shift_L }},
  { 128, Mod1Mask,	{ XK_Alt_L }},
  { 129, Mod2Mask,	{ XK_Meta_L }},
  { 130, Mod2Mask,	{ XK_Meta_R }},
  { 131, ShiftMask,	{ XK_Shift_R }},
  { 132, Mod1Mask,	{ XK_Alt_R }}
  };
