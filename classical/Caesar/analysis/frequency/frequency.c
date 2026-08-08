#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double frequency_table[CAESAR_ALPHABET_SIZE] = {
	0.082, 0.015, 0.028, 0.043,
	0.127, 0.022, 0.020, 0.061,
	0.070, 0.002, 0.008, 0.040,
	0.024, 0.067, 0.075, 0.019,
	0.001, 0.060, 0.063, 0.091,
	0.028, 0.010, 0.023, 0.001,
	0.020, 0.001
};

double pow(double x, int y);

int main(int argc, char* argv[])
{
	char buffer[1024] = {'\0'}, input_text[4 * 1024] = {'\0'};
	double string_frequency[CAESAR_ALPHABET_SIZE] = {0.0};
	int cat_len = 0;
	FILE* fp;
	_Bool isEnd = 0;
	
	/**
	 * @brief: Set file pointer with argument
	 *
	 * 1. If argc is 1, take string from user
	 * 2. If argv[1] is -f, take string from input.txt
	 * 3. Else terminate for invalid input
	 */
	if(argc == 1){
		
		printf("[Input Text]: ");
		fp = stdin;
		isEnd = 1;

	}else if(strncmp(argv[1], "-f", 2) == 0){

		fp = fopen("./test_input.txt", "r");

		if(fp == NULL){
			fp = fopen("../test_input.txt", "r");

			if(fp == NULL){
				fprintf(stderr, "[ERROR]: FAILED TO OPEN FILE\n");
				return CAESAR_INVALID_INPUT;
		}}
	}else{
		fprintf(stderr, "[ERROR]: INVALID ARGUMENT\n");
		return CAESAR_INVALID_INPUT;
	}

	/**
	 * @brief: Take string with set file pointer
	 *
	 * 1. take string with fgets (take string until meet \n)
	 * 2. If input_text size is smaller than text, take only input_text size
	 * 3. If string is end or text is bigger, end loop
	 */
	do{
		if(fgets(buffer, sizeof(buffer), fp) == NULL){
			break;
		}

	
		if(strlen(buffer) > sizeof(input_text) - strlen(input_text)){
			cat_len = sizeof(input_text) - strlen(input_text);
			isEnd = 1;
		}else{
			cat_len = strlen(buffer);
		}
		
		strncat(input_text, buffer, cat_len);

	}while(isEnd != 1);
	
	fclose(fp);

	input_text[strlen(input_text)] = '\0';

	int text_len = strlen(input_text);
	char to_number;

	/**
	 * @brief: Count frequency of input text
	 * 
	 * 1. Change character to integer value ignoring upper and lower case
	 * 2. Add count
	 */
	for(int i = 0; i < text_len; i++){
		if(input_text[i] >= 'A' &&
			input_text[i] <= 'Z'){
			to_number = 'A';
		}else if(input_text[i] >= 'a' &&
			input_text[i] <= 'z'){
			to_number = 'a';
		}else{
			continue;
		}

		string_frequency[input_text[i] - to_number]++;
	}

	/**
	 * @brief: Print out result
	 * 
	 * 1. Divide for text_len
	 * 2. Round to four decimal places
	 */
	printf("[RESULT]\n");

	for(int i = 0; i < CAESAR_ALPHABET_SIZE; i++){
		if(text_len > 0){
			string_frequency[i] /= text_len;
		}

		printf("[%c]: %.3lf\n", (char)(i + 'A'), string_frequency[i]);
	}


	double Chi = 0.0;
	
	for(int i = 0; i < CAESAR_ALPHABET_SIZE; i++){
		Chi += pow((string_frequency[i] - frequency_table[i]), 2) / frequency_table[i];
	}

	printf("\n[Chi-Square Goodness-of-Fit Test]: %.3lf\n", Chi);
	

	return CAESAR_SUCCESS;
}

double pow(double x, int y){
	double temp = x;
	if(y > 0){
		for(int i = 1; i < y; i++){
			x *= temp;
	}}else{
		for(int i = 0; i >= y; i--){
			x /= temp;
	}}

	return x;
}
