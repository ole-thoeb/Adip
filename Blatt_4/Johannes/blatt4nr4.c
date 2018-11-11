//Pythagoras-Triplets
#include <stdio.h>
#include <math.h>

int main() {
	int n = 0;
	printf("Bitte gewuenschte Anzahl von Pythagoras-Triplets angeben: ");
	scanf("%i", &n);
	
	int hits = 0, c = 0;
	//Tendentiell nicht sehr effizient, Compiler kommt aber gut damit klar
	while(hits < n){
		c += 1;
		for(int a = 1; a < c; a++){
			for(int b = 1; b < a; b++){
				if(pow(c,2) == pow(a,2)+pow(b,2)){
					printf("\n[%i, %i, %i]", a, b, c);
					hits +=1;
				}
			}
		}		
	}
	return 0;
}