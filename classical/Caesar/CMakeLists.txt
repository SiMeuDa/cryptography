#set cmake's minimum version
cmake_minimum_required(VERSION 3.5...3.28)

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
	m
)

add_executable (brute_force
	analysis/brute_force/brute_force.c
)

target_link_libraries(brute_force
	PRIVATE caesar
)

add_executable (frequency
	analysis/frequency/frequency.c
)

#Turn off warning sign
if(MSVC)
	target_compile_options(frequency
		PRIVATE 
		/wd4996
	)
else()
	target_compile_options(frequency
		PRIVATE 
		-O3
		-Wno-unused-variable
	)
endif()

target_link_libraries(frequency
	PRIVATE caesar
)
