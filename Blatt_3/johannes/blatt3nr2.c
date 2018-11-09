#include<stdio.h>

double a_mittel(double *array, unsigned length){
	double res = 0;
	for(int i = 0; i<length; i++){
	  res += (array[i]/length);
	}
	return res;
}

double varianz(double *array, unsigned length, double mittel){
	double res = 0;
	for(int i = 0; i<length; i++){
	  res += ((array[i]-mittel)*(array[i]-mittel)/(length -1));
	}
	return res;
}

int main(void){
	unsigned n;
	printf("Bitte Stichprobengroesse angeben: ");
	scanf("%u", &n);
	double *probe;
	probe = malloc(n * sizeof(double));
	
	for(int i = 0; i<n; i++){
	  printf("\nBitte Wert angeben: ");
	  scanf("%lf", &probe[i]);
	}
	//temp zum Testen
	/*printf("\n");
	for(int i = 0; i<n; i++){
	  printf("[%lf] ", probe[i]);
	}*/
	
	printf("\nArithmetisches Mittel: %lf", a_mittel(probe, n));
	printf("\nVarianz: %lf", varianz(probe, n, a_mittel(probe, n)));
	return 0;
}
