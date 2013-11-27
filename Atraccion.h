//
//  Atraccion.h
//  Proyecto Final Cubells
//
//  Created by C�sar Mill�n on 11/11/13.
//  Copyright (c) 2013 C�sar Mill�n. All rights reserved.
//

#ifndef __Proyecto_Final_Cubells__Atraccion__
#define __Proyecto_Final_Cubells__Atraccion__

#include <iostream>
#include <string>
#include "Persona.h"
#include "Cola.h"
#include "Pila.h"


class Atraccion{
protected:
	
	std::string nombre;
	Cola<Persona *> * colaDeTraslado;

public:
	Atraccion (std::string nombre) : nombre(nombre)
	{
		colaDeTraslado = new Cola<Persona *>();
	}

	std::string getNombre() const{
		return nombre;
	}

	void setNombre(std::string nombre){
		this->nombre = nombre;
	}

	Cola<Persona *> * getColaDeTraslado()
	{
		return colaDeTraslado;
	}

	void setColaDeTraslado(Cola<Persona *> * value)
	{
		colaDeTraslado = value;
	}
};

#endif /* defined(__Proyecto_Final_Cubells__Atraccion__) */