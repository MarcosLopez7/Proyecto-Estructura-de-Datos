//
//  Persona.cpp
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#include <ctime>
#include "Persona.h"
#include "Atraccion.h"
#include "Juego.h"
#include "Snack.h"

Persona::Persona(int t, std::string idP)
{
	//srand((int) time(NULL));
	int presupuestos[5] = { 1200, 1000, 800, 750, 500 };
    
	int random = rand() % 5;
	dinero = presupuestos[random];
    
	int salidas [] = { 180, 240, 300, 360, 480 };
	salida = salidas[rand() % 5] + t;
	if (salida >= 1200)
	{
		salida = 1200;
	}
    
	congelamiento = 0;
	ubicacion = 0;
	siguienteAtraccion = NULL;
	this->idP = idP;
	hambre = 180 + rand() % (240 - 180);
	nombre = "";
	llegada = 0;
    VIP=false;
    comiendo = false;
}

Persona::Persona(int s, int h)
{
	salida = s;
	int presupuestos [] = { 1200, 1000, 800, 750, 500 };
    
	dinero = (presupuestos[rand() % 5]);
	hambre = h;
	nombre = "";
    
	congelamiento = 0;
	ubicacion = 0;
	siguienteAtraccion = NULL;
    VIP = false;
    comiendo = false;
}

Persona::Persona(int llegada, int salida, int presupuesto, std::string nombre) : salida(salida), dinero(presupuesto), nombre(nombre), hambre(200){
	congelamiento = 0;
	ubicacion = 0;
	siguienteAtraccion = NULL;
	this->llegada = llegada;
    VIP = false;
    comiendo = false;
}

void Persona::setDinero(int d)
{
	dinero = d;
}

void Persona::setLlegada(int l)
{
	llegada = l;
}

void Persona::setSalida(int s)
{
	salida = s;
}

void Persona::setHambre(int h)
{
	hambre = h;
}

int Persona::getDinero()
{
	return dinero;
}
int Persona::getSalida()
{
	return salida;
}
int Persona::getHambre()
{
	return hambre;
}

int Persona::getLLegada()
{
	return llegada;
}
std::string Persona::getNombre(){
	return nombre;
}

void Persona::setCongelamiento(int value){
	congelamiento = value;
}

void Persona::setUbicacion(int value){
	ubicacion = value;
}

void Persona::setSiguienteAtraccion(Atraccion *sigAtra){
	siguienteAtraccion = sigAtra;
}

int Persona::getCongelamiento(){
	return congelamiento;
}

int Persona::getUbicacion(){
	return ubicacion;
}

bool Persona::getVIP(){
    return VIP;
}

void Persona::setVIP(bool value){
    VIP=value;
}

Atraccion * Persona::getSiguienteAtraccion(){
	return siguienteAtraccion;
}

std::string Persona::getId(){
	return idP;
}


ostream & operator <<(ostream & os, Persona & p)
{
	if (p.nombre != "") {
		os << "Nombre: " << p.nombre << endl;
	}
	if (p.salida % 60 == 0)
	{
		os << "Hora de salida: " << p.salida / 60 << ":" << "00 | ";
	}
    else if (p.salida % 60 < 10){
        os <<  "Hora de salida: " << p.salida / 60 << ":" << "0"<< p.salida % 60 << " | ";
    }
    
	else
	{
		os << "Hora de salida: " << p.salida / 60 << ":" << p.salida % 60 << " | ";
	}
    
	os << "Dinero actual: $" << p.dinero << " | ";
	os << "Energia: " << p.hambre << " |";
    
	os << endl;
	return os;
}