#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	if(argc > 2){
		printf("error: expected 1 argument, found %d", argc);
		return -1;
	}
	
	char *joe;
	char recurse = 0;
	if(argc > 1){
		joe = argv[1];
	} else {
		recurse = 1;
		joe = (char *)malloc(256 *sizeof(char));
		fgets(joe, 256, stdin);

		int i;
		for(i = 0; joe[i] != '\0'; i++);
		joe = (char *)realloc(joe,i);
	}

	char *command;
	command = (char *) malloc(sizeof(joe) + sizeof("curl -s -o tmp-ths.txt https://www.merriam-webster.com/thesaurus/"));
	strcpy(command, "curl -s -o tmp-ths.txt https://www.merriam-webster.com/thesaurus/");
	strcat(command, joe);
	
	system(command);
	free(command);

	FILE *fp = fopen("tmp-ths.txt", "r");
	char clonk[512];
	char count = 0;
	while(fgets(clonk, 512, fp) != NULL){
		if(count < 17){
			count++;
			continue;
		}

		int start;
		char line[512];

		for(start = 0; clonk[start] != ':'; start++){}
		for(int f = start; clonk[f] != ';'; f++){
			line[f-start-2] = clonk[f];
		}

		puts(line);
		break;
	}
	system("rm tmp-ths.txt");
	if(recurse)
		main(1,&joe);
}
