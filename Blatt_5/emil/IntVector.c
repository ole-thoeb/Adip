#include "IntVector.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct IntVectorImpl{
    size_t memo;
    size_t len;
    int *el;
}IntVectorImpl;

IntVector IntVector_new(size_t capacity){
    struct IntVectorImpl *v = malloc(sizeof(struct IntVectorImpl));
    if (v == NULL) return NULL;
    
    v->el = malloc(capacity * sizeof(int));
    if(v->el == NULL){
        free(v);
        return NULL;
    }
    v->memo = capacity;
    v->len = 0;

    return v;
}

void IntVector_delete(IntVector vector){
    free(vector->el);
    free(vector);
}

int IntVector_push_back(IntVector vector, int val){
    assert(vector != NULL && "vector darf nicht NULL sein");

    if(vector->len < vector->memo){
        vector->el[vector->len] = val;
        vector->len++;
        return 0;
    }else{
        //neuere größeres feld erstellen. elemente werden automatisch rüberkopiert
        int *newArg = realloc(vector->el, vector->memo * 2);
        //ueberpruefen ob speicher zur verfuegung gestellt wurde
        if(newArg == NULL) return 1;
        //größe erhöhen
        vector->memo *= 2;
        //neues feld dem struct zuweisen
        vector->el = newArg;

        return IntVector_push_back(vector, val);
    }
}

int IntVector_get(IntVector vector, size_t index){
    assert(vector != NULL && "vector darf nicht NULL sein");
    assert(index < vector->memo && "index muss kleiner als die aktuelle laenge sein");
    return vector->el[index];
}

void IntVector_set(IntVector vector, size_t index, int value){
    assert(vector != NULL && "vector darf nicht NULL sein");
    assert(index < vector->memo && "index muss kleiner als die aktuelle laenge sein");
    vector->el[index] = value;
}

size_t IntVector_size(IntVector vector){
    return vector->len;
}

void IntVector_print(IntVector vector){
    for(size_t i = 0; i < vector->len; i++){
        printf("%i", i);
        if (i != vector->len - 1) printf(", ");
    }
    putchar('\n');
}

int IntVector_contains(IntVector vector, int value){
    for(size_t i = 0; i < vector->len; i++){
        if(vector->el[i] == value) return 1;
    }
    return 0;
}