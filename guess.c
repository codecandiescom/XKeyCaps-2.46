/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996, 1997
 * Jamie Zawinski <jwz@jwz.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 *
 *
 * TODO:
 *
 *  Ronan Waide points out that on certain NCD servers, "xprop -root" reveals:
 *
 *        _NCD_KEYBOARD_TYPE(STRING) = "N-107 US"
 *
 *  It would be good if we noticed that and acted on it.
 */

#include <stdio.h>
#include <string.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include "KbdWidgetP.h"
#include "KeyWidgetP.h"

#include "kbddef.h"

/* Strict versus relaxed ANSI modes tend to be random about these... */
#if defined (__unix) && !defined(unix)
# define unix
#endif
#if defined (__hpux) && !defined(hpux)
# define hpux
#endif
#if defined (__sun) && !defined(sun)
# define sun
#endif

#if defined(sun) || defined(hpux)
# include <netdb.h>
static int display_is_on_console_p P((Display*));
#endif

static char *guess_tek_keyboard_type P((Display*));
static char *tek_kbd_type, *tek_kbd_layout, *tek_kbd_nationality;
static char *tek_kbd_lk401;

extern void make_long_kbd_name P((const char *, const char *, char *));

void
print_kbd_choices P((void))
{
  int i = 0;
  char buf[255];
  while (all_kbds [i].short_name)
    {
      make_long_kbd_name(all_kbds[i].vendor, all_kbds[i].kbd_style, buf);
      fprintf (stderr, "    %s%s\t- %s\n",
	       all_kbds [i].short_name,
	       (strlen (all_kbds [i].short_name) < 4 ? "\t" : ""),
	       buf);
      i++;
    }
}

/* Make sure nobody messed up the data in all-kbds.h... */
static void
check_kbds P((void))
{
  int i = 0;
  char this[255], that[255];
  while (all_kbds [i].short_name)
    {
      int j = i + 1;
      make_long_kbd_name(all_kbds[i].vendor, all_kbds[i].kbd_style, this);
      while (all_kbds [j].short_name)
	{
	  const char *loser1 = 0, *loser2 = 0;
	  make_long_kbd_name(all_kbds[j].vendor, all_kbds[j].kbd_style, that);
	  if (!strcmp (all_kbds [i].short_name, all_kbds [j].short_name))
	    loser1 = "short names", loser2 = all_kbds [j].short_name;
	  else if (!strcmp (this, that))
	    loser1 = "long names", loser2 = strdup(that);
	  else if (all_kbds [i].server_id && all_kbds [j].server_id &&
		   !strcmp (all_kbds [i].server_id, all_kbds [j].server_id))
	    loser1 = "server ids", loser2 = all_kbds [j].server_id;
	  j++;

	  if (loser1)
	    fprintf (stderr,
		     "%s: DATA ERROR: duplicate %s in all-kbds.h for \"%s\"\n",
		     progname, loser1, loser2);
	}
      i++;
    }
}


#define strprefix(target,prefix)				\
      ((strlen ((target)) >= strlen ((prefix))) &&		\
       !(strncmp ((target), (prefix), strlen ((prefix)))))


char choose_kbd_message [2048];
int choose_kbd_dubious_p;

const struct keyboard_instance *
#ifdef __STDC__
choose_kbd (Display *dpy, const char *kbd_name)
#else /* ! __STDC__ */
choose_kbd (dpy, kbd_name)
     Display *dpy;
     const char *kbd_name;
