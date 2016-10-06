/*
 * This source file forms part of wlcrack, which solves Word Ladder puzzles.
 * This compilation unit provides a simple test harness for the unit tests.
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
#ifndef SAXBOPHONE_WLCRACK_TEST_HARNESS_H
#define SAXBOPHONE_WLCRACK_TEST_HARNESS_H

#include <stdbool.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C"{
#endif

// enum for test suite test case results
typedef enum test_status_t {
    TEST_UNKNOWN = 0,
    TEST_FAIL,
    TEST_ERROR,
    TEST_SUCCESS,
} test_status_t;

// struct for test result and test name
typedef struct test_result_t {
    test_status_t result;
    const char * name;
} test_result_t;

/*
 * macro for storing function name as test name
 * usage: test_result_t result = TEST;
 */
#define TEST (test_result_t) { .result = TEST_UNKNOWN, .name = __func__, }

// struct for representing a test case
typedef struct test_case_t {
    // function pointer to function to run for test
    test_result_t (* function)();
    // test result status
    test_result_t result;
} test_case_t;

// struct for representing a whole test suite (one per module/test executable)
typedef struct test_suite_t {
    // pointer to an array of test cases
    test_case_t * tests;
    size_t test_count;
    // test suite fail / pass flag
    bool result;
} test_suite_t;

// returns a blank test suite
test_suite_t init_test_suite();

/*
 * adds a function as a test case to a test suite
 * function must return a test_result_t struct and take no arguments
 */
void add_test_case(test_result_t (* function)(), test_suite_t * suite);

// runs all test cases in a test suite and stores result success / failure
void run_test_suite(test_suite_t * suite);

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
