/*
  LatencyMeasure

  (c) 2020 Christian.Lorenz@gromeck.de

  util definitions and prototypes


  This file is part of LatencyMeasure.

  LatencyMeasure is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  LatencyMeasure is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with LatencyMeasure.  If not, see <https://www.gnu.org/licenses/>.

*/
#ifndef __UTIL_H__
#define __UTIL_H__ 1

#include "common.h"

#if DEBUG
void DbgMsg(const char *fmt, ...);
#else
#define DbgMsg(...)
#endif

#endif

/**/
