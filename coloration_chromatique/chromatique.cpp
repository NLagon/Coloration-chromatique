#include <iostream>
#include <queue>

using namespace std;

int const  taille=4;

void chromatique(int  graph[][taille] ,int sommet_depart,int nbre_sommets){
    
    
    int tab_couleurs[nbre_sommets];// tableau de couleurs pour les couleurs de chaque sommet
    
    for(int i = 0; i <nbre_sommets;i++)
    {
        tab_couleurs[i]=-1;
    }
    
    tab_couleurs[sommet_depart]=1; // couleur du 1 er sommet est initialisé à 1
    
    int j=0;
    
    while(j<nbre_sommets){// tant que la file est vide, il y a un problème ici, voir plus bas
        
        
        
        
        
        for (int i = 0; i <nbre_sommets;i++)
        {
            if(graph[j][i]==1){
                
                if (tab_couleurs[i]==-1){
                    tab_couleurs[i]=tab_couleurs[j]++;
                }
                
                
                else if(tab_couleurs[i]==tab_couleurs[j]){
                    tab_couleurs[i]=tab_couleurs[j]++;
                }
                
            }
            
        }
        
        j++;
        
    }
    
    for (int i = 0; i < 4; ++i)
    {
        printf("%d\n",tab_couleurs[i] );
    }
    
}


int main(int argc, char const *argv[])
{
    int graph[4][4]={{0,1,1,0},{
        1,0,1,0},{
            0,0,1,0},{
                1,0,1,0}
    };
    
    
    chromatique(graph,0,4);
    
    return 0;
}
