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

	double a1 = a;
	int n1 = n;
	while(n1 > 1){
		if (n1 % 2 == 0) {
			n1 /=2;
			a1 *= a1;
		}else{
			a1 *= a1 * 2;
			n1 = (n1-1) / 2;
		}
	}
	
	produkt = a1;
	printf("%lf^%i = %lf\n", a, n, produkt);
	return 0;
}

/*
a) braucht für a^17 17 Schritte, da die Schleife von 1 bis 17 läuft.
a) braucht für a^17 4 Schritte, da:
	1) (17 - 1) / 2 = 8
	2) 8 / 2 = 4
	3) 4 / 2 = 2
	4) 2 / 2 = 1
*/