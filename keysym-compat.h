/* xkeycaps, Copyright (c) 1991-1999 Jamie Zawinski <jwz@jwz.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 */

/* Various X systems differ in the contents of <X11/keysymdef.h>.
   This file defines all the "odd" the keysyms that we reference,
   so that compilation succeeds on oddball systems that don't
   define these already.
 */

#ifndef _XKEYCAPS_KEYSYM_COMPAT_H_
#define _XKEYCAPS_KEYSYM_COMPAT_H_

#ifndef  XK_usldead_grave
# define XK_usldead_grave		XK_dead_grave
#endif
#ifndef  XK_usldead_acute
# define XK_usldead_acute		XK_dead_acute
#endif
#ifndef  XK_usldead_asciicircum
# define XK_usldead_asciicircum		XK_dead_circumflex
#endif
#ifndef  XK_usldead_asciitilde
# define XK_usldead_asciitilde		XK_dead_tilde
#endif
#ifndef  XK_usldead_diaeresis
# define XK_usldead_diaeresis		XK_dead_diaeresis
#endif


/* Evidence suggests that Apollo makes a distinction between Page_Up and Prior
   whereas other systems do not (they have the same numeric value.)  But, some
   systems (notably SCO UnixWare 2) don't have the Page_Up alias for Prior.
   So, we need this to be able to compile on those systems.
 */
#ifndef  XK_KP_Page_Down
# define XK_KP_Page_Down		XK_KP_Next
#endif
#ifndef  XK_KP_Page_Up
# define XK_KP_Page_Up			XK_KP_Prior
#endif



