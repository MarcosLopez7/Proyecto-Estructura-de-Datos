//
//  Juego.cpp
//  Proyecto Final Cubells
//
//  Created by César Millán on 11/11/13.
//  Copyright (c) 2013 César Millán. All rights reserved.
//

#include "Juego.h"
#include "Parque.h"
//#include "Persona.cpp"

Juego::Juego(Parque * parque, int duracion, int capacidad, std::string nombre):Atraccion(parque,nombre),duracion(duracion), capacidad(capacidad) {
    colaVip=new Cola<Persona *>;
    colaNormal= new Cola<Persona *>;
    arriba = new Pila<Persona *>;
    activado = false;
    tiempo = 0;
    //capacidad = rand() % 2; // **opcion**
    //duracion = rand() % 2; // **opcion**
}

void Juego::EntraColaVip (Persona * per){
    colaVip->enqueue(new Nodo<Persona *>(per));
}

Persona * Juego::SalColaVip (){
    return colaVip->dequeue()->getInfo();
}

void Juego::EntraColaNormal (Persona * per){
    colaNormal->enqueue(new Nodo<Persona *>(per));
}

Persona * Juego::SalColaNormal(){
    return colaNormal->dequeue()->getInfo();
}

void Juego::EntraJuego(Persona * per){
    arriba->push(new Nodo<Persona *>(per));
}

Persona * Juego::SalJuego (){
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

void Juego::moverColas (int actualTime){
    int cont = 0;
    int vip = 0;
    
    while (!arriba->empty()) {
        Persona * temp = SalJuego();
        if (actualTime + (parque->distancias[temp->getUbicacion()][0]) >= temp->getSalida())
            delete temp;
        else
            parque->mandarPersona(temp, actualTime);
            //parque->filaRandom(temp);
            //colaGeneral->enqueue(new Nodo<Persona *> (temp));
    }

    while (cont != capacidad && (!colaNormal->empty() && !colaVip->empty())) {
        if (!colaVip->empty() && vip < 3){
            EntraJuego(SalColaVip());
            vip++;
            cont++;
        }
        else if(!colaNormal->empty()){
            EntraJuego(SalColaNormal());
            cont++;
        }
    }
    
    tiempo = duracion;
    
    //tiempoI = actualTime;
    //tiempoF = actualTime + duracion;
    calcularTiempo();
}

void Juego::calcularTiempo(){
    esperaVip = (colaVip->size()/3.0) * duracion;
    esperaNormal = ((colaNormal->size())/(capacidad-3))*duracion;
}


