//
//  Parque.cpp
//  Proyecto Final Cubells
//
//  Created by César Millán on 11/11/13.
//  Copyright (c) 2013 César Millán. All rights reserved.
//

#include <ctime>
#include "Parque.h"
#include "Atraccion.h"
#include "Juego.h"
#include "Snack.h"

using namespace std;


Parque::Parque (){
    caminos = new Grafo<Atraccion *, int>();
    //personas = new ListaEnlazada<Persona *>;
    congelado = new ListaEnlazada<Persona *>;
    srand((int)time(NULL));
    idPersona = 0;
    log = new Log();
    log->writeToLog("Creación del parque");
}

void Parque::crearJuegos(){
    batman = new Juego(this, 5, 30, "Batman");
    superman = new Juego(this, 2,40, "Superman");
    boomerang = new Juego (this, 8,20, "Boomerang");
    medusa = new Juego (this, 5,15, "Medusa");
    splash = new Juego (this, 10,20,"Splash");
    kilauea = new Juego (this, 3,26, "Kilauea");
    huracan = new Juego(this , 8, 40, "Huracan");
    goKart = new Juego(this, 10, 10, "Go Kart");
    vudu = new Juego(this, 8, 30, "Vudu");
    snack = new Snack(this, "Cafeteria");
    entrada = new Atraccion(this, "Entrada");
    log->writeToLog("Creación de juegos");
}