#endif /* ! __STDC__ */
{
  char *vendor = XServerVendor (dpy);
  tek_kbd_type = 0;
  tek_kbd_layout = 0;
  tek_kbd_nationality = 0;
  tek_kbd_lk401 = 0;

  choose_kbd_message [0] = 0;
  choose_kbd_dubious_p = 0;

  check_kbds ();

#ifdef sun
  if ((!kbd_name || !*kbd_name) &&
      display_is_on_console_p (dpy) &&
      (kbd_name = xkeycaps_guess_local_keyboard_type ()))
    {
      /* evil hack - append "OW" to the default keyboard name if
	 running OpenWindows, since the default keymaps are different.
	 Likewise for R6, since the default keymaps AND keycodes have
	 changed there!  Arrrrgh!
       */
      char *suffix = 0;
      if (!strcmp (vendor, "X11/NeWS - Sun Microsystems Inc.") ||
	  /* The vendor ID changed in OpenWound 3.4. */
	  !strcmp(vendor, "Sun Microsystems, Inc."))
 	suffix = "OW";
      else if (!strcmp (vendor, "X Consortium"))
	/* In R6, the vendor id is "X Consortium".
	   In R4 and R5, it was "MIT X Consortium". */
	suffix = "R6";

      if (suffix)
	{
	  int L = strlen (kbd_name);
	  char *s = (char *) calloc (L + 4, 1);
	  strncpy (s, kbd_name, L);
	  if (L > 6) strcat (s + L, "-");
	  strcat (s + L, suffix);
	  kbd_name = s;
	}
      sprintf (choose_kbd_message,
	       "\nkeyboard hardware claims to be \"%s\".\n",
	       /*progname,*/ kbd_name);
    }
  else
#endif /* sun */

#ifdef hpux
  if ((!kbd_name || !*kbd_name) &&
      display_is_on_console_p (dpy) &&
      (kbd_name = xkeycaps_guess_local_keyboard_type ()))
    {
      /* we're done */ ;
    }
  else
#endif /* hpux */

  if (!kbd_name || !*kbd_name)
    {
      kbd_name = 0;

      if (strprefix (vendor, "Tektronix, Inc"))
	/* Tek cleverly tells us what the keyboard is via X properties. */
	kbd_name = guess_tek_keyboard_type (dpy);

      else
	{
	  /* Search all_kbds for an instance that matches the vendor id. */
	  int i = 0;
	  const struct keyboard_instance *kbd;

	  while ((kbd = &all_kbds [i++]), kbd->short_name)
	    if (kbd->server_id && strprefix (vendor, kbd->server_id))
	      break;

	  kbd_name = kbd->short_name;
	}

      if (kbd_name)
	{
	  char *out = choose_kbd_message;
	  choose_kbd_dubious_p = 1;
	  sprintf (out,
 "\nA keyboard type was not specified.  Based on the vendor\n\
 identification string of the display \"%s\", which is\n \"%s\"\n",
		   /* progname, */ DisplayString (dpy), vendor);
	  out += strlen (out);
	  if (tek_kbd_type && tek_kbd_lk401 && tek_kbd_nationality)
	    sprintf (out,
 " and the root window's _TEK_KEYBOARD_TYPE, _TEK_KEYBOARD_LK401, and\n\
 _TEK_KEYBOARD_NATIONALITY properties, which are %s, %s, and %s,\n",
		     tek_kbd_type, tek_kbd_lk401, tek_kbd_nationality);
	  else if (tek_kbd_type && tek_kbd_lk401)
	    sprintf (out,
 " and the root window's _TEK_KEYBOARD_TYPE, _TEK_KEYBOARD_LK401\n\
  properties, which are %s and %s,\n",
		     tek_kbd_type, tek_kbd_lk401);
	  else if (tek_kbd_type && tek_kbd_layout && tek_kbd_nationality)
	    sprintf (out,
 " and the root window's _TEK_KEYBOARD_TYPE, _TEK_KEYBOARD_LAYOUT, and\n\
 _TEK_KEYBOARD_NATIONALITY properties, which are %s, %s, and %s,\n",
		     tek_kbd_type, tek_kbd_layout, tek_kbd_nationality);
	  else if (tek_kbd_type && tek_kbd_layout)
	    sprintf (out, " and the root window's _TEK_KEYBOARD_TYPE\
 and _TEK_KEYBOARD_LAYOUT\n properties, which are \"%s\" and \"%s\",\n",
		     tek_kbd_type, tek_kbd_layout);
	  else if (tek_kbd_type)
	    sprintf (out, " and the root window's _TEK_KEYBOARD_TYPE\
 property, which is \"%s\",\n",
		     tek_kbd_type);
	  out += strlen (out);
	  sprintf (out,
	    " we will assume that you are using a keyboard of type \"%s\".",
		   kbd_name);
	}
#ifdef DEFAULT_KBD_NAME
      else
	{
	  kbd_name = DEFAULT_KBD_NAME;
	  if (kbd_name)
	    {
	      choose_kbd_dubious_p = 1;
	      sprintf (choose_kbd_message,
 "\nA keyboard type was not specified, and the vendor ID string,\n\
 \"%s\"\n\
 is not recognised.  We will guess that you are using a keyboard of\n\
 type \"%s\".",
		       /* progname, */ vendor, kbd_name);
	    }
	}
#endif
    }

  {
    int i = 0;
    const struct keyboard_instance *kbd;

    while ((kbd = &all_kbds [i++]), kbd->short_name)
      {
	char buf[255];
	if (string_equal (kbd_name, kbd->short_name))
	  return kbd;
	make_long_kbd_name(kbd->vendor, kbd->kbd_style, buf);
	if (string_equal (kbd_name, buf))
	  return kbd;
      }

    choose_kbd_dubious_p = 1;

    fprintf (stderr, "%s: unknown keyboard type \"%s\".\n\
Please specify the -keyboard option with one of the following names:\n\n",
	     progname, (kbd_name ? kbd_name : ""));

    print_kbd_choices ();
    exit (-1);
  }
}

