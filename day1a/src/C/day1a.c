#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

long updateTotal(long newValue) {
	static long total=0;

	total+=newValue;
	return total;
}

int main(int argc, char ** argv) {
	int read=0;
	size_t len=0;
	char * line = NULL;
	char * buffer=malloc(64);
	const char * filename = "../../data/datafile";
	FILE * fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "Unable to open %s!\n", filename); 
		exit (-1);
	}
	long total=0;
	while (( read = getline (&buffer, &len, fp)) != -1) {
		line = &buffer[0];
		if (read > 0) {
			line[read-1]=0;
		}
		// printf ("[%s]", line);
		char * e;
		bool negative=false;
		while (('-' == (*line)) || ((*line) == '+'))
  		{
			//printf("Using sign\n");
      			if (*line == '-') {
        			negative=true;
			}
      			line++;
  		}
		long value = strtol(line, &e, 0);
		if (*e != 0 || errno != 0) {
			fprintf(stderr, "Unable to convert %s: Error %d\n", line, errno);
			exit(-1);
		}
		if (negative) {
			value = -value;
		}
		total = updateTotal(value);
		printf("New: %ld   Total: %ld\n", value, total);
	}
	if (buffer) {
		free(buffer);
	}
	printf ("Total: %ld\n",total);
	fclose(fp);

	exit(0);
}