void Parque::crearGrapho(){
    Vertice<Atraccion *, int> * v1 = new Vertice<Atraccion *, int>(entrada);
    Vertice<Atraccion *, int> * v2 = new Vertice<Atraccion *, int>(batman);
    Vertice<Atraccion *, int> * v3 = new Vertice<Atraccion *, int>(superman);
    Vertice<Atraccion *, int> * v4 = new Vertice<Atraccion *, int>(boomerang);
    Vertice<Atraccion *, int> * v5 = new Vertice<Atraccion *, int>(medusa);
    Vertice<Atraccion *, int> * v6 = new Vertice<Atraccion *, int>(splash);
    Vertice<Atraccion *, int> * v7 = new Vertice<Atraccion *, int>(kilauea);
    Vertice<Atraccion *, int> * v8 = new Vertice<Atraccion *, int>(huracan);
    Vertice<Atraccion *, int> * v9 = new Vertice<Atraccion *, int>(goKart);
    Vertice<Atraccion *, int> * v10 = new Vertice<Atraccion *, int>(vudu);
    Vertice<Atraccion *, int> * v11 = new Vertice<Atraccion *, int>(snack);
    
    caminos->insertarVertice(v1);
	caminos->insertarVertice(v2);
	caminos->insertarVertice(v3);
	caminos->insertarVertice(v4);
	caminos->insertarVertice(v5);
	caminos->insertarVertice(v6);
	caminos->insertarVertice(v7);
	caminos->insertarVertice(v8);
	caminos->insertarVertice(v9);
	caminos->insertarVertice(v10);
	caminos->insertarVertice(v11);
    
    caminos->insertarArista(v1, v3, 2); // entrada a superman
	caminos->insertarArista(v3, v1, 2); // superman a entrada
	caminos->insertarArista(v3, v7, 8); // superman a kilauea
	caminos->insertarArista(v7, v3, 8); // kilauea a superman
	caminos->insertarArista(v3, v11, 7); // superman a snack
	caminos->insertarArista(v11, v3, 7); // snack a superman
	caminos->insertarArista(v3, v5, 5); // superman a medusa
	caminos->insertarArista(v5, v3, 5); // medusa a superman
	caminos->insertarArista(v7, v10, 2); // kilauea a Vudu
	caminos->insertarArista(v10, v7, 2); // vudu a kilauea
	caminos->insertarArista(v7, v4, 3); // kilauea a boomerang
	caminos->insertarArista(v4, v7, 3); // boomerang a kilauea
	caminos->insertarArista(v11, v9, 6); // snack a gokart
	caminos->insertarArista(v9, v11, 6); // gokart a snack
	caminos->insertarArista(v5, v8, 2); // medusa a huracan
	caminos->insertarArista(v8, v5, 2); // huracan a medusa
	caminos->insertarArista(v8, v9, 7); // huracan a gokart
	caminos->insertarArista(v9, v8, 7); // gokart a huracan
	caminos->insertarArista(v9, v4, 4); // gokart a boomerang
	caminos->insertarArista(v4, v9, 4); // boomerang a gokart
	caminos->insertarArista(v10, v4, 2); // vudu a boomerang
	caminos->insertarArista(v4, v10, 2); // boomerang a vudu
	caminos->insertarArista(v10, v6, 2); // vudu a splash
	caminos->insertarArista(v6, v10, 2); // splash a vudu
	caminos->insertarArista(v4, v6, 1); // boomerang a splash
	caminos->insertarArista(v6, v4, 1); // splash a boomerang
	caminos->insertarArista(v6, v2, 2); // splash a batman
	caminos->insertarArista(v2, v6, 2); // batman a splash
    
    vector<int> * distancia1 = new vector<int>;
    vector<int> * distancia2 = new vector<int>;
    vector<int> * distancia3 = new vector<int>;
    vector<int> * distancia4 = new vector<int>;
    vector<int> * distancia5 = new vector<int>;
    vector<int> * distancia6 = new vector<int>;
    vector<int> * distancia7 = new vector<int>;
    vector<int> * distancia8 = new vector<int>;
    vector<int> * distancia9 = new vector<int>;
    vector<int> * distancia10 = new vector<int>;
    vector<int> * distancia11 = new vector<int>;
    
    *distancia1 = caminos->dijkstra(v1);
	*distancia2 = caminos->dijkstra(v2);
	*distancia3 = caminos->dijkstra(v3);
	*distancia4 = caminos->dijkstra(v4);
	*distancia5 = caminos->dijkstra(v5);
	*distancia6 = caminos->dijkstra(v6);
	*distancia7 = caminos->dijkstra(v7);
	*distancia8 = caminos->dijkstra(v8);
	*distancia9 = caminos->dijkstra(v9);
	*distancia10 = caminos->dijkstra(v10);
	*distancia11 = caminos->dijkstra(v11);
    
    
	distancias.push_back(*distancia1);
	distancias.push_back(*distancia2);
	distancias.push_back(*distancia3);
	distancias.push_back(*distancia4);
	distancias.push_back(*distancia5);
	distancias.push_back(*distancia6);
	distancias.push_back(*distancia7);
	distancias.push_back(*distancia8);
	distancias.push_back(*distancia9);
	distancias.push_back(*distancia10);
	distancias.push_back(*distancia11);
    
    log->writeToLog("Creación de grafo y algoritmo de dijkstra");
}

void Parque::crearBots(int t){
    if (t < 720){
        int n = rand() % 600;
        for(int i = 0; i < n;i++){
            mandarPersona(new Persona(t,to_string(idPersona)), t);
            log->writeToLog("Llegó persona", t, to_string(idPersona) );
            
            idPersona++;
        }
    }
    if (t >= 720 && t < 840){
        int n = rand() % 400;
        for(int i = 0; i < n;i++){
            mandarPersona(new Persona(t,to_string(idPersona)), t);
            log->writeToLog("Llegó persona", t, to_string(idPersona) );

            idPersona++;
        }
    }
    if (t >= 840 && t < 1080){
        int n = rand() % 200;
        for(int i = 0; i < n;i++){
            mandarPersona(new Persona(t,to_string(idPersona)), t);
            log->writeToLog("Llegó persona", t, to_string(idPersona) );

            idPersona++;
        }
    }
    if (t >= 1080 && t <= 1200){
        int n = rand() % 50;
        for(int i = 0; i < n;i++){
            mandarPersona(new Persona(t,to_string(idPersona)), t);
            log->writeToLog("Llegó persona", t, to_string(idPersona) );

            idPersona++;
        }
    }
    cout << "Personas en el parque: "<<congelado->size()<<endl;
}

