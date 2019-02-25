/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1999
 * Jamie Zawinski <jwz@jwz.org>
 *
 * HP 700/RX PC keyboard (Swedish/Finnish Version)
 * by Heikki Kantola <hezu@iki.fi>
 */

static const struct default_keycode_map hppcsf700rx_map [] = {
  {  16, 0,		{ XK_F1 }},
  {  17, 0,		{ XK_Escape }},
  {  22, 0,		{ XK_Tab,	hpXK_BackTab }},
  {  23, 0,		{ XK_section,	XK_onehalf }},
  {  24, 0,		{ XK_F2 }},
  {  26, ControlMask,	{ XK_Control_L }},
  {  27, ShiftMask,	{ XK_Shift_L }},
  {  28, 0,		{ XK_less, XK_greater,	XK_bar }},
  {  29, LockMask,	{ XK_Caps_Lock }},
  {  30, 0,		{ XK_q,	XK_Q,
			XK_periodcentered,	XK_periodcentered }},
  {  31, 0,		{ XK_1,	XK_exclam,
			XK_exclamdown,	XK_exclamdown }},
  {  32, 0,		{ XK_F3 }},
  {  33, 0,		{ XK_Kanji }},
  {  34, Mod1Mask,	{ XK_Alt_L }},
  {  35, 0,		{ XK_z,	XK_Z,
			XK_paragraph,	XK_paragraph }},
  {  36, 0,		{ XK_s,	XK_S,
			XK_ssharp,	XK_ssharp }},
  {  37, 0,		{ XK_a,	XK_A,
			XK_aring,	XK_Aring }},
  {  38, 0,		{ XK_w,	XK_W,
			XK_asciitilde,	XK_asciitilde }},
  {  39, 0,		{ XK_2,	XK_quotedbl, XK_at }},
  {  40, 0,		{ XK_F4 }},
  {  42, 0,		{ XK_c,	XK_C,
			XK_ccedilla,	XK_Ccedilla }},
  {  43, 0,		{ XK_x,	XK_X,
			XK_scaron,	XK_Scaron }},
  {  44, 0,		{ XK_d,	XK_D,
			XK_eth,	XK_ETH }},
  {  45, 0,		{ XK_e,	XK_E,
			XK_ae,	XK_AE }},
  {  46, 0,		{ XK_4,	XK_currency, XK_dollar,
			XK_onequarter,	hpXK_Ydiaeresis }},
  {  47, 0,		{ XK_3,	XK_numbersign, XK_sterling }},
  {  48, 0,		{ XK_F5 }},
  {  50, 0,		{ XK_space }},
  {  51, 0,		{ XK_v,	XK_V,
			XK_section,	XK_section }},
  {  52, 0,		{ XK_f,	XK_F,
			hpXK_guilder,	hpXK_guilder }},
  {  53, 0,		{ XK_t,	XK_T,
			hpXK_mute_grave,	hpXK_mute_grave }},
  {  54, 0,		{ XK_r,	XK_R,
			hpXK_mute_acute,	hpXK_mute_acute }},
  {  55, 0,		{ XK_5,	XK_percent,
			XK_onehalf,	XK_onehalf }},
  {  56, 0,		{ XK_F6 }},
  {  58, 0,		{ XK_n,	XK_N,
			XK_ordfeminine,	XK_ordfeminine }},
  {  59, 0,		{ XK_b,	XK_B,
			hpXK_block,	hpXK_block }},
  {  60, 0,		{ XK_h,	XK_H,
			XK_yen,	XK_yen }},
  {  61, 0,		{ XK_g,	XK_G,
			XK_currency,	XK_currency }},
  {  62, 0,		{ XK_y,	XK_Y,
			hpXK_mute_asciicircum,	hpXK_mute_asciicircum }},
  {  63, 0,		{ XK_6,	XK_asciicircum,
			XK_asciicircum,	XK_asciicircum }},
  {  64, 0,		{ XK_F7 }},
  {  65, 0,		{ XK_Kanji }},
  {  66, Mod1Mask,	{ XK_Alt_R }},
  {  67, 0,		{ XK_m,	XK_M,
			XK_masculine,	XK_masculine }},
  {  68, 0,		{ XK_j,	XK_J,
			XK_dollar,	XK_dollar }},
  {  69, 0,		{ XK_u,	XK_U,
			hpXK_mute_diaeresis,	hpXK_mute_diaeresis }},
  {  70, 0,		{ XK_7,	XK_slash, XK_braceleft }},
  {  71, 0,		{ XK_8,	XK_parenleft, XK_bracketleft }},
  {  72, 0,		{ XK_F8 }},
  {  74, 0,		{ XK_comma,	XK_semicolon,
			XK_less,	XK_less }},
  {  75, 0,		{ XK_k,	XK_K,
			XK_cent,	XK_cent }},
  {  76, 0,		{ XK_i,	XK_I,
			hpXK_mute_asciitilde,	hpXK_mute_asciitilde }},
  {  77, 0,		{ XK_o,	XK_O,
			XK_oslash,	XK_Ooblique }},
  {  78, 0,		{ XK_0, XK_equal, XK_braceright }},
  {  79, 0,		{ XK_9,	XK_parenright, XK_bracketright }},
  {  80, 0,		{ XK_F9,	XK_KP_F1 }},
  {  82, 0,		{ XK_period,	XK_comma,
			XK_greater,	XK_greater }},
  {  83, 0,		{ XK_slash,	XK_question,
			XK_underscore,	XK_underscore }},
  {  84, 0,		{ XK_l,	XK_L,
			XK_sterling,	XK_sterling }},
  {  85, 0,		{ XK_odiaeresis,	XK_Odiaeresis }},
  {  86, 0,		{ XK_p,	XK_P,
			XK_thorn,	XK_THORN }},
  {  87, 0,		{ XK_plus,	XK_question, XK_backslash }},
  {  88, 0,		{ XK_F10,	XK_KP_F2 }},
  {  91, 0,		{ XK_adiaeresis,	XK_Adiaeresis }},
  {  92, 0,		{ XK_apostrophe,	XK_asterisk }},
  {  93, 0,		{ XK_aring,	XK_Aring }},
  {  94, 0,		{ XK_acute,	XK_grave }},
  {  95, 0,		{ XK_F11,	XK_KP_F3 }},
  {  96, 0,		{ XK_Print, 0xFF15 }},
  {  97, ControlMask,	{ XK_Control_R }},
  {  98, ShiftMask,	{ XK_Shift_R }},
  {  99, 0,		{ XK_Return }},
  { 100, 0,		{ XK_diaeresis,	XK_asciicircum, XK_asciitilde }},
  { 103, 0,		{ XK_F12,	XK_KP_F4 }},
  { 104, 0,		{ XK_Scroll_Lock }},
  { 105, 0,		{ XK_Down }},
  { 106, 0,		{ XK_Left }},
  { 107, 0,		{ XK_Pause,	XK_Break }},
  { 108, 0,		{ XK_Up }},
  { 109, 0,		{ XK_Delete }},
  { 110, 0,		{ XK_End }},
  { 111, 0,		{ XK_BackSpace }},
  { 112, 0,		{ XK_Insert }},
  { 114, 0,		{ XK_KP_1, 0xFF9C }},
  { 115, 0,		{ XK_Right }},
  { 116, 0,		{ XK_KP_4, 0xFF96 }},
  { 117, 0,		{ XK_KP_7, 0xFF95 }},
  { 118, 0,		{ XK_Next }},
  { 119, 0,		{ XK_Home }},
  { 120, 0,		{ XK_Prior }},
  { 121, 0,		{ XK_KP_0, 0xFF9E }},
  { 122, 0,		{ XK_KP_Decimal, 0xFF9F }},
  { 123, 0,		{ XK_KP_2, 0xFF99 }},
  { 124, 0,		{ XK_KP_5 }},
  { 125, 0,		{ XK_KP_6, 0xFF98 }},
  { 126, 0,		{ XK_KP_8, 0xFF97 }},
  { 127, 0,		{ XK_Num_Lock }},
  { 128, 0,		{ XK_KP_Divide }},
  { 130, 0,		{ XK_KP_Enter }},
  { 131, 0,		{ XK_KP_3, 0xFF9B }},
  { 132, Mod1Mask,	{ XK_Mode_switch }},
  { 133, 0,		{ XK_KP_Add }},
  { 134, 0,		{ XK_KP_9, 0xFF9A }},
  { 135, 0,		{ XK_KP_Multiply }},
  { 141, 0,		{ XK_KP_Subtract }},
  };