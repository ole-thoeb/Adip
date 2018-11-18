#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* encrypt(char *s, int k){
	int len = strlen(s);
	//len +1 für \0 am ende
	char *outStr = malloc(len + 1);
	for(int i = 0; i < len + 1; i++){
		if(s[i] >= 65 && s[i] <= 90){
			//((((zwischen 0-25)bereich 0-25)bereich 0-25 falls negativ))auf ascii wert
			outStr[i] = ((((s[i] - 65 + k) % 26) + 26) % 26) + 65;
		}else if(s[i] >= 97 && s[i] <= 122){
			outStr[i] = ((((s[i] - 97 + k) % 26) + 26) % 26) + 97;
		}else{
			outStr[i] = s[i];
		}
	}
	return outStr;
}

char* decrypt(char *s, int k){
	return encrypt(s, -k);
}

int main(int argc, char const *argv[]){
	
    char str[40];
    puts("Bitte gib ein Wort ein: ");
    scanf("%s", &str);

	int k;
    puts("Bitte gib eine Zahl ein: ");
	int check = scanf("%i", &k);
    //wenn die Eingabe das falsche Format hat
    if (check != 1) {
        puts("Fehlerhafte Eingabe!");
        return 1;
    }

	char *cryptStr = encrypt(str, k);
	printf("%s\n", cryptStr);
	printf("%s\n", decrypt(cryptStr, k));
	return 0;
}
