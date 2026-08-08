#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024

#define COLOR_OFF	"\033[0m"
#define COLOR_BLACK	"\033[0;30m"
#define COLOR_RED	"\033[0;31m"
#define COLOR_GREEN	"\033[0;32m"
#define COLOR_BROWN	"\033[0;33m"
#define COLOR_BLUE	"\033[0;34m"
#define COLOR_PURPLE	"\033[0;35m"
#define COLOR_CYAN	"\033[0;36m"

inline static caesar_status_t Menu(int* choice);
inline static caesar_status_t user_input(char* input, size_t size);
inline static caesar_status_t file_input(char* path, char* input, size_t size);
inline static void file_print(char* path, char* output);

int main(void)
{
	char* output, input[8 * BUFFER_SIZE] = {'\0'}, path[BUFFER_SIZE];
	int select, key = 0;
	_Bool isEncrypt;     

	while(1)
	{
		if(Menu(&select) == CAESAR_INVALID_INPUT){
			fprintf(stderr, "\n%s[ERROR]: INVALID INPUT%s\n\n", COLOR_RED, COLOR_OFF);
			return CAESAR_INVALID_INPUT;
		}
		getchar();

		/**
		 * 1. Encrypt User Input
		 * 2. Decrypt User Input
		 * 3. Encrypt File Input
		 * 4. Decrypt File Input
		 * 9. Terminate Program
		 */

		/**
		 * Select input way
		*/
		if(select == 1){
		        isEncrypt = 1;
			if(user_input(input, sizeof(input)) != CAESAR_SUCCESS){
				return CAESAR_INVALID_INPUT;
		}}else if(select == 2){
			isEncrypt = 0;
			if(user_input(input, sizeof(input)) != CAESAR_SUCCESS){
				return CAESAR_INVALID_INPUT;
		}}else if(select == 3){
			isEncrypt = 1;
			if(file_input(path, input, sizeof(input)) != CAESAR_SUCCESS){
				return CAESAR_INVALID_INPUT;
		}}else if(select == 4){
			isEncrypt = 0;
			if(file_input(path, input, sizeof(input)) != CAESAR_SUCCESS){
				return CAESAR_INVALID_INPUT;
		}}else if(select == 9){
			break;
		}else{
			printf("\n%s[System]: Select in 1 - 5%s\n\n", COLOR_BLUE, COLOR_OFF);
			continue;
		}
		
		
		printf("[Input Key]: ");
		if(scanf("%d", &key) != 1){
			fprintf(stderr, "\n%s[ERROR]: INVALID INPUT%s\n\n", COLOR_RED, COLOR_OFF);
			return CAESAR_INVALID_INPUT;
		}
				
		output = (char*)malloc(sizeof(char) * strlen(input) + 1);
	
		if(output == NULL){
			fprintf(stderr, "\n%s[ERROR]: FAILED TO ALLOCATE MEMORY%s\n\n", COLOR_RED, COLOR_OFF);
			return CAESAR_NULL_POINTER;
		}


		/*
		 * ENCRYPTION LOGIC
		 */
		if(isEncrypt == 1){
			if(caesar_encrypt(input, output, &key) 
					!= CAESAR_SUCCESS){
				fprintf(stderr, "\n%s[ERROR]: FAILED TO ENCRYPT SENCTENCE%s\n\n", COLOR_RED, COLOR_OFF);
				return CAESAR_INVALID_INPUT;
		}}else if(isEncrypt == 0){
			if(caesar_decrypt(input, output, &key) 
					!= CAESAR_SUCCESS){
				fprintf(stderr, "\n%s[ERROR]: FAILED TO DECRYPT SENCTENCE%s\n\n", COLOR_RED, COLOR_OFF);
				return CAESAR_INVALID_INPUT;
		}}

		/**
		 * Print output
		 * Reset array value 
		 * Free dynamic memory
		 */
		if(select <= 2){
			printf("[RESULT]: %s\n", output);
		}else if(select <= 4){
			file_print(path, output);
		}
	
		memset(input, 0, sizeof(input));
		memset(&key, 0, sizeof(key));
		free(output);

		printf("\n");
	}

	printf("%s[System]: Terminate Program...%s\n\n", COLOR_BLUE, COLOR_OFF);

	return 0;
}


inline caesar_status_t Menu(int* choice)
{
	printf("============= CAESAR CIPHER PROGRAM =============\n");
	printf("%s1.\tEncrypt Sentence\n", COLOR_GREEN);
	printf("2.\tDecrypt Sentence%s\n", COLOR_OFF);
	printf("%s3.\tEncrypt File\n", COLOR_PURPLE);
	printf("4.\tDecrypt File%s\n", COLOR_OFF);
	printf("%s9.\tTerminate Program%s\n", COLOR_BLUE, COLOR_OFF);
	printf("=================================================\n");
	printf("Select: ");

	if(scanf("%d", choice) != 1)
		return CAESAR_INVALID_INPUT;
	
	return CAESAR_SUCCESS;
}


inline caesar_status_t user_input(char* input, size_t size)
{
	printf("[Input Sentence]: ");

	if(fgets(input, size, stdin) == NULL){
		fprintf(stderr, "\n%s[ERROR]: FAILED TO GET STRING%s\n\n", COLOR_RED, COLOR_OFF);
		return CAESAR_INVALID_INPUT;
	}



	return CAESAR_SUCCESS;
}


inline caesar_status_t file_input(char* path, char* input, size_t size)
{
	char buffer[BUFFER_SIZE];
	FILE* fp;
	int len[2];

	printf("[Path]: ");
	if(!scanf("%s", path)){
		fprintf(stderr, "%s\n[ERROR]: INVALID INPUT%s\n\n", COLOR_RED, COLOR_OFF);
		return CAESAR_INVALID_INPUT;
	}

	fp = fopen(path, "r");
	if(fp == NULL){
		fprintf(stderr, "\n%s[ERROR]: FAILED TO OPEN FILE%s\n\n", COLOR_RED, COLOR_OFF);
		return CAESAR_INVALID_FILE;
	}
	
	while(1)
	{	
		if(fgets(buffer, sizeof(buffer), fp) == NULL){
			break;
		}
		
		len[0] = strlen(input);
		len[1] = strlen(buffer);

		strncat(input, buffer, size - len[0]);
	}

	return CAESAR_SUCCESS;
}

inline static void file_print(char* path, char* output){
	FILE* fp = fopen(path, "w");

	fprintf(fp, "%s", output);

	fclose(fp);
	
	printf("\n%s[SYSTEM]: SUCCESS TO WRITE RESULT ON FILE%s\n", COLOR_BLUE, COLOR_OFF);

	return;
}
