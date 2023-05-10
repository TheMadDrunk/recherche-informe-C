#ifndef RECHERCHE_H
#define RECHERCHE_H

#include "Taquin.h"

struct Noeud {
    int g;
    int h;
    Taquin* etat;
    Noeud* parent;
};

struct Solution
{
    Noeud* chemin;
    int cout;
};


Noeud* cree_noeud(int g,int h,Taquin* etat,Noeud* parent);

Noeud* noeud_fils(Noeud* parent,Noeud* but,Deplmt mv);

bool comparer_noeud(Noeud* left,Noeud* right);

Solution Astar(Noeud *start, Noeud *goal);

Solution IDAstar(Noeud* start, Noeud* goal,int maxLimit);

#endif