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

class Juego:public Atraccion{
    Cola<Persona * > * colaVip;
    Cola<Persona * > * colaNormal;
    Pila<Persona * > * arriba;
    int capacidad;
    
public:
    Juego(int tiempoI, int tiempoF, std::string nombre):Atraccion(tiempoI,tiempoF,nombre), capacidad(0){
        colaVip=new Cola<Persona *>;
        colaNormal= new Cola<Persona *>;
        arriba = new Pila<Persona *>;
    }
    
    Cola<Persona *> * getColaVip () const{
        return colaVip;
    }
    Cola<Persona *> * getColaNomal() const{
        return colaNormal;
    }
    Pila<Persona *> * getArriba () const{
        return arriba;
    }
    
    void EntraColaVip (Persona * per);
    Persona * SalColaVip ();
    void EntraColaNormal (Persona * per);
    Persona * SalColaNormal();
    void EntraJuego(Persona * per);
    Persona * SalJuego ();
};



#endif /* defined(__Proyecto_Final_Cubells__Juego__) */
