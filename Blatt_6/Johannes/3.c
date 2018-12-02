//Studentendatenbank
#include<stdio.h>
#define CLEAR(s) memset(&(s), 0, sizeof(s))

typedef struct {
	unsigned long matrikel;
	char vorname[30];
	char nachname[30];
} student;

void clear_students(student *s, int len){
	for(int i = 0; i<len; i++){	
		CLEAR(s[i].matrikel);
		CLEAR(s[i].vorname);
		CLEAR(s[i].nachname);
	}
	
}

void remove_student(student *s, int mnr, int len){
	for(int i = 0; i < len; i++){
		if(s[i].matrikel == mnr){
			CLEAR(s[i].matrikel);
			CLEAR(s[i].vorname);
			CLEAR(s[i].nachname);
		}
	}
}

void print_student(student *s, int i){
	printf("\nVorname = %s, Nachname = %s, Matrikelnummer = %u", s[i].vorname, s[i].nachname, s[i].matrikel);
}

void print_students(student *s, int len){
	printf("\nListe der Studenten:");
	int leer = 1;
	for(int i = 0; i < len; i++){
		if(s[i].matrikel != 0 || strlen(s[i].vorname) != 0 || strlen(s[i].nachname) != 0){
		print_student(s, i);
		leer = 0;
		}
	}
	if(leer == 1){printf(" Liste ist leer.");}
	printf("\n");
}

void add_student(student *s, int mnr, char *vorname, char *nachname, int max){
	int added = 0;
	for(int i = 0; i < max; i++){
		if(s[i].matrikel == 0 && strlen(s[i].vorname) == 0 && strlen(s[i].nachname) == 0){
			s[i].matrikel = mnr;
			strcpy(s[i].vorname, vorname);
			strcpy(s[i].nachname, nachname);
			added = 1;
			break;
		}
	}
	if (added == 0){printf("Kein Platz!");}
}

void get_name(student *s, int mnr, int len){
	char erg[50] = "Studenten nicht gefunden";
	for(int i = 0; i < len; i++){
		if(s[i].matrikel == mnr){
			strcpy(erg, s[i].nachname);
		}
	}
	printf("\nName Student mit Matrikelnummer %i: %s\n", mnr, erg);
}

int main(void){
	int max = 20;
	student *arr;
	arr = (student*) malloc(max*sizeof(student));

	clear_students(arr, max);
	add_student(arr, 42 ,"Vorname Nr.1", "Nachname Nr.1", max);
	get_name(arr, 42, max);
	add_student(arr, 30, "Vorname Nr.2", "Nachname Nr.2", max);
	remove_student(arr, 42, max);
	print_students(arr, max);
	clear_students(arr, max);
	print_students(arr, max);
	
	return 0;
}