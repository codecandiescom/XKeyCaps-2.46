/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the NCD VT220 keyboard,, via kludgy
 * conditionalizations in ncd108-caps.h (since the two keyboards differ only
 * slightly.)
 */

#define VT220_KLUDGE
#include "ncd108-caps.h"
#undef VT220_KLUDGE
