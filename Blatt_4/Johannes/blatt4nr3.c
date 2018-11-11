//sin & cos & exp
#include <stdio.h>
#include <math.h>

long long fak(int n){
	if (n == 0){
		return 1;
	} else {
		long long erg = 1;
		for (int i=1; i <= n; i++){
			erg *= i;
		}
	return erg;
	}
}

double sin(double x){
	double erg = 0;
	for(int i = 0; i<= 5; i++){
		erg += pow(-1, i)*pow(x,2*i+1)/fak(2*i+1);
	}
	return erg;
}

double cos(double x){
	double erg = 0;
	for(int i = 0; i<= 5; i++){
		erg += pow(-1, i)*pow(x,2*i)/fak(2*i);
	}
	return erg;
}

double exp(double x){
	double erg = 0;
	for(int i = 0; i<= 10; i++){
		erg += pow(x,i)/fak(i);
	}
	return erg;
}


int main() {
	double x;
	printf("Bitte reelle Zahl angeben: ");
	scanf("%lf", &x);
	
	printf("\nSinus-Approximation: %lf", sin(x));
	printf("\nCosinus-Approximation: %lf", cos(x));
	printf("\nExp-Approximation: %lf", exp(x));
}