#include<stdio.h>

int deficient(unsigned int n){
	unsigned sum = 0;
	for(int i = 1; i<n; i++){
		if(n%i==0){
			sum += i;
		}
	}
	if (sum < n){
		return 1;
	} else {
		return 0;
	}
}

unsigned number_deficient(unsigned int n){
	int erg = 0;
	for(int i = 1; i < n; i++){
		if(deficient(i)==1){
			//für Testzwecke
			//printf(" [%i] ", i);
			erg += 1;
		}
	}
	return erg;
}


int main(void){
	unsigned int n;
	printf("Bitte eine natuerliche Zahl eingeben: ");
	scanf("%u", &n);
	
	printf("\nAnzahl von defizienten Zahlen < %u: %u", n, number_deficient(n));
	
	
	return 0;
}