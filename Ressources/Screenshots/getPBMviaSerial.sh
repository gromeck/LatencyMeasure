#!/bin/bash
#
#	get a PBM (Portable Bitmap) from the serial interface
#
#	the LatencyMeasure sketch is programmed to transfer the current
#	screen as ASCII PBM on demand over the serial interface. This
#	scripts reads from the serial interface and converts it to a
#	colored PNG to produce a screenshot file.
#
#	(c) 2020 by Christian.Lorenz@gromeck.de
#
#
#	This file is part of LatencyMeasure.
#	
#	LatencyMeasure is free software: you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation, either version 3 of the License, or
#	(at your option) any later version.
#	
#	LatencyMeasure is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#	
#	You should have received a copy of the GNU General Public License
#	along with LatencyMeasure.  If not, see <https://www.gnu.org/licenses/>.
#
SERIAL=$1

#
#	internal settings
#
PREFIX="Screenshot-OLED-"
TMPFILE=/tmp/screenshot.pbm
FG_ORIGINAL=white
FG_RECOLORED=cyan
RESIZE_PCT=100%


#
#	check some arguments
#
if [ ! "$SERIAL" ]; then
	echo "*** no serial device given -- ABORTING!"
	exit 1
fi


#
#	clear on start
#
rm -f $TMPFILE $OUTPUT


#
#	set serial parameters
#
stty -F $SERIAL raw
stty -F $SERIAL -echo


#
#	wait for transmission
#
TITLE=""
echo "Waiting for serial data @ $SERIAL ..."
while read LINE; do
	[ "${LINE:0:5}" = "# EOF" ] && break
	echo $LINE >>$TMPFILE
done <$SERIAL
echo "Data written to file @ $TMPFILE ..."


#
#	set a filename -- count up a postfix on duplicate
#
TITLE=$( grep "^# TITLE" $TMPFILE | sed -e "s/# TITLE //" )
PAGE=$( echo $TITLE | sed -e "s/^.*, //" | sed -e "s/\/.*$//" | sed -e "s/#//" | tr -d "[:space:]" )
TITLE=$( echo $TITLE | sed -e "s/,.*$//" | tr -s " " | tr " " "-" )
[ "$PAGE" != "" ] && TITLE="$TITLE-$PAGE"
NR=0 
while : ; do
	if [ $NR = 0 ]; then
		POSTFIX=""
	else
		POSTFIX="($NR)"
	fi
	OUTPUT="$PREFIX$TITLE$POSTFIX.png"
	[ ! -f $OUTPUT ] && break;
	NR=$(( $NR + 1 ))
done

#
#	convert and colorize the file
#
echo "Post-processing $TMPFILE to $OUTPUT ..."
convert $TMPFILE -fill $FG_RECOLORED -opaque $FG_ORIGINAL -resize $RESIZE_PCT $OUTPUT


exit 0
