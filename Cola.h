//
//  Cola.h
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#ifndef Proyecto_Final_Estructura_de_Datos_TC1018_Cola_h
#define Proyecto_Final_Estructura_de_Datos_TC1018_Cola_h

#include "Nodo.h"

template <class N> class Cola;
template <class N> ostream & operator <<(ostream & os, Cola<N> & le);



template <class N>
class Cola {
    
	Nodo<N> * inicio;
	Nodo<N> * fin;
	int tamano;
    
public:
	Cola()
	{
		inicio = fin = NULL;
		tamano = 0;
	}
    
	~Cola();
    
	void enqueue(Nodo<N> * n);
    
	Nodo<N> * dequeue();
    
	void clear();
    
	bool find(Nodo<N> * n);
    
	Nodo<N> * getFirst();
    
	int size();
	bool empty();
    
	friend ostream & operator << <>(ostream & os, Cola<N> & c);
    
};

template <class N>
Cola<N>::~Cola()
{
	clear();
}

template <class N>
Nodo<N> * Cola<N>::getFirst(){
	return inicio;
}


template <class N>
void Cola<N>::enqueue(Nodo<N> * n)
{
	if (!empty())
	{
		fin->setNext(n);
		fin = n;
        
	}
	else {
		inicio = fin = n;
	}
    
	tamano++;
}


template <class N>
Nodo<N> * Cola<N>::dequeue()
{
	Nodo<N> * temp = NULL;
    
	if (!empty())
	{
		temp = inicio;
        
		inicio = inicio->getNext();
		temp->setNext(NULL);
		--tamano;
	}
    
	return temp;
}

template <class N>
void Cola<N>::clear()
{
	if (!empty())
	{
		Nodo<N> * temp = inicio;
        
		while (temp != NULL) {
			inicio = temp->getNext();
			delete temp;
			temp = inicio;
            
		}
	}
}

template <class N>
bool Cola<N>::find(Nodo<N> * n)
{
	bool encontrado = false;
	Nodo<N> * temp = inicio;
    
	while (!encontrado && (temp != NULL)) {
		if (temp->getInfo() == n->getInfo())
		{
			encontrado = true;
		}
        
		temp = temp->getNext();
	}
    
	return encontrado;
}

template <class N>
int Cola<N>::size()
{
	return tamano;
}

template <class N>
bool Cola<N>::empty()
{
	return (tamano == 0);
}


template <typename N>
ostream & operator <<(ostream & os, Cola<N> & c)
{
	Nodo<N> * temp = c.inicio;
    
	while (temp != NULL)
	{
		os << *temp << endl;
		temp = temp->getNext();
	}
    
	return os;
}


#endif
