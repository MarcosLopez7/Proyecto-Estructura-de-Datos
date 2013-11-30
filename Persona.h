#ifndef __Proyecto_Final_Cubells__Persona__
#define __Proyecto_Final_Cubells__Persona__

#include <iostream>

using namespace std;

class Atraccion;
class Juego;
class Snack;

class Persona
{
public:
	Persona(int t, std::string idP);
	Persona(int, int);
    Persona(int salida,int presupuesto, std::string nombre);
	//~Persona();
	void setDinero(int);
	void setSalida(int);
	void setHambre(int);
    void setCongelamiento(int value);
    void setUbicacion(int value);
    void setSiguienteAtraccion(Atraccion * sigAtra);

	int getDinero();
	int getSalida();
	int getHambre();
    int getCongelamiento();
    int getUbicacion();
    std::string getId ();
    Atraccion * getSiguienteAtraccion();
    
    std::string getNombre();

	friend ostream & operator <<(ostream & os, Persona & le);

private:
	int dinero;
	int salida;
	int hambre;
    int congelamiento;
    int ubicacion;
    Atraccion * siguienteAtraccion;
    std:: string nombre;
    std:: string idP;
};

#endif /* defined(__Proyecto_Final_Cubells__Persona__) */
