/* xkeycaps, Copyright (c) 1998 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Adesso PCK 301
 * keyboard.  This is based on file "pc101-geom.h".
 * This arrangement created by Tom Spindler <dogcow@redback.com>, 9 Dec 1999
 */

static const struct key_geometry pck301_geom_row0 [] = {
{7, 7}, {7, 0}, /* esc */
{7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {12,0}, /*f1-f5*/
{7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {8, 0}, /*f6-f12*/
{7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pck301_geom_row2 [] = {
 {7, 7},
{7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {9,0}, /* 1-6 */
{7, 7}, {7, 7}, {7, 7}, {7, 7}, 
{7, 7}, {7, 7}, {7,7}, {7,7},
{4, 0},
 {7, 7}, {7, 7}, {7, 7},   /* ins/home/pgup */
{4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7} /* keypad */
};

static const struct key_geometry pck301_geom_row3 [] = {
 {10, 7}, /* tab */
{7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, /*q-t*/
{10,0}, /* gap cuz it's "ergo" */
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, /*y-p */
 {7, 7}, {7, 7}, /* [ ] */
{10, 14}, /* big return key */
 {4,0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0}, /* del-pgdn */
 {7, 7}, {7, 7}, {7, 7}, {7, 14} /* kpad with giant + key */
};

static const struct key_geometry pck301_geom_row4 [] = {
 {13, 7}, /* capslock, hiss */
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, /* a-g */
{10,0}, /* big ergo gap */
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, /* h - ' */
 {43, 0},
 {7, 7}, {7, 7}, {7, 7}, /* kpad 4-6 */
};

static const struct key_geometry pck301_geom_row5 [] = {
 {16, 7}, /*giant shift key*/
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
{10,0}, /*ergo gap*/
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, /* n - / */
{18, 7}, /*gianter shift */
 {11, 0},
 {7, 7}, /*up arrow */
 {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pck301_geom_row6 [] = {
 {10, 7}, /* control */
 {10, 7}, /* meta/window/whatever the hell */
 {10,7}, /* alt */
 {43, 7}, /* space bar is one key because both produce the same scan code */
 {10, 7}, /* alt */
 {10, 7}, /* meta/window/square */
{10, 7}, /* squarepointy/compose */
 {11, 7}, /*r control*/
 {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0}, /* arrows */
 {14, 7}, {7, 7}, {7,0} /* kpad */
};

static const struct keyboard_row_geometry pck301_geom_rows [] = {
  ROW (pck301_geom_row0, 7),
  EMPTYROW (5),
  ROW (pck301_geom_row2, 7),
  ROW (pck301_geom_row3, 7),
  ROW (pck301_geom_row4, 7),
  ROW (pck301_geom_row5, 7),
  ROW (pck301_geom_row6, 7),
};

static const struct keyboard_geometry pck301_geom = {
  sizeof (pck301_geom_rows) / sizeof (struct keyboard_row_geometry),
  pck301_geom_rows, 6, 3, 3
};
