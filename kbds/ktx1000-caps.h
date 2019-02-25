/* xkeycaps, Copyright (c) 1994, ..., 1999 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes what is printed on the keycaps of a KTX 1000 keyboard.
 * The file was edited Neil Zanella <nzanella@ganymede.cs.mun.ca>.
 */

static const struct key_strings ktx1000_caps [] = {

   /* Row 1  */

   {"Esc", 0, 0}, {"F1", "Prt Sc", 0}, {"F2", "Sys Rq", 0}, {"F3", "Speed", 0},
   {"F4", "Backlit", 0}, {"F5", "CRT/LCD", 0}, {"F6", "Gauge", 0},
   {"F7", "KeyLock", 0}, {"F8", "Mute", 0}, {"F9", "Audio Down", 0},
   {"F10", "Audio Up", 0}, {"F11", "Rest", 0}, {"F12", "Scroll", 0},
   {"Num", "Lock", 0}, {"Pause", "Break", 0}, {"Insert", 0, 0},
   {"Delete", 0, 0},

   /* Row 2 */

   {"!", "1", 0}, {"@", "2", 0}, {"#", "3", 0}, {"$", "4", 0}, {"%", "5", 0},
   {"^", "6", 0}, {"&", "7", "7"}, {"*", "8", "8"}, {"(", "9", "9"},
   {")", "0", "*"}, {"-", "_", 0}, {"+", "=", 0}, {"Backspace", "<----", 0},
   {"Home", 0, 0},

   /* Row 3 */

   {"Tab", "<->", 0}, {"Q", 0, 0}, {"W", 0, 0}, {"E", 0, 0}, {"R", 0, 0},
   {"T", 0, 0}, {"Y", 0, 0}, {"U", 0, "4"}, {"I", 0, "5"}, {"O", 0, "6"},
   {"P", 0, "-"}, {"{", "[", 0}, {"}", "]", 0}, {"|", "\\", 0}, {"PgUp", 0, 0},

   /* Row 4 */

   {"Caps", "Lock", 0}, {"A", 0, 0}, {"S", 0, 0}, {"D", 0, 0}, {"F", 0, 0},
   {"G", 0, 0}, {"H", 0, 0}, {"J", 0, "1"}, {"K", 0, "2"}, {"L", 0, "3"},
   {":", ";", "+"}, {"\"", "'", 0}, {"Enter", "<--|", 0}, {"PgDn", 0, 0},

   /* Row 5 */

   {"Shift", "UpArrow", 0}, {"Z", 0, 0}, {"X", 0, 0}, {"C", 0, 0}, {"V", 0, 0},
   {"B", 0, 0}, {"N", 0, 0}, {"M", 0, "0"}, {"<", ",", 0}, {">", ".", "."},
   {"?", "/", "/"}, {"Shift", "UpArrow", 0}, {"UpArrow", "Contrast Up", 0},
   {"End", 0, 0},

   /* Row 6 */

   {"Fn", 0, 0}, {"~", "`", 0}, {"Ctrl", 0, 0}, {"Alt", 0, 0}, {"Win", 0, 0},
   {" ", 0, 0}, {"Win", 0, 0}, {"Menu", 0, 0}, {"Alt", 0, 0}, {"Ctrl", 0, 0},
   {"Brightness Down", "LeftArrow", 0}, {"Contrast Down", "DownArrow", 0},
   {"Brightness Up", "RightArrow", 0}

};
