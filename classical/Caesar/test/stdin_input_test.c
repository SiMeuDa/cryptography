#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char input_text[1024];
	char* output_text;
	int key, isEncrypt = 1;

	printf("[Input Text]: ");
	if(fgets(input_text, sizeof(input_text), stdin) == NULL){
		fprintf(stderr, "[ERROR]: FAILED TO GET STRING\n");
		return INVALID_INPUT;
	}

	printf("[Input Key]: ");
	if(!scanf("%d", &key)){
		fprintf(stderr, "[ERROR]: INVALID INPUT\n");
		return INVALID_INPUT;
	}
	
	printf("[Ecrypt(yes: 1, no: 0)]: ");
	if(!scanf("%d", &isEncrypt)){
		fprintf(stderr, "[ERROR]: INVALID INPUT\n");
		return INVALID_INPUT;
	}


	output_text = (char*)malloc(sizeof(char*) * (strlen(input_text) + 1));
	if(output_text == NULL){
		fprintf(stderr, "[ERROR]: FAILED TO ALLOCATE MEMORY\n");
		return NULL_POINTER;
	}

	if(isEncrypt == 1){
		if(caesar_encrypt(
			input_text, 
			&output_text, 
			key
		) != SUCCESS){
			free(output_text);
			fprintf(stderr, "[ERROR]: FAILED TO ENCRYPT MESSAGE\n");
			return INVALID_INPUT;
	}}else if(isEncrypt == 0){
		if(caesar_decrypt(
			input_text,
			&output_text,
			key
		) != SUCCESS){
			free(output_text);
			fprintf(stderr, "[ERROR]: FAEILD TO DECRYPT MESSAGE\n");
			return INVALID_INPUT;
	}}else{
		free(output_text);
		fprintf(stderr, "[ERROR]: INVALID INPUT\n");
		return INVALID_INPUT;
	}

	printf("[Output]: %s\n", output_text);

	free(output_text);

	return SUCCESS;
}
