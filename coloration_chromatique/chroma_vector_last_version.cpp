#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;


void arete(int sommet1,int sommet2, vector< vector<double> > &graph){

	graph[(sommet1)][sommet2]=1;
}


void occurence (int * pays_actuel, int * k, int nbre_sommets, vector<string> nom_sommets, string pays, int existe){

	for ((*k) = 0; (*k) < nbre_sommets; ++(*k))
	{
		if (pays==nom_sommets[(*pays_actuel)])
		{
			cout << "Un pays ne peut etre frontalier a lui-meme" << endl;
			break;
		}

		else if(pays==nom_sommets[(*k)]&& pays!=nom_sommets[(*pays_actuel)]){
			existe++;
			break;
		}

	}

	while(existe==0){

		cout << "Veuillez entrez un autre nom de pays qui est dans la carte " << endl;
		cin >> pays;

		for ((*k) = 0; (*k) < nbre_sommets; ++(*k)){

			if (pays==nom_sommets[(*pays_actuel)])
			{
				cout << "Un pays ne peut etre frontalier a lui-meme" << endl;
				break;

			}

			if(pays==nom_sommets[(*k)]&& pays!=nom_sommets[(*pays_actuel)]){
				existe++;
				break;
			}

		}

	}

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



int * chromatique(vector< vector<double> > &graph, int sommet_depart){

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
	vector<vector <double> >graph(nbre_sommets,vector<double>(nbre_sommets,0));

	string nom1_sommet="";
	vector<string> nom_sommets;

	cout << "Quel est le nom de ces pays" << endl;

	for (int i = 0; i <nbre_sommets; ++i)
	{

		cin >> nom1_sommet;
		nom_sommets.push_back(nom1_sommet);	
		cout << endl;

	}

	string pays;
	int pays_a_relies;
	int  i;
	for (i = 0; i < nbre_sommets; ++i){

		cout << "Combien de pays sont frontaliers au pays " << nom_sommets[i] << endl;
		cin >> pays_a_relies;

		while(pays_a_relies>=nbre_sommets){

			if ( pays_a_relies==nbre_sommets )
			{
				cout <<"Un pays ne peut pas etre frontalier a lui-meme" << endl;
				cout <<"Choisissez un autre chiffre" << endl;
			}

			else if ( pays_a_relies > nbre_sommets)
			{

				cout << "Erreur: le nombre entre est superieur au nombre de sommets" << endl;
			}

			cin >> pays_a_relies;

		}

		cout << endl;
		cout << "Lesquels ? "  << endl ;
		cout << endl;

		for (int j = 0; j <pays_a_relies; ++j)
		{
			int existe=0;	
			int k;
			cin >> pays;
			occurence(&i,&k,nbre_sommets,nom_sommets,pays,existe);
			cout << endl;
			arete(i,k,graph);
		}

	}

	int * tab=new int[graph.size()];
	tab=chromatique(graph,0);
	for (int p = 0; p < graph.size(); ++p)
	{
		printf("(%s,%d)\n",nom_sommets[p].c_str(),tab[p]);								
	}


	return 0;
}

/*bool bCestUnChiffre=false;
if( strcmp( itoa( atoi( chaine ) ) , chaine ) == 0 )
bCestUnChiffre=true;
*/

//std::vector<std::vector<int>> A(dimension, std::vector<int>(dimension));

