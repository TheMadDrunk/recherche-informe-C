#include <iostream>
#include <cstdlib>
#include "Taquin.h"
#include "recherche.h"

using namespace std;

int main(){
    
    FILE* input = fopen("in","r");


    if(input == NULL){
        printf("Error while openning the file\n");
        return -1;
    }

    Noeud debut,fin;

    debut = fin = {0,0,0,0};

    debut.etat = lire_taquin(input);
    fin.etat = lire_taquin(input);
    puts("Start");
    afficher_taquin(debut.etat);
    puts("fin");
    afficher_taquin(fin.etat);

    puts("----- Solution with A* algorithm ------");
    Solution solution = Astar(&debut,&fin);
    
    for(Noeud* curr = solution.chemin;curr!=nullptr;curr = curr->parent){
        afficher_taquin(curr->etat);
        puts("----------");
    }

    puts("----- Solution with IDA* algorithm ------\n");
    solution = IDAstar(&debut,&fin,10);
    

    if(solution.chemin == NULL){
        cout<<"Pas de solution trouver pour cette profondeur ou la solution n'existe pas!\n";
        
    }
    else {
        cout<<"cout :"<<solution.cout<<'\n';

    for(Noeud* curr = solution.chemin;curr!=nullptr;curr = curr->parent){
        afficher_taquin(curr->etat);
        puts("----------");
    }
    }



    

    

    return 0;
}