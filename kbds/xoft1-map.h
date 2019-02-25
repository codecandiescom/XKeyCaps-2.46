/* xkeycaps, Copyright (c) 1994 by Jamie Zawinski <jwz@jwz.org>
 *
 * AGE and IBM have conspired to confuse us all.
 *
 * AGE XoftWare 2.0 is a PC software product, and therefore works with a
 * variety of PC keyboards.  It comes with the vendor id "AGE Logic, Inc."
 *
 * The IBM Xstation 130 X terminal is an IBM hardware product, which comes
 * with "X Station Manager Software 1.4" which is in fact made by AGE.  It
 * has the vendor id "AGE Logic, Inc. Release 090493".  It has a different
 * default keymap than the PC software, though it comes with a PC101 keyboard.
 * This is apparently so that the IBM product ends up with the same default
 * keymap (and keycaps) as the IBM RS6K keyboards.
 *
 * This file describes the default R4 and R5 keymaps of the IBM Xstation 130.
 *
 * Generated by Tom McConnell <tmcconne@sedona.intel.com> on
 * IBM Xstation 130 running AGE Logic's X11R4, (11.0, release 040793)
 * hosted by IBM RS/6000 55S (550), AIX-3.2.4.
 *
 * Verified by Daniel Packman <pack@uars2.acd.ucar.edu> on
 * IBM Xstation 130 running AGE Logic's X11R5, (11.0, release 090493)
 * hosted by <something> running AIX 3.2.5.
 *
 * On the IBM Xstation 130, keycode 72 (the right Ctrl/Act key) generates
 * ModControl, but on the IBM RS/6000 it is used for window manager stuff.
 */

