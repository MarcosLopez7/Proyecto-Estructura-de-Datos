//
//  Snack.h
//  Proyecto Final Cubells
//
//  Created by C�sar Mill�n on 11/11/13.
//  Copyright (c) 2013 C�sar Mill�n. All rights reserved.
//

#ifndef __Proyecto_Final_Cubells__Snack__
#define __Proyecto_Final_Cubells__Snack__

#include <iostream>
#include <ctime>
#include "Atraccion.h"

class Snack : public Atraccion{
	int ganancia;
	void operacionesHambreDinero(Persona * per, int opcion);
	int Hambre(int nSatisfecho, Persona * per);
	int Fondos(int costo, Persona * per);
	int menu();

public:
	Snack(std::string nombre) : Atraccion( nombre), ganancia(0){}

	void hambreDinero(Persona * per);
	void hambreDineroRand(Persona * per);

};
#endif /* defined(__Proyecto_Final_Cubells__Snack__) */