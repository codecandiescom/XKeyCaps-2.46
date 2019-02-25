/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1997
 *   Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the Cherry ErgoPlus keyboards.
 * By Berthold Gunreben <gunreben@wvwx01.wifak.uni-wuerzburg.de>
 */

static const struct default_keycode_map chergo_de_map [] = {
  {   9, 0,		{ XK_Escape }},
  {  10, 0,		{ XK_1,	XK_exclam,
			  XK_onesuperior,	XK_exclamdown }},
  {  11, 0,		{ XK_2,	XK_quotedbl,
			  XK_twosuperior,	XK_oneeighth }},
  {  12, 0,		{ XK_3,	XK_section,
			  XK_threesuperior,	XK_sterling }},
  {  13, 0,		{ XK_4,	XK_dollar,
			  XK_onequarter,	XK_currency }},
  {  14, 0,		{ XK_5,	XK_percent,
			  XK_onehalf,	XK_threeeighths }},
  {  15, 0,		{ XK_6,	XK_ampersand,
			  XK_threequarters,	XK_fiveeighths }},
  {  16, 0,		{ XK_7,	XK_slash,
			  XK_braceleft,	XK_seveneighths }},
  {  17, 0,		{ XK_8,	XK_parenleft,
			  XK_bracketleft,	XK_trademark }},
  {  18, 0,		{ XK_9,	XK_parenright,
			  XK_bracketright,	XK_plusminus }},
  {  19, 0,		{ XK_0,	XK_equal,
			  XK_braceright,	XK_degree }},
  {  20, 0,		{ XK_ssharp,	XK_question,
			  XK_backslash,	XK_questiondown }},
  {  21, 0,		{ XK_dead_acute,	XK_dead_grave,
			  XK_dead_cedilla,	XK_dead_ogonek }},
  {  22, 0,		{ XK_BackSpace,	XK_BackSpace,
			  XK_3270_DeleteWord }},
  {  23, 0,		{ XK_Tab,	XK_ISO_Left_Tab }},
  {  24, 0,		{ XK_q,	XK_Q,
			  XK_at,	XK_Greek_OMEGA }},
  {  25, 0,		{ XK_w,	XK_W,
			  XK_lstroke,	XK_Lstroke }},
  {  26, 0,		{ XK_e,	XK_E }},
  {  27, 0,		{ XK_r,	XK_R,
			  XK_paragraph,	XK_registered }},
  {  28, 0,		{ XK_t,	XK_T,
			  XK_tslash,	XK_Tslash }},
  {  29, 0,		{ XK_z,	XK_Z,
			  XK_leftarrow,	XK_yen }},
  {  30, 0,		{ XK_u,	XK_U,
			  XK_downarrow,	XK_uparrow }},
  {  31, 0,		{ XK_i,	XK_I,
			  XK_rightarrow,	XK_idotless }},
  {  32, 0,		{ XK_o,	XK_O,
			  XK_oslash,	XK_Ooblique }},
  {  33, 0,		{ XK_p,	XK_P,
			  XK_thorn,	XK_THORN }},
  {  34, 0,		{ XK_udiaeresis,	XK_Udiaeresis,
			  XK_dead_diaeresis,	XK_dead_abovering }},
  {  35, 0,		{ XK_plus,	XK_asterisk,
			  XK_dead_tilde,	XK_dead_macron }},
  {  36, 0,		{ XK_Return }},
  {  37, ControlMask,	{ XK_Control_L }},
  {  38, 0,		{ XK_a,	XK_A,
			  XK_ae,	XK_AE }},
  {  39, 0,		{ XK_s,	XK_S,
			  XK_ssharp,	XK_section }},
  {  40, 0,		{ XK_d,	XK_D,
			  XK_eth,	XK_ETH }},
  {  41, 0,		{ XK_f,	XK_F,
			  XK_dstroke,	XK_ordfeminine }},
  {  42, 0,		{ XK_g,	XK_G,
			  XK_eng,	XK_ENG }},
  {  43, 0,		{ XK_h,	XK_H,
			  XK_hstroke,	XK_Hstroke }},
  {  44, 0,		{ XK_j,	XK_J }},
  {  45, 0,		{ XK_k,	XK_K,
			  XK_kra,	XK_ampersand }},
  {  46, 0,		{ XK_l,	XK_L,
			  XK_lstroke,	XK_Lstroke }},
  {  47, 0,		{ XK_odiaeresis,	XK_Odiaeresis,
			  XK_dead_acute,	XK_dead_doubleacute }},
  {  48, 0,		{ XK_adiaeresis,	XK_Adiaeresis,
			  XK_dead_circumflex,	XK_dead_caron }},
  {  49, 0,		{ XK_dead_circumflex,	XK_degree,
			  XK_notsign }},
  {  50, ShiftMask,	{ XK_Shift_L }},
  {  51, 0,		{ XK_numbersign,	XK_apostrophe,
			  XK_dead_grave,	XK_dead_breve }},
  {  52, 0,		{ XK_y,	XK_Y,
			  XK_guillemotleft,	XK_less }},
  {  53, 0,		{ XK_x,	XK_X,
			  XK_guillemotright,	XK_greater }},
  {  54, 0,		{ XK_c,	XK_C,
			  XK_cent,	XK_copyright }},
  {  55, 0,		{ XK_v,	XK_V,
			  XK_leftdoublequotemark,	XK_grave }},
  {  56, 0,		{ XK_b,	XK_B,
			  XK_rightdoublequotemark,	XK_apostrophe }},
  {  57, 0,		{ XK_n,	XK_N }},
  {  58, 0,		{ XK_m,	XK_M,
			  XK_mu,	XK_masculine }},
  {  59, 0,		{ XK_comma,	XK_semicolon,
			  XK_horizconnector,	XK_multiply }},
  {  60, 0,		{ XK_period,	XK_colon,
			  XK_periodcentered,	XK_division }},
  {  61, 0,		{ XK_minus,	XK_underscore,
			  XK_dead_belowdot,	XK_dead_abovedot }},
  {  62, ShiftMask,	{ XK_Shift_R }},
  {  63, 0,		{ XK_KP_Multiply }},
  {  64, Mod1Mask,	{ XK_Meta_L }},
  {  65, 0,		{ XK_space }},
  {  66, LockMask,	{ XK_Caps_Lock }},
  {  67, 0,		{ XK_F1 }},
  {  68, 0,		{ XK_F2 }},
  {  69, 0,		{ XK_F3 }},
  {  70, 0,		{ XK_F4 }},
  {  71, 0,		{ XK_F5 }},
  {  72, 0,		{ XK_F6 }},
  {  73, 0,		{ XK_F7 }},
  {  74, 0,		{ XK_F8 }},
  {  75, 0,		{ XK_F9 }},
  {  76, 0,		{ XK_F10 }},
  {  77, Mod2Mask,	{ XK_Num_Lock,	XK_Pointer_EnableKeys }},
  {  78, Mod5Mask,	{ XK_Scroll_Lock }},
  {  79, 0,		{ XK_KP_Home,	XK_KP_7 }},
  {  80, 0,		{ XK_KP_Up,	XK_KP_8 }},
  {  81, 0,		{ XK_KP_Prior,	XK_KP_9 }},
  {  82, 0,		{ XK_KP_Subtract }},
  {  83, 0,		{ XK_KP_Left,	XK_KP_4 }},
  {  84, 0,		{ XK_KP_Begin,	XK_KP_5 }},
  {  85, 0,		{ XK_KP_Right,	XK_KP_6 }},
  {  86, 0,		{ XK_KP_Add }},
  {  87, 0,		{ XK_KP_End,	XK_KP_1 }},
  {  88, 0,		{ XK_KP_Down,	XK_KP_2 }},
  {  89, 0,		{ XK_KP_Next,	XK_KP_3 }},
  {  90, 0,		{ XK_KP_Insert,	XK_KP_0 }},
  {  91, 0,		{ XK_KP_Delete,	XK_KP_Decimal }},
  {  94, 0,		{ XK_less,	XK_greater,
			  XK_bar,	XK_brokenbar }},
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
  { 109, ControlMask,	{ XK_Multi_key }},
  { 110, 0,		{ XK_Pause,	XK_Break }},
  { 111, 0,		{ XK_Print,	XK_Execute }},
  { 112, 0,		{ XK_KP_Divide }},
  { 113, Mod3Mask,	{ XK_Mode_switch,	XK_Multi_key }},
  { 115, Mod4Mask,	{ XK_Super_L }},
  { 116, Mod4Mask,	{ XK_Super_R }},
  { 117, Mod5Mask,	{ XK_Hyper_R }}
  };
