#include <stdio.h>
#include <math.h>

unsigned long long fac(int n){
	unsigned long long p = 1;
	for(int i = 1; i <= n; i++){
		p *= i;
	}
	return p;
}

double msin(float x){
	double erg = 0;
	for(int n = 0; n < 6; n++){
		erg += pow(-1, n) * (pow(x, 2 * n + 1)/ fac(2 * n + 1));
	}
	return erg;
}

double mcos(float x){
	double erg = 0;
	for(int n = 0; n < 6; n++){
		erg += pow(-1, n) * (pow(x, 2 * n)/ fac(2 * n));
	}
	return erg;
}

double mexp(float x){
	double erg = 0;
	for(int n = 0; n < 11; n++){
		erg += pow(x, n)/ fac(n);
	}
	return erg;

}

int main(int argc, char const *argv[]){
    float number;
    puts("Bitte gib ein Zahl ein: ");
    int check = scanf("%f", &number);
    //wenn die Eingabe das falsche Format hat
    if (check != 1) {
        puts("Fehlerhafte Eingabe!");
        return 1;
    }

	printf("Sin %lf\n", msin(number));
	printf("Cos %lf\n", mcos(number));
	printf("Exp %lf\n", mexp(number));
}