#!/bin/bash

QMAKE=qmake-qt4

make clean
$QMAKE LatencyTest.pro \
&& $QMAKE \
&& make
