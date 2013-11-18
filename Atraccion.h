//
//  Atraccion.h
//  Proyecto Final Cubells
//
//  Created by César Millán on 11/11/13.
//  Copyright (c) 2013 César Millán. All rights reserved.
//

#ifndef __Proyecto_Final_Cubells__Atraccion__
#define __Proyecto_Final_Cubells__Atraccion__

#include <iostream>
#include <string>
#include "Pila.h"
#include "Cola.h"
#include "Persona.h"


class Atraccion{
protected:
    int tiempoI;
    int tiempoF;
    Cola<Persona *> * colaGeneral;
    std::string nombre;
    
public:
    Atraccion(Cola<Persona *> * colaGeneral, std::string nombre):tiempoF(610),tiempoI(0),nombre(nombre),colaGeneral(colaGeneral){
    }
    
    void setTiempoI (int tiempo){
        tiempoI = tiempo;
    }
    
    int getTiempoI () const{
        return tiempoI;
    }
    
    void setTiempoF (int tiempo){
        tiempoF=tiempo;
    }
    
    int getTiempoF () const{
        return tiempoF;
    }
    
    std::string getNombre() const{
        return nombre;
    }
    
    void setNombre (std::string nombre){
        this->nombre = nombre;
    }
};

#endif /* defined(__Proyecto_Final_Cubells__Atraccion__) */
