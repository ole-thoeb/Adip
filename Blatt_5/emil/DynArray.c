#include "DynArray.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct DynArrayImpl{
    size_t memo;
    size_t len;
    TYPE *el;
}DynArrayImpl;

DynArray DynArray_new(size_t capacity){
    struct DynArrayImpl *v = malloc(sizeof(struct DynArrayImpl));
    if (v == NULL) return NULL;
    
    v->el = malloc(capacity * sizeof(TYPE));
    if(v->el == NULL){
        free(v);
        return NULL;
    }
    v->memo = capacity;
    v->len = 0;

    return v;
}

void DynArray_delete(DynArray vector){
    free(vector->el);
    free(vector);
}

int DynArray_add(DynArray vector, TYPE val){
    assert(vector != NULL && "vector darf nicht NULL sein");

    if(vector->len < vector->memo){
        vector->el[vector->len] = val;
        vector->len++;
        return 0;
    }else{
        //neuere größeres feld erstellen. elemente werden automatisch rüberkopiert
        TYPE *newArg = realloc(vector->el, (vector->memo * 2) * sizeof(TYPE));
        //ueberpruefen ob speicher zur verfuegung gestellt wurde
        if(newArg == NULL) return 1;
        //größe erhöhen
        vector->memo *= 2;
        //neues feld dem struct zuweisen
        vector->el = newArg;

        return DynArray_add(vector, val);
    }
}

TYPE DynArray_get(DynArray vector, size_t index){
    assert(vector != NULL && "vector darf nicht NULL sein");
    assert(index < vector->memo && "index muss kleiner als die aktuelle laenge sein");
    return vector->el[index];
}

void DynArray_set(DynArray vector, size_t index, TYPE value){
    assert(vector != NULL && "vector darf nicht NULL sein");
    assert(index < vector->memo && "index muss kleiner als die aktuelle laenge sein");
    vector->el[index] = value;
}

size_t DynArray_size(DynArray vector){
    return vector->len;
}

void DynArray_print(DynArray vector){
    for(size_t i = 0; i < vector->len; i++){
        printf("%i", vector->el[i]);
        if (i != vector->len - 1) printf(", ");
    }
    putchar('\n');
}