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

#include "../include/caesar.h"
#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include <stdlib.h>

caesar_status_t caesar_encrypt(
	const char* plaintext,
	char** ciphertext,
	volatile int key
){
	/**
	 * Check input value's validation
	 */

	if((key < 0) || (key > ALPHABET_SIZE)){
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
		/**
		 * Check char's value
		 * Set char value for shift logic
		 * if value is alphabet, ready to shift
		 * else non-alphabet save result
		 */
		if(plaintext[i] >= 'A' && plaintext[i] <= 'Z'){
			to_number = 'A';
		}else if(plaintext[i] >= 'a' && plaintext[i] <= 'z'){
			to_number = 'a';
		}else{
			(*ciphertext)[i] = plaintext[i];
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

		(*ciphertext)[i] = ((plaintext[i] - to_number + key) % ALPHABET_SIZE);
		(*ciphertext)[i] += to_number;

	}

	(*ciphertext)[text_len] = '\0';


	/**
	 * SECURE KEY ERASE
	 *
	 * if compiler support memset_s, use that
	 * else erase key value to 0
	 */
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

	/**
	 * Check input value's validation
	 */

	if((key < 0) || (key > ALPHABET_SIZE)){
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
			(*deciphertext)[i] = cipheredtext[i];
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

		(*deciphertext)[i] = ((cipheredtext[i] - to_number + key) % ALPHABET_SIZE);
		(*deciphertext)[i] += to_number;
	}

	(*deciphertext)[text_len] = '\0';

	/**
	 * SECURE KEY ERASE
	 *
	 * if compiler support memset_s, use that
	 * else erase key value to 0
	 */
#ifdef __STDC_LIB_EXT1__
	memset_s(&key, sizeof(key), 0, sizeof(key));
#else	
	key = 0;
#endif
	
	return SUCCESS;
}
