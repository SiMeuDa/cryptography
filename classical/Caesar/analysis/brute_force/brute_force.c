#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char input_text[1024];
	char* output_text;

	printf("[Input Text]: ");
	if(fgets(input_text, sizeof(input_text), stdin) == NULL){
		fprintf(stderr, "[ERROR]: FAILED TO GET STRING\n");
		return INVALID_INPUT;
	}

	output_text = (char*)malloc(sizeof(char*) * (strlen(input_text) + 1));
	if(output_text == NULL){
		fprintf(stderr, "[ERROR]: FAILED TO ALLOCATE MEMORY\n");
		return NULL_POINTER;
	}

	for(int key = 0; key < 26; key++){
		if(caesar_encrypt(
			input_text, 
			&output_text, 
			key
		) != SUCCESS){
			free(output_text);
			fprintf(stderr, "[ERROR]: FAILED TO ENCRYPT MESSAGE\n");
			return INVALID_INPUT;
		}
		printf("[Output(key = %d)]:\t%s", key, output_text);
	}

	free(output_text);

	return SUCCESS;
}
