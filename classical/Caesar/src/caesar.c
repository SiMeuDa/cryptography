/******************************************************************************
 * @file    caesar.c
 * @brief   Implementation of the Caesar cipher.
 *
 * @author  Ye-Seong Kwon
 *
 * @date    2026-08-02
 *
 * @details
 * This file implements the Caesar cipher.
 ******************************************************************************/

#include "caesar.h"
#include <string.h>
#include <stdlib.h>

caesar_status_t caesar_encrypt(
	const char* plaintext,
	char* ciphertext,
	int key
){
	/**
	 * Check input value's validation
	 */
	if(&key == NULL){
		return CAESAR_NULL_POINTER;
	}
	if((key < 0) || (key > CAESAR_ALPHABET_SIZE)){
		return CAESAR_INVALID_KEY;
	}

	if((plaintext == NULL) ||
	(ciphertext == NULL)){
		return CAESAR_NULL_POINTER;
	}

	size_t text_len = strlen(plaintext);
	char to_number;

	for(size_t i = 0; i < text_len; i++)
	{
		/**
		 * ready to shift alphabet
		 * preserve non-alphabet
		 */
		if(plaintext[i] >= 'A' && plaintext[i] <= 'Z'){
			to_number = 'A';
		}else if(plaintext[i] >= 'a' && plaintext[i] <= 'z'){
			to_number = 'a';
		}else{
			ciphertext[i] = plaintext[i];
			continue;
		}

		/**
		 * SHIFT LOGIC
		 *
		 * 1. Make alphabet char to alphabet sequence value
		 * 2. Shift key
		 * 3. Assure alphabet range
		 * 4. Make alphabet sequence to char alphabet
		 */

		ciphertext[i] = ((plaintext[i] - to_number + key) % CAESAR_ALPHABET_SIZE);
		ciphertext[i] += to_number;

	}

	ciphertext[text_len] = '\0';

	return CAESAR_SUCCESS;
}

caesar_status_t caesar_decrypt(
	const char* cipheredtext,
	char* deciphertext,
	int key
){

	/**
	 * Check input value's validation
	 */

	if(&key == NULL){
		return CAESAR_NULL_POINTER;
	}

	if((key < 0) || (key > CAESAR_ALPHABET_SIZE)){
		return CAESAR_INVALID_KEY;
	}

	if((cipheredtext == NULL) ||
	(deciphertext == NULL)){
		return CAESAR_NULL_POINTER;
	}

	size_t text_len = strlen(cipheredtext);
	char to_number; 

	key = 26 - key;

	for(size_t i = 0; i < text_len; i++)
	{
		/**
		 * Check char's value
		 * Set char value for shift logic
		 * if value is alphabet, ready to shift
		 * else non-alphabet save result
		 */
		if(cipheredtext[i] >= 'A' && cipheredtext[i] <= 'Z'){
			to_number = 'A';
		}else if(cipheredtext[i] >= 'a' && cipheredtext[i] <= 'z'){
			to_number = 'a';
		}else{
			deciphertext[i] = cipheredtext[i];
			continue;
		}

		/**
		 * SHIFT LOGIC
		 *
		 * 1. Make alphabet char to alphabet sequence value
		 * 2. Shift key
		 * 3. Assure alphabet range
		 * 4. Make alphabet sequence to char alphabet
		 */

		deciphertext[i] = ((cipheredtext[i] - to_number + key) % CAESAR_ALPHABET_SIZE);
		deciphertext[i] += to_number;
	}

	deciphertext[text_len] = '\0';
	

	return CAESAR_SUCCESS;
}
