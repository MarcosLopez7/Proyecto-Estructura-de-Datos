//
//  Snack.cpp
//  Proyecto Final Cubells
//
//  Created by César Millán on 11/11/13.
//  Copyright (c) 2013 César Millán. All rights reserved.
//

#include "Snack.h"
using namespace std;

int Snack::menu(){
	cout << "Elige una opción: " << endl;
	cout << "1. Combo Hamburguesa \n  -80% hambre\n  $80" << endl;
	cout << "2. Combo HotDog \n  -60% hambre\n  $60" << endl;
	cout << "3. Combo Arrachera \n  -100% hambre\n  $120" << endl;
	cout << "4. Papas fritas \n  -30% hambre\n  $30" << endl;
	cout << "5. Refresco \n -5% hambre\n  $15" << endl;
	int opcion;
	cin >> opcion;
	return opcion;
}

void Snack::hambreDinero(Persona * per) {
	int opcion = menu();
	operacionesHambreDinero(per, opcion);
}

void Snack::hambreDineroRand(Persona * per) {
	srand((int) time(NULL));
	int opcion = rand() % 6;
	operacionesHambreDinero(per, opcion);
}

void Snack::operacionesHambreDinero(Persona * per, int opcion){
	switch (opcion) {
	case 1:
		per->setHambre(Hambre(80, per));
		per->setDinero(Fondos(80, per));
		break;
	case 2:
		per->setHambre(Hambre(60, per));
		per->setDinero(Fondos(60, per));
		break;
	case 3:
		per->setHambre(Hambre(100, per));
		per->setDinero(Fondos(120, per));
		break;
	case 4:
		per->setHambre(Hambre(30, per));
		per->setDinero(Fondos(30, per));
		break;
	case 5:
		per->setHambre(Hambre(5, per));
		per->setDinero(Fondos(15, per));
		break;
	case 6:
		break;
	default:
		cout << "Opcion invalida!" << endl;
		break;
	}
}

int Snack::Hambre(int nSatisfecho, Persona * per){
	if (per->getHambre() + nSatisfecho >= 100) {
		nSatisfecho = 100;
	}
	else{
		nSatisfecho = per->getHambre() + nSatisfecho;
	}
	return nSatisfecho;
}

int Snack::Fondos(int costo, Persona * per){
	if (per->getDinero() < costo){
		throw "No tienes dinero suficiente";
	}
	else{
		costo = per->getDinero() - costo;
	}

	return costo;
}