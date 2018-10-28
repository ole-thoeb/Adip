#include <stdio.h>

int main(int argc, char const *argv[]){
	double a;
	printf("Bitte gib eine Zahl ein: ");
	int check = scanf("%lf", &a);
	//wenn die Eingabe das falsche Format hat
	if (check != 1){
		puts("Fehlerhafte Eingabe!");
		return 1;
	}

	int n;
	printf("Bitte gib eine positive, ganze Zahl ein: ");
	check = scanf("%i", &n);
	//wenn die Eingabe das falsche Format hat oder die Eingabe nicht positiv ist
	if (check != 1 || n < 1){
		puts("Fehlerhafte Eingabe!");
		return 1;
	}

	double produkt = 1;
	for(int i = 1; i <= n; i++){
		produkt *= a;
	}
	
	printf("%lf^%i = %lf\n", a, n, produkt);
	return 0;
}