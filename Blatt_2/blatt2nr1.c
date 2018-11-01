#include <stdio.h>
int main(){
char x1,x2,result;
// Beispiel 1:
x1 =  35;
x2 =  85;
result =  x1 + x2;
printf("Beispiel 1: %hi + %hi = %hi\n",x1 ,x2, result);
// printf("Beispiel 1: %c + %c = %c\n",x1 ,x2, result);
// Beispiel 2:
x1 =  85;
x2 =  85;
result = x1 + x2;
printf("Beispiel 2: %hi + %hi = %hi\n",x1 ,x2, result);
//printf("Beispiel 1: %c + %c = %c\n",x1 ,x2, result);

//char y = 170;
//printf("%c %hi", y,y);
return 0;

/* Erklärung:
x1, x2 sind Chars, enthalten also 8 Bit (darstellbar z.b als Zahl >= 0 und < 256 - Anmerkung unten).
Normalerweise werden die Chars über "%c" ausgegeben - hier wird ihr Wert entsprechend der ascii-Tabelle interpretiert.
Der Printbefehl liest den Char-Inhalt als Integer, und interpretiert den 8-Bit-Wertebereich als Zahl zwischen -128 und 128.
Entsprechend ist der Integerwert von "char c = 255" der Wert "-1".
Daher das verwirrende zweite Beispiel: 85 + 85 = 170 = -86 (denn 170 - 256 = -86).

*/
}