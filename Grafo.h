#include <iostream>
#include "Arista.h"
#include <vector>
#include <queue>

template <class V, class A> class Grafo;
template <typename V, typename A> std::ostream & operator <<(std::ostream & os, Grafo<V, A>  & g);

template <class V, class A>
class Grafo
{
	Vertice<V, A> * inicio;
	int cantidadNodo;

	/*Estos atributos son para hacer dijkstra MAS NADA*/
	vector<int> * distancia = new vector<int>();
	vector<bool> * visitados = new vector<bool>();
	priority_queue<Vertice<V, A> *, int> cola;
	vector<int> * previo = new vector<int>();

public:
	Grafo()
	{
		inicio = NULL;
		cantidadNodo = 0;
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
	void iniciar();
	int posicionDelNodo(Vertice<V, A> *);
	int dijkstra(Vertice<V, A> *, Vertice<V, A> *);
	//vector<int> dijkstra(Vertice<V, A> *);
	void relajacion(Vertice<V, A> *, Vertice<V, A> *, int);
	

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

template<class V, class A>
void Grafo<V, A>::iniciar()
{
	for (int i = 0; i <= cantidadNodo; i++)
	{
		distancia[i] = 100000;
		visitados[i] = true;
		previo[i] = -1;
	}
}

template<class V, class A>
void Grafo<V, A>::relajacion(Vertice<V, A> * ac, Vertice<V, A> * ad, int p)
{

	if (distancia[posicionDelNodo(ac)] + p < distancia[posicionDelNodo(ad)])
	{
		distancia[posicionDelNodo(ad)] = distancia[posicionDelNodo(ac)] + p;
		//previo [posicionDelNodo(ad)] =
		cola.push(ad, distancia[posicionDelNodo(ad)])
	}

}

template<class V, class A>
int Grafo<V, A>::dijkstra(Vertice<V, A> * i, Vertice<V, A> * d)
{
	iniciar();
	cola.push(i, 0);
	distancia[posicionDelNodo(i)] = 0;
	Vertice<V, A> * actual;
	Vertice<V, A> * adyacente;
	int peso;
	while (!cola.empty())
	{
		actual = cola.top();
		cola.pop();
		if (visitados[posicionDelNodo(actual)])
			continue;
		visitados[posicionDelNodo(actual)] = true;

		for (int i = 0; i < actual->numeroAristas(); i++)
		{
			adyacente = actual->getAristas()->getDestino();
			peso = adyacente->getAristas()->getPeso();
			if (!visitados[posicionDelNodo(adyacente)])
			{
				relajacion(actual, adyacente, peso);
			}
		}
	}

	return distancia[posicionDelNodo(d)];

}

template<class V, class A>
int Grafo<V, A>::posicionDelNodo(Vertice<V, A> * v)
{

	Vertice<V, A> * temp = inicio;
	int cont = 0;

	while (temp != NULL && temp == v)
	{
		cont++;
		temp = temp->getNext();
	}

	return cont;

}
