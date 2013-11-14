//
//  Juego.cpp
//  Proyecto Final Cubells
//
//  Created by César Millán on 11/11/13.
//  Copyright (c) 2013 César Millán. All rights reserved.
//

#include "Juego.h"

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