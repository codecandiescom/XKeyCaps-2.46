/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the default keymap of the SONY NWS1250 keyboard.
 * Generated by Pavel Rosendorf <prf@jprix.che.wisc.edu> on 
 * NEWS-OS Release 4.1C #0: Fri Jul  5 14:06:49 JST 1991, X11R4.
 *
 * The blank key between "?" and "Shift_R" is physically disabled (you have to
 * open up the keyboard and remove a piece of plastic to enable it) but once
 * you do that it generates keycode 72.
 *
 * The blank key between "Alt" and "Caps" is also physically disabled, and is
 * rather strange once you enable it: it generates the keycodes 79 and 80
 * alternately; that is, it will generate the sequence
 *     79 KeyPress, 79 KeyRelease, 80 KeyPress, 80 KeyRelease
 * if pressed and released twice.
 */

static const struct default_keycode_map nws1250_map [] = {
  {   8, 0,		{ XK_F1,	XK_F11 }},
  {   9, 0,		{ XK_F2,	XK_F12 }},
  {  10, 0,		{ XK_F3,	XK_F13 }},
  {  11, 0,		{ XK_F4,	XK_F14 }},
  {  12, 0,		{ XK_F5,	XK_F15 }},
  {  13, 0,		{ XK_F6,	XK_F16 }},
  {  14, 0,		{ XK_F7,	XK_F17 }},
  {  15, 0,		{ XK_F8,	XK_F18 }},
  {  16, 0,		{ XK_F9,	XK_F19 }},
  {  17, 0,		{ XK_F10, XK_F20 }},
  {  18, 0,		{ XK_Escape }},
  {  19, 0,		{ XK_1,	XK_exclam }},
  {  20, 0,		{ XK_2,	XK_at }},
  {  21, 0,		{ XK_3,	XK_numbersign }},
  {  22, 0,		{ XK_4,	XK_dollar }},
  {  23, 0,		{ XK_5,	XK_percent }},
  {  24, 0,		{ XK_6,	XK_asciicircum }},
  {  25, 0,		{ XK_7,	XK_ampersand }},
  {  26, 0,		{ XK_8,	XK_asterisk }},
  {  27, 0,		{ XK_9,	XK_parenleft }},
  {  28, 0,		{ XK_0,	XK_parenright }},
  {  29, 0,		{ XK_minus,	XK_underscore }},
  {  30, 0,		{ XK_equal,	XK_plus }},
  {  31, 0,		{ XK_backslash,	XK_bar }},
  {  32, 0,		{ XK_BackSpace }},
  {  33, 0,		{ XK_Tab }},
  {  34, 0,		{ XK_q,	XK_Q }},
  {  35, 0,		{ XK_w,	XK_W }},
  {  36, 0,		{ XK_e,	XK_E }},
  {  37, 0,		{ XK_r,	XK_R }},
  {  38, 0,		{ XK_t,	XK_T }},
  {  39, 0,		{ XK_y,	XK_Y }},
  {  40, 0,		{ XK_u,	XK_U }},
  {  41, 0,		{ XK_i,	XK_I }},
  {  42, 0,		{ XK_o,	XK_O }},
  {  43, 0,		{ XK_p,	XK_P }},
  {  44, 0,		{ XK_bracketleft,	XK_braceleft }},
  {  45, 0,		{ XK_bracketright,	XK_braceright }},
  {  46, 0,		{ XK_Delete,	XK_Insert }},
  {  47, ControlMask,	{ XK_Control_L }},
  {  48, 0,		{ XK_a,	XK_A }},
  {  49, 0,		{ XK_s,	XK_S }},
  {  50, 0,		{ XK_d,	XK_D }},
  {  51, 0,		{ XK_f,	XK_F }},
  {  52, 0,		{ XK_g,	XK_G }},
  {  53, 0,		{ XK_h,	XK_H }},
  {  54, 0,		{ XK_j,	XK_J }},
  {  55, 0,		{ XK_k,	XK_K }},
  {  56, 0,		{ XK_l,	XK_L }},
  {  57, 0,		{ XK_semicolon,	XK_colon }},
  {  58, 0,		{ XK_apostrophe,	XK_quotedbl }},
  {  59, 0,		{ XK_grave,	XK_asciitilde }},
  {  60, 0,		{ XK_Return }},
  {  61, ShiftMask,	{ XK_Shift_L }},
  {  62, 0,		{ XK_z,	XK_Z }},
  {  63, 0,		{ XK_x,	XK_X }},
  {  64, 0,		{ XK_c,	XK_C }},
  {  65, 0,		{ XK_v,	XK_V }},
  {  66, 0,		{ XK_b,	XK_B }},
  {  67, 0,		{ XK_n,	XK_N }},
  {  68, 0,		{ XK_m,	XK_M }},
  {  69, 0,		{ XK_comma,	XK_less }},
  {  70, 0,		{ XK_period,	XK_greater }},
  {  71, 0,		{ XK_slash,	XK_question }},
  {  72, 0,		{ XK_Menu }},
  {  73, ShiftMask,	{ XK_Shift_R }},
  {  74, Mod1Mask,	{ XK_Alt_L }},
  {  75, LockMask,	{ XK_Caps_Lock }},
  {  76, 0,		{ XK_Multi_key }},
  {  77, 0,		{ XK_space }},
  {  78, 0,		{ XK_Select }},
  {  79, Mod5Mask,	{ XK_Mode_switch }},
  {  80, Mod5Mask,	{ XK_Mode_switch }},
  {  81, 0,		{ XK_Execute }},
  {  82, 0,		{ XK_KP_7 }},
  {  83, 0,		{ XK_KP_8 }},
  {  84, 0,		{ XK_KP_9 }},
  {  85, 0,		{ XK_KP_Subtract, XK_KP_Divide }},
  {  86, 0,		{ XK_KP_4 }},
  {  87, 0,		{ XK_KP_5 }},
  {  88, 0,		{ XK_KP_6 }},
  {  89, 0,		{ XK_KP_Add,	XK_KP_Multiply }},
  {  90, 0,		{ XK_KP_1 }},
  {  91, 0,		{ XK_KP_2 }},
  {  92, 0,		{ XK_KP_3 }},
  {  93, 0,		{ XK_KP_Separator,	XK_KP_Equal }},
  {  94, 0,		{ XK_KP_0 }},
  {  95, 0,		{ XK_Up }},
  {  96, 0,		{ XK_KP_Decimal }},
  {  97, 0,		{ XK_KP_Enter }},
  {  98, 0,		{ XK_Left }},
  {  99, 0,		{ XK_Down }},
  { 100, 0,		{ XK_Right }}
  };
