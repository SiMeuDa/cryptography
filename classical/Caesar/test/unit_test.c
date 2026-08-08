#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024

#ifdef MULTI_TEST
typedef struct{
	char str[128];
	int key;
}CASE_TEST;

#endif

int main(int argc, char* argv[])
{
	char buffer[BUFFER_SIZE] = {'\0'}, input_text[8 * BUFFER_SIZE] = {'\0'};
	char* output_text;
	int key, isEncrypt = 1;
        size_t	buf_len = 0, in_len = 0;
	FILE* fp;
	void* ret_ptr = NULL;

#ifndef MULTI_TEST
	/*
	 * Set FILE ptr according to argument value
	 */
	if(argc == 1){
		printf("[Input Text]: ");
		fp = stdin;
	}else if(strncmp("-f", argv[1], 3) == 0){
		fp = fopen("./test_input.txt", "r");
		if(fp == NULL){
			fprintf(stderr, "[ERROR]: FAILED TO OPEN FILE\n");
			return CAESAR_INVALID_FILE;
	}}
	
	/*
	 * Take Text from file ptr
	 */
	do{
		ret_ptr = fgets(buffer, BUFFER_SIZE, fp);
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

	/*
	 * Take Key and isEncrypt from User
	 * with checking validation
	 */
	printf("[Input Key]: ");
	if(!scanf("%d", &key)){
		fprintf(stderr, "[ERROR]: INVALID INPUT\n");
		return CAESAR_INVALID_INPUT;
	}
	
	printf("[Ecrypt(yes: 1, no: 0)]: ");
	if(!scanf("%d", &isEncrypt)){
		fprintf(stderr, "[ERROR]: INVALID INPUT\n");
		return CAESAR_INVALID_INPUT;
	}

	
	output_text = (char*)malloc(sizeof(char) * (strlen(input_text) + 1));
	if(output_text == NULL){
		fprintf(stderr, "[ERROR]: FAILED TO ALLOCATE MEMORY\n");
		return CAESAR_NULL_POINTER;
	}
	
	/*
	 * Encryption Logic
	 */
	if(isEncrypt == 1){
		if(caesar_encrypt(
			input_text, 
			output_text, 
			&key
		) != CAESAR_SUCCESS){
			free(output_text);
			fprintf(stderr, "[ERROR]: FAILED TO ENCRYPT MESSAGE\n");
			return CAESAR_INVALID_INPUT;
	}}else if(isEncrypt == 0){
		if(caesar_decrypt(
			input_text,
			output_text,
			&key
		) != CAESAR_SUCCESS){
			free(output_text);
			fprintf(stderr, "[ERROR]: FAEILD TO DECRYPT MESSAGE\n");
			return CAESAR_INVALID_INPUT;
	}}else{
		free(output_text);
		fprintf(stderr, "[ERROR]: INVALID INPUT\n");
		return CAESAR_INVALID_INPUT;
	}

	printf("[Output]: %s\n", output_text);

	free(output_text);
#endif

#ifdef MULTI_TEST
	/** Expected Checking List
	 * 1. Basic En/Decryption
	 * 2. Boundary Value
	 * 3. Special characters
	 * 4. Empty String
	 * 5. NULL value
	 * 6. En/Decrption round trip
	 */

	CASE_TEST ctest[] = {
		{"ABCDEF", 3},
		{"abcdef", 3},
		{"UVWXYZ", 3},
		{"ABCDEF", 0},
		{"ABCDEF", 25},
		{"ABCDEF", 26},
		{"Hello, World!", 3},
		{"1234431", 3},
		{"안녕하세요", 3},
		{"", 3},
	};

	char output[4][BUFFER_SIZE] = {
		{'\0'},
		{'\0'},
		{'\0'},
		{'\0'}
	};

	size_t len;

	for(size_t i = 0; i < sizeof(ctest) / sizeof(CASE_TEST); i++){
		
		len = strlen(ctest[i].str);

		/**
		 * 1 - 5 Test
		 */
		if(caesar_encrypt(ctest[i].str, output[0], &ctest[i].key)
				!= CAESAR_SUCCESS){
			fprintf(stderr, "[ERROR]: FAILED TO ENCRYPT STRING\n");
		}
		printf("[Encrypt]: %s\t", output[0]);
		if(caesar_decrypt(ctest[i].str, output[1], &ctest[i].key)
				!= CAESAR_SUCCESS){
			fprintf(stderr, "[ERROR]: FAILED TO DECRYPT STRING\n");
		}

		printf("[Decrypt]: %s\n", output[1]);
		
		/*
		 * Round trip Test
		 */

		strncpy(output[2], output[0], len);
		
		caesar_decrypt(output[2], output[3], &ctest[i].key);

		printf("[ROUND TEST]: ");
		if(strcmp(ctest[i].str, output[3]) != 0){
			printf("FAIL TO ROUND TEST\n");
		}else{
			printf("SUCCESS TO ROUND TEST\n");
		}

		printf("\n");

		for(size_t i = 0; i < 4; i++){
			for(size_t j = 0 ; j < len ; j++){
				output[i][j] = '\0';
			}
		}

	}
	
#endif
	return CAESAR_SUCCESS;
}
