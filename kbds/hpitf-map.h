/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the default keymap of the HP 300, 400, and 700 series
 * keyboards.  Generated by Dave Brooks <dbrooks@inel.gov> running on an
 * HP 9000/720 with the stock HP-UX 9.01 X server.
 */

static const struct default_keycode_map hpitf_map [] = {
  {  10, Mod1Mask,	{ XK_Meta_R }},
  {  11, Mod1Mask,	{ XK_Meta_L }},
  {  12, ShiftMask,	{ XK_Shift_R }},
  {  13, ShiftMask,	{ XK_Shift_L }},
  {  14, ControlMask,	{ XK_Control_L }},
  {  15, 0,		{ XK_Break,	hpXK_Reset }},
  {  16, 0,		{ XK_KP_4 }},
  {  17, 0,		{ XK_KP_8 }},
  {  18, 0,		{ XK_KP_5 }},
  {  19, 0,		{ XK_KP_9 }},
  {  20, 0,		{ XK_KP_6 }},
  {  21, 0,		{ XK_KP_7 }},
  {  22, 0,		{ XK_KP_Separator }},
  {  23, 0,		{ XK_KP_Enter }},
  {  24, 0,		{ XK_KP_1 }},
  {  25, 0,		{ XK_KP_Divide }},
  {  26, 0,		{ XK_KP_2 }},
  {  27, 0,		{ XK_KP_Add }},
  {  28, 0,		{ XK_KP_3 }},
  {  29, 0,		{ XK_KP_Multiply }},
  {  30, 0,		{ XK_KP_0 }},
  {  31, 0,		{ XK_KP_Subtract }},
  {  32, 0,		{ XK_B,	0,
			hpXK_block }},
  {  33, 0,		{ XK_V,	0,
			XK_section }},
  {  34, 0,		{ XK_C,	0,
			XK_ccedilla,	XK_Ccedilla }},
  {  35, 0,		{ XK_X,	0,
			XK_scaron,	XK_Scaron }},
  {  36, 0,		{ XK_Z,	0,
			XK_paragraph }},
  {  39, 0,		{ XK_Escape,	XK_Delete }},
  {  41, 0,		{ XK_F10,	XK_KP_F2 }},
  {  43, 0,		{ XK_F11,	XK_KP_F3 }},
  {  44, 0,		{ XK_KP_Decimal }},
  {  45, 0,		{ XK_F9,	XK_KP_F1 }},
  {  46, 0,		{ XK_KP_Tab,	hpXK_KP_BackTab }},
  {  47, 0,		{ XK_F12,	XK_KP_F4 }},
  {  48, 0,		{ XK_H,	0,
			XK_yen }},
  {  49, 0,		{ XK_G,	0,
			XK_currency }},
  {  50, 0,		{ XK_F,	0,
			hpXK_guilder }},
  {  51, 0,		{ XK_D,	0,
			XK_eth,	XK_ETH }},
  {  52, 0,		{ XK_S,	0,
			XK_ssharp }},
  {  53, 0,		{ XK_A,	0,
			XK_aring,	XK_Aring }},
  {  54, Mod1Mask,	{ XK_Mode_switch,	0,
			0,	XK_Mode_switch }},
  {  55, LockMask,	{ XK_Caps_Lock }},
  {  56, 0,		{ XK_U,	0,
			hpXK_mute_diaeresis }},
  {  57, 0,		{ XK_Y,	0,
			hpXK_mute_asciicircum }},
  {  58, 0,		{ XK_T,	0,
			hpXK_mute_grave }},
  {  59, 0,		{ XK_R,	0,
			hpXK_mute_acute }},
  {  60, 0,		{ XK_E,	0,
			XK_ae,	XK_AE }},
  {  61, 0,		{ XK_W,	0,
			XK_asciitilde }},
  {  62, 0,		{ XK_Q,	0,
			XK_periodcentered }},
  {  63, 0,		{ XK_Tab,	hpXK_BackTab }},
  {  64, 0,		{ XK_7,	XK_ampersand,
			XK_backslash }},
  {  65, 0,		{ XK_6,	XK_asciicircum,
			XK_asciicircum }},
  {  66, 0,		{ XK_5,	XK_percent,
			XK_onehalf }},
  {  67, 0,		{ XK_4,	XK_dollar,
			XK_onequarter,	XK_threequarters }},
  {  68, 0,		{ XK_3,	XK_numbersign,
			XK_numbersign }},
  {  69, 0,		{ XK_2,	XK_at,
			XK_at }},
  {  70, 0,		{ XK_1,	XK_exclam,
			XK_exclamdown }},
  {  71, 0,		{ XK_grave,	XK_asciitilde,
			XK_guillemotleft,	XK_guillemotright }},
  {  80, 0,		{ XK_Menu }},
  {  81, 0,		{ XK_F4 }},
  {  82, 0,		{ XK_F3 }},
  {  83, 0,		{ XK_F2 }},
  {  84, 0,		{ XK_F1 }},
  {  86, 0,		{ XK_Cancel }},
  {  87, 0,		{ XK_Execute,	XK_Print }},
  {  88, 0,		{ hpXK_System,	hpXK_User }},
  {  89, 0,		{ XK_F5 }},
  {  90, 0,		{ XK_F6 }},
  {  91, 0,		{ XK_F7 }},
  {  92, 0,		{ XK_F8 }},
  {  94, 0,		{ hpXK_ClearLine }},
  {  95, 0,		{ XK_Clear }},
  {  96, 0,		{ XK_8,	XK_asterisk,
			XK_bracketleft,	XK_braceleft }},
  {  97, 0,		{ XK_9,	XK_parenleft,
			XK_bracketright,	XK_braceright }},
  {  98, 0,		{ XK_0,	XK_parenright,
			XK_questiondown }},
  {  99, 0,		{ XK_minus,	XK_underscore,
			hpXK_longminus,	XK_macron }},
  { 100, 0,		{ XK_equal,	XK_plus,
			XK_plusminus }},
  { 101, 0,		{ XK_BackSpace }},
  { 102, 0,		{ hpXK_InsertLine }},
  { 103, 0,		{ hpXK_DeleteLine }},
  { 104, 0,		{ XK_I,	0,
			hpXK_mute_asciitilde }},
  { 105, 0,		{ XK_O,	0,
			XK_oslash,	XK_Ooblique }},
  { 106, 0,		{ XK_P,	0,
			XK_thorn,	XK_THORN }},
  { 107, 0,		{ XK_bracketleft,	XK_braceleft,
			XK_degree }},
  { 108, 0,		{ XK_bracketright,	XK_braceright,
			XK_bar,	XK_brokenbar }},
  { 109, 0,		{ XK_backslash,	XK_bar,
			XK_mu }},
  { 110, 0,		{ hpXK_InsertChar }},
  { 111, 0,		{ hpXK_DeleteChar }},
  { 112, 0,		{ XK_J,	0,
			XK_dollar }},
  { 113, 0,		{ XK_K,	0,
			XK_cent }},
  { 114, 0,		{ XK_L,	0,
			XK_sterling }},
  { 115, 0,		{ XK_semicolon,	XK_colon,
			hpXK_lira }},
  { 116, 0,		{ XK_apostrophe,	XK_quotedbl,
			XK_grave,	XK_apostrophe }},
  { 117, 0,		{ XK_Return }},
  { 118, 0,		{ XK_Home }},
  { 119, 0,		{ XK_Prior }},
  { 120, 0,		{ XK_M,	0,
			XK_masculine }},
  { 121, 0,		{ XK_comma,	XK_less,
			XK_less }},
  { 122, 0,		{ XK_period,	XK_greater,
			XK_greater }},
  { 123, 0,		{ XK_slash,	XK_question,
			XK_underscore }},
  { 125, 0,		{ XK_Select }},
  { 127, 0,		{ XK_Next }},
  { 128, 0,		{ XK_N,	0,
			XK_ordfeminine }},
  { 129, 0,		{ XK_space }},
  { 132, 0,		{ XK_Left }},
  { 133, 0,		{ XK_Down }},
  { 134, 0,		{ XK_Up }},
  { 135, 0,		{ XK_Right }}
  };
