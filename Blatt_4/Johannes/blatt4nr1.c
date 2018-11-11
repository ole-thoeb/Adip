//Binomialkoeffizienten
#include <stdio.h>

/* rekursive Variante (für den Fall, das jemand die Aufgabenstellung nicht lesen kann...)
long long fak_rek(long long n){
	if (n == 0 || n == 1){
		return 1;

	} else {
		return n*fak_rek(n-1);
	}
}
*/

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

/* Anmerkung: Diese Variante der Berechnung des Binomialkoeffizienten ist schlecht,
da die einzelnen Faktoren schnell sehr sehr groß werden (zB. passt fak_rek(21) schon nicht mehr in longlong)
Besser wäre eine rekursive Berechnung.
*/

long long binomial(int n, int k){
	long long erg = 0;
	if (n > k){
	erg = fak(n)/(fak(k)*fak(n-k));
	return erg;
	} else {
		return 0;
	}
}

long long lotto(int n, int k){
	long long erg = 0;
	erg = binomial(n, k)*fak(k);
	return erg;
}

int main() {
	int n, k;
	printf("Bitte 2 Parameter fuer Binomialkoeffizienten angeben:\nParameter n: ");
	scanf("%i", &n);
	printf("\nParameter k: ");
	scanf("%i", &k);
	
	printf("\nn ueber k: %lld", binomial(n, k));
	printf("\nMoeglichkeiten, %i aus %i zu ziehen: %lld", k, n, lotto(n,k));	
return 0;
}
