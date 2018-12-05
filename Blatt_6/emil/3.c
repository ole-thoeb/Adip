#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct studentImpl{
	int matrikelNummer;
	char vorname[30];
	char nachname[30];
};

typedef struct studentImpl* Student;

Student Student_new(int matrikelNummer,	char* vorname,	char* nachname){
	Student s = malloc(sizeof(struct studentImpl));
	s->matrikelNummer = matrikelNummer;
	strcpy(s->vorname, vorname);
	strcpy(s->nachname, nachname);
	return s;
}

void Student_delete(Student s){
	free(s);
}

void print_student(Student s){
	assert(s);
	printf("%s, %s: %i\n", s->nachname, s->vorname, s->matrikelNummer);
}

void clear_students(Student *arg){
	for(int i = 0; i < 20; i++){
		if(arg[i] != NULL){
			Student_delete(arg[i]);
			arg[i] = NULL;
		}
	}
}

Student get_Name(int matrikelNummer, Student *arg){
	for(int i = 0; i < 20; i++){
		if(arg[i]->matrikelNummer == matrikelNummer){
			print_student(arg[i]);
			return arg[i];
		}
	}
	printf("Student mit %i nicht gefunden\n", matrikelNummer);
}

int add_student(int matrikelNummer,	char* vorname,	char* nachname, Student *arg){
	for(int i = 0; i < 20; i++){
		if(arg[i] == NULL){
			arg[i] = Student_new(matrikelNummer, vorname, nachname);
			return 1;
		}
	}
	return 0;
}

int remove_student(int matrikelNummer, Student *arg){
	for(int i = 0; i < 20; i++){
		if(arg[i]->matrikelNummer == matrikelNummer){
			Student_delete(arg[i]);
			arg[i] = NULL;
			return 1;
		}
	}
	return 0;
}

void print_students(Student *arg){
	int empty = 1;
	for(int i = 0; i < 20; i++){
		if(arg[i] != NULL){
			print_student(arg[i]);
			empty = 0;
		}
	}
	if(empty) puts("Liste ist leer");
}

int main(int argc, char const *argv[]){
	Student *arg = malloc(sizeof(Student) * 20);
	
	for(size_t i = 0; i < 20; i++)
		arg[i] = NULL;

	add_student(42, "max", "mustermann", arg);
	get_Name(42, arg);
	puts("name");
	add_student(30, "Maxi", "Musterfrau", arg);
	puts("add 2");
	remove_student(42, arg);
	puts("remove");
	print_students(arg);
	puts("print 2");
	clear_students(arg);
	puts("clear");
	print_students(arg);
	return 0;
}
