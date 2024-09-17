#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 8

int main(){
	FILE *file = fopen("input.txt", "r");
	int sum = 0;
	int index = 0;
	char line[MAX_LINE_LENGTH];
	int *arr = (int*)malloc(sizeof(int) * 1000000);
	int *sums = (int*)malloc(sizeof(int) * 1000000);
	while(fgets(line, MAX_LINE_LENGTH, file)){
		int num = atoi(line);
		arr[index] = num;
		++index;
	}
	int index2 = 0;
	while(1){
		for(int i = 0; i < index; ++i){
			sum += arr[i];
			sums[index2] = sum;
			if(index2 == (index-1))printf("part1: %d\n", sums[index2]); // part 1
			for(int x = 0; x < index2; ++x){
				if(sums[x] == sum){
					printf("part2 %d\n", sums[x]); // part 2
					exit(1);
				}
			}
			++index2;
		}
	}
	fclose(file);
	return 0;
}
