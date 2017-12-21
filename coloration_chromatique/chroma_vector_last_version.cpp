#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;


void arete(double sommet1,double sommet2, vector< vector<double> > &graph){

	graph[sommet1][sommet2]=1;
//graph[sommet2][sommet1]=1;
}


int occurence (int * k, int nbre_sommets, vector<string> nom_sommets, string pays, int existe){


	for ((*k) = 0; (*k) < nbre_sommets; ++(*k))
	{
		if(pays==nom_sommets[(*k)]){
			existe++;
			break;

		}

	}

	return existe;

}


int estUnnombre(char*buff){

	int ok = 0;
	int i;
	while (!ok) {
		printf("Entrez un nombre : ");
		fflush(NULL);
		cin >> buff;
		for (i=0;i<strlen(buff);i++){
			if (!isdigit(buff[i])) {
				cout << "Erreur, ce n'est pas un nombre" << endl;
				break;
			}
		}

		if (i==strlen(buff))
			ok=1;
	}

	return atoi(buff);


}



int * chromatique(vector< vector<double> > &graph,int sommet_depart){

	int * tab_couleurs=new int[graph.size()];
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


return tab_couleurs;

}


int main(int argc, char const *argv[])
{


	cout << "-----------------COLORATION DE CARTES-------------------------" <<endl;

	int nbre_sommets;

	cout <<"Combien de pays possedent cette carte" << endl;

	char buff[100];

	nbre_sommets=estUnnombre(buff);
	int test=nbre_sommets;
	cout << test << endl;
// Permet d'entrer le nombre de sommets

	vector<vector <double> >graph(nbre_sommets,vector<double>(nbre_sommets,0));

	string nom1_sommet="";
	vector<string> nom_sommets;

	cout << "Quel est le nom de ces pays" << endl;

	for (int i = 0; i <nbre_sommets; ++i)
	{

		cin >> nom_sommets[i];

		cout << endl;

	}

	string pays;
	int pays_a_relies;

	for (int i = 0; i < nbre_sommets; ++i){

		cout << "Combien de pays sont frontaliers au pays " << nom_sommets[i] << endl;

		cin >> pays_a_relies;

		cout << endl;

		cout << " Lesquels ? "  << endl ;

		cout << endl;

		for (int j = 0; j <pays_a_relies; ++j)
		{
			int existe=0;	
			int k;

			cin >> pays;

			existe=occurence(&k,nbre_sommets,nom_sommets,pays,existe);

			cout << existe << endl;

			while(existe==0){

				cout << "Veuillez entrez un nom de pays que vous avez deja choisi, pensez a l'orthographe" << endl;

				cin >> pays;

				existe=occurence(&k,nbre_sommets,nom_sommets,pays,existe);

			}

			cout << endl;
			arete(i,k,graph);

		}

	}

	int * tab=new int[graph.size()];
	tab=chromatique(graph,0);
	for (int i = 0; i < graph.size(); ++i)
	{
		printf(" (%s,%d)\n",nom_sommets[i].c_str(),tab[i]);								
	}


	return 0;
}

/*bool bCestUnChiffre=false;
if( strcmp( itoa( atoi( chaine ) ) , chaine ) == 0 )
bCestUnChiffre=true;
*/

//std::vector<std::vector<int>> A(dimension, std::vector<int>(dimension));

