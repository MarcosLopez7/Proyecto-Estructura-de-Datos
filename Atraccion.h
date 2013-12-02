//
//  Atraccion.h
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#ifndef Proyecto_Final_Estructura_de_Datos_TC1018_Atraccion_h
#define Proyecto_Final_Estructura_de_Datos_TC1018_Atraccion_h

#include <iostream>
#include <string>
#include "Pila.h"
#include "Cola.h"

class Persona;
class Parque;

class Atraccion{
protected:
	int tiempoI;
	int tiempoF;
	Cola<Persona *> * colaGeneral;
	std::string nombre;
	Parque * parque;
    
    
public:
	Atraccion(Parque * parque, std::string nombre) : tiempoF(610), tiempoI(0), nombre(nombre), parque(parque){
	}
    
	void setTiempoI(int tiempo){
		tiempoI = tiempo;
	}
    
	int getTiempoI() const{
		return tiempoI;
	}
    
	void setTiempoF(int tiempo){
		tiempoF = tiempo;
	}
    
	int getTiempoF() const{
		return tiempoF;
	}
    
	std::string getNombre() const{
		return nombre;
	}
    
	void setNombre(std::string nombre){
		this->nombre = nombre;
	}
};


#endif
