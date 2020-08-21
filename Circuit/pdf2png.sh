#!/bin/bash
#
#	Convert the circuit from PDF to PNG
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
PDF=LatencyMeasure.pdf
PNG=LatencyMeasure.png

convert \
	-density 150 \
	$PDF \
	-background white \
	-alpha remove \
	$PNG

	#-geometry 1000 \
