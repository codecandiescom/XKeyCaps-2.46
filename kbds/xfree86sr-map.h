/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1999
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the default SR keymap used by the XFree86 X server.
 *
 * Keymap file of the 102 keys PC-style keyboard, swiss french layout (qwertz).
 * Linux 2.0.35 / XFree86 3.3
 *
 * By Martin Ouwehand <Martin.Ouwehand@epl.ch>
 *
 * This map file was obtained under the following conditions:
 *
 *        * RedHat 5.2 with XFree86 3.3.2 (I've heard reports that
 *          things are slightly different under RedHat 5.1)
 *
 *        * before starting X, the console's keyboard is configured with:
 *
 *                      loadkeys fr_CH-latin1
 *
 *        * In the /usr/X11R6/lib/X11/XF86Config file's "Keyboard" Section
 *          we have the following two lines:
 *
 *                      RightAlt    ModeShift
 *                      XkbLayout   "sf"
 *
 *          The "Modeshift" line is necessary to get a usable keyboard
 *          and a satisfactory output from the "build-map.sh" script
 *          (to be able to get e.g. the "@" and "#" characters with
 *          <AltGr> + "2" and <AltGr> + "3").
 *
 * Note that I didn't define things like "LeftAlt Meta" or bind a key
 * to "Compose" to keep things as simple as possible.
 *
 */

