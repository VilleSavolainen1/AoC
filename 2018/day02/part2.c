#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LENGTH 27  
#define LINES 250 


int main() {
	FILE *file = fopen("input.txt", "r");
	char buf[MAX_LENGTH];
	char lines[LINES][MAX_LENGTH];
	int line;
	int index = 0;
	while((line = fscanf(file, "%s", buf)) == 1){
		strcpy(lines[index], buf);
		index++;
	}
	char match[2][250];
	char ans[MAX_LENGTH];
	int next;
	int count;
	for(int i=0; i<LINES; i++){
		next = i+1;
		while(next<LINES){
			count = 0;
			for(int j = 0; j < MAX_LENGTH; j++){
				if(lines[i][j] == lines[next][j]){
					count++;
				}
				if(count == MAX_LENGTH-1){
					strcpy(match[0], lines[i]);
					strcpy(match[1], lines[next]);
				}
			}
			next++;
		}
	}
	int indx;
	int ansIndex;
	for(int x = 0; x < 1; x++){
		indx = 0;
		ansIndex = 0;
		while(indx<MAX_LENGTH-1){
			if(match[x][indx] == match[x+1][indx]){
				ans[ansIndex] = match[x+1][indx];
				ansIndex++;
			}
			indx++;
		}
	}
	printf("%s", ans);
	fclose(file);
	return 0;
}