void Parque::mandarPersona(Persona * persona, int t)
{
	int Num = rand() % 9;
	//cout << lala << endl;
	switch (Num)
	{
        case 0:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][1]);
            log->writeToLog("Caminando a siguiente atracción " + to_string(distancias[persona->getUbicacion()][1]) + " minutos para llegar", t, persona->getId());
            persona->setSiguienteAtraccion(batman);
            persona->setUbicacion(1);
            congelado->insertBack(new Nodo<Persona *>(persona));
            //personas->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 1:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][2]);
            log->writeToLog("Caminando a siguiente atracción " + to_string(distancias[persona->getUbicacion()][2]) + " minutos para llegar", t, persona->getId());
            persona->setSiguienteAtraccion(superman);
            persona->setUbicacion(2);
            congelado->insertBack(new Nodo<Persona *>(persona));
            //personas->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 2:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][3]);
            log->writeToLog("Caminando a siguiente atracción " + to_string(distancias[persona->getUbicacion()][3]) + " minutos para llegar", t, persona->getId());
            persona->setSiguienteAtraccion(boomerang);
            persona->setUbicacion(3);
            congelado->insertBack(new Nodo<Persona *>(persona));
            //personas->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 3:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][4]);
            log->writeToLog("Caminando a siguiente atracción " + to_string(distancias[persona->getUbicacion()][4]) + " minutos para llegar", t, persona->getId());
            persona->setSiguienteAtraccion(medusa);
            persona->setUbicacion(4);
            congelado->insertBack(new Nodo<Persona *>(persona));
            //personas->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 4:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][5]);
            log->writeToLog("Caminando a siguiente atracción " + to_string(distancias[persona->getUbicacion()][5]) + " minutos para llegar", t, persona->getId());
            persona->setSiguienteAtraccion(splash);
            persona->setUbicacion(5);
            congelado->insertBack(new Nodo<Persona *>(persona));
            //personas->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 5:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][6]);
            log->writeToLog("Caminando a siguiente atracción " + to_string(distancias[persona->getUbicacion()][6]) + " minutos para llegar", t, persona->getId());
            persona->setSiguienteAtraccion(kilauea);
            persona->setUbicacion(6);
            congelado->insertBack(new Nodo<Persona *>(persona));
            //personas->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 6:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][7]);
            log->writeToLog("Caminando a siguiente atracción " + to_string(distancias[persona->getUbicacion()][7]) + " minutos para llegar", t, persona->getId());
            persona->setSiguienteAtraccion(huracan);
            persona->setUbicacion(7);
            congelado->insertBack(new Nodo<Persona *>(persona));
            //personas->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 7:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][8]);
            log->writeToLog("Caminando a siguiente atracción " + to_string(distancias[persona->getUbicacion()][8]) + " minutos para llegar", t, persona->getId());
            persona->setSiguienteAtraccion(goKart);
            persona->setUbicacion(8);
            congelado->insertBack(new Nodo<Persona *>(persona));
            //personas->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 8:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][9]);
            log->writeToLog("Caminando a siguiente atracción " + to_string(distancias[persona->getUbicacion()][9]) + " minutos para llegar", t, persona->getId());
            persona->setSiguienteAtraccion(vudu);
            persona->setUbicacion(9);
            congelado->insertBack(new Nodo<Persona *>(persona));
            //personas->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        default:
            break;
	}
}

void Parque::checarCongelamiento(){
    Nodo<Persona *> * temp1 = NULL;
    temp1 = (congelado->getInicio());
    while (temp1 != NULL) {
        if (temp1->getInfo()->getCongelamiento() == 0){
            filaRandom(temp1->getInfo());
            congelado->deleteAtNodo(temp1);
        }
        else{
            temp1->getInfo()->setCongelamiento(temp1->getInfo()->getCongelamiento() - 1);
            //temp1 = temp1->getNext();
        }
        temp1 = temp1->getNext();
    }
}

