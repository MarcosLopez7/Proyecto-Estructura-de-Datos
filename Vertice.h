#include <iostream>

template <class V, class A> class Arista;
template <class V, class A> class Vertice;
template <typename V, typename A> std::ostream & operator <<(std::ostream & os, Vertice<V, A>  & v);

template <class V, class A>
class Vertice {
	V info;

	Vertice<V, A> * siguiente;
	Arista<V, A> * aristas;

public:
	Vertice(V info)
	{
		this->info = info;
		siguiente = NULL;
		aristas = NULL;
	}

	~Vertice()
	{
		if (aristas != NULL)
		{
			Arista<V, A> * temp = aristas;

			while (temp != NULL) {
				aristas = aristas->getNext();
				delete temp;
				temp = aristas;
			}
		}
	}

	V getInfo()
	{
		return info;
	}

	void setInfo(V value)
	{
		info = value;
	}

	Vertice<V, A> * getNext()
	{
		return siguiente;
	}

	void setNext(Vertice<V, A> * value)
	{
		siguiente = value;
	}

	Arista<V, A> * getAristas()
	{
		return aristas;
	}

	void setAristas(Arista<V, A> * value)
	{
		aristas = value;
	}

	Arista<V, A> * ultimaArista();
	void insertarArista(Arista<V, A> * a);

	friend std::ostream & operator << <>(std::ostream &, Vertice<V, A> &);

};

template <class V, class A>
Arista<V, A> * Vertice<V, A>::ultimaArista()
{
	Arista<V, A> * temp = aristas;

	if (temp != NULL) {
		while (temp->getNext() != NULL) {
			temp = temp->getNext();
		}
	}

	return temp;
}

template <class V, class A>
void Vertice<V, A>::insertarArista(Arista<V, A> * a)
{
	Arista<V, A> * temp = ultimaArista();

	if (temp == NULL)
	{
		aristas = a;
	}
	else {
		temp->setNext(a);
	}
}


template <typename V, typename A>
std::ostream & operator <<(std::ostream & os, Vertice<V, A> & v)
{
	os << "Vértice: " << v.info << std::endl;

	/* Imprimir las aristas que salen de v */

	Arista<V, A> * temp = v.aristas;

	os << "Aristas que salen: " << std::endl;
	while (temp != NULL) {
		os << *temp;
		temp = temp->getNext();
	}

	os << std::endl;

	return os;
}
