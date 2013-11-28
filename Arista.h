#include <iostream>
#include "Vertice.h"

//template <class A, class V> class Arista;
template <typename V, typename A> std::ostream & operator <<(std::ostream & os, Arista<V, A>  & v);

template <class V, class A>
class Arista {
	A peso;

	Vertice<V, A> * destino;
	Arista<V, A> * siguiente;

public:
	Arista(A peso, Vertice<V, A> * destino)
	{
		this->peso = peso;
		this->destino = destino;
		siguiente = NULL;
	}

	A getPeso()
	{
		return peso;
	}

	void setPeso(A value)
	{
		peso = value;
	}

	Vertice<V, A> * getDestino()
	{
		return destino;
	}

	void setDestino(Vertice<V, A> * value)
	{
		destino = value;
	}


	Arista<V, A> * getNext()
	{
		return siguiente;
	}

	void setNext(Arista<V, A> * value)
	{
		siguiente = value;
	}

	friend std::ostream & operator << <>(std::ostream &, Arista<V, A> &);

};

template <typename V, typename A>
std::ostream & operator <<(std::ostream & os, Arista<V, A> & a)
{
	os << " --- " << a.peso << " ---> " << a.destino->getInfo() << std::endl;

	os << std::endl;

	return os;
}