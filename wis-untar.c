#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
	if(argc >= 2) {
		int i = 1;
		while(i < argc) {
			FILE *fp = fopen(argv[i],"rb");
                	if(fp == NULL) {
                      		printf("wis-untar: cannot open file\n");
                        	exit(1);
               	 	}
			while(1) {
				size_t nameSize = 1024;
				char *name = (char*) malloc(nameSize *sizeof(char));
                		long int size;

				fread(name, 100, 1, fp);
				FILE *newfp = fopen(name, "w");
				if(newfp == NULL) {
					printf("wis-untar: cannot open file\n");
                                	exit(1);
				}

				fread(&size, sizeof(size), 1, fp);

				char *buffer = (char*) malloc(size * sizeof(char));
				fread(buffer, sizeof(char), size, fp);
				fwrite(buffer, sizeof(char), size, newfp);
				
				long int pos = ftell(fp);

				free(buffer);
				free(name);
				fclose(newfp);

				char c;
				if((c = fgetc(fp)) == EOF) {
					break;
				}

				fseek(fp, pos, SEEK_SET);
			}
			fclose(fp);
			i++;
		}

	} else {
		printf("wis-untar: tar-file\n");
		exit(1);
	}
	return 0;
}
