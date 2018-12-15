#include "Stack.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
	Stack s = Stack_new();
	//puts("1");
	Stack_push(s, 4);
	//puts("2");
	Stack_push(s, 2);
	//puts("3");
	Stack_push(s, 1);
	//puts("4");
	printf("%i\n", Stack_peek(s));
	//puts("5");
	Stack_print(s);
	printf("%i\n", Stack_pop(s));
	Stack_print(s);
	printf("%i\n", Stack_isEmpty(s));
	Stack_pop(s);
	Stack_pop(s);
	printf("%i\n", Stack_isEmpty(s));
	return 0;
}
/*
Für eine Queue benötigte man einen weiteren pointer, welcher auf das letzte Element zeigt.
Dieses wird dann bei pop entfernt/bei peek gezeigt.
*/