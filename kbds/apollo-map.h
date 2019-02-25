/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key mapping of an HP Apollo-thingy type keyboard.
 * By Mick J Hellstrom <mickh@rd.scitec.com.au>              
 */


static const struct default_keycode_map apollo_map [] =
{
  /* Row 0. */
  {   9, 0,		{ XK_Select,	XK_KP_Insert }},
  {  10, 0,		{ XK_KP_Begin }},
  {  11, 0,		{ XK_KP_Delete }},
  {  12, 0,		{ XK_F10 }},
  {  13, 0,		{ XK_F1 }},
  {  14, 0,		{ XK_F2 }},
  {  15, 0,		{ XK_F3 }},
  {  16, 0,		{ XK_F4 }},
  {  17, 0,		{ XK_F5 }},
  {  18, 0,		{ XK_F6 }},
  {  19, 0,		{ XK_F7 }},
  {  20, 0,		{ XK_F8 }},
  {  21, 0,		{ XK_F9 }},
  {  22, 0,		{ XK_Redo }},
  {  23, 0,		{ XK_KP_F1 }}, /* aka "READ". */
  {  24, 0,		{ XK_KP_F3,	XK_KP_F4}}, /* aka "EDIT, SAVE". */
  {  25, 0,		{ XK_Break,	XK_Cancel }}, /* aka "EXIT, ABORT". */
  {  26, 0,		{ XK_Pause,	XK_Help }}, /* aka "HOLD, HELP". */

  /* Row 1. */
  {  27, 0,		{ XK_F20,	XK_F21 }}, /* aka "COPY, CUT". */
  {  28, 0,		{ XK_F22,	XK_Undo }}, /* aka "PASTE, UNDO". */
  {  29, 0,		{ XK_F24,	XK_F25 }}, /* aka "GROW, MOVE". */
  {  31, 0,		{ XK_Escape }},
  {  32, 0,		{ XK_1,	XK_exclam }},
  {  33, 0,		{ XK_2,	XK_at }},
  {  34, 0,		{ XK_3,	XK_numbersign }},
  {  35, 0,		{ XK_4,	XK_dollar }},
  {  36, 0,		{ XK_5,	XK_percent }},
  {  37, 0,		{ XK_6,	XK_asciicircum }},
  {  38, 0,		{ XK_7,	XK_ampersand }},
  {  39, 0,		{ XK_8,	XK_asterisk }},
  {  40, 0,		{ XK_9,	XK_parenleft }},
  {  41, 0,		{ XK_0,	XK_parenright }},
  {  42, 0,		{ XK_minus,	XK_underscore }},
  {  43, 0,		{ XK_equal,	XK_plus }},
  {  44, 0,		{ XK_grave,	XK_asciitilde }},
  {  45, 0,		{ XK_BackSpace }},

  /* Row 2. */
  {  47, 0,		{ XK_KP_Home }},
  {  48, 0,		{ XK_Execute,	XK_Execute }}, /* aka CMD, SHELL */
  {  49, 0,		{ XK_KP_End }},
  {  52, 0,		{ XK_Tab }},
  {  53, 0,		{ XK_Q }},
  {  54, 0,		{ XK_W }},
  {  55, 0,		{ XK_E }},
  {  56, 0,		{ XK_R }},
  {  57, 0,		{ XK_T }},
  {  58, 0,		{ XK_Y }},
  {  59, 0,		{ XK_U }},
  {  60, 0,		{ XK_I }},
  {  61, 0,		{ XK_O }},
  {  62, 0,		{ XK_P }},
  {  63, 0,		{ XK_bracketleft,	XK_braceleft }},
  {  64, 0,		{ XK_bracketright,	XK_braceright }},
  {  66, 0,		{ XK_Delete }},
  {  68, 0,		{ XK_KP_7 }},
  {  69, 0,		{ XK_KP_8 }},
  {  70, 0,		{ XK_KP_9 }},
  {  71, 0,		{ XK_KP_Add }},

  /* Row 3. */
  {  72, 0,		{ XK_KP_Left }},
  {  73, 0,		{ XK_Up }},
  {  74, 0,		{ XK_KP_Right }},
  {  75, ControlMask,	{ XK_Control_L }},
  { 134, LockMask,	{ XK_Caps_Lock }},
  {  78, 0,		{ XK_A }},
  {  79, 0,		{ XK_S }},
  {  80, 0,		{ XK_D }},
  {  81, 0,		{ XK_F }},
  {  82, 0,		{ XK_G }},
  {  83, 0,		{ XK_H }},
  {  84, 0,		{ XK_J }},
  {  85, 0,		{ XK_K }},
  {  86, 0,		{ XK_L }},
  {  87, 0,		{ XK_semicolon,	XK_colon }},
  {  88, 0,		{ XK_apostrophe,	XK_quotedbl }},
  {  90, 0,		{ XK_Return }},
  {  91, 0,		{ XK_backslash,	XK_bar }},
  {  93, 0,		{ XK_KP_4 }},
  {  94, 0,		{ XK_KP_5 }},
  {  95, 0,		{ XK_KP_6 }},
  {  96, 0,		{ XK_KP_Subtract }},

  /* Row 4. */
  {  97, 0,		{ XK_Left }},
  {  98, 0,		{ XK_Next }},
  {  99, 0,		{ XK_Right }},
  { 101, 0,		{ XK_Alt_L,	XK_Meta_L }}, /* aka "Repeat" */
  { 102, ShiftMask,	{ XK_Shift_L }},
  { 104, 0,		{ XK_Z }},
  { 105, 0,		{ XK_X }},
  { 106, 0,		{ XK_C }},
  { 107, 0,		{ XK_V }},
  { 108, 0,		{ XK_B }},
  { 109, 0,		{ XK_N }},
  { 110, 0,		{ XK_M }},
  { 111, 0,		{ XK_comma,	XK_less }},
  { 112, 0,		{ XK_period,	XK_greater }},
  { 113, 0,		{ XK_slash,	XK_question }},
  { 114, ShiftMask,	{ XK_Shift_R }},
  { 116, 0,		{ XK_Alt_R,	XK_Meta_R }}, /* aka "Pop" */
  { 118, 0,		{ XK_KP_1 }},
  { 119, 0,		{ XK_KP_2 }},
  { 120, 0,		{ XK_KP_3 }},
  { 132, 0,		{ XK_KP_Enter }},

  /* Row 5. */
  { 122, 0,		{ XK_KP_Page_Up,	XK_Prior }},
  { 123, 0,		{ XK_Down }},
  { 124, 0,		{ XK_KP_Page_Down,	XK_Next }},
  { 125, 0,		{ XK_Alt_L,	XK_Meta_L }}, /* aka "Repeat" */
  { 126, 0,		{ XK_space }},
  { 127, 0,		{ XK_Alt_R,	XK_Meta_R }}, /* aka "Pop" */
  { 129, 0,		{ XK_KP_0 }},
  { 131, 0,		{ XK_KP_Decimal }}
  };
