#include <iostream>
using namespace std;

class Persona
{
public:
	Persona(int);
	Persona(int, int);
	~Persona();
	void setDinero(int);
	void setSalida(int);
	void setHambre(int);

	int getDinero();
	int getSalida();
	int getHambre();

	friend ostream & operator <<(ostream & os, Persona & le);

private:
	int dinero;
	int salida;
	int hambre;

};
