#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char input_text[1024];
	char* output_text;
	void* pStatus;
	int key, isEncrypt = 1;
	FILE* fp;
	_Bool isFirst = 1;

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

	while(1){
		
		fp = fopen("../test/text_file_test.txt", "r");
		if(fp == NULL){
                	fprintf(stderr, "[ERROR]: FAILED TO OPEN READ FILE\n");
                	return INVALID_INPUT;
        	}

		pStatus = fgets(input_text, sizeof(input_text), fp);

		if(pStatus == NULL){
			if(fclose(fp) == EOF){
				fprintf(stderr, "[ERROR]: FAILED TO CLOSE FILE\n");
				return NULL_POINTER;
			}
			break;
		}
		if(fclose(fp) == EOF){
                	fprintf(stderr, "[ERROR]: FAILED TO CLOSE FILE\n");
                	return INVALID_INPUT;
        	}

		output_text = (char*)malloc(sizeof(char) * (strlen(input_text) + 1));
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

		fp = fopen("../test/text_file_test_result.txt", "w+");
		if(fp == NULL){
			fprintf(stderr, "[ERROR]: FAILED TO OPEN WRITE FILE\n");
         	       return INVALID_INPUT;
       		}
		
		if(isFirst == 1){
			fprintf(fp, "[Output]: \n");
			isFirst = 0;
		}

		fprintf(fp, "%s", output_text);
		
		if(fclose(fp) == EOF){
			fprintf(stderr, "[ERROR]: FAILED TO CLOSE FILE\n");
		}

		free(output_text);
	}


	return SUCCESS;
}
