#!/bin/bash

make clean \
&& qmake LatencyTest.pro \
&& qmake \
&& make
