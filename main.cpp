#include "Persona.h"
#include <iostream>

int main(int argc, const char * argv [])
{

	for (int t = 600; t < 1200; t = t + 10)
	{
		Persona * personon = new Persona(t);
		cout << *personon;
		delete personon;
	}

	system("pause");
	return 0;
}