//
//  Parque.h
//  Proyecto Final Cubells
//
//  Created by César Millán on 11/11/13.
//  Copyright (c) 2013 César Millán. All rights reserved.
//

#ifndef __Proyecto_Final_Cubells__Parque__
#define __Proyecto_Final_Cubells__Parque__

#include <iostream>
#include <vector>

#include "Lista.h"
#include "Grafo.h"
//#include "Vertice.h"
//#include "Arista.h"
#include "Persona.h"
#include "Log.h"

class Atraccion;
class Juego;
class Snack;

class Parque{
    Juego * batman;
    Juego * superman;
    Juego * boomerang;
    Juego * medusa;
    Juego * splash;
    Juego * kilauea;
    Juego * huracan;
    Juego * goKart;
    Juego * vudu;
    Snack * snack;
    Atraccion * entrada;
    //Cola<Persona *> * colaGeneral;
    Grafo<Atraccion *, int> * caminos;
    ListaEnlazada<Persona *> * personas;
    ListaEnlazada<Persona *> * congelado;
    int idPersona;

public:
    vector<vector<int>> distancias;

    Parque();
    void crearJuegos();
    void checarCongelamiento();
    void crearBots(int actualTime);
    void AgregarAFilasVip(Persona * per);
    void AgregarAFilasNormal(Persona * per);
    void filaRandom(Persona * per);
    void crearGrapho();
    void mandarPersona (Persona * per, int t);
    void moverFilas (int t);
    Log * log;

    ~Parque();

};

#endif /* defined(__Proyecto_Final_Cubells__Parque__) */
