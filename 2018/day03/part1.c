#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 16
#define LINES 3

int main(){

	FILE *file = fopen("input.txt", "r");

	char lines[LINES][LENGTH];
	int line;
	int index = 0;
	int inIndex = 0;
	while((line = fgetc(file)) != EOF){
		if(line == '\n'){
			inIndex = 0;
			index++;
		} else {
			lines[index][inIndex] = line;
			inIndex++;
		}
	}
	for(int i = 0; i < LINES; i++){
		printf("%s\n", lines[i]);
	}

	return 0;
}
