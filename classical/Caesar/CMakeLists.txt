#set cmake's minimum version
cmake_minimum_required(VERSION 3.5...3.28)

#set project name and language
project(
	CaesarTest
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

#add excute file
add_executable (test_caesar
	test/unit_test.c)

target_compile_definitions(test_caesar
	PRIVATE MULTI_TEST=1
)

#set libraries range
target_link_libraries(test_caesar
	PRIVATE caesar
)

#make test text file
file(TOUCH 
	"./build/test_input.txt")


add_executable (brute_force
	analysis/brute_force/brute_force.c
)

target_link_libraries(brute_force
	PRIVATE caesar
)

add_executable (frequency
	analysis/frequency/frequency.c
)

target_link_libraries(frequency
	PRIVATE caesar
)

