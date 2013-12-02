//
//  main.cpp
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán & Marcos López on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//


#include "Parque.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <unistd.h>


void menu();
void hora(int t);
int convierteHora(int hora);
bool verificarNumero (string prueba);
Persona * personaEspecial;

using namespace std;

int main(int argc, const char * argv [])
{
    
    menu();
    Parque * parque = new Parque(personaEspecial);
    
    
	parque->crearJuegos();
	parque->crearGrapho();
    
	
	/* impresión de prueba */
	cout << *personaEspecial;
    
	for (int t = 600; t < 1200; t++)
	{
        usleep(200000);
        hora(t);
        parque->checarLlegada(t);
        
		if (t % 10 == 0){
			parque->crearBots(t);
		}
		parque->checarCongelamiento();
        parque->moverFilas(t);
		parque->checarCongelamientoSnack();
		parque->checarPersonasComiendo(t);
		parque->hambrear();
        parque->escribirDocumentos(t);
	}
    
    cout << "Cierre parque" << endl;
	return 0;
}

void menu(){
	cout << "Bienvenido a Six Flags! " << endl;
	cout << "Ingresa tu nombre: " << endl;
	string nombre;
	getline(cin, nombre);
    int horaLlegada = 0;
    while (true) {
        cout << "Cuál es tu hora de llegada? \nHint: \n10:03 = 1003\n14:39 = 1439" << endl;
        string hora;
        cin >> hora;
        if (!verificarNumero(hora))
            cout << "No es un número" << endl;
        else{
            horaLlegada = convierteHora(stoi(hora));
            if (horaLlegada>=600 && horaLlegada<=1200) {
                break;
            }
            else
                cout << "El horario del parque es de 10:00 a 20:00" << endl;
        }
    }
    cout << "Cuánto tiempo vas a permanecer en el parque? (horas)" << endl;
	int tiempoPermanencia;
    
    while (true){
        string tiempo;
        cin >> tiempo;
        if (!verificarNumero(tiempo))
            cout << "Porfavor ingresa un número" << endl;
        else{
            tiempoPermanencia=stoi(tiempo) * 60;
            if (horaLlegada + tiempoPermanencia > 1200)
                cout << "Demasiado tiempo, recuerda que cerramos a las 20:00" << endl;
            else
                break;
        }
    }
	cout << "Cuál es tu presupuesto?" << endl;
	int presupuesto;
    while (true) {
        string dinero;
        cin >> dinero;
        if (!verificarNumero(dinero))
            cout << "Entrada no valida, únicamente se aceptan números" << endl;
        else{
            presupuesto = stoi(dinero);
            break;
        }
    }
    personaEspecial = new Persona(horaLlegada, horaLlegada + tiempoPermanencia, presupuesto, nombre);
}

int convierteHora(int hora){
	int horaArreglada;
	horaArreglada = hora % 10;
	hora = hora / 10;
	horaArreglada = horaArreglada + (hora % 10) * 10;
	hora = hora / 10;
	horaArreglada = horaArreglada + hora * 60;
	return horaArreglada;
}

bool verificarNumero (string prueba){
    int numero = 0;
    if (istringstream(prueba) >> numero)
        return true;
    else
        return false;
}

void hora(int t){
	cout << "Son las: " << t / 60 << ":";
	if (t % 60 == 0)
		cout << "00" << endl;
    else if(t%60 < 10)
        cout << "0" + to_string(t%60) << endl;
	else
		cout << t % 60 << endl;
}