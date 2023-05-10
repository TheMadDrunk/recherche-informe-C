#include "Taquin.h"

#include <algorithm>

Taquin* cree_Taquin(){
    Taquin* t = new Taquin();
    for(int  i = 0;i<9;i++){
        t->matrix[i] = i;
    }
    t->x = 0;t->y = 0;

    return t;
}

void position(Taquin* taquin){
    int pos = 0;
    for(int i  =0;i<9;i++){
        if(taquin->matrix[i]==0)
            pos = i;
    }
    
    taquin->x = pos%3;
    taquin->y = pos/3;
}

int deplacement_possible(Taquin* taquin,Deplmt* deplacements){
    int size = 3;
    int dplptr = 0;
    
    if (taquin->y > 0){
        deplacements[dplptr] = UP;
        dplptr++;
    }
    if (taquin->y < size - 1){
        deplacements[dplptr] = DOWN;
        dplptr++;
    }
    if (taquin->x > 0){
        deplacements[dplptr] = LEFT;
        dplptr++;
    }
        
    if (taquin->x < size - 1){
        deplacements[dplptr] = RIGHT;
        dplptr++;
    }
    return dplptr;
}

Taquin* depalcer_taquin(Taquin* taquin,Deplmt deplacement){
    int size = 3;
    int pos = taquin->y * size + taquin->x;
    printf("--%d--\n",deplacement);
    switch (deplacement)
    {
    case UP:
        std::swap(taquin->matrix[pos], taquin->matrix[pos - size]);
        taquin->y--;
        break;
    case DOWN:
        std::swap(taquin->matrix[pos], taquin->matrix[pos + size]);
        taquin->y++;
        break;
    case LEFT:
        std::swap(taquin->matrix[pos], taquin->matrix[pos-1]);
        taquin->x--;
        break;
    case RIGHT:
        std::swap(taquin->matrix[pos], taquin->matrix[pos+1]);
        taquin->x++;
        break;
    }
    

    return taquin;
}


void afficher_taquin(Taquin* taquin){
    printf("%d - %d\n",taquin->x,taquin->y);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",taquin->matrix[i*3+j]);   
        }
        printf("\n");
    }
}


Taquin* lire_taquin(FILE* input){
    Taquin* out = cree_Taquin();
    for(int i = 0;i<9;i++)
        fscanf(input,"%d",&out->matrix[i]);

    position(out);
    return out;
}

bool egale(void* tls,void* trs){
    Taquin* tl = (Taquin*)tls;
    Taquin* tr = (Taquin*)trs;

    if(tl->x != tr->x || tl->y != tr->y)
        return false;
    for (int i = 0; i < 9; i++)
        if(tl->matrix[i] != tr->matrix[i])
            return false;
    
    
    return true;
}

int heuristique(const Taquin& tl, const Taquin& tr){
    int diff_count = 0;
    for (int i = 0; i < 9; i++)
        if(tl.matrix[i]!=tr.matrix[i])
            diff_count++;
            
    return diff_count;
}