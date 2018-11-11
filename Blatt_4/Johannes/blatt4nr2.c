//rekursive Berechnungen
#include <stdio.h>

// Gibt den Nachfolger des ubergebenen Wertes zuruck
int succ(int x) {
	return ++x;
}
// Gibt den Vorganger des ubergebenen Wertes zuruck
int pre(int x) {
	return --x;
}

int add(int x, unsigned int y){
	if(y>0){
		return add(succ(x), pre(y));
	} else {
		return x;
	}	
}

int sub(int x, unsigned int y){
	if(y>0){
		return sub(pre(x), pre(y));
	} else {
		return x;
	}	
}

/* Anmerkung:
	4 * 3 = 4 + 4 + 4 
	Hier muss wahrscheinlich noch eine bessere Erklärung hin, warum mult funktioniert.
*/

int mult(int x, unsigned int y){
	if(y>1){
		return add(x, mult(x,pre(y)));
	} else {
		return x;
	}	
}


int main() {
	int x;
	unsigned int y;
	printf("Bitte 2 Zahlen angeben\nGanze Zahl: ");
	scanf("%i", &x);
	printf("\nNatuerliche Zahl: ");
	scanf("%ui", &y);
	
	printf("\nAddition: %i + %i = %i", x, y, add(x,y));
	printf("\nSubtraktion: %i - %i = %i", x, y, sub(x,y));
	printf("\nMultiplikation: %i * %i = %i", x, y, mult(x,y));

return 0;
}