static const struct default_keycode_map xoft1_map [] = {
  {   9, 0,		{ XK_grave,	XK_asciitilde }},
  {  10, 0,		{ XK_1,	XK_exclam }},
  {  11, 0,		{ XK_2,	XK_at }},
  {  12, 0,		{ XK_3,	XK_numbersign }},
  {  13, 0,		{ XK_4,	XK_dollar }},
  {  14, 0,		{ XK_5,	XK_percent }},
  {  15, 0,		{ XK_6,	XK_asciicircum }},
  {  16, 0,		{ XK_7,	XK_ampersand }},
  {  17, 0,		{ XK_8,	XK_asterisk }},
  {  18, 0,		{ XK_9,	XK_parenleft }},
  {  19, 0,		{ XK_0,	XK_parenright }},
  {  20, 0,		{ XK_minus,	XK_underscore }},
  {  21, 0,		{ XK_equal,	XK_plus }},
  {  22, 0,		{ XK_yen }},
  {  23, 0,		{ XK_BackSpace }},
  {  24, 0,		{ XK_Tab }},
  {  25, 0,		{ XK_q,	XK_Q }},
  {  26, 0,		{ XK_w,	XK_W }},
  {  27, 0,		{ XK_e,	XK_E }},
  {  28, 0,		{ XK_r,	XK_R }},
  {  29, 0,		{ XK_t,	XK_T }},
  {  30, 0,		{ XK_y,	XK_Y }},
  {  31, 0,		{ XK_u,	XK_U }},
  {  32, 0,		{ XK_i,	XK_I }},
  {  33, 0,		{ XK_o,	XK_O }},
  {  34, 0,		{ XK_p,	XK_P }},
  {  35, 0,		{ XK_bracketleft,	XK_braceleft }},
  {  36, 0,		{ XK_bracketright,	XK_braceright }},
  {  37, 0,		{ XK_backslash,	XK_bar }},
  {  38, LockMask,	{ XK_Caps_Lock }},
  {  39, 0,		{ XK_a,	XK_A }},
  {  40, 0,		{ XK_s,	XK_S }},
  {  41, 0,		{ XK_d,	XK_D }},
  {  42, 0,		{ XK_f,	XK_F }},
  {  43, 0,		{ XK_g,	XK_G }},
  {  44, 0,		{ XK_h,	XK_H }},
  {  45, 0,		{ XK_j,	XK_J }},
  {  46, 0,		{ XK_k,	XK_K }},
  {  47, 0,		{ XK_l,	XK_L }},
  {  48, 0,		{ XK_semicolon,	XK_colon }},
  {  49, 0,		{ XK_apostrophe,	XK_quotedbl }},
  {  50, 0,		{ XK_asterisk,	XK_mu }},
  {  51, 0,		{ XK_Return,	XK_Return }},
  {  52, ShiftMask,	{ XK_Shift_L }},
  {  53, 0,		{ XK_less,	XK_greater }},
  {  54, 0,		{ XK_z,	XK_Z }},
  {  55, 0,		{ XK_x,	XK_X }},
  {  56, 0,		{ XK_c,	XK_C }},
  {  57, 0,		{ XK_v,	XK_V }},
  {  58, 0,		{ XK_b,	XK_B }},
  {  59, 0,		{ XK_n,	XK_N }},
  {  60, 0,		{ XK_m,	XK_M }},
  {  61, 0,		{ XK_comma,	XK_less }},
  {  62, 0,		{ XK_period,	XK_greater }},
  {  63, 0,		{ XK_slash,	XK_question }},
  {  64, 0,		{ XK_underscore,	XK_underscore }},
  {  65, ShiftMask,	{ XK_Shift_R }},
  {  66, ControlMask,	{ XK_Control_L }},
  {  68, Mod1Mask,	{ XK_Alt_L }},
  {  69, 0,		{ XK_space }},
  {  70, Mod1Mask,	{ XK_Alt_R }},
  {  72, ControlMask,	{ XK_Execute }},
  {  83, 0,		{ XK_Insert }},
  {  84, 0,		{ XK_Delete }},
  {  87, 0,		{ XK_Left }},
  {  88, 0,		{ XK_Home }},
  {  89, 0,		{ XK_End }},
  {  91, 0,		{ XK_Up }},
  {  92, 0,		{ XK_Down }},
  {  93, 0,		{ XK_Prior }},
  {  94, 0,		{ XK_Next }},
  {  97, 0,		{ XK_Right }},
  {  98, Mod5Mask,	{ XK_Num_Lock }},
  {  99, 0,		{ XK_KP_7 }},
  { 100, 0,		{ XK_KP_4 }},
  { 101, 0,		{ XK_KP_1 }},
  { 103, 0,		{ XK_KP_Divide }},
  { 104, 0,		{ XK_KP_8 }},
  { 105, 0,		{ XK_KP_5 }},
  { 106, 0,		{ XK_KP_2 }},
  { 107, 0,		{ XK_KP_0 }},
  { 108, 0,		{ XK_KP_Multiply }},
  { 109, 0,		{ XK_KP_9 }},
  { 110, 0,		{ XK_KP_6 }},
  { 111, 0,		{ XK_KP_3 }},
  { 112, 0,		{ XK_KP_Decimal }},
  { 113, 0,		{ XK_KP_Subtract }},
  { 114, 0,		{ XK_KP_Add }},
  { 116, 0,		{ XK_KP_Enter }},
  { 118, 0,		{ XK_Escape }},
  { 120, 0,		{ XK_F1 }},
  { 121, 0,		{ XK_F2 }},
  { 122, 0,		{ XK_F3 }},
  { 123, 0,		{ XK_F4 }},
  { 124, 0,		{ XK_F5 }},
  { 125, 0,		{ XK_F6 }},
  { 126, 0,		{ XK_F7 }},
  { 127, 0,		{ XK_F8 }},
  { 128, 0,		{ XK_F9 }},
  { 129, 0,		{ XK_F10 }},
  { 130, 0,		{ XK_F11 }},
  { 131, 0,		{ XK_F12 }},
  { 132, 0,		{ XK_Print }},
  { 133, 0,		{ XK_Cancel }},
  { 134, 0,		{ XK_Pause }},
  { 139, 0,		{ XK_Multi_key }},
  { 140, 0,		{ XK_Kanji }},
  { 141, 0,		{ XK_Mode_switch }}
  };
