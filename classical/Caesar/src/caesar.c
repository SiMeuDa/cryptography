#include "../include/caesar.h"
#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

caesar_status_t caesar_encrypt(
	const char* plaintext,
	char** ciphertext,
	volatile int key
){
	if((key < 0) || (key > 26)){
		return INVALID_KEY;
	}

	if((plaintext == NULL) ||
	(ciphertext == NULL)){
		return NULL_POINTER;
	}

	int text_len = strlen(plaintext);
	char to_number;

	for(int i = 0; i < text_len; i++)
	{
		if(plaintext[i] >= 'A' && plaintext[i] <= 'Z'){
			to_number = 'A';
		}else if(plaintext[i] >= 'a' && plaintext[i] <= 'z'){
			to_number = 'a';
		}else{
			(*ciphertext)[i] = plaintext[i];
			continue;
		}

		(*ciphertext)[i] = ((plaintext[i] - to_number + key) % 26);
		(*ciphertext)[i] += to_number;

	}

	(*ciphertext)[text_len] = '\0';

#ifdef __STDC_LIB_EXT1__
	memset_s(&key, sizeof(key), 0, sizeof(key));
#else	
	key = 0;
#endif

	return SUCCESS;
}

caesar_status_t caesar_decrypt(
	const char* cipheredtext,
	char** deciphertext,
	int key
){
	if((key < 0) || (key > 26)){
		return INVALID_KEY;
	}

	if((cipheredtext == NULL) ||
	(deciphertext == NULL)){
		return NULL_POINTER;
	}

	int text_len = strlen(cipheredtext);
	char to_number; 

	key = 26 - key;

	for(int i = 0; i < text_len; i++)
	{
		if(cipheredtext[i] >= 'A' && cipheredtext[i] <= 'Z'){
			to_number = 'A';
		}else if(cipheredtext[i] >= 'a' && cipheredtext[i] <= 'z'){
			to_number = 'a';
		}else{
			(*deciphertext)[i] = cipheredtext[i];
			continue;
		}

		(*deciphertext)[i] = ((cipheredtext[i] - to_number + key) % 26);
		(*deciphertext)[i] += to_number;
	}

	(*deciphertext)[text_len] = '\0';

#ifdef __STDC_LIB_EXT1__
	memset_s(&key, sizeof(key), 0, sizeof(key));
#else	
	key = 0;
#endif
	
	return SUCCESS;
}
