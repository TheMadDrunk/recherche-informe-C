#include "set.h"
#include <cstdlib>
#include <iostream>


Set* createSet(int initSize){
    Set* new_set = new Set();
    new_set->array = (void**)malloc(sizeof(void*)*initSize);
    new_set->size = initSize;
    new_set->position = 0;
    return new_set;
}

void destroySet(Set* set){
    delete[] set->array;
    delete set;
}

void insert(Set* set,void* object){
    if(set->position == set->size){
       set->array =(void**) realloc(set->array,set->size*2*sizeof(void*));
       set->size*=2;
    }
    

    set->array[set->position] = object;

    set->position++;
    
}

bool check(Set* set,void* object,bool (*compare)(void* left,void* right)){
    
    for(int i = 0;i<set->position;i++)
        if(compare(set->array[i],object))
            return true;
    return false;
}
