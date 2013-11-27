//
//  Juego.h
//  Proyecto Final Cubells
//
//  Created by César Millán on 11/11/13.
//  Copyright (c) 2013 César Millán. All rights reserved.
//

#ifndef __Proyecto_Final_Cubells__Juego__
#define __Proyecto_Final_Cubells__Juego__

#include <iostream>
#include "Atraccion.h"


class Juego : public Atraccion{
	Cola<Persona * > * colaVip;
	Cola<Persona * > * colaNormal;
	Pila<Persona * > * arriba;
	int capacidad;
	int duracion;
	int esperaVip;
	int esperaNormal;
	bool activado;
	int tiempo;
//	int tiempoF;

	Persona * SalColaVip();
	Persona * SalColaNormal();
	void EntraJuego(Persona * per);
	Persona * SalJuego();
	void calcularTiempo();
	void sacarDelJuego();


	
public:
	Juego(std::string nombre, int duracion, int capacidad ) : Atraccion(nombre), duracion(duracion), capacidad(capacidad) {
		colaVip = new Cola<Persona *>;
		colaNormal = new Cola<Persona *>;
		arriba = new Pila<Persona *>;
		activado = false;
		tiempo = 0;
		//capacidad = rand() % 2; // **opcion**
		//duracion = rand() % 2; // **opcion**
	}

	Cola<Persona *> * getColaVip() const{
		return colaVip;
	}
	Cola<Persona *> * getColaNomal() const{
		return colaNormal;
	}
	Pila<Persona *> * getArriba() const{
		return arriba;
	}

	void EntraColaVip(Persona * per);
	void EntraColaNormal(Persona * per);
	void moverColas();
	bool transicion(Persona *);

	int getEsperaNormal(){
		return esperaNormal;
	}
	int getEsperaVip(){
		return esperaVip;
	}

	int getTiempo();
	void setTiempo(int);

	bool getActivado();
	void setActivado(bool);
};



#endif /* defined(__Proyecto_Final_Cubells__Juego__) */