#include<stdio.h>

void vollkommen(unsigned int n){
	unsigned sum = 0;
	for(int i = 1; i<n; i++){
		if(n%i==0){
			sum += i;
		}
	}
	if (sum == n){
		printf("\n%u ist vollkommen.", n);
	} else {
		printf("\n%u ist nicht vollkommen.", n);
	}
}

int main(void){
	unsigned int n;
	printf("Bitte eine natuerliche Zahl eingeben: ");
	scanf("%u", &n);
	
	vollkommen(n);
	
	//Tests
	vollkommen(14);
	vollkommen(18);
	vollkommen(25);
	vollkommen(28);
	vollkommen(51);

	return 0;
}