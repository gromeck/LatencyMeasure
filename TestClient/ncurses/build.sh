aclocal \
&& autoheader \
&& automake --gnu --add-missing --copy \
&& autoconf \
&& ./configure \
&& make
