#include "Nodo.h"
#include <ctime>

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

	Nodo<N> * denqueue();
	Nodo<N> * getInicio();
	int size();
	void clear();
	bool find(Nodo<N> * n);
	bool empty();

	friend ostream & operator << <>(ostream & os, Cola<N> & le);

};

template <class N>
Cola<N>::~Cola()
{
	clear();
}

template<class N>
int Cola<N>::size()
{
	return tamano;
}

template <class N>
void Cola<N>::enqueue(Nodo<N> * n)
{
	//Nodo<N> * temp;

	if (!empty())
	{
		fin->setNext(n);
		fin = n;
	}
	else {
		inicio = n;
		fin = n;
	}

	tamano++;
}

template <class N>
Nodo<N> * Cola<N>::denqueue()
{
	Nodo<N> * temp = NULL;

	if (!empty())
	{
		temp = inicio;
		inicio = inicio->getNext();
		--tamano;
	}
	
	temp->setNext(NULL);

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
bool Cola<N>::empty()
{
	return (tamano == 0);
}


template<class N>
Nodo<N> * Cola<N>::getInicio()
{
	return inicio;
}

template <typename N>
ostream & operator <<(ostream & os, Cola<N> & le)
{
	Nodo<N> * temp = le.inicio;

	while (temp != NULL)
	{
		os << *temp << endl;
		temp = temp->getNext();
	}

	return os;
}
