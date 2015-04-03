#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char* args[]){
	/*----------------------------------------*\
					MAIN VARIABLES
	\*----------------------------------------*/
	FILE* file;
	char* c = "/words.txt";
	int stringLength = strlen(args[1]);
	char filePath[stringLength];

	/*----------------------------------------*\
					PREPARATIONS
	\*----------------------------------------*/

	/* check if words.txt exists and open it */
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

	/* check if other files exist */
	int count = 0;
	DIR* dir = opendir(args[1]);
	struct dirent* dp;
	printf("--> CHAPTER FILES TO INDEX:\n\n");
	while((dp = readdir(dir)) != NULL){
		if( strstr(dp->d_name,".txt") != NULL)
			if( (strcmp(dp->d_name,"0_ReadMe.txt") != 0) 
				&& (strcmp(dp->d_name, "words.txt") != 0) 
				&& (strcmp(dp->d_name, "index.txt") != 0)){
				printf("%s\n",dp->d_name);
				count++;
			}
				
	}
	closedir(dir);
	if(count==0){
		printf("--> There aren't any chapter files to index.\n\n");
		return 2;
	}
	printf("\n--> Number of chapter files in the directory: %d\n\n", count);

	/*----------------------------------------*\
				GET WORDS FROM WORDS.TXT
	\*----------------------------------------*/

	/* count the number of words in words.txt */
	int nWords = 0;
	int ch;
	char buf[256];
	while (EOF != (ch=fgetc(file))){
    	if (ch=='\n')
        	nWords++;
	}
	if(nWords <= 0){
		printf("---> You have no words in words.txt. Please insert them line by line.");
		return 3;
		fclose(file);
	}
	fclose(file);

	/* print all the words in words.tx */
	file = fopen(filePath,"r");
	char* words[nWords];
	int index = 0;
	printf("---> WORDS:\n\n");
	while (fgets (buf, sizeof(buf), file)) {
		words[index] = strtok(buf,"\n");
    	printf("- %s\n", buf);
    	index++;
  	}
  	printf("\n");
  	printf("---> Number of words: %d\n\n",nWords);


	/*----------------------------------------*\
				CREATE SUB-PROCESSES
	\*----------------------------------------*/



	return 0;
}