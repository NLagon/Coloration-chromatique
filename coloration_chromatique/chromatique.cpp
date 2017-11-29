#include <iostream>
#include <queue>

using namespace std;


bool chromatique(int graph[][],int sommet_depart,int nbre_sommets){


	int tab_couleurs[nbre_sommets];// tableau de couleurs pour les couleurs de chaque sommet

	for(int i = 0; i <nbre_sommets;i++)
	{
		tab_couleurs[i]=-1;
	}

	tab_couleurs[sommet_depart]=1; // couleur du 1 er sommet est initialisé à 1

queue <int> q;                  //file d'attente F
q.push(sommet_depart);// pusher l'indice du sommet de départ pour pouvoir accéder à sa ligne ds le tableau 2D

    while(!q.empty()){// tant que la file est vide, il y a un problème ici, voir plus bas

	int x = q.front(); 

	q.pop();

	int ligne=x;

	for (int i = 0; i <nbre_sommets;i++)
	{
		if(graph[ligne][i]==1){

			if (tab_couleurs[i]==-1){
				tab_couleurs[i]=tab_couleurs[ligne]++;
				q.push(i);// la pile ne va jamais se vider
			}


			else if(tab_couleurs[i]==tab_couleurs[ligne]){
				tab_couleurs[i]=tab_couleurs[ligne]++;
				q.push(i);// ici non plus
			}

		}

	}


}

for (int i = 0; i < 4; ++i)
{
	printf("%d\n",tab_couleurs[i] );								
}		

}

int main(int argc, char const *argv[])
{
	int graph[4][4]={0,1,1,0
						  1,0,1,0
						  0,0,1,0
						  1,0,1,0
									};


chromatique(graph,0,4);
						
	return 0;
}
