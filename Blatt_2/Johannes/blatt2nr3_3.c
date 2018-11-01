#include<stdio.h>


int vollkommen(unsigned int n){
	unsigned sum = 0;
	for(int i = 1; i<n; i++){
		if(n%i==0){
			sum += i;
		}
	}
	if (sum == n){
		return 1;
	} else {
		return 0;
	}
}

void all_vollkommen(unsigned int n){
	for(int i = 1; i < n; i++){
		if(vollkommen(i) == 1){
			printf(" %i", i);
		}
	}
}

int main(void){
	unsigned int n;
	printf("Bitte eine natuerliche Zahl eingeben: ");
	scanf("%u", &n);
	
	printf("\n Ausgabe aller vollkommenen Zahlen kleiner %u:", n);
	all_vollkommen(n);
	
	return 0;
}