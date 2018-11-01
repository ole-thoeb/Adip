#include<stdio.h>

void einmaleins(void){
	for(int i = 1; i <= 10; i++){
		for(int j = 1; j <= 10; j++){
			printf("%i * %i = %i\n", i, j, i*j);
		}
	}
}

int main(void){
	einmaleins();
	return 0;
}