#if defined(sun) || defined(hpux)

static int
#ifdef __STDC__
display_is_on_console_p (Display *display)
#else /* ! __STDC__ */
display_is_on_console_p (display)
     Display *display;
#endif /* ! __STDC__ */
{
  int not_on_console = 1;
  char *dpy = DisplayString (display);
  char *tail = (char *) strchr (dpy, ':');
  if (! tail || strncmp (tail, ":0", 2))
    not_on_console = 1;
  else
    {
      char dpyname[255], localname[255];
      strncpy (dpyname, dpy, tail-dpy);
      dpyname [tail-dpy] = 0;
      if (!*dpyname ||
	  !strcmp(dpyname, "unix") ||
	  !strcmp(dpyname, "localhost"))
	not_on_console = 0;
      else if (gethostname (localname, sizeof (localname)))
	not_on_console = 1;  /* can't find hostname? */
      else
	{
	  /* We have to call gethostbyname() on the result of gethostname()
	     because the two aren't guarenteed to be the same name for the
	     same host: on some losing systems, one is a FQDN and the other
	     is not.  Here in the wide wonderful world of Unix it's rocket
	     science to obtain the local hostname in a portable fashion.
	     
	     And don't forget, gethostbyname() reuses the structure it
	     returns, so we have to copy the fucker before calling it again.
	     Thank you master, may I have another.
	   */
	  struct hostent *h = gethostbyname (dpyname);
	  if (!h)
	    not_on_console = 1;
	  else
	    {
	      char hn [255];
	      struct hostent *l;
	      strcpy (hn, h->h_name);
	      l = gethostbyname (localname);
	      not_on_console = (!l || !!(strcmp (l->h_name, hn)));
	    }
	}
    }
  return !not_on_console;
}

#endif /* sun || hpux */


static char *
#ifdef __STDC__
get_prop_string (Display *dpy, char *prop)
#else /* ! __STDC__ */
get_prop_string (dpy, prop)
    Display *dpy;
     char *prop;
#endif /* ! __STDC__ */
{
  Atom prop_atom;
  unsigned char *value;
  Boolean status;
  Atom actual_type;
  int actual_format;
  unsigned long nitems, bytes_after;

  prop_atom = XInternAtom (dpy, prop, True);
  if (prop_atom == None)
    return 0;
  status = XGetWindowProperty (dpy, DefaultRootWindow (dpy), prop_atom,
			       0L, 6L, False, XA_STRING, &actual_type,
			       &actual_format, &nitems, &bytes_after,
			       &value);
  if (status != Success || value == 0 || actual_type != XA_STRING ||
      actual_format != 8 || bytes_after != 0)
    return 0;
  else
    return (char *) value;
}

static char *
#ifdef __STDC__
guess_tek_keyboard_type (Display *dpy)
#else /* ! __STDC__ */
guess_tek_keyboard_type (dpy)
    Display *dpy;
