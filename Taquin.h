#ifndef TAQUIN_H
#define TAQUIN_H

#include <cstdlib>
#include <cstdio>

enum Deplmt { //deplacement
    LEFT,RIGHT,UP,DOWN
};

struct Taquin
{
    int matrix[9];
    int x,y;
};

Taquin* cree_Taquin();

int deplacement_possible(Taquin* taquin,Deplmt* deplacements);

Taquin* depalcer_taquin(Taquin* taquin,Deplmt deplacement);

void afficher_taquin(Taquin* taquin);

Taquin* lire_taquin(FILE* input);

bool egale(void* tls,void* trs);

int heuristique(const Taquin& tl, const Taquin& tr);


#endif