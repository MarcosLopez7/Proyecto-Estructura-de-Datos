#include <iostream>
#include "Arista.h"

template <class V, class A> class Grafo;
template <typename V, typename A> std::ostream & operator <<(std::ostream & os, Grafo<V, A>  & g);

template <class V, class A>
class Grafo
{
	Vertice<V, A> * inicio;

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
	void busquedaVertice(Vertice<V, A> *);
	void busquedaArista(Arista<V, A> *);
	//void eliminarArista(Arista<V, A> * );
	//void eliminarVertice()

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

	/* Imprimir los vértices */

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
		while (tempA != NULL)
		{
			if (tempA->getDestino() == v)
			{
				i++;
			}
			tempA = tempA->getNext();
		}
		temp = temp->getNext();
	}

	return i;
}

/*template<class V, class A>
void Grafo<V, A>::eliminarArista(Arista<V, A> * a)
{

	Vertice<V, A> * temp = inicio;
	

	while (temp != NULL)
	{

		Arista<V, A> * tempA = temp->getAristas();
		while (tempA != NULL && tempA != a)
		{
			tempA = tempA->getNext();
		}
		temp = temp->getNext();
	}

	tempA = 

}*/

template<class V, class A>
void Grafo<V, A>::busquedaVertice(Vertice<V, A> * v)
{



}

template<class V, class A>
void Grafo<V, A>::busquedaArista(Arista<V, A> * a)
{

}
