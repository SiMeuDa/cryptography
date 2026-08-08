cmake_minimum_required(VERSION 3.5...3.28)

project(
	CaesarFrequency
	LANGUAGES C)

add_executable(frequency.out frequency.c)

file(TOUCH "input.txt")
