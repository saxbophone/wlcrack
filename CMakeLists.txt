# This source file forms part of wlcrack, which solves Word Ladder puzzles.
# Copyright (C) 2016, Joshua Saxby joshua.a.saxby+TNOPLuc8vM==@gmail.com
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# begin basic metadata
cmake_minimum_required(VERSION 3.0)

project(wlcrack VERSION 1.0.0 LANGUAGES C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(
    WLCRACK_VERSION_STRING
    "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
)
set(WLCRACK_ESCAPED_VERSION_STRING "\"${WLCRACK_VERSION_STRING}\"")
# end basic metadata

# pass in version of library as preprocessor definitions
add_definitions(-DWLCRACK_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
add_definitions(-DWLCRACK_VERSION_MINOR=${PROJECT_VERSION_MINOR})
add_definitions(-DWLCRACK_VERSION_PATCH=${PROJECT_VERSION_PATCH})
add_definitions(-DWLCRACK_VERSION_STRING=${WLCRACK_ESCAPED_VERSION_STRING})

# used for enabling additional compiler options if supported
include(CheckCCompilerFlag)

function(enable_c_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_C_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_c_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${flag}" PARENT_SCOPE)
        endif()
    endif()
endfunction()

# enable extra flags (warnings) if we're not in release mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "")
    message("Warnings Enabled")
    # enable all warnings about 'questionable constructs'
    enable_c_compiler_flag_if_supported("-Wall")
    # issue 'pedantic' warnings for strict ISO compliance
    enable_c_compiler_flag_if_supported("-pedantic")
    # enable 'extra' strict warnings
    enable_c_compiler_flag_if_supported("-Wextra")
    # convert all warnings into errors
    enable_c_compiler_flag_if_supported("-Werror")
endif()

# C Source files
file(GLOB LIB_WLCRACK_SOURCES "wlcrack/*.c")
# C Header files
file(GLOB LIB_WLCRACK_HEADERS "wlcrack/*.h")

# Test Suite Harness Source Files
file(GLOB TEST_HARNESS_SOURCES "unit_test_harness/*.c")

# Unit test C Source files
file(GLOB TEST_WLCRACK_SOURCES "tests/*.c")

# main library
add_library(wlcrack ${LIB_WLCRACK_SOURCES})

# test harness library
add_library(test_harness ${TEST_HARNESS_SOURCES})

# main program cli executable
add_executable(wlcc wlcc.c)
# link cli executable with library
target_link_libraries(wlcc wlcrack)

enable_testing()
# unit test executables
foreach(test_source_file ${TEST_WLCRACK_SOURCES})
    # remove '.c' extension and parent directories
    get_filename_component(test_name ${test_source_file} NAME_WE)
    # append "test_" to test_name
    set(test_name "test_${test_name}")
    # create executable for test
    add_executable(${test_name} ${test_source_file})
    # link test with library and test harness library
    target_link_libraries(${test_name} wlcrack test_harness)
    # add test
    add_test(${test_name} ${test_name})
endforeach()

install(
    TARGETS wlcrack
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# install library header files
install(FILES ${LIB_WLCRACK_HEADERS} DESTINATION include/wlcrack)

# install executables
install(PROGRAMS wlcc DESTINATION bin)
