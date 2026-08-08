/******************************************************************************
 * @file    caesar.h
 * @brief   Implementation of the Caesar cipher.
 *
 * @author  Ye-Seong Kwon
 *
 * @date    2026-08-02
 *
 * @details
 * This file implements the Caesar cipher.
 ******************************************************************************/

#ifndef CAESAR_H
#define CAESAR_H

/**
 * @brief
 * Constants for alphabet's range
 * size of alphabet is 26 (A - Z)
 */
#define CAESAR_ALPHABET_SIZE 26

/**
 * @brief 
 * Constants for indicating status in caesar logic.
 *
 * SUCCESS:		on succes to logic.
 * NULL_POINTER:	on fail to logic caused by NULL pointer.
 * INVALID_KEY:		on fail to logic caused by key range (0 - 26).
 * INVALID_INPUT:	on fail to logic caused by IO system.
 */
typedef enum
{
	CAESAR_SUCCESS = 0,
	CAESAR_NULL_POINTER,
	CAESAR_INVALID_KEY,
	CAESAR_INVALID_INPUT,
	CAESAR_INVALID_FILE

} caesar_status_t;

/**
 * @brief Encrypt plaintext using Caesar cipher
 *
 * By using given key, alphabet is shifted to right
 * Non-alphabet characters remain plaintext
 *
 * @param plaintext 	Input buffer.
 * @param ciphertext 	Output buffer.
 * @param key		Shift value.
 * 
 * @return SUCCESS
 * @return NULL_POINTER
 * @return INVALID_KEY
 */
caesar_status_t caesar_encrypt(
	const char* plaintext,
        char* ciphertext,
	int key
);

/**
 *
 * @brief Deencrypt plaintext using Caesar cipher
 *
 * By using given key, alphabet is shifted to left
 * Non-alphabet characters remain plaintext
 *
 * @param cipheredtext 	Input buffer.
 * @param deciphertext 	Output buffer.
 * @param key		Shift value.
 * 
 * @return SUCCESS
 * @return NULL_POINTER
 * @return INVALID_KEY
 */
caesar_status_t caesar_decrypt(
	const char* cipheredtext,
        char* deciphertext,
	int key
);

#endif
