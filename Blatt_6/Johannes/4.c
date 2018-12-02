#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

double f(double x) {
	return 0.4*pow(x,5)+pow(x,3);
}

double integrate(double(*fnct)(double), double left, double right, double stepsize) {
	// Sie koennen die Funktion fnct wie gewohnt aufrufen
	double erg = 0;
	for(double i = left; i <= right; i = i + stepsize){
		//Integration via Addition von Balken (Funktionswert * stepsize)
		erg += fnct(i)*stepsize;
	}
	return erg;
}

int main(int argc, char**argv) {
	printf("Integral von Sinus [0, pi]: %f\n", integrate(&sin, 0, M_PI, 0.0001)); //2
	printf("Integral von Sinus [0, 2pi]: %f\n", integrate(&sin, 0, 2*M_PI, 0.0001)); //0
	printf("Integral von f(x)=0.4x^5+x^3 [0, 3]: %f\n", integrate(&f, 0, 3, 0.0001)); //ca. 68,84
return 0;
}