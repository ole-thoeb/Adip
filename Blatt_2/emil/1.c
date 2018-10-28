#include <stdio.h>
int main(){
	char x1,x2,result;
	// Beispiel 1:
	x1 = 35;
	x2 = 85;
	result = x1 + x2;
	printf("Beispiel 1: %hi + %hi = %hi\n",x1 ,x2, result);
	// Beispiel 2:
	x1 = 85;
	x2 = 85;
	result = x1 + x2;
	printf("Beispiel 2: %hi + %hi = %hi\n",x1 ,x2, result);
	return 0;
}

/*Erklärung:
In Beispiel 1 funktioniert die Addition normal, da der Speicher ausreicht.
In Beispiel 2 kommt es zu einem Overflow. Ein char hat nur 8 Bit Speicher, 
deckt mit negativen Zahlen also den Zahlenbereich -128 bis 127 ab. 85 + 85
ist 170, also größer als die maximale Zahl, deshalb kommt es zum Overflow.
Die -86 kommt auf Grund der Zweierkomplimentdarstellung zu stande: 
170 - 128 - 128 = -86
*/