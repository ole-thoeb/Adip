#include<stdio.h>
#include<string.h>

void lautschrift(unsigned n){
	//Zehnerstelle
	char zehner[4][10];
	strcpy(zehner[0], "zwanzig");
	strcpy(zehner[1], "dreissig");
	strcpy(zehner[2], "vierzig");
	strcpy(zehner[3], "fuefnzig");
	strcpy(zehner[4], "sechzig");
	
	//Einerstelle
	char einer[9][20];
	strcpy(einer[0], "");
	strcpy(einer[1], "ein-und-");
	strcpy(einer[2], "zwei-und-");
	strcpy(einer[3], "drei-und-");
	strcpy(einer[4], "vier-und-");
	strcpy(einer[5], "fuenf-und-");
	strcpy(einer[6], "sechs-und-");
	strcpy(einer[7], "sieben-und-");
	strcpy(einer[8], "acht-und-");
	strcpy(einer[9], "neun-und-");
	
	printf("%s%s",einer[n%10], zehner[(n/10)-2]);	
}
	
int main(void){
	unsigned int n;
	printf("Bitte eine natuerliche Zahl zwischen 20 und 69 eingeben: ");
	scanf("%u", &n);
	//Abbruch bei falschen eingaben
	if(n < 20 || n > 69){goto ende;}
	lautschrift(n);
	
	
	ende:
	return 0;
}