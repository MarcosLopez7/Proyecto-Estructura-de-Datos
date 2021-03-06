//
//  Grafo.h
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#ifndef Proyecto_Final_Estructura_de_Datos_TC1018_Grafo_h
#define Proyecto_Final_Estructura_de_Datos_TC1018_Grafo_h

#include <iostream>
#include "Arista.h"
#include "Lista.h"
#include <vector>

using namespace std;

template <class V, class A> class Grafo;
template <typename V, typename A> std::ostream & operator <<(std::ostream & os, Grafo<V, A>  & g);

template <class V, class A>
class Grafo
{
	Vertice<V, A> * inicio;
    
	int cantidadNodo;
    
	/*Estos atributos son para hacer dijkstra MAS NADA*/
    
	vector<int>  distancia;
	vector<bool> visitados;
	ListaEnlazada<Vertice<int, int> *> lista;
	vector<int>  previo;
    
public:
	Grafo()
	{
		inicio = NULL;
	}
    
	~Grafo();
    
	void insertarVertice(Vertice<V, A> * v);
	void insertarArista(Vertice<V, A> * o, Vertice<V, A> * d, A peso);
	int salidas(Vertice<V, A> *);
	int entradas(Vertice<V, A> *);
	Vertice<V, A> * busquedaVertice(V);
	void busquedaArista(Arista<V, A> *);
	void eliminarArista(A);
	void eliminarVertice(Vertice<V, A> *);
	Vertice<V, A> * elementAt(int);
	void ordena();
    
	/*m?todo de dijkstra*/
	void iniciar();
	int posicionDelNodo(Vertice<V, A> *);
	vector<int>  dijkstra(Vertice<V, A> *);
	void relajacion(int, int, Vertice<V, A> *, Vertice<V, A> *, int);
	void imprimir(int);
    
	friend std::ostream & operator << <>(std::ostream &, Grafo<V, A> &);
};

template <class V, class A>
Grafo<V, A>::~Grafo()
{
	if (inicio != NULL)
	{
		Vertice<V, A> * temp = inicio;
        
		while (temp != NULL) {
			inicio = inicio->getNext();
			delete temp;
			temp = inicio;
		}
	}
}

template <typename V, typename A>
std::ostream & operator <<(std::ostream & os, Grafo<V, A> & g)
{
    
	/* Imprimir los v?rtices */
    
	Vertice<V, A> * temp = g.inicio;
    
	while (temp != NULL) {
		os << *temp;
		temp = temp->getNext();
	}
    
	os << std::endl;
    
	return os;
}

template <class V, class A>
void Grafo<V, A>::insertarVertice(Vertice<V, A> * v)
{
	if (inicio == NULL) {
		inicio = v;
	}
	else {
		Vertice<V, A> * temp = inicio;
		while (temp->getNext() != NULL) {
			temp = temp->getNext();
		}
        
		temp->setNext(v);
	}
    
	cantidadNodo++;
}

template <class V, class A>
void Grafo<V, A>::insertarArista(Vertice<V, A> * o, Vertice<V, A> * d, A peso)
{
	if (o != NULL && d != NULL) {
		Arista<V, A> * nueva = new Arista<V, A>(peso, d);
        
		o->insertarArista(nueva);
	}
}

template<class V, class A>
int Grafo<V, A>::salidas(Vertice<V, A> * v)
{
    
	Arista<V, A> * temp = v->getAristas();
	int i = 0;
    
	if (temp != NULL)
	{
		while (temp != NULL)
		{
			temp = temp->getNext();
			i++;
		}
	}
    
	return i;
    
}

template<class V, class A>
int Grafo<V, A>::entradas(Vertice<V, A> * v)
{
	int i = 0;
	Vertice<V, A> * temp = inicio;
    
	while (temp != NULL)
	{
        
		Arista<V, A> * tempA = temp->getAristas();
		if (tempA != NULL)
		{
            
			while (tempA != NULL)
			{
				if (tempA->getDestino() == v)
				{
					i++;
				}
				tempA = tempA->getNext();
			}
		}
		temp = temp->getNext();
	}
    
	return i;
}

template<class V, class A>
void Grafo<V, A>::eliminarArista(A a)
{
    
	Vertice<V, A> * temp = inicio;
	Arista<V, A> * tempA = inicio->getAristas();
    
    
	while (temp != NULL && tempA->getPeso() != a)
	{
		Arista<V, A> * prev = NULL;
		if (tempA != NULL)
		{
			tempA = temp->getAristas();
			if (tempA->getPeso() == a)
			{
				temp->setAristas(NULL);
			}
			else
			{
				while (tempA != NULL && tempA->getPeso() != a)
				{
					prev = tempA;
					tempA = tempA->getNext();
				}
                
			}
		}
		if (tempA != NULL)
		{
			if (tempA->getPeso() == a)
			{
                
				if (prev == NULL)
				{
					temp->setAristas(tempA->getNext());
				}
				else
				{
					prev->setNext(tempA->getNext());
					tempA->setNext(NULL);
				}
			}
		}
		else
		{
			tempA = temp->getAristas();
		}
		temp = temp->getNext();
	}
    
    
}

