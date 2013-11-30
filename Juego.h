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

//class Parque;
//class Persona;

class Juego:public Atraccion{
    Cola<Persona * > * colaVip;
    Cola<Persona * > * colaNormal;
    Pila<Persona * > * arriba;
    int capacidad;
    int duracion;
    int esperaVip;
    int esperaNormal;
    int tiempo;
    bool activado;
    
    Persona * SalColaVip ();
    Persona * SalColaNormal();
    void EntraJuego(Persona * per);
    Persona * SalJuego ();
    void calcularTiempo();

    
    Cola<Persona *> * getColaVip () const{
        return colaVip;
    }
    Cola<Persona *> * getColaNomal() const{
        return colaNormal;
    }
    Pila<Persona *> * getArriba () const{
        return arriba;
    }
public:
    
    Juego (Parque * parque,int duracion,int capacidad, std::string nombre);
    void EntraColaVip (Persona * per);
    void EntraColaNormal (Persona * per);
    void moverColas (int actualTime);
    
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
};



#endif /* defined(__Proyecto_Final_Cubells__Juego__) */
