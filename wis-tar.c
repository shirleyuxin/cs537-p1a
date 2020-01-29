#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	if(argc > 2) {
		FILE *fp_in = fopen(argv[1], "w");
		if(fp_in == NULL) {
			printf("wis-tar: cannot open file\n");
                        exit(1);
		}
		int i = 2;
		while( i < argc) {
			FILE *fp = fopen(argv[i],"r");
			if(fp == NULL) {
				printf("wis-tar: cannot open file\n");
				exit(1);
			}

			char dest[100];
			strncpy(dest, argv[i], 100);
			fwrite(dest, 1, sizeof(dest), fp_in);
			
			fseek(fp, 0L, SEEK_END);
			long int res = ftell(fp);
			if(res != -1) {
				fwrite(&res, sizeof(res), 1, fp_in);
			}

			fseek(fp, 0, SEEK_SET);
			char* buffer;
     			size_t bufSize = 1024;
    			buffer = (char*) malloc(bufSize * sizeof(char));
			//size_t size;
			while (getline(&buffer, &bufSize, fp) != -1) {
				//fputs(buffer, fp_in);
				int m = 0;
				m = strlen(buffer);
				fwrite(buffer, sizeof(char), m, fp_in);
			}
			free(buffer); 
     			fclose(fp);
     			i++;
		}
		fclose(fp_in);	
	} else {
		printf("wis-tar: tar-file file […]\n");
		exit(1);
	}
	return 0;
}
