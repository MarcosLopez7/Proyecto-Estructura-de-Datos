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

void Juego::moverColas (int actualTime){
    int cont = 0;
    int vip = 0;
    
    while (!arriba->empty()) {
        Persona * temp = SalJuego();
        if (actualTime >= temp->getSalida() && temp->getNombre() != "")
            delete temp;
        else
            colaGeneral->enqueue(new Nodo<Persona *> (temp));
    }

    while (cont != capacidad && !colaNormal->empty() && !colaVip->empty()) {
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
    tiempoI = actualTime;
    tiempoF = actualTime + duracion;
}