void Parque::filaRandom(Persona * per){
    int seleccion = rand() % 100 + 1;
    
    if (seleccion < 90)
        AgregarAFilasNormal(per);
    
    if (seleccion >=90  && seleccion <= 100){
        if (per->getDinero() >= 100){
            per->setDinero(per->getDinero() - 100 );
            AgregarAFilasVip(per);
        }
        else
            filaRandom(per);
    }
}

void Parque::AgregarAFilasVip(Persona * per){
    switch (per->getUbicacion()){
        case 1:
            batman->EntraColaVip(per);
            break;
        case 2:
            superman->EntraColaVip(per);
            break;
        case 3:
            boomerang->EntraColaVip(per);
            break;
        case 4:
            medusa->EntraColaVip(per);
            break;
        case 5:
            splash->EntraColaVip(per);
            break;
        case 6:
            kilauea->EntraColaVip(per);
            break;
        case 7:
            huracan->EntraColaVip(per);
            break;
        case 8:
            goKart->EntraColaVip(per);
            break;
        case 9:
            vudu->EntraColaVip(per);
            break;

        default:
            break;
    }
}

void Parque::AgregarAFilasNormal(Persona * per){
    switch (per->getUbicacion()) {
        case 1:
            batman->EntraColaNormal(per);
            break;
        case 2:
            superman->EntraColaNormal(per);
            break;
        case 3:
            boomerang->EntraColaNormal(per);
            break;
        case 4:
            medusa->EntraColaNormal(per);
            break;
        case 5:
            splash->EntraColaNormal(per);
            break;
        case 6:
            kilauea->EntraColaNormal(per);
            break;
        case 7:
            huracan->EntraColaNormal(per);
            break;
        case 8:
            goKart->EntraColaNormal(per);
            break;
        case 9:
            vudu->EntraColaNormal(per);
            break;
            
        default:
            break;
    }
}

void Parque::moverFilas (int actualTime)
{
    for(int i = 0; i<9; i++){
        switch (i)
        {
            case 0:
                if (!batman->getActivado())
                    batman->moverColas(actualTime);
                else
                    batman->setTiempo(batman->getTiempo()-1);
                break;
            case 1:
                if (!superman->getActivado())
                    superman->moverColas(actualTime);
                else
                    superman->setTiempo(batman->getTiempo() - 1);
                break;
            case 2:
                if (!boomerang->getActivado())
                    boomerang->moverColas(actualTime);
                else
                    boomerang->setTiempo(boomerang->getTiempo() - 1);
                break;
            case 3:
                if (!medusa->getActivado())
                    medusa->moverColas(actualTime);
                else
                    medusa->setTiempo(medusa->getTiempo() - 1);
                break;
            case 4:
                if (!splash->getActivado())
                    splash->moverColas(actualTime);
                else
                    splash->setTiempo(splash->getTiempo() - 1);
                break;
            case 5:
                if (!kilauea->getActivado())
                    kilauea->moverColas(actualTime);
                else
                    kilauea->setTiempo(kilauea->getTiempo() - 1);
                break;
            case 6:
                if (!huracan->getActivado())
                    huracan->moverColas(actualTime);
                else
                    huracan->setTiempo(huracan->getTiempo() - 1);
                break;
            case 7:
                if (!goKart->getActivado())
                    goKart->moverColas(actualTime);
                else
                    goKart->setTiempo(goKart->getTiempo() - 1);
                break;
            case 8:
                if (!vudu->getActivado())
                    vudu->moverColas(actualTime);
                else
                    vudu->setTiempo(vudu->getTiempo() - 1);
                break;
            default:
                break;
        }
    }
}

Parque::~Parque(){
    delete batman;
    delete superman;
    delete boomerang;
    delete medusa;
    delete splash;
    delete kilauea;
    delete huracan;
    delete goKart;
    delete entrada;
    delete vudu;
    delete snack;
    delete log;
}