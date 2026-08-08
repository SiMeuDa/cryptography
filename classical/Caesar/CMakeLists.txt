cmake_minimum_required(VERSION 3.5...3.28)

project(
	CaesarTest
	LANGUAGES C)

add_executable (stdin_input.out test/stdin_input_test.c)

add_executable (file_input.out test/file_input_test.c)

file(TOUCH "test/text_file_test.txt")
