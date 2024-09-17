#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 27 

int cmpfunc(const void *a, const void *b){
	return (*(char*)a - *(char*)b);
}

void countChars(char str[], int *two, int *three){
	qsort(str, strlen(str), sizeof(str[0]), cmpfunc);
	int index;
	int index2;
	for(int i = 0; i < MAX_LENGTH; i++){
		index = i+1;
		index2 = i+2;
		if(str[i-1] != str[i] && str[i] == str[index] && str[i] != str[index2] && str[i] != str[index2+1]){
			(*two)++;	
			break;
		}
	}

	for(int j = 0; j < MAX_LENGTH; j++){
		index = j+1;
		index2 = j+2;
		if(str[j] != str[j-1] && str[j] == str[index] && str[j] == str[index2] && str[j] != str[index2+1]){
			(*three)++;	
			break;
		}
	}
}

int main() {
	FILE *file = fopen("input.txt", "r");
	char buf[MAX_LENGTH];
	char lines[251][MAX_LENGTH];
	int line;
	int index = 0;
	while((line = fscanf(file, "%s", buf)) == 1){
		strcpy(lines[index], buf);	
		index++;
	}
	int two = 0;
	int three = 0;
	for(int i = 0; i < index; i++){
		countChars(lines[i], &two, &three);
	}
	printf("part1 %d", two * three);

	fclose(file);
	return 0;
}
