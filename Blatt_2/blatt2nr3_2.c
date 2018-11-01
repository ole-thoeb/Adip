#include<stdio.h>

void deficient(unsigned int n){
	unsigned sum = 0;
	for(int i = 1; i<n; i++){
		if(n%i==0){
			sum += i;
		}
	}
	if (sum < n){
		printf("\n%u ist deficient.", n);
	} else {
		printf("\n%u ist nicht deficient.", n);
	}
}

int main(void){
	unsigned int n;
	printf("Bitte eine natuerliche Zahl eingeben: ");
	scanf("%u", &n);
	
	deficient(n);
	
	// Tests
	deficient(14);
	deficient(18);
	deficient(25);
	deficient(28);
	deficient(51);
	
	return 0;
}