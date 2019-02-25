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

/* HPUX-specific stuff: if we're on console, we can query the keyboard
   hardware directly to find out what kind it is (assuming HIL driver.)
   By Rens Troost, derived from sunOS.c.

   If the HIL device can't be opened, try to get the keyboard type and
   language from /etc/kbdlang (it's probably a PS-DIN-style keyboard then)
   and return the name with a prefix of "HP-".
   By Michael Piotrowski <mxp@linguistik.uni-erlangen.de> 1997-05-29
 */

#ifdef _HPUX_SOURCE	/* whole file */

#ifdef __STDC__
#include <stdlib.h>
#include <unistd.h>
extern char *strdup (const char *);
#endif

#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/ioctl.h>

#include <sys/hilioctl.h>

#undef P
#ifdef __STDC__
# define P(x)x
#else
# define P(x)()
#endif

char *
xkeycaps_guess_local_keyboard_type P((void))
{
  int kbdfd;
  int arg1 = -1, arg2 = 0;
  char buf [255];
  char idcode  = -1;
  char language = 0;

  if ((kbdfd = open ("/dev/hilkbd", O_WRONLY)) <= 0)
    {
      FILE *kbdlangfile = fopen("/etc/kbdlang", "r");
      if (!kbdlangfile)
	return 0;
      strcpy (buf, "HP-");
      fgets (buf + strlen(buf), sizeof(buf), kbdlangfile);
      fclose (kbdlangfile);
      return strdup(buf);
    }

  if (ioctl (kbdfd, KBD_READ_LANGUAGE, &language))
    {
      close (kbdfd);
      return 0;
    }
  ioctl (kbdfd, KBD_READ_CONFIG, &idcode);
  idcode &= KBD_IDCODE_MASK;
  
  close (kbdfd);
  
  switch (idcode)
    {
    case KBD_IDTYPE_ITF:
      switch (language)
	{
	case KBD_JAPANESE:	   return "HP-ITF-Japanese";
	case KBD_SWISS_FRENCH:	   return "HP-ITF-Swiss/French";
	case KBD_PORTUGESE:	   return "HP-ITF-Portugese";
	case KBD_ARABIC:	   return "HP-ITF-Arabic";
	case KBD_HEBREW:	   return "HP-ITF-Hebrew";
	case KBD_CANADIAN_ENGLISH: return "HP-ITF-Canadian/English";
	case KBD_TURKISH:	   return "HP-ITF-Turkish";
	case KBD_GREEK:		   return "HP-ITF-Greek";
	case KBD_THAI:		   return "HP-ITF-Thai";
	case KBD_ITALIAN:	   return "HP-ITF-Itailan";
	case KBD_HANGUL:	   return "HP-ITF-Hangul";
	case KBD_DUTCH:		   return "HP-ITF-Dutch";
	case KBD_SWEDISH:	   return "HP-ITF-Swedish";
	case KBD_GERMAN:	   return "HP-ITF-German";
	case KBD_CHINESE_PRC:	   return "HP-ITF-Chinese/PRC";
	case KBD_CHINESE_ROC:	   return "HP-ITF-Chinese/ROC";
	case KBD_SWISS_FRENCH_II:  return "HP-ITF-Swiss/French-2";
	case KBD_SPANISH:	   return "HP-ITF-Spanish";
	case KBD_SWISS_GERMAN_II:  return "HP-ITF-Swiss/German-2";
	case KBD_BELGIAN:	   return "HP-ITF-Belgian";
	case KBD_FINNISH:	   return "HP-ITF-Finnish";
	case KBD_UNITED_KINGDOM:   return "HP-ITF-UK";
	case KBD_FRENCH_CANADIAN:  return "HP-ITF-French/Canadian";
	case KBD_SWISS_GERMAN:	   return "HP-ITF-Swiss/German";
	case KBD_NORWEGIAN:	   return "HP-ITF-Norwegian";
	case KBD_FRENCH:	   return "HP-ITF-French";
	case KBD_DANISH:	   return "HP-ITF-Danish";
	case KBD_KATAKANA:	   return "HP-ITF-Katakana";
	case KBD_LATIN_AMERICAN:   return "HP-ITF-Latin-American";
	case KBD_UNITED_STATES:	   return "HP-ITF";
	  /* ####  Unfortunately, the HPPC keyboard reports itself as
	     ####  a KBD_IDTYPE_ITF/KBD_UNITED_STATES, which is totally
	     ####  inappropriate, since it is *not* the same keyboard!!
	   */
	default:
	  sprintf (buf, "HP-ITF-%d", language);
	  return strdup (buf);
	}
    case KBD_IDTYPE_98203C:
      switch (language)
	{
	case KBD_98203C_UNITED_STATES:	return "HP-98203C";
	case KBD_98203C_FRENCHQ:	return "HP-98203C-FrenchQ";
	case KBD_98203C_GERMAN:		return "HP-98203C-German";
	case KBD_98203C_FINNISH:	return "HP-98203C-Finnish";
	case KBD_98203C_SPANISH:	return "HP-98203C-Spanish";
	case KBD_98203C_KATAKANA:	return "HP-98203C-Katakana";
	case KBD_98203C_FRENCHA:	return "HP-98203C-FrenchA";
	default:
	  sprintf (buf, "HP-98203C-%d", language);
	  return strdup (buf);
	}
    default:
      if (language)
	sprintf (buf, "HP-%d-%d", idcode, language);
      else
	sprintf (buf, "HP-%d", idcode);
      return strdup (buf);
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


#endif /* _HPUX_SOURCE */
