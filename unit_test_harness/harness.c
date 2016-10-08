/*
 * This source file forms part of wlcrack, which solves Word Ladder puzzles.
 * This compilation unit provides a simple test harness for the unit tests.
 *
 * Copyright (C) 2016, Joshua Saxby joshua.a.saxby+TNOPLuc8vM==@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "harness.h"


#ifdef __cplusplus
extern "C"{
#endif

// returns a blank test suite
test_suite_t init_test_suite() {
    return (test_suite_t) { .tests = NULL, .test_count = 0, .result = true };
}

/*
 * adds a function as a test case to a test suite
 * function must return a test_result_t struct and take no arguments
 */
void add_test_case(test_result_t (* function)(), test_suite_t * suite) {
    // increment test count
    suite->test_count++;
    // allocate or re-allocate memory for adding test case
    if(suite->tests == NULL) {
        // first time allocation
        suite->tests = (test_case_t *) malloc(sizeof(test_case_t));
    } else {
        // re-allocate
        suite->tests = (test_case_t *) realloc(
            suite->tests, sizeof(test_case_t) * suite->test_count
        );
    }
    // assign function pointer to latest test case
    suite->tests[suite->test_count - 1].function = function;
}

// returns string for test result code
static const char * test_status_string(test_status_t status) {
    switch(status) {
        case TEST_UNKNOWN:
            return "NO RESULT";
        case TEST_FAIL:
            return "FAIL";
        case TEST_ERROR:
            return "ERROR";
        case TEST_SUCCESS:
            return "SUCCESS";
        default:
            return "UNEXPECTED RESULT";
    }
}

// runs all test cases in a test suite and stores result success / failure
void run_test_suite(test_suite_t * suite) {
    // iterate over every test case in array
    for(size_t i = 0; i < suite->test_count; i++) {
        // run the current test case and store result
        test_result_t result = suite->tests[i].function();
        // print out the test case name and return code
        printf("%s\t%s\n", result.name, test_status_string(result.result));
        // combine with current stored result in test suite
        suite->result = (
            (result.result == TEST_SUCCESS) ? true : false
        ) && suite->result;
    }
}

#ifdef __cplusplus
} // extern "C"
#endif
