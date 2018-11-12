#include <stdio.h>

int add(int x, int y);
int sub(int x, int y);
// Gibt den Nachfolger des uebergebenen Wertes zurueck
int succ(int x) {
	return ++x;
}

// Gibt den Vorgaenger des uebergebenen Wertes zurueck
int pre(int x) {
	return --x;
}

int add(int x, int y){
	return y > 0 ? add(succ(x), pre(y)) : x;
}

int sub(int x, int y){
	return y > 0 ? sub(pre(x), pre(y)) : x;
}

int mult(int x, int y){
	return y > 0 ? mult(x, pre(y)) < 0 ? sub(x, -mult(x, pre(y))) : add(x, mult(x, pre(y))) : 0;
}

int main(int argc, char const *argv[])
{
	printf("2 - 0 = %d\n", sub(2, 0));
	printf("2 + 0 = %d\n", add(0, 2));
	printf("2 * 0 = %d\n", mult(2, 0));
	printf("-3 - 2 = %d\n", sub(-3, 2));
	printf("-3 + 2 = %d\n", add(-3, 2));
	printf("-3 * 2 = %d\n", mult(-3, 2));
	return 0;
}
