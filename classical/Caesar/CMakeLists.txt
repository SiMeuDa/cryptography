#set cmake's minimum version
cmake_minimum_required(VERSION 3.20)

#set project name and language
project(
	Caesar
	LANGUAGES C)

#add library(API) source code location
add_library(caesar
	src/caesar.c
)

#add libaray header location
target_include_directories(caesar
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

####################### MAIN PROGRAM ##########################
#add excute file
add_executable(main
	main/main.c
)

#add compile options
target_compile_options(main
	PRIVATE
	-O3
)

#set libraries ranges
target_link_libraries(main
	PRIVATE caesar
)

####################### TEST PROGRAM ##########################
add_executable (test_caesar
	test/unit_test.c
)

target_compile_options(test_caesar
	PRIVATE 
	-O0
)

target_link_libraries(test_caesar
	PRIVATE 
	caesar
)

enable_testing()

add_test(
	NAME CaesarTests
	COMMAND test_caesar
)

####################### BRUTE_FORCE PROGRAM ##########################

add_executable (brute_force
	analysis/brute_force/brute_force.c
)

target_link_libraries(brute_force
	PRIVATE caesar
)

####################### FREQUENCY CHECKING PROGRAM ##########################
add_executable (frequency
	analysis/frequency/frequency.c
)

target_link_libraries(frequency
	PRIVATE caesar
	PRIVATE m
)
