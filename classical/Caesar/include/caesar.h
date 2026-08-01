#ifndef CAESAR_H
#define CAESAR_H

typedef enum
{
	SUCCESS = 0,
	NULL_POINTER,
	INVALID_KEY,
	INVALID_INPUT

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
        char** ciphertext,
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
        char** deciphertext,
	int key
);

#endif
