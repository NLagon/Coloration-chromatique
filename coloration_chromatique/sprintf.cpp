	#include <iostream>
	#include <queue>
	#include <stdio.h>
	#include <stdlib.h>
	#include <vector>
	using namespace std;



	int main ()
{
int i;
  char buffer [100];
  printf ("Enter a number: ");
  scanf ("%d",&i);

  sprintf(buffer, "%d", i);

  cout << buffer ;
      cout << endl;

  return 0;
}