//
//  Snack.cpp
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#include "Snack.h"
#include "Parque.h"
#include "Persona.h"
using namespace std;

void Snack::hambreDinero(Persona * per) {
    cout << endl<<endl<<"Bienvenido al Buffet" << endl;
    cout << "El aproximado de comida es de 30 minutos" << endl;
    if (per->getDinero() >= 100 ){
        cout << "El costo es de $100 y te brindará 150 de energía" << endl << endl;
        per->setHambre(Hambre(150, per));
        per->setDinero(Fondos(100, per));
        per->setCongelamiento(30);
        per->setComiendo(true);
        comiendo->insertBack(new Nodo<Persona *>(per));
    }
    else{
        cout << "No te alcanza para comer" << endl;
        parque->menuJuegos(per);
    }
}

void Snack::hambreDineroRand(Persona * per) {
    if (per->getDinero() >= 100 ){
        per->setHambre(Hambre(150, per));
        per->setDinero(Fondos(100, per));
        per->setCongelamiento(30);
        per->setComiendo(true);
        comiendo->insertBack(new Nodo<Persona *>(per));
    }
    else{
        delete per;
    }

}

int Snack::Hambre(int nSatisfecho, Persona * per){
	if (per->getHambre() + nSatisfecho >= 240) {
		nSatisfecho = 240;
	}
	else{
		nSatisfecho = per->getHambre() + nSatisfecho;
	}
	return nSatisfecho;
}

int Snack::Fondos(int costo, Persona * per){
	if (per->getDinero() < costo){
        return per->getDinero();
    }
	else{
		costo = per->getDinero() - costo;
	}
    
	return costo;
}

void Snack::checarPersonasComiendo(int actualTime)
{
	Nodo<Persona *> * temp = comiendo->getInicio();
	while (temp != NULL)
	{
		if (temp->getInfo()->getCongelamiento() == 0)
		{
			if (temp->getInfo()->getNombre() == parque->getEspecial()->getNombre())
			{
                if (actualTime + (parque->recorrido(temp->getInfo(), 0)) >= temp->getInfo()->getSalida()){
                    cout << "Ya te tienes que ir, bye!" << endl;
                }
                else {
                    if (temp->getInfo()->getDinero() <= 15){
                        cout << "Ya no tienes dinero" << endl;
                        temp->getInfo()->setComiendo(false);
                        parque->menuJuegos(temp->getInfo());
                    }
                    else{
                        temp->getInfo()->setComiendo(false);
                        parque->menuJuegos(temp->getInfo());
                    }
                }
				comiendo->deleteAtNodo(temp);
			}
			else
			{
				if (actualTime + parque->recorrido(temp->getInfo(),0) >= temp->getInfo()->getSalida())
				{
                    delete temp->getInfo();
				}
				else
				{
					int Num = rand() % 9;
                    temp->getInfo()->setComiendo(false);
					parque->mandarPersona(temp->getInfo(), actualTime, Num);
				}
				comiendo->deleteAtNodo(temp);
			}
		}
		else
		{
			temp->getInfo()->setCongelamiento(temp->getInfo()->getCongelamiento() - 1);
		}
		temp = temp->getNext();
	}
}