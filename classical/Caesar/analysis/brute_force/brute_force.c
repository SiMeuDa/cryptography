#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
	char buffer[BUFFER_SIZE], input_text[8 * BUFFER_SIZE];
	char* output_text;
	FILE* fp = stdin;
	void* ret_ptr;
	size_t in_len, buf_len;

	/**
	 * Check validation of argument
	 * Determine file pointer
	 */
	if(argc == 1){
		printf("[Input Text]: ");
	}else if(strncmp("-f", argv[1], 2) == 0){
		fp = fopen("./test_input.txt", "r");
		if(fp == NULL){
			fprintf(stderr, "[ERROR]: FAILED TO OPEN FILE\n");
			return CAESAR_INVALID_FILE;
	}}
	
	 /*
         * Take Text from file ptr
         */
	do{
		ret_ptr = fgets(buffer, sizeof(buffer), fp);
		if(ret_ptr == NULL){
			break;
		}
		
		in_len = strlen(input_text);
                buf_len = strlen(buffer);

                if(sizeof(input_text) - in_len > buf_len){
                        strncat(input_text, buffer, buf_len);
                }else{
                        strncat(input_text, buffer, in_len);
                }
	}while(fp != stdin);

	output_text = (char*)malloc(sizeof(char) * (strlen(input_text) + 1));
	if(output_text == NULL){
		fprintf(stderr, "[ERROR]: FAILED TO ALLOCATE MEMORY\n");
		return CAESAR_NULL_POINTER;
	}


	/**
	 * Do BruteForce
	 * Print out All possible key value
	 */
	for(int key = 0; key < CAESAR_ALPHABET_SIZE; key++){
		if(caesar_encrypt(
			input_text, 
			output_text, 
			&key
		) != CAESAR_SUCCESS){
			free(output_text);
			fprintf(stderr, "[ERROR]: FAILED TO ENCRYPT MESSAGE\n");
			return CAESAR_INVALID_INPUT;
		}
		printf("[Output(key = %d)]:\t%s", key, output_text);
	}

	free(output_text);

	return CAESAR_SUCCESS;
}
