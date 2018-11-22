#include<stdio.h>

char *encrypt_k(char *s, int k){
	for(int i = 0; i < strlen(s); i++){
		//zum Verständnis ascii-Tabelle angucken: so organisiert, das immer im kleinen Alphabet drinbleibt
		//Fallunterscheidung, um zu verhindern, dass man aus dem Alphabet fliegt.
		if(s[i] > 96 && s[i] < 123 - k){
			s[i] = (s[i] + k);
		} else if(s[i] >= 123 - k && s[i] < 123){
			s[i] = s[i] + k - 123 + 97;
		}
	}

 return s;	
}	

char *decrypt_k(char *s, int k){
	printf("\nEncrypted, k = %i: %s", k, s);
	for(int i = 0; i < strlen(s); i++){
		//zum Verständnis ascii-Tabelle angucken: so organisiert, das immer im kleinen Alphabet drinbleibt
		//Fallunterscheidung, um zu verhindern, dass man aus dem Alphabet fliegt.
		if(s[i] >= 97 + k && s[i] < 123){
			s[i] = (s[i] - k);
		} else if (s[i] < 97 + k){
			s[i] = s[i] - k + 123 - 97;
		}
	}
	printf("\nDecrypted, k = %i: %s", k, s);
 return s;	
}

char *encrypt(char *s){
	for(int i = 0; i < strlen(s); i++){
		//zum Verständnis ascii-Tabelle angucken: so organisiert, das immer im kleinen Alphabet drinbleibt
		//Fallunterscheidung, um zu verhindern, dass man aus dem Alphabet fliegt.
		if(s[i] > 96 && s[i] < 110){
			s[i] = (s[i] + 13);
		} else if(s[i] > 109 && s[i] < 123){
			s[i] = s[i] + 12 - 122 + 97;
		}
	}

 return s;	
}	

char *decrypt(char *s){
	printf("\nEncrypted, k = 13: %s", s);
	for(int i = 0; i < strlen(s); i++){
		//zum Verständnis ascii-Tabelle angucken: so organisiert, das immer im kleinen Alphabet drinbleibt
		//Fallunterscheidung, um zu verhindern, dass man aus dem Alphabet fliegt.
		if(s[i] > 109 && s[i] < 123){
			s[i] = (s[i] - 13);
		} else if (s[i] > 96 && s[i] < 110){
			s[i] = s[i] - 12 + 122 - 97;
		}
	}
	printf("\nDecrypted, k = 13: %s", s);
 return s;	
}	

main(void){
	//input-String ohne Größenbeschränkung
	char input[1000];
	printf("Bitte einzelnes Wort in Kleinbuchstaben eingeben: ");
	scanf("%s", &input);
	
	int k = -1;
	//While zur Eingabe-Kontrolle
	//Frage: warum bricht diese Weil-Schliefe bei k = 26 erfolgreich ab?
	while(k < 0 || k > 26){
		printf("Bitte 0 < k < 27 angeben: ");
		scanf("%i", &k); 
	}
	
	//Variable len als Hilfsmittel zur Erzeugung dynamischer Arrays
	int len = strlen(input);
	
	char *dyn_input; 
	dyn_input = malloc(len*sizeof(char));
	strcpy(dyn_input, input);
	//Übergangslösung - Array-Weitergabe ist verwirrend...
	decrypt(encrypt(dyn_input));
	decrypt_k(encrypt_k(dyn_input, k), k);

	free(dyn_input);
	
	
	//Palindrom-Test
	int palindrom = 1;
	printf("\nChar-Vertauschung: ");
	for(int i = 0; i < len; i++){
		if (input[i] != input[len-i-1]){palindrom = 0;}
		printf("%c", input[len-i-1]);
	}
	if(palindrom == 1){printf("\nInput ist Palindrom");}else{printf("\nInput ist kein Palindrom");}
	
	return 0;
}