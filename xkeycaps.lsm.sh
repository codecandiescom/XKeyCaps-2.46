#!/bin/sh
#
# generate an lsm file (http://sunsite.unc.edu/pub/Linux/Incoming/LSM-TEMPLATE)
# that is more-or-less correct for the current version of xkeycaps.
# jwz, 18-Jan-98

size() {
    ls -l $* |
    tail -1 |
    sed 's/.* \([0-9][0-9][0-9][0-9][0-9]*\) .*/\1/' |
    sed 's/[0-9][0-9][0-9]$/K/'
}

TAR_SIZE=`size xkeycaps-*.Z`
README_SIZE=`size README`
#LSM_SIZE=`size xkeycaps.lsm`
LSM_SIZE="1K"

VERSION=`sed -n 's/.*\([0-9][0-9]*\.[0-9]*\).*/\1/p' < version.h`
DATE=`date '+%d%b%y' | tr a-z A-Z`

N=`make index | wc -l | sed 's/ //g'`

#URL=`sed -n 's/\(http:[^ ]*\)/\1/p' < README | sed 's/[^a-zA-Z/]$//'`

echo "Begin3
Title:          xkeycaps
Version:        $VERSION
Entered-date:   $DATE
Description:    A graphical front-end to xmodmap.
                Understands $N different keyboards.
                Home page: http://www.jwz.org/xkeycaps/
Keywords:       xmodmap, keyboard, keymaps, loadkeys, keytables, X11
Author:         jwz@jwz.org (Jamie Zawinski)
Maintained-by:  jwz@jwz.org (Jamie Zawinski)
Primary-site:   ftp.x.org /contrib/applications/
                $TAR_SIZE xkeycaps-$VERSION.tar.Z
                $README_SIZE   xkeycaps.README
                $LSM_SIZE   xkeycaps.lsm
Alternate-site: sunsite.unc.edu /pub/X11/contrib/applications/
                $TAR_SIZE xkeycaps-$VERSION.tar.Z
                $README_SIZE   xkeycaps.README
                $LSM_SIZE   xkeycaps.lsm
Platforms:      Linux, Irix, SunOS, Solaris, HPUX, AIX, FreeBSD, NetBSD,
                BSDI, SCO, OSF1, Ultrix, NeXT, DG-UX, VMS.
                Requires X11 (and the Athena widgets.)
Copying-policy: BSD
End"

exit 0
