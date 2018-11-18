#include "DynArrayMin.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct DynArrayMinImpl{
    size_t memo;
    size_t len;
    TYPE *el;
}DynArrayMinImpl;

DynArrayMin DynArrayMin_new(size_t capacity){
    struct DynArrayMinImpl *v = malloc(sizeof(struct DynArrayMinImpl));
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

void DynArrayMin_delete(DynArrayMin vector){
    free(vector->el);
    free(vector);
}

int DynArrayMin_add(DynArrayMin vector, TYPE val){
    assert(vector != NULL && "vector darf nicht NULL sein");

    if(vector->len < vector->memo){
        vector->el[vector->len] = val;
        vector->len++;
        return 0;
    }else{
        //neuere größeres feld erstellen. elemente werden automatisch rüberkopiert
        TYPE *newArg = realloc(vector->el, vector->memo + 1);
        //ueberpruefen ob speicher zur verfuegung gestellt wurde
        if(newArg == NULL) return 1;
        //größe erhöhen
        vector->memo++;
        //neues feld dem struct zuweisen
        vector->el = newArg;

        return DynArrayMin_add(vector, val);
    }
}

TYPE DynArrayMin_get(DynArrayMin vector, size_t index){
    assert(vector != NULL && "vector darf nicht NULL sein");
    assert(index < vector->memo && "index muss kleiner als die aktuelle laenge sein");
    return vector->el[index];
}

void DynArrayMin_set(DynArrayMin vector, size_t index, TYPE value){
    assert(vector != NULL && "vector darf nicht NULL sein");
    assert(index < vector->memo && "index muss kleiner als die aktuelle laenge sein");
    vector->el[index] = value;
}

size_t DynArrayMin_size(DynArrayMin vector){
    return vector->len;
}

void DynArrayMin_print(DynArrayMin vector){
    for(size_t i = 0; i < vector->len; i++){
        printf("%d", vector->el[i]);
        if (i != vector->len - 1) printf(", ");
    }
    putchar('\n');
}