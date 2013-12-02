//
//  Juego.cpp
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#include "Juego.h"
#include "Parque.h"

Juego::Juego(Parque * parque, int duracion, int capacidad, std::string nombre) : Atraccion(parque, nombre), duracion(duracion), capacidad(capacidad), tiempo(0), activado(false) {
	colaVip = new Cola<Persona *>;
	colaNormal = new Cola<Persona *>;
	arriba = new Pila<Persona *>;
    capacidadVip = this->capacidad * 0.3;
}

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
	if (tiempo == 0)
		activado = false;
}

void Juego::moverColas(int actualTime){
	int cont = 0;
	int vip = 0;
    
	while (!arriba->empty()) {
		Persona * temp = SalJuego();
		if (temp->getNombre() == parque->getEspecial()->getNombre())
		{
			if (actualTime + (parque->recorrido(temp, 0)) >= temp->getSalida()){
                cout << "Ya te tienes que ir, bye!" << endl;
            }
            else {
                if (temp->getHambre() <= 0 ){
                    if (temp->getDinero() >= 100){
                    cout << "Ya no tienes energía te mandaremos a la cafetería" << endl;
                    parque->mandarPersonaSnack(temp);
                    }
                    else{
                        cout << "Ya te fuiste, ya no tienes energía ni dinero" << endl;
                        temp->setSalida(actualTime+1);
                    }
                        
                    
                }
                    
                else
                    parque->menuJuegos(temp);
            }
		}
		else
		{
			if (actualTime + parque->recorrido(temp, 0) >= temp->getSalida())
				delete temp;
			else
			{
				if (temp->getHambre() <= 60)
				{
                    if (temp->getDinero() < 15)
						delete temp;
					else
						parque->mandarPersonaSnack(temp);
				}
				else
				{
					int Num = rand() % 9;
					parque->mandarPersona(temp, actualTime, Num);
				}
			}
		}
	}
    
	while (cont != capacidad) {
		if (!colaVip->empty() && vip < capacidadVip){
			EntraJuego(SalColaVip());
			vip++;
			cont++;
		}
		else if (!colaNormal->empty()){
			EntraJuego(SalColaNormal());
			cont++;
		}
        if (colaNormal->empty() && colaVip->empty())
            break;
	}
    
	tiempo = duracion - 1;
	activado = true;
    
}

void Juego::hambrear()
{
	Cola<Persona *> * temp = new Cola<Persona *>();
	Cola<Persona *> * tempVIP = new Cola<Persona *>();
    
	while (!colaVip->empty())
	{
		colaVip->getFirst()->getInfo()->setHambre(colaVip->getFirst()->getInfo()->getHambre() - 1);
		tempVIP->enqueue(colaVip->dequeue());
	}
    
	while (!tempVIP->empty())
		colaVip->enqueue(tempVIP->dequeue());
    
	delete tempVIP;
    
    
	while (!colaNormal->empty())
	{
		colaNormal->getFirst()->getInfo()->setHambre(colaNormal->getFirst()->getInfo()->getHambre() - 1);
		temp->enqueue(colaNormal->dequeue());
	}
    
	while (!temp->empty())
		colaNormal->enqueue(temp->dequeue());
    
	delete temp;
}

void Juego::calcularTiempo(){
	esperaVip = (colaVip->size() / capacidadVip) * duracion;
	esperaNormal = ((colaNormal->size()) / (capacidad - capacidadVip))*duracion;
}

Juego::~Juego(){
    delete colaVip;
    delete arriba;
    delete colaNormal;
}
