#include <ctime>
#include "Persona.h"

Persona::Persona(int t)
{
	int presupuestos [] = {1200, 1000, 800, 750, 500};
	srand((int) time(NULL));

	dinero = presupuestos[rand() % 5];

	int salidas [] = {1800, 2400, 3000, 3600, 4800};
	salida = salidas[rand() % 5] + t;
	if (salida >= 12000)
	{
		salida = 12000;
	}

	hambre = rand() % 30;
}

Persona::Persona(int s, int h)
{
	int salida = s;
	int presupuestos [] = { 1200, 1000, 800, 750, 500 };
	srand((int) time(NULL));

	dinero = presupuestos[rand() % 5];
	hambre = h;
}

Persona::~Persona(){}

void Persona::setDinero(int d)
{
	dinero = d;
}

void Persona::setSalida(int s)
{
	salida = s;
}

void Persona::setHambre(int h)
{
	hambre = h;
}

int Persona::getDinero()
{
	return dinero;
}
int Persona::getSalida()
{
	return salida;
}
int Persona::getHambre()
{
	return hambre;
}

ostream & operator <<(ostream & os, Persona & p)
{
	os << "Hora de salida: " << p.salida << "| ";
	os << "Dinero actual: " << p.dinero << " | ";
	os << "Hambre actual" << p.hambre << "% |" ;

	return os;
}