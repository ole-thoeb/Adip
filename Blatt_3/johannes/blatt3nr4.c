#include<stdio.h>
#include<math.h>

/* Berechnung von Hand 4a)
x1  = 10000.0        = 10000
x2  = -1.0e-3 / 9.0  = -1/9000
x3  = 25.0e2         = 2500
x4  = 1.0e-3 / 7.0   = 1/7000
x5  = -12.5e3        = -12500


10000+(-1/9000)+2500+1/7000+(-12500)
=10000+2500-12500-1/9000+1/7000
=12500-12500-1/9000+1/7000
=0-1/9000+1/7000
=1/7000-1/9000
=9/63000-7/63000
=2/63000
=1/31500

→ 0.001/31.5
=1e-3/31.5
*/

float floatsum(float *array, unsigned len){
	float erg = 0;
	for(int i = 0; i<len; i++){
		erg+= array[i];	
	}
	return erg;
}

double doublesum(double *array, unsigned len){
	double erg = 0;
	for(int i =0; i<len; i++){
		erg+= array[i];	
	}
	return erg;
}

float newsum(float *array, unsigned len){
	float s = 0, sold = 0, d = 0;
	for(int i = 0; i<len; i++){
		sold = s;
		s += array[i];
		d += (array[i] - (s - sold));
		s = s + d;
	}
	return s;
}

double newsum_double(double *array, unsigned len){
	double s = 0, sold = 0, d = 0;
	for(int i = 0; i<len; i++){
		sold = s;
		s += array[i];
		d += (array[i] - (s - sold));
		s = s + d;
	}
	return s;
}

int main(void){
	float xf[5]; // = {10000.0, -1.0e-3/9.0, 25.0e2, 1.0e-3/7.0, -12.5e3};
	xf[0] = 10000;
	xf[1] =  -1.0e-3/9.0;
	xf[2] = 25.0e2;
	xf[3] = 1.0e-3/7.0;
	xf[4] = -12.5e3;
	
	double xd[5]; //= {10000.0, -1.0e-3/9.0, 25.0e2, 1.0e-3/7.0, -12.5e3};
	xd[0] = 10000;
	xd[1] =  -1.0e-3/9.0;
	xd[2] = 25.0e2;
	xd[3] = 1.0e-3/7.0;
	xd[4] = -12.5e3;
	
	//Für Suche nach Fehlern
	/*for(int i = 0; i<5; i++){
		printf("[%f] - ", xf[i]);
		printf("[%lf]\n", xd[i]);
	}*/
	
	printf("float-Summe: %f\n", floatsum(xf, 5));
	printf("double-Summe: %lf\n", doublesum(xd, 5));
	printf("Algorithmus - float: %f\n", newsum(xf, 5));
	printf("Das Spezialverfahren ist besser geeignet, da in diesem Fall Rundungsfehler wieder rueckgaengig gemacht werden koennen.\n\tWaehrend bei der einfachen Addition durch die hohen Zahlen und den Gleitpunkt Genauigkeit bei den Nachkommastellen verloren geht, \n\tkann in dem Spezialverfahren die Variable D fuer die Genauigkeit bei den Nachkommastellen sorgen.\n" );
	printf("Algorithmus - double: %lf\n", newsum_double(xd, 5));
	return 0;
}
