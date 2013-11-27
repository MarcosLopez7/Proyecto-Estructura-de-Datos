#include <iostream>
#include <string>


using namespace std;

class Persona
{
public:
	Persona(int);
	Persona(int, int);
	Persona(int salida, int presupuesto, std::string nombre);
	//~Persona();
	void setDinero(int);
	void setSalida(int);
	void setHambre(int);
	void setCongelamiento(int);
//	void setProximaAtraccion(Atraccion *);
//	void setAtraccionActual(Atraccion *);

	int getDinero();
	int getSalida();
	int getHambre();
	int getCongelamiento();
//	Atraccion * getProximaAtraccion();
//	Atraccion * getAtraccionActual();
	std::string getNombre();

	friend ostream & operator <<(ostream & os, Persona & le);

private:
	int dinero;
	int salida;
	int hambre;
	int congelamiento;
//	Atraccion * proximaAtraccion;
//	Atraccion * atraccionActual;
	std::string nombre;

};



