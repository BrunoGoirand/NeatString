#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#include "NeatString.h"


/**
 * Remove CPP comments
 * WARNING - Pointer allocation that needs to be freed
 */
char *removeCPPComments(char *str) {

	char *result;
	int cursor = stringHap(str, "//");
	size_t sLen = strlen(str);

	if(cursor == -1) {

		result = (char *) malloc(sLen + 1);	// always add null terminating string '\0'
		strcpy(result, str);
		return(result);
	}

	result = (char *) malloc(cursor + 1);	// always add null terminating string '\0'
	strncpy(result, str, cursor);
	result[cursor] = '\0';

	return(result);
}


/**
 *  transform a string to lower case
 *  WARNING - Pointer allocation that needs to be freed
 */
char *lowerCase(char *str) {

	int len = strlen(str);
	char *result = (char *) malloc(len + 1);	// always add null terminating string '\0'

	for(int i = 0; i < len; i++)
		result[i] = (str[i] >= 65 && str[i] <=90) ? str[i] + 32 : str[i];
	
	return(result);
}


/**
 *  transform a string to upper case
 *  WARNING - Pointer allocation that needs to be freed
 */
char *upperCase(char *str) {

	int len = strlen(str);
	char *result = (char *) malloc(len + 1);	// always add null terminating string '\0'

	for(int i = 0; i < len; i++)
		result[i] = (str[i] >= 97 && str[i] <=122) ? str[i] - 32 : str[i];
	
	return(result);
}


/**
 * count the number of occurrence of the character 'c' in the string str
 * 
 */
int charHap(char *str, char c) {

	int found = 0;
	for(int i = 0; i < strlen(str); i++) {
		if(str[i] == c)
			found++;
	}

	return(found);
}

// specific version using "spaces" treated by 'isspace()'
//
int charSpaceHap(char *str) {

	int found = 0;
	for(int i = 0; i < strlen(str); i++) {
		if(isspace(str[i]))
			found++;
	}

	return(found);
}

// look for a string and return the position in the input string
// return -1 if the string was not found
//
int stringHap(char *str, char *lookFor) {

	//fprintf(stderr, "-StringHAP-");
	int found = 0;
	size_t sLen = strlen(str),
		lfLen = strlen(lookFor);

	for(size_t i = 0; i < (sLen - lfLen + 1); i++) {

		if(str[i] == lookFor[0]) {

			found = 1;
			for(size_t j = 1; j < lfLen; j++)
				if(str[i+j] != lookFor[j])
					found = 0;

		}

		if(found) {
			//fprintf(stderr, "||%lu||\n", i);
			return((int)(i));
		}
	}

	//fprintf(stderr, "NOT_FOUND\n");
	return(-1);
}

/**
 * trim functions
 * 
 * "spaces" treated by 'isspace()' include:
 * 
 * ' '  (0x20) space (SPC)
 * '\t' (0x09) horizontal tab (TAB)
 * '\n' (0x0a) newline (LF)
 * '\v' (0x0b) vertical tab (VT)
 * '\f' (0x0c) feed (FF)
 * '\r' (0x0d) carriage return (CR)
 * 
 */
// left trim
char *ltrim(char *str) {

	size_t cursor = 0;
	char *result;

	while(isspace(str[cursor]))
		cursor++;
		
	result = (char *) malloc(strlen(str) - cursor + 1);	// always add null terminating string '\0'
	strcpy(result, str + cursor);

	return(result);
}

// right trim
char *rtrim(char *str) {

	size_t cursor = strlen(str) - 1;
	char *end = str + cursor,
		*result;

	while(isspace(str[cursor])) 
		cursor--;

	result = (char *) malloc(++cursor + 1);	// always add null terminating string '\0'
	strncpy(result, str, cursor);
	result[cursor] = '\0';

	return(result);
}

// right + left trim
char *trim(char *str) {

	char *intermediate, *result;

	intermediate = ltrim(str);
	result = rtrim(intermediate);
	free(intermediate);

	return(result);
}

// left + right + inside
char *itrim(char *str) {

   int count = charSpaceHap(str),
      inputLen = strlen(str),
      outputLen = inputLen-count;

	//fprintf(stderr, "inside[%d][%d][%d]\n", count, inputLen, outputLen);

   char *result = (char *) malloc(outputLen + 1);	// always add null terminating string '\0'

   int j = 0;
   for(int i= 0; i < inputLen; i++)
      if(!isspace(str[i]))
         result[j++] = str[i];

   result[j] = '\0';
   return(result);
}

/**
 *
 */
