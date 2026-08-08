#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024

typedef struct{
	char plaintext[256];
	char ciphertext[256];
	int key;
}CASE_TEST;


int main(int argc, char* argv[])
{
	/** Expected Checking List
	 * 1. Basic En/Decryption
	 * 2. Boundary Value
	 * 3. Special characters
	 * 4. Empty String
	 * 5. NULL value
	 * 6. En/Decrption round trip
	 */

	CASE_TEST ctest[] = {
	    {"ABCDEF", "DEFGHI", 3},
	    {"abcdef", "defghi", 3},
	    {"UVWXYZ", "XYZABC", 3},
	    {"ABCDEF", "ABCDEF", 0},
	    {"ABCDEF", "ZABCDE", 25},
	    {"ABCDEF", "ABCDEF", 26},
	    {"Hello, World!", "Khoor, Zruog!", 3},
	    {"", "", 3},
	};

	char output[3][BUFFER_SIZE] = {
		{'\0'},
		{'\0'},
		{'\0'}
	};

	size_t len;
	
	for(size_t i = 0; i < 8; i++)
	{
		/**
		 * Basics Encryption Test
		 */

		if(caesar_encrypt(ctest[i].plaintext, output[0], ctest[i].key)
				!= CAESAR_SUCCESS){
			printf("[SYSTEM]: Fail");
		}else{
			printf("[SYSTEM]: Success");
		}
		printf(" to Encryption\n");
		
		if(strcmp(ctest[i].ciphertext, output[0]) == 0){
			printf("[SYSTEM]: Success");
		}else{
			printf("[SYSTEM]: Fail");
		}
		printf(" to verify encryption logic\n");

		/**
		 * Basic Decryption Test
		 */
		
		if(caesar_decrypt(ctest[i].ciphertext, output[1], ctest[i].key)
				!= CAESAR_SUCCESS){
			printf("[SYSTEM]: Fail");
		}else{
			printf("[SYSTEM]: Success");
		}
		printf(" to Decryption\n");
		
		if(strncmp(ctest[i].plaintext, output[1], strlen(ctest[i].plaintext)) == 0){
			printf("[SYSTEM]: Success");
		}else{
			printf("[SYSTEM]: Fail");
		}

		printf(" to verify decryption logic\n");

		/**
		 * Round-Trip Test
		 */

		caesar_decrypt(output[0], output[2], ctest[i].key);

		if(strncmp(ctest[i].plaintext, output[2], 
				strlen(ctest[i].plaintext)) == 0){
			printf("[SYSTEM]: Success");
		}else{
			printf("[SYSTEM]: Fail");
		}

		printf(" to round trip test\n\n");

		for(int j = 0;j < 3; j++){
			memset(output[j], sizeof(output[j]), sizeof(output[j]));
		}
	}

	/**
	 * NULL value Test
	 */

	if(caesar_encrypt(NULL, output[0], ctest[8].key) == CAESAR_NULL_POINTER){
		printf("[SYSTEM]: Sucess");
	}else{
		printf("[SYSTEM]: Fail");
	}

	printf(" to NULL value Test (Encryption)\n");
	if(caesar_decrypt(NULL, output[0], ctest[8].key)
			== CAESAR_NULL_POINTER){
		printf("[SYSTEM]: Success");
	}else{
		printf("[SYSTEM]: Fail");
	}

	printf(" to NULL value Test (Decryption)\n");


	return CAESAR_SUCCESS;
}