template<class V, class A>
void Grafo<V, A>::eliminarVertice(Vertice<V, A> * v)
{
    
    
    
}

template<class V, class A>
Vertice<V, A> * Grafo<V, A>::busquedaVertice(V info)
{
	Vertice<V, A> * temp = inicio;
    
	while (temp->getInfo() != info)
	{
		temp = temp->getNext();
	}
    
	return temp;
}

template<class V, class A>
void Grafo<V, A>::busquedaArista(Arista<V, A> * a)
{
    
}

template<class V, class A>
void Grafo<V, A>::ordena()
{
    
	if (lista.size() != 1)
	{
        
		Vertice<int, int> * temp;
		for (int i = 0; i < lista.size(); i++)
		{
			for (int j = lista.size() - 1; j > i; j--)
			{
                
                
				if (lista.elementAt(j - 1)->getInfo()->getInfo2() > lista.elementAt(j)->getInfo()->getInfo2())
				{
                    
					temp = lista.elementAt(j - 1)->getInfo();
					lista.elementAt(j - 1)->setInfo(lista.elementAt(j)->getInfo());
					lista.elementAt(j)->setInfo(temp);
				}
			}
		}
	}
    
}

template<class V, class A>
Vertice<V, A> * Grafo<V, A>::elementAt(int i)
{
    
	int pos = 0;
	Vertice<V, A> * temp = inicio;
    
	while (pos < i)
	{
		temp = temp->getNext();
		pos++;
	}
    
	return temp;
}

template<class V, class A>
void Grafo<V, A>::iniciar()
{
	distancia.clear();
	visitados.clear();
	previo.clear();
	for (int i = 0; i < cantidadNodo; i++)
	{
		distancia.push_back(10000);
		visitados.push_back(false);
		previo.push_back(-1);
	}
}

template<class V, class A>
void Grafo<V, A>::relajacion(int actual, int adyacencia, Vertice<V, A> * ac, Vertice<V, A> * ad, int p)
{
	if (distancia[actual] + p < distancia[adyacencia])
	{
		distancia[adyacencia] = distancia[actual] + p;
		previo[adyacencia] = actual;
		Vertice<int, int> * ver = new Vertice<int, int>(adyacencia, distancia[adyacencia]);
		Nodo<Vertice<int, int> *> * nodulon = new Nodo<Vertice<int, int> *>(ver);
		lista.insertFront(nodulon);
	}
    
}

template<class V, class A>
vector<int>  Grafo<V, A>::dijkstra(Vertice<V, A> * i)
{
	iniciar();
	Vertice<int, int> * vertice = new Vertice<int, int>(posicionDelNodo(i), 0);
	Nodo<Vertice<int, int> *> * nodulon = new Nodo<Vertice<int, int> *>(vertice);
	lista.insertBack(nodulon);
	distancia[posicionDelNodo(i)] = 0;
	int actual, adyacente, peso;
	Vertice<V, A> * temp = i;
	while (!lista.empty())
	{
		ordena();
		actual = lista.elementAt(0)->getInfo()->getInfo();
		temp = elementAt(lista.elementAt(0)->getInfo()->getInfo());
		lista.deleteFront();
		if (visitados[actual])
			continue;
		visitados[actual] = true;
        
		Arista<V, A> * tempA = temp->getAristas();
		for (int i = 0; i < temp->numeroAristas(temp); i++)
		{
			adyacente = posicionDelNodo(tempA->getDestino());
			peso = tempA->getPeso();
			if (!visitados[adyacente])
			{
				relajacion(actual, adyacente, temp, tempA->getDestino(), peso);
			}
			tempA = tempA->getNext();
		}
	}
    
    
    
	return distancia;
}

template<class V, class A>
void Grafo<V, A>::imprimir(int d)
{
	if (previo[d] != -1)
		imprimir(previo[d]);
	cout << d << endl;
}

template<class V, class A>
int Grafo<V, A>::posicionDelNodo(Vertice<V, A> * v)
{
    
	Vertice<V, A> * temp = inicio;
	int cont = 0;
    
	while (temp != NULL && temp != v)
	{
		cont++;
		temp = temp->getNext();
	}
    
	return cont;
    
}

#endif
