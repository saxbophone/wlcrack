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

// library version variable
extern const version_t VERSION;

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
