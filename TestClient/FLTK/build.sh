#!/bin/bash

aclocal \
&& autoheader \
&& automake --gnu --add-missing --copy \
&& autoconf \
&& ./configure --enable-static \
&& make clean \
&& make