#endif /* ! __STDC__ */
{
  /* Tek stores the keyboard type on a property on the root window.
     The _TEK_KEYBOARD_TYPE property is ibm101, ibm102, or vt200.
     If _TEK_KEYBOARD_TYPE is vt200, then _TEK_KEYBOARD_LAYOUT is
     ultrix, vms, x_esc, or x_f11. Also, _TEK_KEYBOARD_NATIONALITY
     is usascii, uk, french, swedish, danish, norwegian, german,
     italian, spanish, swiss-german, katakana, or finnish.
     There is also _TEK_KEYBOARD_LK401 which is used to identify
     the LK401-style keyboards.
   */
  char buf [255];
  tek_kbd_type = get_prop_string (dpy, "_TEK_KEYBOARD_TYPE");

  if (!tek_kbd_type || !strcmp (tek_kbd_type, "ibm101"))
    {
      /* the default keymap changed between release 4 and release 5. */
      if (VendorRelease(dpy) <= 4) return "TEK101-4";
      return "TEK101";
    }
  else if (!strcmp (tek_kbd_type, "ibm102"))
    return "TEK102";
  else if (!strcmp (tek_kbd_type, "unix"))
    return "TEKsun4";		      /* So Robert Zwickenpflug says... */
  else if (!strcmp (tek_kbd_type, "vt200"))
    {
      tek_kbd_layout = get_prop_string (dpy, "_TEK_KEYBOARD_LAYOUT");
      tek_kbd_nationality = get_prop_string (dpy, "_TEK_KEYBOARD_NATIONALITY");
      tek_kbd_lk401 = get_prop_string (dpy, "_TEK_KEYBOARD_LK401");

      if (tek_kbd_lk401)
	{
	  if (!tek_kbd_nationality)                          return "TEK401US";
	  else if (!strcmp (tek_kbd_nationality, "swedish")) return "TEK401SF";
	  else                                               return "TEK401US";
	}
      else if (!tek_kbd_layout)
	return "TEK200";
      else if (!strcmp (tek_kbd_layout, "x_esc"))
	return "TEK200ESC";
      else if (!strcmp (tek_kbd_layout, "x_f11"))
	return "TEK200F11";
      else if (!strcmp (tek_kbd_layout, "vms"))
	return "TEK200VMS";
      else if (!strcmp (tek_kbd_layout, "ultrix"))
	{
	  char *n = tek_kbd_nationality;
	  if (! n)				return "TEK200US";
	  else if (!strcmp (n, "usascii"))	return "TEK200US";
	  else if (!strcmp (n, "danish"))	return "TEK200DA";
	  else if (!strcmp (n, "german"))	return "TEK200DE";
	  else if (!strcmp (n, "finnish"))	return "TEK200FI";
	  else if (!strcmp (n, "french"))	return "TEK200FR";
	  else if (!strcmp (n, "italian"))	return "TEK200IT";
	  else if (!strcmp (n, "katakana"))	return "TEK200KA";
	  else if (!strcmp (n, "norwegian"))	return "TEK200NO";
	  else if (!strcmp (n, "spanish"))	return "TEK200SP";
	  else if (!strcmp (n, "swedish"))	return "TEK200SW";
	  else if (!strcmp (n, "swiss-german"))	return "TEK200SWDE";
	  else if (!strcmp (n, "uk"))		return "TEK200UK";
	  else
	    {
	      /* some otherwise unknown nationality... */
	      char *s;
	      sprintf (buf, "TEK200_%s", tek_kbd_nationality);
	      s = (char *) malloc (strlen (buf) + 1);
	      strcpy (s, buf);
	      return s;
	    }
	}
      else
	{
	  /* some otherwise unknown layout... */
	  char *s;
	  sprintf (buf, "TEK200_%s", tek_kbd_layout);
	  s = (char *) malloc (strlen (buf) + 1);
	  strcpy (s, buf);
	  return s;
	}
    }
  else
    {
      char *s;
      /* some otherwise unknown type of keyboard... */
      sprintf (buf, "TEK_%s", tek_kbd_type);
      s = (char *) malloc (strlen (buf) + 1);
      strcpy (s, buf);
      return s;
    }
}
