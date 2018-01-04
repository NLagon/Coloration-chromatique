	#include <iostream>
	#include <queue>
	#include <stdio.h>
	#include <stdlib.h>
	#include <vector>
	using namespace std;




	int estUnnombre(char*buff){

	    int ok = 0;
	    int i;
	    while (!ok) {
	        printf("Entrez un nombre : ");
	        fflush(NULL);
	        cin >> buff;
	        for (i=0;i<strlen(buff);i++){
	            if (!isdigit(buff[i])) {
	                cout << "Erreur" << endl;
	                break;
	            }
	         }
	        if (i==strlen(buff))
	            ok=1;
	    }
	    
	    return atoi(buff);


	}


int main (void)
{
	char buff[100];

    //int i=estUnnombre(buff);

    //cout << i << endl;
    return 0;
}