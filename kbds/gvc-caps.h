/* xkeycaps, Copyright (c) 1994, 1997 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keys on the GVC laptops with a Win '95 keyboard
 * (at least I think they use the same keyboard for all models). These
 * laptops are sold in the U.S. by ARM (and everybody that sells ARM
 * notebooks).  I used a ARMNOTE 753CD to generate these files...
 *
 * I omitted the Strings on some keys that correspond to hardware control
 * functions (in connection with the Fn-key) such as suspend/resume (S/R) or
 * LCD/CRT switching, since there are no keycodes for these keys
 *
 * done by R.Back <back@picard.mathematik.uni-wuerzburg.de>.  */

static const struct key_strings gvc_caps [] = {

 /* Row 1  */

 {"Esc",0,0}, {"F1",0,0}, {"F2",0,0}, {"F3",0,0}, {"F4",0,0},
 {"F5",0,0}, {"F6",0,0}, {"F7",0,0}, {"F8",0,0}, {"F9",0,0},
 {"F10",0,0}, {"F11",0,0}, {"F12",0,0}, {"Num","Pad",0},
 {"PrtSc","SysRq",0}, {"Scroll","Lock",0},  {"Pause","Break",0},

 /* Row 2 */

 {"!", "1", 0}, {"@", "2", 0}, {"#", "3", 0}, {"$", "4", 0}, {"%", "5", 0},
 {"^", "6", 0}, {"&", "7", "7"}, {"*", "8", "8"}, {"(", "9", "9"}, 
 {")", "0", "*"}, {"_", "-", 0}, {"+", "=", 0}, 
 {"Backspace", 0, 0}, {"~", "`", 0},


 /* Row 3 */

 {"Tab",0,0}, {"Q", 0, 0}, {"W", 0, 0}, {"E", 0, 0}, {"R", 0, 0}, {"T", 0, 0}, 
 {"Y", 0, 0}, {"U",0, "4"}, {"I", 0, "5"}, {"O", 0, "6"}, {"P", 0, "-"},
 {"{", "[" }, {"}", "]" }, {"|","\\" }, {"Home", "    End", 0},

 /* Row 4 */

 {"Caps", "Lock",0}, {"A", 0, 0}, {"S", 0, 0}, {"D", 0, 0}, {"F", 0, 0},
 {"G", 0, 0}, {"H", 0, 0}, {"J", 0, "1"}, {"K", 0, "2"}, {"L", 0, "3"},
 {":", ";", "+"}, {"\"", "'", 0}, {"Enter", 0, 0}, {"Ins", 0, 0},

 /* Row 5 */

 {"Shift", 0 ,0},  {"Z", 0, 0}, {"X", 0, 0}, {"C", 0, 0}, {"V", 0, 0}, 
 {"B", 0, 0}, {"N", 0, 0}, {"M", 0, "0"}, {"<", ",", 0}, {">", ".", "/"},
 {"?", "/", "/"}, {"Shift", 0, 0}, {"UpArrow", "   PgUp", 0}, {"Del",0,0}, 

 /* Row 6 */

 {"Fn", 0, 0}, {"Ctrl", 0, 0}, {"Alt", 0, 0}, {"Win", 0, 0},
 {"|", "\\", 0}, {" ", 0, 0}, {"Menu", 0, 0}, {"Alt", 0, 0}, {"Ctrl", 0, 0},
 {"LeftArrow", "   Home"}, {"DownArrow", "   PgDn", 0},
 {"RightArrow", "    End", 0}
};
