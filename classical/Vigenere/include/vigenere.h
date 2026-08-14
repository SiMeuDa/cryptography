/******************************************************************************
 * @file    vigenere.h
 * @brief   Implementation of the Vigenere cipher.
 *
 * @author  Ye-Seong Kwon
 *
 * @date    2026-08-06
 *
 * @details
 * This file implements the Vigenere cipher.
 ******************************************************************************/

#ifndef VIGENERE_H
#define VIGENERE_H


/**
 * @brief
 * Constants for alphabet's range
 * size of alphabet is 26 (A - Z)
 */
#define ALPHABET_SIZE 26

/**
 * @brief 
 * Constants for indicating status in vigenere logic.
 *
 * SUCCESS:             on succes to logic.
 * NULL_POINTER:        on fail to logic caused by NULL pointer.
 * INVALID_KEY:         on fail to logic caused by key range (0 - 26).
 * INVALID_INPUT:       on fail to logic caused by IO system.
 */
typedef enum
{
        SUCCESS = 0,
        NULL_POINTER,
        INVALID_KEY,
        INVALID_INPUT,
	FAIL_FILEIO,
	FAIL_STDIO

} vigenere_status_t;

/**
 * @brief Encrypt plaintext using Vigenere cipher
 *
 * Alphabet is shifted to right each key value
 * Non-alphabet characters remain plaintext
 *
 * @param plaintext     Input buffer.
 * @param ciphertext    Output buffer.
 * @param key           Shift value.
 * 
 * @return SUCCESS
 * @return NULL_POINTER
 * @return INVALID_KEY
 */

vigenere_status_t vigenere_encrypt(
        const char* plaintext,
        char* ciphertext,
        char* key
);

/**
 *
 * @brief Deencrypt plaintext using Vigenere cipher
 *
 * Alphabet is shifted to left each key value
 * Non-alphabet characters remain plaintext
 *
 * @param cipheredtext  Input buffer.
 * @param deciphertext  Output buffer.
 * @param key           Shift value.
 * 
 * @return SUCCESS
 * @return NULL_POINTER
 * @return INVALID_KEY
 */
vigenere_status_t caesar_decrypt(
        const char* cipheredtext,
        char* deciphertext,
        char* key
);

#endif
