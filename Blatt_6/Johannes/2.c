//Studenten & Noten
#include<stdio.h>

typedef struct {
	char nachname[30];
	float note;
} student;

// Nur für Testzwecke
void printstudents(student *s, int len){
	for(int i = 0; i < len; i++){
		printf("\nName des %i. Studenten: %s", i, s[i].nachname);
		printf("\nNote des %i. Studenten: %f", i, s[i].note);
	}	
}

void printbeststudents(student *s, int len){
	//Teil 1 - Beste Note suchen:
	float bestnote = s[0].note;
	for(int i = 1; i < len; i++){
		if(s[i].note < bestnote){
			bestnote = s[i].note;
		}
	}
	
	// Teil 2 - Alle mit bestnote ausgeben:
	for(int j = 0; j < len; j++){
		if(s[j].note == bestnote){
			printf("\nBester Student: %s [Note = %f]", s[j].nachname, s[j].note);
		}
	}
}

void printaveragegrade(student *s, int len){
	double avg = 0;
	for(int i = 0; i < len; i++){
		avg += (s[i].note/(double)len);
	}
	printf("\n\nDurchschnittliche Note: %lf", avg);
}	

int main(void){
	unsigned anzahl = 0;
	printf("Bitte Anzahl von Studenten angeben: ");
	scanf("%ui", &anzahl);
	
	student *arr;
	arr = (student*) malloc(anzahl*sizeof(student));
	
	for(int i = 0; i < anzahl; i++){
		printf("\nName des %i. Studenten: ", i);
		scanf("%s", &arr[i].nachname);
		//Bedingung für korrekte Noten - funktioniert, solange man keinen totalen Unsinn eingibt.
		while(arr[i].note < 1.0 || arr[i].note > 5.0){
			printf("Note des %i. Studenten: ", i);
			scanf("%f", &arr[i].note);
		}
	}
	
	//Nur für Testzwecke
	//printstudents(arr, anzahl);
	
	printbeststudents(arr, anzahl);
	printaveragegrade(arr, anzahl);
	free(arr);
	return 0;
}