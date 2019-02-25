/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1996, 1997
 *  Jamie Zawinski <jwz@jwz.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 */

#ifndef _XKEYCAPS_H_
#define _XKEYCAPS_H_

#ifdef __STDC__
# include <stdlib.h>
# include <memory.h>
#endif

#ifndef __STDC__
# undef const
# define const /**/
#endif

# undef P
#ifdef __STDC__
# define P(x)x
#else
# define P(x)()
#endif


/* from xkeycaps.c
 */
extern char *progname;
extern char *version;
extern char *short_version;
extern Window XSendEvent_BadWindow;
extern void xkeycaps_DispatchEvent_hook P((KeyboardWidget, XEvent *event));
extern void replace_keyboard P((KeyboardWidget keyboard, const char *name));

/* from guess.c
 */
extern int choose_kbd_dubious_p;
extern char choose_kbd_message[];
extern const struct keyboard_instance *choose_kbd P((Display *dpy,
						     const char *kbd_name));
void print_kbd_choices P((void));


/* from commands.c
 */
extern struct key_menus *make_key_menus P((KeyboardWidget *));
extern Widget make_command_widgets P((Widget parent, Widget *kbd));
extern int string_equal P((const char *, const char *));
extern void sensitize_menu P((KeyboardWidget, Widget menu, Bool sensitive));
extern void pop_up_kbd_dbox P((Widget, XtPointer, XtPointer));
extern KeyWidget prompt_for_key P((KeyboardWidget, char *msg));

/* from actions.c
 */
extern int mappingNotify_event_expected;
extern void highlight_key_action P((Widget, XEvent *, String *, Cardinal *));
extern void unhighlight_key_action P((Widget, XEvent *, String *, Cardinal *));
extern void toggle_key_action P((Widget, XEvent *, String *, Cardinal *));
extern void simulate_KeyPress_action P((Widget, XEvent*, String*, Cardinal*));
extern void simulate_KeyRelease_action P((Widget, XEvent*, String*,Cardinal*));
extern void describe_key_action P((Widget, XEvent *, String *, Cardinal *));
extern void track_key_action P((Widget, XEvent *, String *, Cardinal *));
extern void untrack_key_action P((Widget, XEvent *, String *, Cardinal *));
extern void key_menu_pre_popup_hook P((Widget menu, XtPointer client_data,
				       XtPointer call_data));
extern void keyboard_track_motion_hook P((Widget, XtPointer, String, XEvent *,
					  String *, Cardinal *));

extern void key_to_event P((KeyWidget key, XEvent *event, int down_p));
extern void keyboard_handle_mapping_notify P((Widget widget,
					      XtPointer client_data,
					      XEvent *event,
					      Boolean *cont));
extern void keyboard_handle_keymap_notify P((Widget widget,
					     XtPointer client_data,
					     XEvent *event,
					     Boolean *cont));
extern KeyWidget window_to_key P((Display *dpy, Window window));
extern KeyWidget keycode_to_key P((KeyboardWidget keyboard, KeyCode code));
extern void init_modifier_mapping P((KeyboardWidget widget));

/* from info.c
 */
extern struct info_labels *make_info_widget P((Widget parent,
					       Widget parent_left));
extern Widget make_label_1 P((Widget parent, char *name, char *string,
			      Widget left, Widget top, WidgetClass class,
			      XtCallbackProc callback, XtPointer data));
extern Widget make_label P((Widget parent, char *name, char *string,
			    Widget left, Widget top));
extern void message P((KeyboardWidget, char *));
extern void message2 P((KeyboardWidget, char *));
extern void describe_key P((KeyWidget));

/* from KbdWidget.c
 */
extern void create_icon_pixmaps P((Display *));
extern Pixmap get_keyboard_icon P((Display *dpy,
				   const struct keyboard_instance *kbd,
				   int *wP, int *hP));

/* from sunOS.c or hpux.c
 */
#if defined(sun) || defined(hpux)
extern char *xkeycaps_guess_local_keyboard_type P((void));
#endif



/* When we have to guess, and haven't a clue.
   The Imakefile can define this to be 0, to make there be no default.
 */
#ifndef DEFAULT_KBD_NAME
# define DEFAULT_KBD_NAME "L101"
#endif

#endif /* _XKEYCAPS_H_ */
