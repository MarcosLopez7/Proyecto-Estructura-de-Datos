#include <iostream>
using namespace std;

class Persona
{
public:
	Persona(int);
	Persona(int, int);
    Persona(int salida,int presupuesto, std::string nombre);
	//~Persona();
	void setDinero(int);
	void setSalida(int);
	void setHambre(int);

	int getDinero();
	int getSalida();
	int getHambre();
    std::string getNombre();

	friend ostream & operator <<(ostream & os, Persona & le);

private:
	int dinero;
	int salida;
	int hambre;
    std:: string nombre;

};
