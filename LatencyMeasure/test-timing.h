/*
    LatencyMeasure

    (c) 2020 Christian.Lorenz@gromeck.de

    test timing definitions and prototypes
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
