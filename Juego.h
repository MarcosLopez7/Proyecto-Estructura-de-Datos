//
//  Juego.h
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#ifndef __Proyecto_Final_Estructura_de_Datos_TC1018__Juego__
#define __Proyecto_Final_Estructura_de_Datos_TC1018__Juego__

#include <iostream>
#include "Atraccion.h"

class Juego : public Atraccion{
	Cola<Persona * > * colaVip;
	Cola<Persona * > * colaNormal;
	Pila<Persona * > * arriba;
	int capacidad;
	int duracion;
    int capacidadVip;
	int esperaVip;
	int esperaNormal;
	int tiempo;
	bool activado;
    
	Persona * SalColaVip();
	Persona * SalColaNormal();
	void EntraJuego(Persona * per);
	Persona * SalJuego();
    

public:
    
	Juego(Parque * parque, int duracion, int capacidad, std::string nombre);
    ~Juego();
	void EntraColaVip(Persona * per);
	void EntraColaNormal(Persona * per);
	void moverColas(int actualTime);
	void hambrear();
    void calcularTiempo();
    
    
	bool getActivado();
	void setActivado(bool a);
	int getTiempo();
	void setTiempo(int t);
    
	int getEsperaNormal(){
		return esperaNormal;
	}
	int getEsperaVip(){
		return esperaVip;
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
};

#endif /* defined(__Proyecto_Final_Estructura_de_Datos_TC1018__Juego__) */
