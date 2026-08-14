#include "vigenere.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 256

typedef struct{
	char input[STR_SIZE];
	char expected[STR_SIZE];
	char key[STR_SIZE];
}TEST_CASE;

int main(void)
{
	/** 
	 * 1. Basic En/Decryption
         * 2. Boundary Value
         * 3. Special characters
         * 4. Empty String
         * 5. NULL value
         * 6. En/Decrption round trip
	 */

	char output[STR_SIZE];
	
	TEST_CASE ctest[] = {
	{"Hello World", "Khoor Zruog", "DDD"},
	{"Sphinx of black quartz, judge my vow", "Alfrje wb zuwjs msjnah, fsmcl uu txs", "Secret"},
	{"ZZZZZZZ", "AZMAZMA", "BAN"},
	{"ZZZZZZZ", "XLNRXXL", "COMIC"},
	{"Man Of Mission", "Lam Oe Lirshnn", "ZAZAZ"},
	{"!@#$%^&*()", "!@#$%^&*()", "KEYVALUE"},
	{"Hello World", "Hello World", "!@#"},
	{"", "", "KEY"},
	{"Hello World", "Hello World", ""},
	{"ROUND", "ROUND", "TRIP"}
	};
	
	/**
	 * 1 - 2 TEST
	 */

	for(int i = 0; i <= 4; i += 2)
	{
		if(vigenere_encrypt(ctest[i].input, output, ctest[i].key)
			!= VIGENERE_SUCCESS){
			fprintf(stderr, "[SYSTEM]: FAILED TO ENCRYPT STRING(%s)\n", ctest[i].input);
			return 1;
		}else if(strcmp(output, ctest[i].expected) != 0){
			fprintf(stderr, "[SYSTEM]: INVALID ENCRYPT LOGIC(%d)\n", i);
			return 1;
		}

		if(vigenere_decrypt(ctest[i + 1].input, output, ctest[i + 1].key)
			!= VIGENERE_SUCCESS){
			fprintf(stderr, "[SYSTEM]: FAILED TO DECRYPT STRING(%s)\n", ctest[i].input);
			return 1;
		}else if(strcmp(output, ctest[i + 1].expected) != 0){
			fprintf(stderr, "[SYSTEM]: INVALID DECRYPT LOGIC(%d)\n", i + 1);
			return 1;
		}
	}
	
	/**
	 * 3 Special characters TEST
	 */

	if(vigenere_encrypt(ctest[5].input, output, ctest[5].key)
		!= VIGENERE_SUCCESS){
		fprintf(stderr, "[SYSTEM]: INVALID ENCRYPT LOGIC(5)\n");
		return 1;
	}else if(vigenere_decrypt(ctest[6].input, output, ctest[6].key)
		!= VIGENERE_INVALID_KEY){
		fprintf(stderr, "[SYSTEM]: INVALID KEY LOGIC(6)\n");
		return 1;
	}

	/**
	 * 4 Empty String TEST
	 */

	if(vigenere_encrypt(ctest[7].input, output, ctest[7].key)
		!= VIGENERE_SUCCESS){
		fprintf(stderr, "[SYSTEM]: INVALID ENCRYPT LOGIC\n");
		return 1;
	}else if(strcmp(output, ctest[7].expected) != 0){
		fprintf(stderr, "[SYSTEM]: INVALID ENCRYPT LOGIC(7)\n");
		return 1;
	}

	if(vigenere_decrypt(ctest[8].input, output, ctest[8].key)
		!= VIGENERE_INVALID_KEY){
		fprintf(stderr, "[SYSTEM]: INVALID KEY LOGIC(8)\n");
		return 1;
	}

	/**
	 * 5 NULL vaule TEST
	 */

	if(vigenere_encrypt(NULL, output, "KEY")
		!= VIGENERE_NULL_POINTER){
		fprintf(stderr, "[SYSTEM]: INVALID NULL LOGIC(9)\n");
		return 1;
	}

	if(vigenere_decrypt("INPUT", output, NULL)
		!= VIGENERE_INVALID_KEY){
		fprintf(stderr, "[SYSTEM]: INVALID NULL LOGIC(10)\n");
		return 1;
	}

	/**
	 * 6 Round-Trip TEST
	 */
	char temp[STR_SIZE];
	vigenere_encrypt(ctest[9].input, temp, ctest[9].key);
	
	vigenere_decrypt(temp, output, ctest[9].key);

	if(strcmp(output, ctest[9].expected) != 0){
		fprintf(stderr, "[SYSTEM]: FAILED TO ROUND TRIP TEST\n");
		return 1;
	}

	printf("[SYSTEM]: SUCCESS TO ALL TEST\n");


	return 0;
}
