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
OUTPUT=$2

#
#	internal settings
#
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
if [ ! "$OUTPUT" ]; then
	echo "*** no target file name given -- ABORTING!"
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
echo "Waiting for serial data @ $SERIAL ..."
while read -e LINE; do
	[ "${LINE:0:1}" = "#" ] && break
	echo $LINE >>$TMPFILE
done <$SERIAL
echo "Data written to file @ $TMPFILE ..."

#
#	colorize the file
#
echo "Post-processing $TMPFILE to $OUTPUT ..."
convert $TMPFILE -fill $FG_RECOLORED -opaque $FG_ORIGINAL -resize $RESIZE_PCT $OUTPUT

exit 0
