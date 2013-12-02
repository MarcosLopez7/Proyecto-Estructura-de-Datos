//
//  Parque.cpp
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#include <ctime>
#include "Parque.h"
#include "Atraccion.h"
#include "Juego.h"
#include "Snack.h"

using namespace std;


Parque::Parque(Persona * e){
	caminos = new Grafo<Atraccion *, int>();
	//personas = new ListaEnlazada<Persona *>;
	congelado = new ListaEnlazada<Persona *>;
	srand((int) time(NULL));
	idPersona = 0;
	log = new Log();
	log->writeToLog("Creación del parque");
	congeladoSnack = new ListaEnlazada<Persona *>;
	especial = e;
}

void Parque::crearJuegos(){
	batman = new Juego(this, 5, 30, "Batman");
	superman = new Juego(this, 2, 40, "Superman");
	boomerang = new Juego(this, 8, 20, "Boomerang");
	medusa = new Juego(this, 3, 15, "Medusa");
	splash = new Juego(this, 10, 20, "Splash");
	kilauea = new Juego(this, 3, 26, "Kilauea");
	huracan = new Juego(this, 8, 40, "Huracan");
	goKart = new Juego(this, 5, 15, "Go Kart");
	vudu = new Juego(this, 8, 30, "Vudu");
	snack = new Snack(this, "Cafeteria");
	entrada = new Atraccion(this, "Entrada");
	log->writeToLog("Creacion de juegos");
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
    
	//for (int i = 0; i < distancia11->size(); i++)
    //cout << distancia11->at(i) << " ";
    
	//cout << endl;
    
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
		for (int i = 0; i < n; i++){
			int Num = rand() % 9;
			mandarPersona(new Persona(t, to_string(idPersona)), t, Num);
			idPersona++;
		}
	}
	if (t >= 720 && t < 840){
		int n = rand() % 400;
		for (int i = 0; i < n; i++){
			int Num = rand() % 9;
			mandarPersona(new Persona(t, to_string(idPersona)), t, Num);
			idPersona++;
		}
	}
	if (t >= 840 && t < 1080){
		int n = rand() % 200;
		for (int i = 0; i < n; i++){
			int Num = rand() % 9;
			mandarPersona(new Persona(t, to_string(idPersona)), t, Num);
			idPersona++;
		}
	}
	if (t >= 1080 && t <= 1200){
		int n = rand() % 50;
		for (int i = 0; i < n; i++){
			int Num = rand() % 9;
			mandarPersona(new Persona(t, to_string(idPersona)), t, Num);
			idPersona++;
		}
	}
}

void Parque::mandarPersona(Persona * persona, int t, int Num)
{
	switch (Num)
	{
        case 0:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][1]);
			persona->setSiguienteAtraccion(batman);
			persona->setUbicacion(1);
			congelado->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 1:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][2]);
			persona->setSiguienteAtraccion(superman);
			persona->setUbicacion(2);
			congelado->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 2:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][3]);
			persona->setSiguienteAtraccion(boomerang);
			persona->setUbicacion(3);
			congelado->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 3:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][4]);
			persona->setSiguienteAtraccion(medusa);
			persona->setUbicacion(4);
			congelado->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 4:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][5]);
			persona->setSiguienteAtraccion(splash);
			persona->setUbicacion(5);
			congelado->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 5:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][6]);
			persona->setSiguienteAtraccion(kilauea);
			persona->setUbicacion(6);
			congelado->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 6:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][7]);
			persona->setSiguienteAtraccion(huracan);
			persona->setUbicacion(7);
			congelado->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 7:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][8]);
			persona->setSiguienteAtraccion(goKart);
			persona->setUbicacion(8);
			congelado->insertBack(new Nodo<Persona *>(persona));
		}
            break;
        case 8:
		{
			persona->setCongelamiento(distancias[persona->getUbicacion()][9]);
			persona->setSiguienteAtraccion(vudu);
			persona->setUbicacion(9);
			congelado->insertBack(new Nodo<Persona *>(persona));
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
        
		temp1->getInfo()->setHambre(temp1->getInfo()->getHambre() - 1);
        
		if (temp1->getInfo()->getCongelamiento() == 0){
			filaRandom(temp1->getInfo());
			congelado->deleteAtNodo(temp1);
		}
		else{
			temp1->getInfo()->setCongelamiento(temp1->getInfo()->getCongelamiento() - 1);
		}
		temp1 = temp1->getNext();
	}
}

