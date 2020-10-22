#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if(argc < 2){
		printf("insufficient arguments\n");
		return 0;
	}	
	

	FILE* fp = fopen(argv[1], "r");
	
	unsigned int X = atoi(argv[1]);
	fscanf(fp, "%d\n", &X);
	char content[15];
	int pair;
	while(fscanf(fp, "%s\t%d\n", content, &pair) != EOF){
		unsigned int count = 0;
		unsigned int prevBit = 0;
		unsigned int currBit = 0;
		while(X){
			currBit = X & 01;
			if(currBit == 1){
				count++;
			}
			if(currBit == prevBit){
				pair++;
			}
			currBit = prevBit;
			X >>= 1;
		}
		if(count % 2 == 0){
			printf("%s\t%d\n", content, pair);
		}
		else{
			printf("%s\t%d\n", content, pair);
		}		
	}		
 	fclose(fp);
 	return 0;
}
