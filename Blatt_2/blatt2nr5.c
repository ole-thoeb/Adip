#include<stdio.h>
//Funktion power wird (exp+1)-mal aufgerufen [das letzte mal zum Abschluss mit return 1]
//Funktion power_case wird aufgerufen: 2^ (1+min{k : 2^k > exp}) - 1
//a in sprüngen bei 2er-Exponenten

//globale Variable zum Mitzählen der Aufrufe
unsigned nr_p = 0, nr_pc = 0;

double power_case(double basis, unsigned exp){
	nr_pc +=1;
	if (exp == 0){
		return 1;
	} else if (exp%2==0){
		return power_case(basis, exp/2) * power_case(basis, exp/2);
	} else {
		return basis * power_case(basis, (exp-1)/2) * power_case(basis, (exp-1)/2);
	}
	
}

double power(double basis, unsigned exp){
	nr_p += 1;
	if(exp>0){
		return basis * power(basis, exp-1);
	} else {
		return 1;
	}
}

int main(void){
	double basis;
	unsigned int n;
	
	printf("Bitte Basis angeben: ");
	scanf("%lf", &basis);
	printf("\nBitte Exponenten angeben: ");
	scanf("%u", &n);
	
	printf("\n%lf hoch %u = %lf", basis, n, power(basis,n));
	printf("\n(Via Fallunterscheidung) - %lf hoch %u = %lf", basis, n, power_case(basis,n));
	printf("\nFallunterscheidung: %u aufgerufen --- Primitiv iterativ: %u aufgerufen.", nr_pc, nr_p); 
	
	//Zur Suche nach der Formel der Anzahl der Funtionsaufrufe
	/*for(int i = 1; i<100; i+=1){
		nr_p = 0;
		nr_pc = 0;
		basis = power(2,i);
		basis = power_case(2,i);
		printf("\n [Exp = %u] Fallunterscheidung: %u aufgerufen --- Primitiv iterativ: %u aufgerufen.", i, nr_pc, nr_p);
	
	}
	*/
	return 0;
}