static const struct default_keycode_map xfree86sr_map [] = {
  {   9, 0,		{ XK_Escape }},
  {  10, 0,		{ XK_1,	XK_plus }},
  {  11, 0,		{ XK_2,	XK_quotedbl,
			  XK_at }},
  {  12, 0,		{ XK_3,	XK_asterisk,
			  XK_numbersign }},
  {  13, 0,		{ XK_4,	XK_ccedilla }},
  {  14, 0,		{ XK_5,	XK_percent }},
  {  15, 0,		{ XK_6,	XK_ampersand,
			  XK_notsign }},
  {  16, 0,		{ XK_7,	XK_slash,
			  XK_bar }},
  {  17, 0,		{ XK_8,	XK_parenleft,
			  XK_cent }},
  {  18, 0,		{ XK_9,	XK_parenright }},
  {  19, 0,		{ XK_0,	XK_equal }},
  {  20, 0,		{ XK_apostrophe,	XK_question,
			  XK_dead_acute }},
  {  21, 0,		{ XK_dead_circumflex,	XK_dead_grave,
			  XK_dead_tilde }},
  {  22, 0,		{ XK_Delete }},
  {  23, 0,		{ XK_Tab }},
  {  24, 0,		{ XK_q,	XK_Q,
			  XK_q }},
  {  25, 0,		{ XK_w,	XK_W,
			  XK_w }},
  {  26, 0,		{ XK_e,	XK_E,
			  XK_e }},
  {  27, 0,		{ XK_r,	XK_R,
			  XK_r }},
  {  28, 0,		{ XK_t,	XK_T,
			  XK_t }},
  {  29, 0,		{ XK_z,	XK_Z,
			  XK_z }},
  {  30, 0,		{ XK_u,	XK_U,
			  XK_u }},
  {  31, 0,		{ XK_i,	XK_I,
			  XK_i }},
  {  32, 0,		{ XK_o,	XK_O,
			  XK_o }},
  {  33, 0,		{ XK_p,	XK_P,
			  XK_p }},
  {  34, 0,		{ XK_egrave,	XK_udiaeresis,
			  XK_bracketleft }},
  {  35, 0,		{ XK_dead_diaeresis,	XK_exclam,
			  XK_bracketright }},
  {  36, 0,		{ XK_Return }},
  {  37, ControlMask,	{ XK_Control_L }},
  {  38, 0,		{ XK_a,	XK_A,
			  XK_a }},
  {  39, 0,		{ XK_s,	XK_S,
			  XK_s }},
  {  40, 0,		{ XK_d,	XK_D,
			  XK_d }},
  {  41, 0,		{ XK_f,	XK_F,
			  XK_f }},
  {  42, 0,		{ XK_g,	XK_G,
			  XK_g }},
  {  43, 0,		{ XK_h,	XK_H,
			  XK_h }},
  {  44, 0,		{ XK_j,	XK_J,
			  XK_j }},
  {  45, 0,		{ XK_k,	XK_K,
			  XK_k }},
  {  46, 0,		{ XK_l,	XK_L,
			  XK_l }},
  {  47, 0,		{ XK_eacute,	XK_odiaeresis }},
  {  48, 0,		{ XK_agrave,	XK_adiaeresis,
			  XK_braceleft }},
  {  49, 0,		{ XK_section,	XK_degree }},
  {  50, ShiftMask,	{ XK_Shift_L }},
  {  51, 0,		{ XK_dollar,	XK_sterling,
			  XK_braceright }},
  {  52, 0,		{ XK_y,	XK_Y,
			  XK_y }},
  {  53, 0,		{ XK_x,	XK_X,
			  XK_x }},
  {  54, 0,		{ XK_c,	XK_C,
			  XK_c }},
  {  55, 0,		{ XK_v,	XK_V,
			  XK_v }},
  {  56, 0,		{ XK_b,	XK_B,
			  XK_b }},
  {  57, 0,		{ XK_n,	XK_N,
			  XK_n }},
  {  58, 0,		{ XK_m,	XK_M,
			  XK_m }},
  {  59, 0,		{ XK_comma,	XK_semicolon }},
  {  60, 0,		{ XK_period,	XK_colon }},
  {  61, 0,		{ XK_minus,	XK_underscore }},
  {  62, ShiftMask,	{ XK_Shift_R }},
  {  63, 0,		{ XK_KP_Multiply }},
  {  64, Mod1Mask,	{ XK_Alt_L,	XK_Meta_L }},
  {  65, 0,		{ XK_space }},
  {  66, LockMask,	{ XK_Caps_Lock }},
  {  67, 0,		{ XK_F1,	XK_F13 }},
  {  68, 0,		{ XK_F2,	XK_F14 }},
  {  69, 0,		{ XK_F3,	XK_F15 }},
  {  70, 0,		{ XK_F4,	XK_F16 }},
  {  71, 0,		{ XK_F5,	XK_F17 }},
  {  72, 0,		{ XK_F6,	XK_F18 }},
  {  73, 0,		{ XK_F7,	XK_F19 }},
  {  74, 0,		{ XK_F8,	XK_F20 }},
  {  75, 0,		{ XK_F9 }},
  {  76, 0,		{ XK_F10 }},
  {  77, Mod2Mask,	{ XK_Num_Lock }},
  {  78, 0,		{ XK_Multi_key }},
  {  79, 0,		{ XK_KP_7 }},
  {  80, 0,		{ XK_KP_8 }},
  {  81, 0,		{ XK_KP_9 }},
  {  82, 0,		{ XK_KP_Subtract }},
  {  83, 0,		{ XK_KP_4 }},
  {  84, 0,		{ XK_KP_5 }},
  {  85, 0,		{ XK_KP_6 }},
  {  86, 0,		{ XK_KP_Add }},
  {  87, 0,		{ XK_KP_1 }},
  {  88, 0,		{ XK_KP_2 }},
  {  89, 0,		{ XK_KP_3 }},
  {  90, 0,		{ XK_KP_0 }},
  {  91, 0,		{ XK_KP_Separator }},
  {  94, 0,		{ XK_less,	XK_greater,
			  XK_backslash }},
  {  95, 0,		{ XK_F11 }},
  {  96, 0,		{ XK_F12 }},
  {  97, 0,		{ XK_Home }},
  {  98, 0,		{ XK_Up }},
  {  99, 0,		{ XK_Prior }},
  { 100, 0,		{ XK_Left }},
  { 102, 0,		{ XK_Right }},
  { 103, 0,		{ XK_End }},
  { 104, 0,		{ XK_Down }},
  { 105, 0,		{ XK_Next }},
  { 106, 0,		{ XK_Insert }},
  { 107, 0,		{ XK_Delete }},
  { 108, 0,		{ XK_KP_Enter }},
  { 109, ControlMask,	{ XK_Control_R }},
  { 110, 0,		{ XK_Pause }},
  { 111, 0,		{ 0 }},
  { 112, 0,		{ XK_KP_Divide }},
  { 113, Mod3Mask,	{ XK_Mode_switch }},
  { 114, 0,		{ XK_Break }},
  };