#ifndef  XK_Greek_OMEGA
# define XK_Greek_OMEGA			0x07D9
#endif
#ifndef  XK_3270_DeleteWord
# define XK_3270_DeleteWord		0xFD1A
#endif
#ifndef  XK_ISO_Left_Tab
# define XK_ISO_Left_Tab		0xFE20
#endif
#ifndef  XK_dead_grave
# define XK_dead_grave			0xFE50
#endif
#ifndef  XK_dead_acute
# define XK_dead_acute			0xFE51
#endif
#ifndef  XK_dead_circumflex
# define XK_dead_circumflex		0xFE52
#endif
#ifndef  XK_dead_tilde
# define XK_dead_tilde			0xFE53
#endif
#ifndef  XK_dead_macron
# define XK_dead_macron			0xFE54
#endif
#ifndef  XK_dead_breve
# define XK_dead_breve			0xFE55
#endif
#ifndef  XK_dead_abovedot
# define XK_dead_abovedot		0xFE56
#endif
#ifndef  XK_dead_diaeresis
# define XK_dead_diaeresis		0xFE57
#endif
#ifndef  XK_dead_abovering
# define XK_dead_abovering		0xFE58
#endif
#ifndef  XK_dead_doubleacute
# define XK_dead_doubleacute		0xFE59
#endif
#ifndef  XK_dead_caron
# define XK_dead_caron			0xFE5A
#endif
#ifndef  XK_dead_cedilla
# define XK_dead_cedilla		0xFE5B
#endif
#ifndef  XK_dead_ogonek
# define XK_dead_ogonek			0xFE5C
#endif
#ifndef  XK_dead_belowdot
# define XK_dead_belowdot		0xFE60
#endif
#ifndef  XK_Pointer_EnableKeys
# define XK_Pointer_EnableKeys		0xFEF9
#endif
#ifndef  XK_Sys_Req
# define XK_Sys_Req			0xFF15
#endif
#ifndef  XK_KP_Home
# define XK_KP_Home			0xFF95
#endif
#ifndef  XK_KP_Left
# define XK_KP_Left			0xFF96
#endif
#ifndef  XK_KP_Up
# define XK_KP_Up			0xFF97
#endif
#ifndef  XK_KP_Right
# define XK_KP_Right			0xFF98
#endif
#ifndef  XK_KP_Down
# define XK_KP_Down			0xFF99
#endif
#ifndef  XK_KP_Prior
# define XK_KP_Prior			0xFF9A
#endif
#ifndef  XK_KP_Next
# define XK_KP_Next			0xFF9B
#endif
#ifndef  XK_KP_End
# define XK_KP_End			0xFF9C
#endif
#ifndef  XK_KP_Begin
# define XK_KP_Begin			0xFF9D
#endif
#ifndef  XK_KP_Insert
# define XK_KP_Insert			0xFF9E
#endif
#ifndef  XK_KP_Delete
# define XK_KP_Delete			0xFF9F
#endif
#ifndef  XK_usldead_acute
# define XK_usldead_acute		0x100000A8
#endif
#ifndef  hpXK_mute_acute
# define hpXK_mute_acute		0x100000A8
#endif
#ifndef  XK_usldead_grave
# define XK_usldead_grave		0x100000A9
#endif
#ifndef  hpXK_mute_grave
# define hpXK_mute_grave		0x100000A9
#endif
#ifndef  XK_usldead_asciicircum
# define XK_usldead_asciicircum		0x100000AA
#endif
#ifndef  hpXK_mute_asciicircum
# define hpXK_mute_asciicircum		0x100000AA
#endif
#ifndef  XK_usldead_diaeresis
# define XK_usldead_diaeresis		0x100000AB
#endif
#ifndef  hpXK_mute_diaeresis
# define hpXK_mute_diaeresis		0x100000AB
#endif
#ifndef  XK_usldead_asciitilde
# define XK_usldead_asciitilde		0x100000AC
#endif
#ifndef  hpXK_mute_asciitilde
# define hpXK_mute_asciitilde		0x100000AC
#endif
#ifndef  hpXK_lira
# define hpXK_lira			0x100000AF
#endif
#ifndef  hpXK_guilder
# define hpXK_guilder			0x100000BE
#endif
#ifndef  hpXK_Ydiaeresis
# define hpXK_Ydiaeresis		0x100000EE
#endif
#ifndef  hpXK_longminus
# define hpXK_longminus			0x100000F6
#endif
#ifndef  hpXK_block
# define hpXK_block			0x100000FC
#endif
#ifndef  XK_usldead_cedilla
# define XK_usldead_cedilla		0x1000FE2C
#endif
#ifndef  XK_usldead_ring
# define XK_usldead_ring		0x1000FEB0
#endif
#ifndef  DXK_Remove
# define DXK_Remove			0x1000FF00
#endif
#ifndef  TekXK_Remove
# define TekXK_Remove			0x1000FF00
#endif
#ifndef  TekXK_Hold
# define TekXK_Hold			0x1000FF10
#endif
#ifndef  TekXK_Copy
# define TekXK_Copy			0x1000FF11
#endif
#ifndef  TekXK_Setup
# define TekXK_Setup			0x1000FF12
#endif
#ifndef  TekXK_Setup
# define TekXK_Setup			0x1000FF12 /* Setup */
#endif
#ifndef  TekXK_SetUp
# define TekXK_SetUp			0x1000FF17 /* new Setup */
#endif
#ifndef  TekXK_SetUp
# define TekXK_SetUp			0x1000FF17 /* new setup */
#endif
#ifndef  hpXK_Reset
# define hpXK_Reset			0x1000FF6C
#endif
#ifndef  hpXK_System
# define hpXK_System			0x1000FF6D
#endif
#ifndef  hpXK_User
# define hpXK_User			0x1000FF6E
#endif
#ifndef  hpXK_ClearLine
# define hpXK_ClearLine			0x1000FF6F
#endif
#ifndef  hpXK_InsertLine
# define hpXK_InsertLine		0x1000FF70
#endif
#ifndef  hpXK_DeleteLine
# define hpXK_DeleteLine		0x1000FF71
#endif
#ifndef  hpXK_InsertChar
# define hpXK_InsertChar		0x1000FF72
#endif
#ifndef  hpXK_DeleteChar
# define hpXK_DeleteChar		0x1000FF73
#endif
#ifndef  hpXK_BackTab
# define hpXK_BackTab			0x1000FF74
#endif
#ifndef  hpXK_KP_BackTab
# define hpXK_KP_BackTab		0x1000FF75
#endif
#ifndef  TekXK_Tek
# define TekXK_Tek			0x1000FFFF
#endif
#ifndef  SunXK_Dead_Grave
# define SunXK_Dead_Grave		0x1005FF00 /* SunXK_FA_Grave? */
#endif
#ifndef  SunXK_Dead_Grave
# define SunXK_Dead_Grave		0x1005FF00
#endif
#ifndef  SunXK_FA_Grave
# define SunXK_FA_Grave			0x1005FF00 /* SunXK_Dead_Grave? */
#endif
#ifndef  SunXK_FA_Grave
# define SunXK_FA_Grave			0x1005FF00
#endif
#ifndef  SunXK_Dead_Circum
# define SunXK_Dead_Circum		0x1005FF01 /* SunXK_FA_Circum? */
#endif
#ifndef  SunXK_FA_Circum
# define SunXK_FA_Circum		0x1005FF01
#endif
#ifndef  SunXK_Dead_Tilde
# define SunXK_Dead_Tilde		0x1005FF02 /* SunXK_FA_Tilde? */
#endif
#ifndef  SunXK_FA_Tilde
# define SunXK_FA_Tilde			0x1005FF02
#endif
#ifndef  SunXK_FA_Acute
# define SunXK_FA_Acute			0x1005FF03
#endif
#ifndef  SunXK_FA_Diaeresis
# define SunXK_FA_Diaeresis		0x1005FF04
#endif
#ifndef  SunXK_F36
# define SunXK_F36			0x1005FF10
#endif
#ifndef  SunXK_F37
# define SunXK_F37			0x1005FF11
#endif
#ifndef  SunXK_Sys_Req
# define SunXK_Sys_Req			0x1005FF60
#endif
#ifndef  SunXK_Props
# define SunXK_Props			0x1005FF70
#endif
#ifndef  SunXK_Front
# define SunXK_Front			0x1005FF71
#endif
#ifndef  SunXK_Copy
# define SunXK_Copy			0x1005FF72
#endif
#ifndef  SunXK_Open
# define SunXK_Open			0x1005FF73
#endif
#ifndef  SunXK_Paste
# define SunXK_Paste			0x1005FF74
#endif
#ifndef  SunXK_Cut
# define SunXK_Cut			0x1005FF75
#endif
#ifndef  SunXK_PowerSwitch
# define SunXK_PowerSwitch		0x1005FF76
#endif
#ifndef  SunXK_AudioLowerVolume
# define SunXK_AudioLowerVolume		0x1005FF77
#endif
#ifndef  SunXK_AudioMute
# define SunXK_AudioMute		0x1005FF78
#endif
#ifndef  SunXK_AudioRaiseVolume
# define SunXK_AudioRaiseVolume		0x1005FF79
#endif
#ifndef  SunXK_VideoDegauss
# define SunXK_VideoDegauss		0x1005FF7A
#endif
#ifndef  SunXK_VideoLowerBrightness
# define SunXK_VideoLowerBrightness	0x1005FF7B
#endif
#ifndef  SunXK_VideoRaiseBrightness
# define SunXK_VideoRaiseBrightness	0x1005FF7C
#endif
#ifndef  SunXK_PowerSwitchShift
# define SunXK_PowerSwitchShift		0x1005FF7D
#endif
#ifndef  XK_SGI_Long_Compose
# define XK_SGI_Long_Compose		0x1007FF20
#endif
#ifndef  XK_XF86ModeLock
# define XK_XF86ModeLock		0x1008FF01
#endif
#ifndef  XK_dead_circumflex
# define XK_dead_circumflex		0x1800005E
#endif
#ifndef  XK_dead_grave
# define XK_dead_grave			0x18000060
#endif
#ifndef  XK_dead_tilde
# define XK_dead_tilde			0x1800007E
#endif
#ifndef  XK_dead_acute
# define XK_dead_acute			0x180000B4
#endif

#endif /* _XKEYCAPS_KEYSYM_COMPAT_H_ */
