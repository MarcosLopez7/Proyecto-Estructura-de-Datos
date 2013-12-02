//
//  Snack.h
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#ifndef __Proyecto_Final_Estructura_de_Datos_TC1018__Snack__
#define __Proyecto_Final_Estructura_de_Datos_TC1018__Snack__

#include <iostream>
#include <ctime>
#include "Atraccion.h"
#include "Lista.h"

class Snack : public Atraccion{
	int ganancia;
	int Hambre(int nSatisfecho, Persona * per);
	int Fondos(int costo, Persona * per);
	ListaEnlazada<Persona *> * comiendo;
    
public:
    
	Snack(Parque * parque, std::string nombre) : Atraccion(parque, nombre)
	{
		ganancia = 0;
		comiendo = new ListaEnlazada<Persona *>();
	}
    
	ListaEnlazada<Persona *> * getComiendo()
	{
		return comiendo;
	}
    
	void setComiendo(ListaEnlazada<Persona *> * value)
	{
		comiendo = value;
	}
    
	void hambreDinero(Persona * per);
	void hambreDineroRand(Persona * per);
    void checarPersonasComiendo(int actualTime);
    
};

#endif /* defined(__Proyecto_Final_Estructura_de_Datos_TC1018__Snack__) */
