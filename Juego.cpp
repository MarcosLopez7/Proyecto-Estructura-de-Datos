//
//  Juego.cpp
//  Proyecto Final Cubells
//
//  Created by César Millán on 11/11/13.
//  Copyright (c) 2013 César Millán. All rights reserved.
//

#include "Juego.h"

void Juego::EntraColaVip(Persona * per){
	colaVip->enqueue(new Nodo<Persona *>(per));
}

Persona * Juego::SalColaVip(){
	return colaVip->dequeue()->getInfo();
}

void Juego::EntraColaNormal(Persona * per){
	colaNormal->enqueue(new Nodo<Persona *>(per));
}

Persona * Juego::SalColaNormal(){
	return colaNormal->dequeue()->getInfo();
}

void Juego::EntraJuego(Persona * per){
	arriba->push(new Nodo<Persona *>(per));
}

Persona * Juego::SalJuego(){
	return arriba->pop()->getInfo();
}

bool Juego::getActivado()
{
	return activado;
}

void Juego::setActivado(bool a)
{
	activado = a;
}

int Juego::getTiempo()
{
	return tiempo;
}

void Juego::setTiempo(int t)
{
	tiempo = t;
	if (tiempo = 0)
		activado = false;
}

void Juego::moverColas()
{
	int i = 0;
	while (!colaVip->empty() && i < 3)
	{
		EntraJuego(SalColaVip());
	}

	while (!colaNormal->empty() && i < capacidad - 3)
	{
		EntraJuego(SalColaNormal());
	}

	activado = true;
}


void Juego::calcularTiempo(){
	esperaVip = (colaVip->size() / 3.0) * duracion;
	esperaNormal = ((colaNormal->size()) / (capacidad - 3))*duracion;
}

bool Juego::transicion(Persona * p)
{
	if (p->getCongelamiento() == 0)
	{
		int lol = rand() % 9;
		if (3 > lol)
		{
			EntraColaVip(p);
		}
		else
		{
			EntraColaNormal(p);
		}
		return true;
	}
	else
		return false;
}