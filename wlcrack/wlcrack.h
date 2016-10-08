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
#ifndef SAXBOPHONE_WLCRACK_WLCRACK_H
#define SAXBOPHONE_WLCRACK_WLCRACK_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C"{
#endif

// struct for representing version of wlcrack
typedef struct version_t {
    uint8_t major;
    uint8_t minor;
    uint8_t patch;
} version_t;

// for brevity
typedef unsigned char c_string_t;

// struct type for fixed-length char array for word
typedef struct wlcrack_word_t {
    c_string_t characters[4];
} wlcrack_word_t;

// struct type for one word ladder 'chain'
typedef struct wlcrack_ladder_t {
    wlcrack_word_t words[5];
} wlcrack_ladder_t;

// struct for storing zero or more solutions for a given word ladder puzzle
typedef struct wlcrack_solutions_t {
    size_t count; // number of solutions found
    wlcrack_ladder_t* solutions; // dynamic array of word ladder structs
} wlcrack_solutions_t;

// library version variable
extern const version_t VERSION;

// converts a c string of length 4 to a wlcrack_word_t
void c_string_to_wlcrack_word_t(c_string_t in[4], wlcrack_word_t* out);

// converts a wlcrack_word_t to a c string of length 4
void wlcrack_word_t_to_c_string(wlcrack_word_t in, c_string_t* out);

/*
 * given two c strings of length 4 (which are the start and end words), find any
 * and all solutions for the word ladder and store these in a given
 * wlcrack_solutions_t struct
 * returns true if no errors or false if errors were encountered
 */
bool solve_word_ladder(
    c_string_t first_str[4], c_string_t last_str[4], wlcrack_solutions_t * results
);

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
