#include <stdio.h>

unsigned long long fakultaet(int n){
	unsigned long long p = 1;
	for(int i = 1; i <= n; i++){
		p *= i;
	}
	return p;
}

unsigned long long binomialkoeffizient(int n, int k){
	if(n < k) return 0;
	return fakultaet(n) / (fakultaet(k) * fakultaet(n - k));
}

long long lotto(int n, int k){
	return binomialkoeffizient(n, k) * fakultaet(k);
}

int main(int argc, char const *argv[])
{
	int k, n;

	printf("Bei einer Ziehung von k Karten = ");
    int check = scanf("%d", &k);
    //wenn die Eingabe das falsche Format hat
    if (check != 1) {
        puts("Fehlerhafte Eingabe!");
        return 1;
    }

	printf("aus n Karten = ");
    check = scanf("%d", &n);
    //wenn die Eingabe das falsche Format hat 
    if (check != 1) {
        puts("Fehlerhafte Eingabe!");
        return 1;
    }

	printf("gibt es bei Beruecksichtigung der Reihenfolge %llu moeglichkeiten", lotto(n, k));
	printf(" und ohne %lld moeglichkeiten", binomialkoeffizient(n, k));
	return 0;
}
