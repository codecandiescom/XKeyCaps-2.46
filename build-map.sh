#!/bin/sh
#
# xkeycaps, Copyright (c) 1991, 1992, 1993, 1996, 1997
#  Jamie Zawinski <jwz@jwz.org>
#
# Permission to use, copy, modify, distribute, and sell this software and its
# documentation for any purpose is hereby granted without fee, provided that
# the above copyright notice appear in all copies and that both that
# copyright notice and this permission notice appear in supporting
# documentation.  No representations are made about the suitability of this
# software for any purpose.  It is provided "as is" without express or 
# implied warranty.
#
#               *********************************************
#               *                                           *
#               *                   ALERT!                  *
#               *                                           *
#               *     Have you read "defining.txt" yet?     *
#               *     Please do, before adding a new        *
#               *     keyboard description to xkeycaps.     *
#               *     It will make my life much easier!     *
#               *                                           *
#               *                                           *
#               *********************************************
#
# This parses the output of xmodmap to automatically generate *-map.h files
# which encode the current keyboard state in the format the the xkeycaps
# source requires.  Be certain you are running this on a virgin keymap; you
# don't want to encode a modified keymap into the xkeycaps source.

NAME=$1

if [ "x$NAME" = "x" ]; then
  NAME=FOO
fi

echo "static const struct default_keycode_map ${NAME}_map [] = {"

( xmodmap -pm ; echo "======" ; xmodmap -pk ) |
sed 's/(no name)/(UNKNOWN_KEYSYM)/' |
awk '
  BEGIN {
	  parsing_mods = 1;
	}
  {
    # First parse the output of "xmodmap -pm", and fill the "bits" table
    # with keysym/maskname pairs for those keycodes with modifier bits.
    # (Its not quite right that we index off of syms instead of codes
    # but I dont feel writing a parser for hex numbers right now...)
    if (parsing_mods)
    {
      if ( $0 ~ /^======$/ )
      { 
        parsing_mods = 0;
      }
      else if ( $0 ~ /^shift|lock|control|mod[1-5]/ )
      {
        for (i = 2; i <= NF; i+=2)
	 {
	   L = length ($1);
	   if ( $0 ~ /^shift/ ) { M = "ShiftMask"; }
	   else if ( $0 ~ /^lock/ ) { M = "LockMask"; }
	   else if ( $0 ~ /^control/ ) { M = "ControlMask"; }
	   else if ( $0 ~ /^mod/ ) { M = "Mod" substr($0,4,1) "Mask"; }
	   else { M = "????"; }
	   bits [ $i ] = M;
	 }
      }
      else if ( NF == 0 || $0 ~ / keys per modifier, / )
      {
      }
      else
      {
        printf "  /* %s */\n", $0;
      }
    }
    #
    # Now reformat the output of "xmodmap -pk"
    # If we dont recognise a line, print it inside of /* */.
    #
    else if ( $0 ~ /^[ \t]*[0-9][0-9]*[ \t][ \t]*$/ ) { }
    else if ( $0 ~ /^[ \t]*[0-9][0-9]*[ \t]/ )
    {
       printf "  { %3d, ", $1;

       # Look in the "bits" table for the modifier bit masks to print here.
       this_sym = substr ($3, 2, length($3) - 2);
       this_bits = bits [ this_sym ];
       if ( this_bits == 0 ) { printf "0,\t"; }
       else { printf "%s,", this_bits; }

       # Print out the keysyms of this keycode, with commas as appropriate.
       for (i = 3; i <= NF; i+=2) 
	{ 
	  if (i == 7) { printf "\n\t\t"; }
	  keysym = substr ($i, 2, length($i) - 2);
	  printf "\t";
	  if ( i == 7) { printf "  "; }
	  if ( i == 3) { printf "{ "; }
	  # Print "NoSymbol" as "0" instead "XK_NoSymbol".
	  if (keysym == "NoSymbol" )
             { printf "0"; }
	  # Print "hpFooBar" as "hpXK_FooBar" instead of "XK_hpFooBar".
	  else if ( keysym ~ /^hp/ )
             { keysym = substr (keysym, 3, length(keysym));
               printf "hpXK_%s", keysym; }
	  # Print "SunFoo" as "SunXK_Foo" instead of "XK_SunFoo".
	  else if ( keysym ~ /^Sun/ )
             { keysym = substr (keysym, 4, length(keysym));
               printf "SunXK_%s", keysym; }
	  # Sigh... print "apLineDel" as "DXK_Remove" and
	  # "apSave" as "TekXK_Setup"...
	  else if ( keysym ~ /^apLineDel$/ )
             { printf "DXK_Remove"; }
	  else if ( keysym ~ /^apSave$/ )
             { printf "TekXK_Setup"; }
	  else
             { printf "XK_%s", keysym; }
	  if (i < NF) printf ",";
	}
       printf " }},\n";
    }
    else if (NF == 0 \
	     || $0 ~ /^There are [0-9]* KeySyms per KeyCode/ \
	     || $0 ~ /^[ \t]*KeyCode[ \t]*Keysym[ \t]*\(Keysym\)/ \
	     || $0 ~ /^[ \t]*Value[ \t]*Value[ \t]*\(Name\)/ )
    {
    }
    else
    {
       printf "  /* %s */\n", $0;
    }
  }
'

echo "  };"
