#include "Nodo.h"

template <class N> class Pila;
template <class N> ostream & operator <<(ostream & os, Pila<N> & le);

template <class N>
class Pila {

	Nodo<N> * tope;
	int tamano;

public:
	Pila()
	{
		tope = NULL;
		tamano = 0;
	}

	~Pila();

	void push(Nodo<N> * n);
	Nodo<N> * pop();
	Nodo<N> * top();
	void clear();
	int size();
	bool empty();
	friend ostream & operator << <>(ostream & os, Pila<N> & le);

};

template <class N>
Pila<N>::~Pila()
{
	clear();
}

template<class N>
int Pila<N>::size()
{
	return tamano;
}



template <class N>
void Pila<N>::push(Nodo<N> * n)
{
	if (!empty())
	{
		n->setNext(tope);
		tope = n;
	}
	else{
		tope = n;
	}

	tamano++;
}

template <class N>
Nodo<N> * Pila<N>::pop()
{
	Nodo<N> * temp = NULL;

	if (!empty())
	{

		temp = tope;
		tope = tope->getNext();

		--tamano;
	}

	temp->setNext(NULL);

	return temp;
}

template <class N>
void Pila<N>::clear()
{
	if (!empty())
	{
		Nodo<N> * temp = tope;

		while (!empty()) {
			temp = pop();
			delete temp;
		}
	}
}


template <class N>
bool Pila<N>::empty()
{
	return (tamano == 0);
}


template<class N>
Nodo<N> * Pila<N>::top()
{
	return tope;
}

template <typename N>
ostream & operator <<(ostream & os, Pila<N> & le)
{
	Nodo<N> * temp = le.tope;

	while (temp != NULL)
	{
		os << *temp << endl;
		temp = temp->getNext();
	}

	return os;
}
