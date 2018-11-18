#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printReversed(char *inStr){
	int len = strlen(inStr);
	char *reversedStr = malloc(len + 1);
	
	for(int i = 0; i < len; i++){
		reversedStr[i] = inStr[len - i - 1];
	}
	reversedStr[len] = '\0';
	printf(reversedStr);
	free(reversedStr);
}

int isPalindrom(char *inStr){
	int len = strlen(inStr);
	
	for(int i = 0; i < len; i++){
		if (inStr[i] != inStr[len - i - 1]) {
			return 0;
		}	
	}
	return 1;
}

int main(int argc, char const *argv[]){
	printReversed("emil");
	printf("%i\n", isPalindrom("anna"));
	return 0;
}
