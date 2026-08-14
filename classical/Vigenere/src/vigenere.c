/******************************************************************************
 * @file    vigenere.c
 * @brief   Implementation of the Vigenere cipher.
 *
 * @author  Ye-Seong Kwon
 *
 * @date    2026-08-06
 *
 * @details
 * This file implements the Vigenere cipher.
 ******************************************************************************/
#include "../include/vigenere.h"
#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include <stdlib.h>

vigenere_status_t vigenere_encrypt(
	const char* plaintext,
	char* ciphertext,
	char* key
){
	/**
	 * Check input value's validation
	 * Check NULL pointer
	 */
	if((key == NULL) || (strlen(key) == 0)){
		return INVALID_KEY;
	}

	if((plaintext == NULL) ||
	(ciphertext == NULL)){
		return NULL_POINTER;
	}

	int text_len = strlen(plaintext), key_len = strlen(key), key_index = 0, count = 0;
	char to_number;

	/**
	 * Check key value' validation & Change to Integer 
	 */
	for(int i = 0; i < key_len; i++){
		if(key[i] >= 'A' &&
			key[i] <= 'Z'){
			key[i] -= 'A';
		}else if(key[i] >= 'a' &&
			key[i] <= 'z'){
			key[i] -= 'a';
		}else{
			return INVALID_KEY;
		}
	}

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
			to_number ='a';
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

		ciphertext[i] = ((plaintext[i] - to_number + key[count % key_len]) % ALPHABET_SIZE);
		ciphertext[i] += to_number;

		count++;

	}

	ciphertext[text_len] = '\0';


	/**
	 * SECURE KEY ERASE
	 *
	 * if compiler support memset_s, use that
	 * else erase key value to 0
	 */
#ifdef __STDC_LIB_EXT1__
	memset_s(key, key_len, 0, key_len);
#else	
	for(int i = 0; i < key_len; i++)
		key[i] = '\0';
#endif

	return SUCCESS;
}

vigenere_status_t vigenere_decrypt(
	const char* cipheredtext,
	char* deciphertext,
	char* key
){

	/**
	 * Check input value's validation
	 * Check NULL pointer
	 */
	if((key == NULL) || (strlen(key) == 0)){
		return INVALID_KEY;
	}

	if((cipheredtext == NULL) ||
	(deciphertext == NULL)){
		return NULL_POINTER;
	}

	int text_len = strlen(cipheredtext), key_len = strlen(key), count = 0;
	char to_number; 

	/**
	 * Check key value' validation & Change to Integer 
	 * Check key contain non-alphabet
	 * Change to integer don't related to alphabet case
	 */
	for(int i = 0; i < key_len; i++){
		if(key[i] >= 'A' &&
			key[i] <= 'Z'){
			key[i] -= 'A';
		}else if(key[i] >= 'a' &&
			key[i] <= 'z'){
			key[i] -= 'a';
		}else{
			return INVALID_KEY;
		}
		key[i] = ALPHABET_SIZE - key[i];
	}

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

		deciphertext[i] = ((cipheredtext[i] - to_number + key[count % key_len]) % ALPHABET_SIZE);
		deciphertext[i] += to_number;

		count++;
	}

	deciphertext[text_len] = '\0';

	/**
	 * SECURE KEY ERASE
	 *
	 * if compiler support memset_s, use that
	 * else erase key value to 0
	 */
#ifdef __STDC_LIB_EXT1__
	memset_s(key, key_len, 0, key_len);
#else	
	for(int i = 0; i < key_len; i++)
		key[i] = '\0';
#endif

	return SUCCESS;
}