void Parque::filaRandom(Persona * per){
	
    int seleccion;
    if (per->getNombre() == "")
        seleccion= rand() % 100 + 1;
    else{
        seleccion = per->getVIP();
        seleccion+=89;
        if (per->getDinero() < 100){
            seleccion = 2;
            if (per->getVIP())
                cout << "No tienes fondos suficientes para ingresar a la fila VIP, entraras a la cola normal" << endl;
        }
        else if (per->getVIP())
            cout << "Se descontaron $100 de tu cuenta" << endl;
    }
    
	if (seleccion < 90)
		AgregarAFilasNormal(per);
    
	if (seleccion >= 90 && seleccion <= 100){
		if (per->getDinero() >= 100){
			per->setDinero(per->getDinero() - 100);
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

void Parque::moverFilas(int actualTime)
{
	for (int i = 0; i < 9; i++){
		switch (i)
		{
            case 0:
                
                if (!batman->getActivado())
                {
                    batman->moverColas(actualTime);
                }
                else
                    batman->setTiempo(batman->getTiempo() - 1);
                break;
            case 1:
                if (!superman->getActivado())
                    superman->moverColas(actualTime);
                else
                    superman->setTiempo(superman->getTiempo() - 1);
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

void Parque::mandarPersonaSnack(Persona * per)
{
	per->setCongelamiento(recorrido(per, 10));
	per->setUbicacion(10);
    per->setSiguienteAtraccion(snack);
	congeladoSnack->insertBack(new Nodo<Persona *>(per));
}

void Parque::checarCongelamientoSnack()
{
	Nodo<Persona *> * temp1 = NULL;
	temp1 = (congeladoSnack->getInicio());
	while (temp1 != NULL) {
        
		temp1->getInfo()->setHambre(temp1->getInfo()->getHambre() - 1);
        
		if (temp1->getInfo()->getCongelamiento() == 0)
		{
			if (temp1->getInfo()->getNombre() == especial->getNombre())
			{
				snack->hambreDinero(temp1->getInfo());
				congeladoSnack->deleteAtNodo(temp1);
			}
			else
			{
				snack->hambreDineroRand(temp1->getInfo());
				congeladoSnack->deleteAtNodo(temp1);
			}
		}
		else{
			temp1->getInfo()->setCongelamiento(temp1->getInfo()->getCongelamiento() - 1);
		}
		temp1 = temp1->getNext();
	}
}

void Parque::checarPersonasComiendo(int actualTime){
    snack->checarPersonasComiendo(actualTime);
}

void Parque::hambrear()
{
	batman->hambrear();
	superman->hambrear();
	boomerang->hambrear();
	medusa->hambrear();
	splash->hambrear();
	kilauea->hambrear();
	huracan->hambrear();
	goKart->hambrear();
	vudu->hambrear();
}

void Parque::checarLlegada(int t)
{
	if (especial->getLLegada() == t)
	{
		menuJuegos(especial);
	}
    
    if ( t >= especial->getLLegada()){
        if (t <= especial->getSalida() ){
            if (especial->getCongelamiento() != 0){
                if (especial->getComiendo())
                    cout << "Estas comiendo, te faltan " << especial->getCongelamiento() << " minutos para terminar." << endl;
                else{
                    cout << "Estas en camino a: " << caminos->elementAt(especial->getUbicacion())->getInfo()->getNombre() << " te faltán " << especial->getCongelamiento() << " minutos para llegar " << endl;
                }
            }
            else{
                cout << "Estas en: " << caminos->elementAt(especial->getUbicacion())->getInfo()->getNombre() << endl;
            }
        }
    }
}

void Parque::menuJuegos(Persona * per)
{
	string opcion;
    cout << endl << endl;
	cout << "Tu ubicacion actual es: ";
	cout << caminos->elementAt(per->getUbicacion())->getInfo()->getNombre() << endl;
	cout << "Tu informacion: \n";
	cout << *per;
    
    batman->calcularTiempo();
    superman->calcularTiempo();
    boomerang->calcularTiempo();
    medusa->calcularTiempo();
    splash->calcularTiempo();
    kilauea->calcularTiempo();
    huracan->calcularTiempo();
    goKart->calcularTiempo();
    vudu->calcularTiempo();
    
	cout << endl;
    
	cout << "Que accion quieres tomar?\n";
	cout << "1.- | Batman |"  << endl << "Te tardarías: " << recorrido(per, 1) << " minutos en llegar a la atracción."<<endl<< "Tiempo aproximado de espera: " << endl <<"\t- Cola normal: " << batman->getEsperaNormal() << " minutos."<<endl <<"\t- Cola VIP: " << batman->getEsperaVip() << " minutos."<< endl<<endl;
    cout << "2.- | Superman |"  << endl << "Te tardarías: " << recorrido(per, 2) << " minutos en llegar a la atracción."<<endl<< "Tiempo aproximado de espera: " << endl <<"\t- Cola normal: " << superman->getEsperaNormal() << " minutos."<<endl <<"\t- Cola VIP: " << superman->getEsperaVip() << " minutos."<< endl<<endl;
    cout << "3.- | Boomerang |"  << endl << "Te tardarías: " << recorrido(per, 3) << " minutos en llegar a la atracción."<<endl<< "Tiempo aproximado de espera: " << endl <<"\t- Cola normal: " << boomerang->getEsperaNormal() << " minutos."<<endl <<"\t- Cola VIP: " << boomerang->getEsperaVip() << " minutos."<< endl<<endl;
    cout << "4.- | Medusa |"  << endl << "Te tardarías: " << recorrido(per, 4) << " minutos en llegar a la atracción."<<endl<< "Tiempo aproximado de espera: " << endl <<"\t- Cola normal: " << medusa->getEsperaNormal() << " minutos."<<endl <<"\t- Cola VIP: " << medusa->getEsperaVip() << " minutos."<< endl<<endl;
    cout << "5.- | Spalsh |"  << endl << "Te tardarías: " << recorrido(per, 5) << " minutos en llegar a la atracción."<<endl<< "Tiempo aproximado de espera: " << endl <<"\t- Cola normal: " << splash->getEsperaNormal() << " minutos."<<endl <<"\t- Cola VIP: " << splash->getEsperaVip() << " minutos."<< endl<<endl;
    cout << "6.- | Kilauea |"  << endl << "Te tardarías: " << recorrido(per, 6) << " minutos en llegar a la atracción."<<endl<< "Tiempo aproximado de espera: " << endl <<"\t- Cola normal: " << kilauea->getEsperaNormal() << " minutos."<<endl <<"\t- Cola VIP: " << kilauea->getEsperaVip() << " minutos."<< endl<<endl;
    cout << "7.- | Huracán |"  << endl << "Te tardarías: " << recorrido(per, 7) << " minutos en llegar a la atracción."<<endl<< "Tiempo aproximado de espera: " << endl <<"\t- Cola normal: " << huracan->getEsperaNormal() << " minutos."<<endl <<"\t- Cola VIP: " << huracan->getEsperaVip() << " minutos."<< endl<<endl;
    cout << "8.- | Go Kart |"  << endl << "Te tardarías: " << recorrido(per, 8) << " minutos en llegar a la atracción."<<endl<< "Tiempo aproximado de espera: " << endl <<"\t- Cola normal: " << goKart->getEsperaNormal() << " minutos."<<endl <<"\t- Cola VIP: " << goKart->getEsperaVip() << " minutos."<< endl<<endl;
    cout << "9.- | Vudu |"  << endl << "Te tardarías: " << recorrido(per, 9) << " minutos en llegar a la atracción."<<endl<< "Tiempo aproximado de espera: " << endl <<"\t- Cola normal: " << vudu->getEsperaNormal() << " minutos."<<endl <<"\t- Cola VIP: " << vudu->getEsperaVip() << " minutos."<< endl<<endl;
    cout << "10.- | Cafetería |"  << endl << "Te tardarías: " << recorrido(per, 10) << " minutos en llegar a la atracción."<<endl<<endl<<endl;

    int opcion1;
    
    while (true){
        cin >> opcion;
        if (verificarNumero(opcion)){
            opcion1 = stoi(opcion);
            if (opcion1 > 0 && opcion1 <=10)
                break;
            else
                cout << "Opción invalida, opciones van del 1 al 10" << endl;
            
        }
        else {
        cout << "Opción invalida, intenta nuevamente" << endl;
        }
    }
	opcion1--;
    
    
	if (opcion1 != 9)
	{
		menuVipNormal(per);
		mandarPersona(per, 0, opcion1);
	}
    else
        mandarPersonaSnack(per);
}

void Parque::menuVipNormal (Persona * per){
    cout << endl;
    cout << "1. Entrar a la cola Nomral" << endl;
    cout << "2. Entrar a la cola VIP (Costo de $100)" << endl;
    cout << endl;
    
    string opcion;
    int opcion1;
    
    while (true){
        cin >> opcion;
        if (verificarNumero(opcion)){
            opcion1 = stoi(opcion);
            if (opcion1 > 0 && opcion1 <=2)
                break;
            else
                cout << "Opción invalida, opciones van del 1 al 2" << endl;
            
        }
        else {
            cout << "Opción invalida, intenta nuevamente" << endl;
        }
    }
    opcion1--;
    per->setVIP(opcion1);
}

int Parque::recorrido (Persona * UbicacionActual , int Destino){
    return distancias[UbicacionActual->getUbicacion()][Destino];
}

void Parque::escribirDocumentos(int actualTime){
    log->writeToLog("\n|Batman|\nPersonas en cola normal: " +
                    to_string(batman->getColaNomal()->size()) +
                    "\nPersonas en cola VIP: "+
                    to_string(batman->getColaVip()->size()) +
                    "\nPersonas en la atracción: " +
                    to_string(batman->getArriba()->size()) +
                    "\nActivado? " + (batman->getActivado()?"sí":"no")+
                    "\n|Superman|\nPersonas en cola normal: " +
                    to_string(superman->getColaNomal()->size()) +
                    "\nPersonas en cola VIP: "+
                    to_string(superman->getColaVip()->size()) +
                    "\nPersonas en la atracción: " +
                    to_string(superman->getArriba()->size()) +
                    "\nActivado? " + (superman->getActivado()?"sí":"no")+
                    "\n|Boomerang|\nPersonas en cola normal: " +
                    to_string(boomerang->getColaNomal()->size()) +
                    "\nPersonas en cola VIP: "+
                    to_string(boomerang->getColaVip()->size()) +
                    "\nPersonas en la atracción: " +
                    to_string(boomerang->getArriba()->size()) +
                    "\nActivado? " + (boomerang->getActivado()?"sí":"no")+
                    "\n|Medusa|\nPersonas en cola normal: " +
                    to_string(medusa->getColaNomal()->size()) +
                    "\nPersonas en cola VIP: "+
                    to_string(medusa->getColaVip()->size()) +
                    "\nPersonas en la atracción: " +
                    to_string(medusa->getArriba()->size()) +
                    "\nActivado? " + (medusa->getActivado()?"sí":"no")+
                    "\n|Splash|\nPersonas en cola normal: " +
                    to_string(splash->getColaNomal()->size()) +
                    "\nPersonas en cola VIP: "+
                    to_string(splash->getColaVip()->size()) +
                    "\nPersonas en la atracción: " +
                    to_string(splash->getArriba()->size()) +
                    "\nActivado? " + (splash->getActivado()?"sí":"no")+
                    "\n|Kilauea|\nPersonas en cola normal: " +
                    to_string(kilauea->getColaNomal()->size()) +
                    "\nPersonas en cola VIP: "+
                    to_string(kilauea->getColaVip()->size()) +
                    "\nPersonas en la atracción: " +
                    to_string(kilauea->getArriba()->size()) +
                    "\nActivado? " + (kilauea->getActivado()?"sí":"no")+
                    "\n|Huracán|\nPersonas en cola normal: " +
                    to_string(huracan->getColaNomal()->size()) +
                    "\nPersonas en cola VIP: "+
                    to_string(huracan->getColaVip()->size()) +
                    "\nPersonas en la atracción: " +
                    to_string(huracan->getArriba()->size()) +
                    "\nActivado? " + (huracan->getActivado()?"sí":"no")+
                    "\n|Go Kart|\nPersonas en cola normal: " +
                    to_string(goKart->getColaNomal()->size()) +
                    "\nPersonas en cola VIP: "+
                    to_string(goKart->getColaVip()->size()) +
                    "\nPersonas en la atracción: " +
                    to_string(goKart->getArriba()->size()) +
                    "\nActivado? " + (goKart->getActivado()?"sí":"no")+
                    "\n|Vudu|\nPersonas en cola normal: " +
                    to_string(vudu->getColaNomal()->size()) +
                    "\nPersonas en cola VIP: "+
                    to_string(vudu->getColaVip()->size()) +
                    "\nPersonas en la atracción: " +
                    to_string(vudu->getArriba()->size()) +
                    "\nActivado? " + (vudu->getActivado()?"sí":"no")+
                    "\n|Cafetería|\nPersonas comiendo: " +
                    to_string(snack->getComiendo()->size()) +
                    "\nPersonas caminando en el parque: " +
                    to_string(congelado->size() + congeladoSnack->size())
                    , actualTime);
}

bool Parque::verificarNumero (string prueba){
    int numero = 0;
    if (istringstream(prueba) >> numero)
        return true;
    else
        return false;
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
    delete especial;
}