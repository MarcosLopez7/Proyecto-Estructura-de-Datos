//
//  Nodo.h
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#ifndef Proyecto_Final_Estructura_de_Datos_TC1018_Nodo_h
#define Proyecto_Final_Estructura_de_Datos_TC1018_Nodo_h

#include <iostream>
using namespace std;



template <class T> class Nodo;

template <typename T> ostream & operator <<(ostream & os, Nodo<T>  & n);


template <class T>
class Nodo {
	T info;
	Nodo<T> * siguiente;
    
    
    
public:
	Nodo(T i) : info(i), siguiente(NULL)
	{
	}
    
	Nodo() : siguiente(NULL){}
    
	T getInfo()
	{
		return info;
	}
    
	void setInfo(T value)
	{
		info = value;
	}
    
	Nodo<T> * getNext()
	{
		return siguiente;
	}
    
	void setNext(Nodo<T> * value)
	{
		siguiente = value;
	}
    
	friend ostream & operator << <>(ostream & os, Nodo<T>  & n);
};

template <typename T>
ostream & operator <<(ostream & os, Nodo<T>  & n)
{
	os << n.info;
	return os;
}


#endif
