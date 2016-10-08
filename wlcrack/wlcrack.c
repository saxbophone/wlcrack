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
#include <stdint.h>

#include "wlcrack.h"


#ifdef __cplusplus
extern "C"{
#endif

// Version numbers are passed as preprocessor definitions by CMake
const version_t VERSION = {
    .major = WLCRACK_VERSION_MAJOR,
    .minor = WLCRACK_VERSION_MINOR,
    .patch = WLCRACK_VERSION_PATCH,
};

// converts a c string of length 4 to a wlcrack_word_t
void c_string_to_wlcrack_word_t(c_string_t in[4], wlcrack_word_t* out) {
    // copy characters across
    for(uint8_t i = 0; i < 4; i++) {
        out->characters[i] = in[i];
    }
}

// converts a wlcrack_word_t to a c string of length 4
void wlcrack_word_t_to_c_string(wlcrack_word_t in, c_string_t* out) {
    // copy characters across
    for(uint8_t i = 0; i < 4; i++) {
        out[i] = in.characters[i];
    }
}

/*
 * given two c strings of length 4 (which are the start and end words), find any
 * and all solutions for the word ladder and store these in a given
 * wlcrack_solutions_t struct
 * returns true if no errors or false if errors were encountered
 */
bool solve_word_ladder(
    c_string_t first_str[4], c_string_t last_str[4], wlcrack_solutions_t * results
) {
    // create word structs from strings
    wlcrack_word_t first, last;
    c_string_to_wlcrack_word_t(first_str, &first);
    c_string_to_wlcrack_word_t(last_str, &last);
    // NOTE: Dummy implementation from here on...
    results->count = 0;
    return true;
}

#ifdef __cplusplus
} // extern "C"
#endif
