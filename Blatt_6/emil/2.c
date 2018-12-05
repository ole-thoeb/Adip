#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nachname[30];
	float note;
} student;

int main(int argc, char const *argv[]){
	int N;
	printf("Wie viele Daten einlesen? N = ");
	scanf("%i", &N);

	student **studArg = malloc(sizeof(student) * N);
	char name[30];
	float note;
	for(size_t i = 0; i < N; i++){
		printf("Note");
		scanf("%f", &note);
		if(note < 1.0 || note > 5.0){
			puts("falsche Eingabe");
			i--;
			continue;
		}
		printf("Name");
		scanf("%s", name);
		student *s = malloc(sizeof(student));
		strcpy(s->nachname, name);
		s->note = note;
		studArg[i] = s;
	}
	
	float bestGrade = 5.0;
	float gradeSum = 0.0;
	for(size_t i = 0; i < N; i++){
		if (studArg[i]->note < bestGrade) {
			bestGrade = studArg[i]->note;
		}
		gradeSum += studArg[i]->note;
	}
	
	for(size_t i = 0; i < N; i++){
		if(studArg[i]->note == bestGrade) printf("%s:%f\n", studArg[i]->nachname, studArg[i]->note);
	}

	printf("Durchschnitt %f", gradeSum / N);
	
	return 0;
}