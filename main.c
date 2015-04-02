#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* args[]){
	/*----------------------------------------*\
					MAIN VARIABLES
	\*----------------------------------------*/



	/*----------------------------------------*\
					PREPARATIONS
	\*----------------------------------------*/
	FILE* file;
	char* c = "/words.txt";
	int stringLength = strlen(args[1]);
	char filePath[stringLength];
	strcpy(filePath,args[1]);
	strcat(filePath,c);

	printf("---> Search for words.txt in %s\n\n",filePath);
	file = fopen(filePath,"r");
	if(file==NULL){
		perror(filePath);
		printf("---> The file words.txt doesn't exit in the directory: %s\n\n",args[1]);
		fclose(file);
		return 1;
	}
	else
	{
		printf("---> The file words.txt was found! Preparing for indexing.\n\n");
	}

	/*----------------------------------------*\
				GET WORDS FROM WORDS.TXT
	\*----------------------------------------*/
	int nWords = 0;
	int ch;
	char buf[256];
	while (EOF != (ch=fgetc(file))){
    	if (ch=='\n')
        	nWords++;
	}
	if(nWords <= 0){
		printf("---> You have no words in words.txt. Please insert them line by line.");
		return 2;
		fclose(file);
	}
	fclose(file);
	file = fopen(filePath,"r");
	printf("---> Number of words: %d\n\n",nWords);
	char* words[nWords];
	int index = 0;
	printf("---> WORDS:\n\n");
	while (fgets (buf, sizeof(buf), file)) {
		words[index] = strtok(buf,"\n");
    	printf("- %s\n", buf);
    	index++;
  	}
  	printf("\n");


	/*----------------------------------------*\
				CREATE SUB-PROCESSES
	\*----------------------------------------*/



	return 0;
}