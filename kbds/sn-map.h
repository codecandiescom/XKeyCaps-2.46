/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keymap of a generic 102 key PC keyboard
 * from Siemens/Nixdorf.  By Edwin Klement <edwin.klement@dresdner-bank.com>
 */

#ifndef XK_Sys_Req
# define XK_Sys_Req		0xFF15
#endif

static const struct default_keycode_map sn_map [] = {

  /* Row 0 */
  {   8, 0,		{ XK_Escape }},
  {  68, 0,		{ XK_F1 }},
  {  69, 0,		{ XK_F2 }},
  {  70, 0,		{ XK_F3 }},
  {  71, 0,		{ XK_F4 }},
  {  72, 0,		{ XK_F5 }},
  {  73, 0,		{ XK_F6 }},
  {  74, 0,		{ XK_F7 }},
  {  75, 0,		{ XK_F8 }},
  {  76, 0,		{ XK_F9 }},
  {  77, 0,		{ XK_F10 }},
  {  78, 0,		{ XK_F11 }},
  {  79, 0,		{ XK_F12 }},
  /* What is Druck / S-Abf ? */ {  120, 0,	{ XK_Print, XK_Sys_Req }},
  {  90, 0,		{ XK_Scroll_Lock }},
  {  91, 0,		{ XK_Pause }},

  /* Row 2 */
  {  127, 0,		{ XK_asciicircum }},
  {  10, 0,		{ XK_1,	XK_exclam }},
  {  11, 0,		{ XK_2,	XK_quotedbl, XK_twosuperior }},
  {  12, 0,		{ XK_3,	XK_section, XK_threesuperior }},
  {  13, 0,		{ XK_4,	XK_dollar }},
  {  14, 0,		{ XK_5,	XK_percent }},
  {  15, 0,		{ XK_6,	XK_ampersand }},
  {  16, 0,		{ XK_7,	XK_slash, XK_braceleft }},
  {  17, 0,		{ XK_8,	XK_parenleft, XK_bracketleft }},
  {  18, 0,		{ XK_9,	XK_parenright, XK_bracketright }},
  {  19, 0,		{ XK_0,	XK_equal, XK_braceright }},
  {  20, 0,		{ XK_ssharp, XK_question, XK_backslash }},
  { 125, 0,		{ XK_acute, XK_eacute }},
  {  22, 0,		{ XK_BackSpace }},
  {  80, 0,		{ XK_Insert }},
  {  81, 0,		{ XK_Home }},
  {  82, 0,		{ XK_Prior }},
  {  92, 0,		{ XK_Num_Lock }},
  {  93, 0,		{ XK_KP_Divide }},
  {  94, 0,		{ XK_KP_Multiply }},
  {  95, 0,		{ XK_KP_Subtract }},

  /* Row 3 */
  {  23, 0,		{ XK_Tab }},
  {  24, 0,		{ XK_q, XK_Q, XK_at }},
  {  25, 0,		{ XK_W }},
  {  26, 0,		{ XK_E }},
  {  27, 0,		{ XK_R }},
  {  28, 0,		{ XK_T }},
  {  29, 0,		{ XK_Z }},
  {  30, 0,		{ XK_U }},
  {  31, 0,		{ XK_I }},
  {  32, 0,		{ XK_O }},
  {  33, 0,		{ XK_P }},
  {  34, 0,		{ XK_Udiaeresis }},
  {  35, 0,		{ XK_plus, XK_asterisk, XK_asciitilde }},
  {  49, 0,		{ XK_Return }},
  {  83, 0,		{ XK_Delete }},
  {  84, 0,		{ XK_End }},
  {  85, 0,		{ XK_Next }},
  {  96, 0,		{ XK_Home, XK_KP_7, XK_KP_7, XK_Home }},
  {  97, 0,		{ XK_Up, XK_KP_8, XK_KP_8, XK_KP_8, XK_Up }},
  {  98, 0,		{ XK_Prior, XK_KP_9, XK_KP_9, XK_Prior }},
  {  107, 0,		{ XK_KP_Add }},

  /* Row 4 */
  {  36, LockMask,	{ XK_Caps_Lock }},
  {  37, 0,		{ XK_A }},
  {  38, 0,		{ XK_S }},
  {  39, 0,		{ XK_D }},
  {  40, 0,		{ XK_F }},
  {  41, 0,		{ XK_G }},
  {  42, 0,		{ XK_H }},
  {  43, 0,		{ XK_J }},
  {  44, 0,		{ XK_K }},
  {  45, 0,		{ XK_L }},
  {  46, 0,		{ XK_Odiaeresis }},
  {  47, 0,		{ XK_Adiaeresis }},
  {  48, 0,		{ XK_numbersign, XK_apostrophe }},
  {  99, 0,		{ XK_Left, XK_KP_4, XK_KP_4, XK_Left }},
  { 100, 0,		{ XK_Begin, XK_KP_5, XK_KP_5, XK_Begin }},
  { 101, 0,		{ XK_Right, XK_KP_6, XK_KP_6, XK_Right }},

  /* Row 5 */
  {  50, ShiftMask,	{ XK_Shift_L }},
  {  51, 0,		{ XK_less, XK_greater, XK_bar }},
  {  52, 0,		{ XK_Y }},
  {  53, 0,		{ XK_X }},
  {  54, 0,		{ XK_C }},
  {  55, 0,		{ XK_V }},
  {  56, 0,		{ XK_B }},
  {  57, 0,		{ XK_N }},
  {  58, 0,		{ XK_m, XK_M, XK_mu }},
  {  59, 0,		{ XK_comma, XK_semicolon }},
  {  60, 0,		{ XK_period, XK_colon }},
  {  61, 0,		{ XK_minus, XK_underscore }},
  {  62, ShiftMask,	{ XK_Shift_R }},
  {  89, 0,		{ XK_Up }},
  { 102, 0,		{ XK_End, XK_KP_1, XK_KP_1, XK_End }},
  { 103, 0,		{ XK_Down, XK_KP_2, XK_KP_2, XK_Down }},
  { 104, 0,		{ XK_Next, XK_KP_3, XK_KP_3, XK_Next }},
  { 108, 0,		{ XK_KP_Enter }},

  /* Row 6 */
  {  63, ControlMask,	{ XK_Control_L }},
  {  64, Mod1Mask,	{ XK_Alt_L, XK_Meta_L }},
  {  67, 0,		{ XK_space }},
  {  66, 0,		{ XK_Mode_switch }},
  {  65, ControlMask,	{ XK_Control_R }},
  {  86, 0,		{ XK_Left }},
  {  87, 0,		{ XK_Down }},
  {  88, 0,		{ XK_Right }},
  { 105, 0,		{ XK_Insert, XK_KP_0, XK_KP_0, XK_Insert }},
  { 106, 0,		{ XK_Delete, XK_KP_Decimal, XK_KP_Decimal, XK_Delete }},

  /* with Numlock */
  { 128, 0,		{ XK_KP_0 }},
  { 129, 0,		{ XK_KP_1 }},
  { 130, 0,		{ XK_KP_2 }},
  { 131, 0,		{ XK_KP_3 }},
  { 132, 0,		{ XK_KP_4 }},
  { 133, 0,		{ XK_KP_5 }},
  { 134, 0,		{ XK_KP_6 }},
  { 135, 0,		{ XK_KP_7 }},
  { 136, 0,		{ XK_KP_8 }},
  { 137, 0,		{ XK_KP_9 }},
  { 138, 0,		{ XK_KP_Decimal }}
  };
