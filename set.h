#ifndef SET_H
#define SET_H


struct Set
{
    void** array; 
    int size;
    int position;
};

Set* createSet(int initSize=5);
void destroySet(Set* set);
void insert(Set* set,void* object);
bool check(Set* set,void* object,bool (*compare)(void* left,void* right));




#endif