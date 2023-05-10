#include "recherche.h"
#include "queue.h"
#include "set.h"


Noeud* cree_noeud(int g,int h,Taquin* etat,Noeud* parent){
    Noeud* n = new Noeud();
    n->g = g;
    n->h = h;
    n->etat = etat;
    n->parent = parent;

    return n ;
}

Noeud* noeud_fils(Noeud* parent,Noeud* but,Deplmt mv){
    Noeud *child = new Noeud();
    child->parent = parent;
    Taquin* etat_fils = new Taquin(*parent->etat);
    child->etat = depalcer_taquin(etat_fils , mv);
    child->h = heuristique(*child->etat,*but->etat);
    child->g = parent->g + 1;
    return child;
}


bool comparer_noeud(void* left,void* right){

    Noeud* l = (Noeud*)left;
    Noeud* r = (Noeud*)right;


    return l->g+l->h < r->g+r->h;
}

bool noeud_egaux(Noeud* a,Noeud* b){
    return egale(a->etat,b->etat);
}

Solution Astar(Noeud *start, Noeud *goal)
{

    Queue* frontiere = createQueue();
    push(frontiere,start);
    
    Set* explore = createSet();
    
    while (!isQueueEmpty(frontiere))
    {
        
        printf("%d\n",explore->size);
        
       
        
        Noeud *curr_Noeud = (Noeud*) pop(frontiere);

        if (egale(curr_Noeud->etat,goal->etat))
        {
            return Solution({curr_Noeud,curr_Noeud->g+curr_Noeud->h});
        }

        insert(explore,curr_Noeud->etat);
        
        Deplmt deplacement[4];
        int taille = deplacement_possible(curr_Noeud->etat,deplacement);
        printf("taille %d\n",taille);
        for (int i = 0;i<taille;i++)
        {   
            puts("here");
            Noeud *fils_Noeud = noeud_fils(curr_Noeud, goal, deplacement[i]);
            afficher_taquin(fils_Noeud->etat);
            puts("herefr()");

            if (!check(explore, fils_Noeud,egale))
            {
                puts("insserted");
                insert(frontiere,fils_Noeud,comparer_noeud);
            }
            
        }
        
    }
    
    return {nullptr,-1};
}


Solution IDAsearch(Noeud *debut, Noeud *but,int limit){
    Queue* frontiere = createQueue();
    push(frontiere,debut);

    Set* explore = createSet();

    while (!isQueueEmpty(frontiere))
    {
        

        Noeud *curr_Noeud = (Noeud*) pop(frontiere);

        if(curr_Noeud->g > limit)
            return {nullptr,limit};

        if (egale(curr_Noeud->etat,but->etat))
        {
            return Solution({curr_Noeud,curr_Noeud->g+curr_Noeud->h});
        }

        insert(explore,curr_Noeud->etat);
        
        Deplmt deplacement[4];
        int taille = deplacement_possible(curr_Noeud->etat,deplacement);
        
        for (int i = 0;i<taille;i++)
        {   
            
            Noeud *fils_Noeud = noeud_fils(curr_Noeud, but, deplacement[i]);
            afficher_taquin(fils_Noeud->etat);
            

            if (!check(explore, fils_Noeud,egale))
            {
                
                insert(frontiere,fils_Noeud,comparer_noeud);
            }
            
        }

    }

    return {nullptr,-1};
}


Solution IDAstar(Noeud* start, Noeud* goal,int maxLimit){
    int limit = start->g;
    
    while(limit<=maxLimit){
        Solution answer = IDAsearch(start,goal,limit);
        if(answer.chemin != nullptr)
            return answer;
        else if(answer.cout == -1)
            return {NULL,-1};
        limit++;
    }

    return {NULL,-1};
}