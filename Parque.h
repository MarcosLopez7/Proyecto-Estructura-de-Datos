//
//  Parque.h
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#ifndef __Proyecto_Final_Estructura_de_Datos_TC1018__Parque__
#define __Proyecto_Final_Estructura_de_Datos_TC1018__Parque__

#include <iostream>
#include <vector>

#include "Lista.h"
#include "Grafo.h"
//#include "Vertice.h"
//#include "Arista.h"
#include "Persona.h"
#include "Log.h"
#include <sstream>

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
	Grafo<Atraccion *, int> * caminos;
	ListaEnlazada<Persona *> * personas;
	ListaEnlazada<Persona *> * congelado;
	ListaEnlazada<Persona *> * congeladoSnack;
	int idPersona;
	Persona * especial;
    
public:
	vector<vector<int>> distancias;
    bool verificarNumero (std::string prueba);
	Persona * getEspecial()
	{
		return especial;
	}
    
	Parque(Persona *);
	void crearJuegos();
	void checarCongelamiento();
	void checarCongelamientoSnack();
	void checarPersonasComiendo(int);
	void crearBots(int actualTime);
	void AgregarAFilasVip(Persona * per);
	void AgregarAFilasNormal(Persona * per);
	void filaRandom(Persona * per);
	void crearGrapho();
	void mandarPersona(Persona * per, int t, int);
	void moverFilas(int t);
	void mandarPersonaSnack(Persona * per);
	void hambrear();
	void checarLlegada(int t);
	void menuJuegos(Persona *);
    void menuVipNormal (Persona * per);
    int recorrido (Persona * UbicacionActual , int Destino);
    void escribirDocumentos(int actualTime);

	Log * log;
    
	~Parque();
    
};

#endif /* defined(__Proyecto_Final_Estructura_de_Datos_TC1018__Parque__) */
