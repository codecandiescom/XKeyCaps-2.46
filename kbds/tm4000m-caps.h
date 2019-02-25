/* xkeycaps, Copyright (c) 1994, 1995, 1996 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the Texas Instruments
 * TravelMate 4000M multimedia notebook keyboard interface.
 * By Kenneth E. Harker <iago@cs.dartmouth.edu>
 */

static const struct key_strings tm4000m_caps [] = {

 /* Row 0 */

 {"Esc","Setup",0}, {"F1",0,0}, {"F2",0,0}, {"F3",0,0}, {"F4",0,0},
 {"F5",0,0}, {"F6",0,0}, {"F7",0,0}, {"F8","/",0}, {"F9","*",0},
 {"F10","-",0}, {"F11",0,0}, {"F12",0,0}, {"NumLk","ScrLck",0}, 
 {"PrtSc","SysRq",0}, {"Pause","Break",0}, {"Ins",0,0}, {"Del",0,0},

 /* Row 2 */

 {"~", "`", 0}, {"!", "1", 0}, {"@", "2", 0}, {"#", "3", 0}, {"$", "4", 0}, 
 {"%", "5", 0}, {"^", "6", 0}, {"&", "7", "7"}, {"*", "8", "8"}, 
 {"(", "9", "9"}, {")", "0", "+"}, {"_", "-", 0}, {"+", "=", 0}, 
 {"Back", "Space", 0}, 

 /* Row 3 */
 {"Tab", 0, 0}, {"Q", 0, 0}, {"W", 0, 0}, {"E", 0, 0}, {"R", 0, 0}, 
 {"T", 0, 0}, {"Y", 0, 0}, {"U", 0, "4"}, {"I", 0, "5"}, {"O", 0, "6"}, 
 {"P", 0, "+"}, {"{", "[", 0}, {"}", "]", 0}, {"|", "\\", 0},

 /* Row 4 */

 {"Caps", "Lock", 0}, {"A", 0, 0}, {"S", 0, 0}, {"D", 0, 0}, {"F", 0, 0}, 
 {"G", 0, 0}, {"H", 0, 0}, {"J", 0, "1"}, {"K", 0, "2"}, {"L", 0, "3"}, 
 {":", ";", "Enter"}, {"\"", "'", 0}, {"Enter", 0, 0},

 /* Row 5 */

 {"Shift", 0, 0},  {"Z", 0, 0}, {"X", 0, 0}, {"C", 0, 0}, {"V", 0, 0}, 
 {"B", 0, 0}, {"N", 0, 0}, {"M", 0, "0"}, {"<", ",", "0"}, {">", ".", "."}, 
 {"?", "/", "Enter"}, {"Shift", 0, 0},

 /* Row 6a */

 {"Fn", 0, 0}, {"Ctrl", 0, 0}, {"Alt", 0, 0}, {" ", 0, 0}, {"Alt", 0, 0}, 
 {"Home", 0, 0}, {"UpArrow", 0, 0}, {"End", 0, 0}, {"PgUp", 0, 0},

 /* Row 6b */

 {"LeftArrow", 0, 0}, {"DownArrow", 0, 0}, {"RightArrow", 0, 0}, 
 {"PgDn", 0, 0}

};
