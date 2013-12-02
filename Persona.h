//
//  Persona.h
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#ifndef __Proyecto_Final_Estructura_de_Datos_TC1018__Persona__
#define __Proyecto_Final_Estructura_de_Datos_TC1018__Persona__

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
	Persona(int, int salida, int presupuesto, std::string nombre);
	void setDinero(int);
	void setSalida(int);
	void setHambre(int);
	void setCongelamiento(int value);
	void setUbicacion(int value);
	void setSiguienteAtraccion(Atraccion * sigAtra);
	void setLlegada(int);
    void setVIP(bool value);
    
	int getDinero();
	int getSalida();
	int getHambre();
	int getCongelamiento();
	int getUbicacion();
	int getLLegada();
    
    bool getVIP();
	std::string getId();
	Atraccion * getSiguienteAtraccion();
    
	std::string getNombre();
    
    bool getComiendo(){
        return comiendo;
    }
    
    void setComiendo(bool value){
        comiendo = value;
    }
    
	friend ostream & operator <<(ostream & os, Persona & le);
    
private:
	int dinero;
	int salida;
	int hambre;
	int congelamiento;
	int ubicacion;
	int llegada;
    bool VIP;
    bool comiendo;
	Atraccion * siguienteAtraccion;
	std::string nombre;
	std::string idP;
};

#endif /* defined(__Proyecto_Final_Estructura_de_Datos_TC1018__Persona__) */
