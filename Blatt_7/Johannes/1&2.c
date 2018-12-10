
/* Zu Nr.1a
PrintList L1: ( 11.000000 7.000000 3.000000 )
PrintList L2: ( 14.000000 5.000000 11.000000 7.000000 3.000000 )

vgl main unten
*/

#include<stdio.h>
typedef struct DoubleNode{ 
	struct DoubleNode *next;
	double data;
	} DoubleNode;

//Vgl. Skript
DoubleNode * insertFirst(DoubleNode *head, double d){
	DoubleNode *tmp;
	tmp = malloc(sizeof(DoubleNode));
	tmp->data = d;
	tmp->next = head;
	return tmp;
}

//Vgl. Skript
DoubleNode * insertLast(DoubleNode *head, double d){
	DoubleNode *tmp, *cursor;
	//Trivialfall:
	if(head == NULL){return insertFirst(head,d);}
	else{
		cursor = head;
		while(cursor->next != NULL){cursor=cursor->next;}
		tmp = malloc(sizeof(DoubleNode));
		tmp->data = d;
		tmp->next = NULL;
		cursor->next = tmp;
		return head;
	}
}

//Vgl. Skript
void printList(DoubleNode *head){
	DoubleNode *cursor;
	printf("\nPrintList: ( ");
	cursor = head;
	while (cursor != NULL){
		printf("%lf", cursor->data);
		printf(" ");
		cursor=cursor->next;
	}
	printf(")");
}

//Konstruktives Invertieren
//Vgl. Skript
DoubleNode * reverseDoubleListCon(DoubleNode *head){
	DoubleNode *res, *tmp, *cell;
	cell = head;
	res = NULL;
	while(cell != NULL){
		tmp = malloc(sizeof(DoubleNode));
		tmp->data = cell->data;
		tmp->next = res;
		res = tmp;
		cell = cell->next;		
	}
	return res;
}

//Destruktives Invertieren
//Vgl. Skript
void reverseDoubleList(DoubleNode **head_ref){
	DoubleNode *prev = NULL;
	DoubleNode *current = *head_ref;
	DoubleNode *next;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

//Holt Wert aus Liste an Position pos
double get(DoubleNode *head, unsigned pos){
	//Trivialfall: Test auf leere Liste
	if (head != NULL){		
		int i = 0;
		while(i < pos && head->next != NULL){
			i++;
			head = head->next;
		}
		if(i != pos) printf("\n\nGet-Funktion: Liste zu klein. Liefere stattdessen letzen Wert:");
		return head->data;
	} else {
		printf("\n\nGet-Funktion: Liste ist leer. Liefere stattdessen eine freundliche 4.212");
		return 4.212;		
	}
}

DoubleNode * delete(DoubleNode *head, unsigned pos){
		DoubleNode *tmp, *cursor;
		cursor = head;
		//Fall 1: Die Stelle, die gelöscht werden soll, ist nicht die erste
		if(pos != 0){
			if(head == NULL){
				return head;
			} else {
				int i = 1;
				while(i < pos && cursor->next != NULL){
					cursor = cursor->next;
					i++;		
				}
				tmp = cursor;
				tmp = tmp->next;
				//Kontrolle, ob hinter dem Listeneintrag noch etwas folgt. Sonst muss gar nichts passieren - Liste ist zu klein
				if(tmp != NULL)cursor->next = tmp->next;
				return head;
			}
		} else {
			//Fall 2: Das erste Element soll gelöscht werden.
			//Fall 2b: Es gibt ein zweites Element
			if(cursor->next != NULL){
				cursor = cursor->next;
				head->data = cursor->data;
				head->next = cursor->next;
			} else {
				//Fall 2c: Es gibt kein zweites Element. Dann hat die List ein Element, sollte also ganz gelöscht werden.
				head = NULL;
			}
			return head;
		}
}

DoubleNode * insert(DoubleNode *head, unsigned pos, double d){
	DoubleNode *tmp, *cursor;
	cursor = head;
	
	//Trivialfall
	if(head == NULL){		
		head = insertFirst(head, d);
	} else {
		if(pos != 0){
			int i = 1;
			while(i < pos && cursor->next != NULL){
				cursor = cursor->next;
				i++;		
			}
			tmp = malloc(sizeof(DoubleNode));
			tmp->data = d;
			tmp->next = cursor->next;
			cursor->next = tmp;
		} else {
			tmp = malloc(sizeof(DoubleNode));
			tmp->data = d;
			tmp->next = head;
			return tmp;
		}		
	}	
	return head;
}


	
int main(void){
	//für Nr1a:
	
	//ACHTUNG: Die exakte Zeile 1 der Aufgabenstellung lautet: "DoubleNode *L1, *L2 = NULL;"
	//Damit kommt der Compiler nicht klar - printList(L1) erhängt sich.
	//Also hier L1 mit NULL initialisiert.
	DoubleNode *L1 = NULL, *L2 = NULL;
	L1 = insertFirst( L1, 3);
	L1 = insertFirst( L1, 7);
	L1 = insertFirst( L1, 11);
	L2 = L1;
	L2 = insertFirst( L2, 5);
	L2 = insertFirst( L2, 14);
	printList(L1);
	printList(L2);
	
	/* Tests
	DoubleNode *l = NULL;
	l = insertFirst(l, 4);
	l = insertLast(l, 3);
	l = insertLast(l, 2);
	l = insertLast(l, 1);
	l = reverseDoubleListCon(l);
	reverseDoubleList(&l);
	unsigned pos = 2;
	printf("\nget(l, %u) = %lf\n", pos, get(l, pos));
	l = delete(l, 2);
	l = insert(l, 0, 5.0);
	
	printList(l);
	*/
	
	
	//zu Nr.2:
	//(sollte nochmal jemand drüberschauen...)
	printf("\n\nPreOrder: ( 19 12 10 1 15 14 16 33 20 22 97 96 99 )");
	printf("\nPostOrder: ( 1 10 14 16 15 12 22 20 96 99 97 33 19 )");
	printf("\nInOrdner: ( 1 10 12 14 15 16 19 22 20 96 97 99 33 )");
	
	
	return 0;
}

