/*
 * This source file forms part of wlcrack, which solves Word Ladder puzzles.
 * This source file provides a unit test for the public function
 * 'solve_word_ladder', provided by the wlcrack library as the main interface.
 * The function attempts to provide solutions for the word ladder puzzle with
 * the given start and end words.
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

// dummy test case
test_result_t dummy_test_case() {
    // initialise test result
    test_result_t test = TEST;
    // set result to success for now, until proven otherwise by checks
    test.result = TEST_SUCCESS;
    return test;
}

int main() {
    // initialise test suite
    test_suite_t suite = init_test_suite();
    // add test cases
    add_test_case(dummy_test_case, &suite);
    // run test suite
    run_test_suite(&suite);
    // return test suite status
    return suite.result ? 0 : 1;
}

#ifdef __cplusplus
} // extern "C"
#endif
