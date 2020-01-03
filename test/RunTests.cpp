/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

/*
    MATHS CHALLENGE QUIZ - Testing System
    =====================================

    This file contains the testing system used by MCQ.

    The testing system used is called "catch2" (located in catch.h) and is licensed under the
    Boost Software Licence (copy enclosed in Catch2_Licence.txt).

    - To build the test script, run `make build`.
    - To build and run the test script, run `make run`.
    - To build and run the test script and then clean up the results, run `make test`

    The testing executable will be generated in the build folder.
*/

// Include and configure catch
#define CATCH_CONFIG_MAIN
#include "catch.h"

// Version checks
#if CATCH_VERSION_MAJOR < 2
#error "MCQ Requires catch V.2 or later"
#endif


// ==================== [BEGIN TESTS] ====================

// ====================  [END TESTS]  ====================