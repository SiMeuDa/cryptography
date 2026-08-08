#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024

typedef struct{
	char str[128];
	int key;
}CASE_TEST;


int main(int argc, char* argv[])
{
	int key;
	FILE* fp;
	void* ret_ptr = NULL;

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
		if(caesar_encrypt(ctest[i].str, output[0], ctest[i].key)
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
		
		caesar_decrypt(output[2], output[3], ctest[i].key);

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
	
	return CAESAR_SUCCESS;
}
