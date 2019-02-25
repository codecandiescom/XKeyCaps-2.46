/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the Sun French type 5 keyboard.
 * By Olivier STEPHANT, nov.1997.
 * This keyboard meet the TUV standard.
 * Defined from Sun document "Notes claviers Sun type 5" ref. #800-6803-10
 *
 */

static const struct key_strings sun5fr_caps [] = {

  /* Row 0 */

  {"Aide", 0},
  {"Esc", 0},
  {"F1", 0},
  {"F2", 0},
  {"F3", 0},
  {"F4", 0},
  {"F5", 0},
  {"F6", 0},
  {"F7", 0},
  {"F8", 0},
  {"F9", 0},
  {"F10", 0},
  {"F11", 0},
  {"F12", 0},
  {"Impr.", "\351cran", 0},
  {"Arr\352t", "d\351fil.", 0},
  {"Pause", 0},
  {"Degauss", "Muet", 0},
  {"Contr-", "Son -", 0},
  {"Contr+", "Son +", 0},
  {"Power", 0},

  /* Row 1 */

  {"Stop", 0},
  {"Encore", 0},
  {"\262", 0},
  {"1", "&", 0},
  {"2", "\351", "~"},
  {"3", "\"", "#"},
  {"4", "'", "{"},
  {"5", "(", "["},
  {"6", "-", "|"},
  {"7", "\350", "`"},
  {"8", "_", "\\"},
  {"9", "\347", "^"},
  {"0", "\340", "@"},
  {"\260", ")", "]"},
  {"+", "=", "}"},

  {"Back", 0, 0},
  {"Inser.", 0},
  {"Debut", 0},
  {"Pr\351c", 0},
  {"Verr", "Num\351", 0},
  {"/", 0},
  {"*", 0},
  {"-", 0},

  /* Row 2 */

  {"Props", 0},
  {"Annu", "ler", 0},
  {"Tab", 0},
  {"A", 0},
  {"Z", 0},
  {"E", 0},
  {"R", 0},
  {"T", 0},
  {"Y", 0},
  {"U", 0},
  {"I", 0},
  {"O", 0},
  {"P", 0},
  {"\250", "^", 0},
  {"\243", "$", "\244"},

  {"Retour", 0},
  {"Suppr.", 0},
  {"Fin", 0},
  {"Suiv", 0},
  {"7", "D\351but", 0},
  {"8", "upArrow", 0},
  {"9", "Pr\351c", 0},
  {"+", 0},

  /* Row 3 */

  {"Devant", 0},
  {"Copier", 0},
  {"Verr Maj", 0},
  {"Q", 0},
  {"S", 0},
  {"D", 0},
  {"F", 0},
  {"G", 0},
  {"H", 0},
  {"J", 0},
  {"K", 0},
  {"L", 0},
  {"M", 0},
  {"%", "\371", 0},
  {"\265", "*", 0},

  {"4", "leftArrow", 0},
  {"5", 0},
  {"6", "rightArrow", 0},

  /* Row 4 */

  {"Ouvrir", 0},
  {"Coller", 0},
  {"Maj", 0},
  {">", "<", 0},
  {"W", 0},
  {"X", 0},
  {"C", 0},
  {"V", 0},
  {"B", 0},
  {"N", 0},
  {"?", ",", 0},
  {".", ";", 0},
  {"/", ":", 0},
  {"\247", "!", 0},
  {"Maj", 0},
  {"upArrow", 0},
  {"1", "Fin", 0},
  {"2", "downArrow", 0},
  {"3", "Suiv", 0},
  {"Entr\351e", 0},

  /* Row 5 */

  {"Cher.", 0},
  {"Couper", 0},
  {"Control", 0},
  {"Alt", 0},
  {"<>", 0},
  {" ", 0},
  {"<>", 0},
  {"Com-", "poser", 0},
  {"Alt.", "Graph.", 0},
  {"leftArrow", 0},
  {"downArrow", 0},
  {"rightArrow", 0},
  {"0", "Inser.", 0},
  {".", "Suppr.", 0}
};
