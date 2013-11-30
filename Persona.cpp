#include <ctime>
#include "Persona.h"
#include "Atraccion.h"
#include "Juego.h"
#include "Snack.h"

Persona::Persona(int t, std::string idP)
{
	//srand((int) time(NULL));
	int presupuestos[5] = { 1200, 1000, 800, 750, 500 };

	int random = rand() % 5;
	dinero = presupuestos[random];

	int salidas [] = { 180, 240, 300, 360, 480 };
	salida = salidas[rand() % 5] + t;
	if (salida >= 1200)
	{
		salida = 1200;
	}
    
    congelamiento = 0;
    ubicacion = 0;
    siguienteAtraccion = NULL;
    this->idP = idP;
	hambre = rand() % 30;
    nombre = "";
}

Persona::Persona(int s, int h)
{
	salida = s;
	int presupuestos [] = { 1200, 1000, 800, 750, 500 };
	//	srand((int) time(NULL));

	dinero = (presupuestos[rand() % 5]);
	//setDinero(presupuestos[rand() % 5]);
	hambre = h;
    nombre = "";
    
    congelamiento = 0;
    ubicacion = 0;
    siguienteAtraccion = NULL;
}

Persona::Persona(int salida,int presupuesto, std::string nombre):salida(salida),dinero(presupuesto),nombre(nombre),hambre(20){
    congelamiento = 0;
    ubicacion = 0;
    siguienteAtraccion = NULL;
}

//Persona::~Persona(){}

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
std::string Persona::getNombre(){
    return nombre;
}

void Persona::setCongelamiento(int value){
    congelamiento =  value;
}

void Persona::setUbicacion(int value){
    ubicacion = value;
}

void Persona::setSiguienteAtraccion(Atraccion *sigAtra){
    siguienteAtraccion = sigAtra;
}

int Persona::getCongelamiento(){
    return congelamiento;
}

int Persona::getUbicacion(){
    return ubicacion;
}

Atraccion * Persona::getSiguienteAtraccion(){
    return siguienteAtraccion;
}

std::string Persona::getId (){
    return idP;
}


ostream & operator <<(ostream & os, Persona & p)
{
	if (p.nombre != "") {
        os << "Nombre: " << p.nombre << endl;
    }
    if (p.salida % 60 == 0)
	{
		os << "Hora de salida: " << p.salida / 60 << ":" << "00| ";
	}
	else
	{
		os << "Hora de salida: " << p.salida / 60 << ":" << p.salida % 60 << "| ";
	}

	os << "Dinero actual: $" << p.dinero << " | ";
	os << "Hambre actual: " << p.hambre << "% |";
    
	os << endl;
	return os;
}