#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;


void arete(double sommet1,double sommet2, vector< vector<double> > &graph){
		
		graph[sommet1][sommet2]=1;
		//graph[sommet2][sommet1]=1;
}



void chromatique(vector< vector<double> > &graph,int sommet_depart){

	int tab_couleurs[graph.size()];
	for(int i = 0; i <graph.size();i++)
	{
		tab_couleurs[i]=-1;
	}
	tab_couleurs[sommet_depart]=1;

for(int j=0;j<graph.size();j++){

	for (int i = 0; i <graph[j].size();i++)
	{	    
	    if(graph[j][i]==0){					// si il n y'a aucune arête et que le sommet n'a pas encore de couleur, on lui donne la couleur du smmet de départ.
			if(tab_couleurs[i]==-1){	        
	        		tab_couleurs[i]=tab_couleurs[j];
			}	        
	    }
	    
	    
	    
		else if(graph[j][i]==1){		
			if (tab_couleurs[i]==-1){		// si il y a une arête mais aucune couleur on donne au sommet une couleur différente
				tab_couleurs[i]=tab_couleurs[j]+1;

			}


			else if(tab_couleurs[i]==tab_couleurs[j]){ // si il y a une arête et une couleur identique on donne au sommet une couleur différente
				tab_couleurs[i]=tab_couleurs[j]+1;

			}

		}

	    
	}	
		

	}

	for (int i = 0; i < graph.size(); ++i)
{
	printf(" %d----->%d\n",i,tab_couleurs[i] );								
}



		

}

int main(int argc, char const *argv[])
{

int nbre_sommets;

cout <<"Combien de sommets possedent le graphe" << endl;
//cout << ""
cin >> nbre_sommets ; // Permet d'entrer le nombre de sommets

vector<vector <double> >graph(nbre_sommets,vector<double>(nbre_sommets,0));
//ou bien cette methode pour les mettre ˆ vide
//vector<vector <double> >graph; // tableau dynamique vide

int sommet;
int sommet_relies;

for (int i = 0; i < nbre_sommets; ++i){

	cout << "Combien de  sommets voulez-vous relies au sommet " << i << endl;

	cin >> sommet_relies;

	cout << endl;

	cout << " Lesquels ? "  << endl ;

	cout << endl;

	for (int j = 0; j <sommet_relies; ++j)
	{
		cin >> sommet ;	

		cout << endl;
		arete(i,sommet,graph);
	
	}

}





/*arete(0,1,graph) ;
arete(0,2,graph) ;
arete(1,2,graph) ;
arete(2,3,graph) ;*/


//graph={{0,1,1,0},{1,0,1,0},{1,1,0,1},{0,0,1,0}};


chromatique(graph,0);
						
	return 0;
}

//std::vector<std::vector<int>> A(dimension, std::vector<int>(dimension));

