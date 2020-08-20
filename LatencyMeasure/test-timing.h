/*
  LatencyMeasure
  
  (c) 2020 Christian.Lorenz@gromeck.de
  
  test timing definitions and prototypes
  
  
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
#ifndef __TEST_TIMING_H__
#define __TEST_TIMING_H__ 1

#include "common.h"

/*
   max deviation from the expected delay in ms
   to consider the test passed
*/
#define MAX_DEVIATION 1

/*
   how long will be keep the test LED on in ms
*/
#define TEST_TIME      10

void test_timing(void);

#endif

/**/
