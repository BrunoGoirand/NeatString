/**
 * Neat String library test file
 *
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "NeatString.h"


/*
** command line argument management
*/
int checkArgs(int nbArg, int argc, char **argv) {

	fprintf(stderr, "# args: %d\n", argc);
	for(int i = 1; i<argc; i++)
		fprintf(stderr, "arg[%d]: [%s](%lu)\n", i, argv[i], strlen(argv[i]));

	if(argc != nbArg) {
		fprintf(stdout, "Usage: %s", argv[0]);
		for(int j = 1; j < nbArg; j++)
			fprintf(stdout, " string%d", j);
		fprintf(stdout, "\n");
		return(EXIT_FAILURE);
	}

  return(EXIT_SUCCESS);
}


/**
 * 
 */
int main(int argc, char **argv) {

	checkArgs(2, argc, argv);

	char *result;
	result = ltrim(argv[1]);
	fprintf(stdout, "[%s](%lu)\n", result, strlen(result));

	result = rtrim(argv[1]);
	fprintf(stdout, "[%s](%lu)\n", result, strlen(result));

	result = ltrim(result);
	fprintf(stdout, "[%s](%lu)(%d)\n", result, strlen(result), charHap(result, ' '));

	result = itrim(argv[1]);
	fprintf(stdout, "[%s](%lu)\n", result, strlen(result));
	free(result);

	return(EXIT_SUCCESS);
}


/**
 *
 */
