/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1996, 1997
 * by Jamie Zawinski <jwz@jwz.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 */

/* SunOS-specific stuff: if we're on console, we can query the keyboard
   hardware directly to find out what kind it is.  I would have just put
   this code in guess.c, but vuid_event.h defines a `struct keyboard' 
   that conflicts with our own...
 */

#if defined(__sun) || defined(sun)	/* whole file */

#ifdef __STDC__
#include <stdlib.h>
#include <unistd.h>
extern char *strdup (const char *);
#endif

#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/time.h>
#include <sys/stream.h>
#include <sys/stropts.h>
#include <sys/fcntl.h>
#include <sys/ioctl.h>

#ifdef SVR4
# include <sys/vuid_event.h>
# include <sys/kbio.h>
# include <sys/kbd.h>
# include <sys/systeminfo.h>
#else
# include <sundev/vuid_event.h>
# include <sundev/kbio.h>
# include <sundev/kbd.h>
#endif

char *
xkeycaps_guess_local_keyboard_type ()
{
  int type = -1, layout = 0;
  int kbdfd;

  /* Opening of /dev/kbd on Solaris/Intel fail because it doesn't
     exist. However, we can guess the keyboard if the machine sysinfo
     returns i86pc.  -- Dave Carrigan */
#ifdef SVR4
  {
    char mach[16];
    if (sysinfo(SI_MACHINE, mach, 16) < 0)
      {
	perror("sysinfo");
	return 0;
      }
    if (!strncmp(mach, "i86pc", 5))
      return "OW101";
    if (!strncmp(mach, "prep", 4))
      return "prep";
  }
#endif

  if ((kbdfd = open ("/dev/kbd", O_WRONLY)) <= 0)
    return 0;

  /* See /usr/man/man4/kb.4m on SunOS 4.1.3 */

  if (ioctl (kbdfd, KIOCTYPE, &type))
    {
      close (kbdfd);
      return 0;
    }
  ioctl (kbdfd, KIOCLAYOUT, &layout);
  close (kbdfd);
  switch (type) {
  case -1:	  return 0;
  case KB_ASCII:  return "SunASCII";	/* Ascii terminal */
  case KB_KLUNK:  return "MS103SD32-2";	/* Micro Switch 103SD32-2 */
  case KB_VT100:  return "SunVT100";	/* Keytronics VT100 compatible */
  case KB_VT220:  return "SunVT220";	/* vt220 Emulation */
  case KB_VT220I: return "SunVT220i";	/* International vt220 Emulation */
  case KB_SUN2:   return "Sun2";
  case KB_SUN3:   return "Sun3";
  case KB_SUN4:
    switch (layout) {
    case  0: return "Sun4"; /* Part 320-1005-02 REV A. */
    case  1: return "Sun4"; /* Part 320-1005-01 REV B.  Seems identical... */

    case  2: return "Sun4FR";			/* French/Belgian */
    case  3: return "Sun4CA";			/* Canadian	*/
    case  4: return "Sun4DK";			/* Danish	*/
    case  5: return "Sun4DE";			/* German	*/
    case  6: return "Sun4IT";			/* Italian	*/
    case  7: return "Sun4DU";			/* Dutch	*/
    case  8: return "Sun4NO";			/* Norwegian	*/
    case  9: return "Sun4PO";			/* Portuguese	*/
    case 10: return "Sun4ES";			/* Spanish	*/
    case 11: return "Sun4SW";			/* Swedish/Finnish */
    case 12: return "Sun4SWFR";			/* Swiss/French	*/
    case 13: return "Sun4SWDE";			/* Swiss/German	*/
    case 14: return "Sun4UK";			/* UK		*/
      /* 15 unknown */
    case 16: return "Sun4KO";			/* Korean	*/
    case 17: return "Sun4TA";			/* Taiwanese	*/
      /* 18 unknown */
    case 19: return "Sun101A";			/* US		*/
      /* The Sun101A was apparently an early version
	 of the Sun5 kbd: it didn't last very long. */
      /* 20-31 unknown */
    case 32: return "Sun4JA";			/* Japanese	*/

      /* It appears that there is no such keyboard as (for example) Sun5PCDE,
	 or any non-US version of the sun5PC keyboard.  I guess non-US versions
	 only exist for the Sun5 keyboard.  This is odd, but it looks like the
	 stuff in /usr/share/lib/keytables/ doesn't provide for that
	 possibility either. */

    case 33: return "Sun5PC";			/* US		*/
    case 34: return "Sun5";			/* US		*/
    case 35: return "Sun5FR";			/* French	*/
    case 36: return "Sun5DA";			/* Danish	*/
    case 37: return "Sun5DE";			/* German	*/
    case 38: return "Sun5IT";			/* Italian	*/
    case 39: return "Sun5DU";			/* Dutch	*/
    case 40: return "Sun5NO";			/* Norwegian	*/
    case 41: return "Sun5PO";			/* Portuguese	*/
    case 42: return "Sun5ES";			/* Spanish	*/
    case 43: return "Sun5SW";			/* Swedish	*/
    case 44: return "Sun5SWFR";			/* Swiss/French	*/
    case 45: return "Sun5SWDE";			/* Swiss/German	*/
    case 46: return "Sun5UK";			/* UK		*/
    case 47: return "Sun5KO";			/* Korean	*/
    case 48: return "Sun5TA";			/* Taiwanese	*/
    case 49: return "Sun5JA";			/* Japanese	*/
    default:
      {
	char buf [255];
	sprintf (buf, "Sun4_%d", layout);
	return strdup (buf);
      }
    }
  default:
    {
      char buf [255];
      if (layout)
	sprintf (buf, "Sun_%d_%d", type, layout);
      else
	sprintf (buf, "Sun_%d", type);
      return strdup (buf);
    }
  }
}


#ifdef DEBUG
void
main ()
{
  printf ("%s\n", xkeycaps_guess_local_keyboard_type ());
  exit (0);
}
#endif /* DEBUG */


#endif /* __sun	*/
