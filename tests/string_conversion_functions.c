/*
 * This source file forms part of wlcrack, which solves Word Ladder puzzles.
 * This source file provides a unit test for the public functions provided by
 * the wlcrack library for converting to/from c strings and the internal struct
 * type used by the library.
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
#include "../wlcrack/wlcrack.h"
#include "../unit_test_harness/harness.h"


#ifdef __cplusplus
extern "C"{
#endif

// test that c strings of length 4 can be converted to wlcrack_word_t structs
test_result_t test_c_string_to_wlcrack_word_t() {
    // initialise test result
    test_result_t test = TEST;
    // set result to success for now, until proven otherwise by checks
    test.result = TEST_SUCCESS;
    // create c string to convert
    c_string_t input[4] = "CASE";
    // create output struct
    wlcrack_word_t output;

    // convert
    c_string_to_wlcrack_word_t(input, &output);

    // check output characters
    for(uint8_t i = 0; i < 4; i++) {
        if(output.characters[i] != input[i]) {
            test.result = TEST_FAIL;
            break;
        }
    }
    return test;
}

// test that wlcrack_word_t structs can be converted to c strings of length 4
test_result_t test_wlcrack_word_t_to_c_string() {
    // initialise test result
    test_result_t test = TEST;
    // set result to success for now, until proven otherwise by checks
    test.result = TEST_SUCCESS;
    // create input struct to convert
    wlcrack_word_t input = { .characters = "JOIN", };
    // create output c string
    c_string_t output[4];

    // convert
    wlcrack_word_t_to_c_string(input, output);

    // check output string
    for(uint8_t i = 0; i < 4; i++) {
        if(output[i] != input.characters[i]) {
            test.result = TEST_FAIL;
            break;
        }
    }
    return test;
}

int main() {
    // initialise test suite
    test_suite_t suite = init_test_suite();
    // add test cases
    add_test_case(test_c_string_to_wlcrack_word_t, &suite);
    add_test_case(test_wlcrack_word_t_to_c_string, &suite);
    // run test suite
    run_test_suite(&suite);
    // return test suite status
    return suite.result ? 0 : 1;
}

#ifdef __cplusplus
} // extern "C"
#endif
