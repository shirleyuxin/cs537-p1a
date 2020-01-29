#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if(argc == 2) {
		char *buffer;
                size_t bufSize = 512;
               	buffer = (char*) malloc(bufSize * sizeof(char));
		while(getline(&buffer, &bufSize, stdin) != -1) {
			if((strstr(buffer, argv[1])) != NULL) {
                         	//printf("this line has %s in it\n", argv[1]);
                               	printf("%s", buffer);
                        }
		}
		free(buffer);	
	} else if (argc >= 3) {

		int i = 2;
		while(i < argc) {
			FILE *fp = fopen(argv[i], "r");
			if(fp == NULL) {
				printf("wis-grep: cannot open file\n");
				exit(1);
			}
			
			char *buffer;
			size_t bufSize = 512;
			buffer = (char*) malloc(bufSize * sizeof(char));
			
     			while(getline(&buffer, &bufSize, fp)!= -1){
       				if((strstr(buffer, argv[1])) != NULL) {
					//printf("this line has %s in it\n", argv[1]);
					printf("%s", buffer);
				}
     			}
    
     			fclose(fp);
     			i++;
			free(buffer);
		}
	} else {
		printf("wis-grep: searchterm [file …]\n");
                exit(1);
	}
	return 0;	
}
