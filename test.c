#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

int main(int argc, char* argv[]){
	char * s;

	s= read();

	printf("%s",s);

	return EXIT_SUCCESS;
}