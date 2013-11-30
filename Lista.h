#ifndef __Proyecto_Final_Cubells__Lista__
#define __Proyecto_Final_Cubells__Lista__

#include "Nodo.h"

template <class N> class ListaEnlazada;
template <class N> ostream & operator <<(ostream & os, ListaEnlazada<N> & le);



template <class N>
class ListaEnlazada {

	Nodo<N> * inicio;
	int tamano;

public:
	ListaEnlazada()
	{
		inicio = NULL;
		tamano = 0;
	}

	~ListaEnlazada();

	void insertAt(int index, Nodo<N> * n);
	void insertBack(Nodo<N> * n);
	void insertFront(Nodo<N> * n);

	Nodo<N> * deleteAt(int index);
    Nodo<N> * deleteAtNodo(Nodo<N> * n);
	Nodo<N> * deleteBack();
	Nodo<N> * deleteFront();
	Nodo<N> * elementAt(int);
	void deleteAll();
	void ordena(int, ListaEnlazada<N> *);
	void invierte(int, ListaEnlazada<N> *);
    
    Nodo<N> * getInicio();
	bool find(Nodo<N> * n);

	int size();
	bool empty();

	friend ostream & operator << <>(ostream & os, ListaEnlazada<N> & le);

};

template <class N>
ListaEnlazada<N>::~ListaEnlazada()
{
	deleteAll();
}

template <class N>
void ListaEnlazada<N>::insertAt(int index, Nodo<N> * n)
{
	if (!empty())
	{
		if (index == 0)
		{
			n->setNext(inicio);
			inicio = n;
		}
		else {
			int pos = 0;
			Nodo<N> * temp = inicio;
			Nodo<N> * prev = NULL;

			while ((pos < index) && (temp != NULL)) {
				++pos;
				prev = temp;
				temp = temp->getNext();
			}

			n->setNext(temp);
			prev->setNext(n);

		}
	}
	else {
		inicio = n;
	}

	tamano++;
}

template <class N>
void ListaEnlazada<N>::insertBack(Nodo<N> * n)
{
	insertAt(tamano, n);

}

template <class N>
void ListaEnlazada<N>::insertFront(Nodo<N> * n)
{
	insertAt(0, n);
}

template <class N>
Nodo<N> * ListaEnlazada<N>::deleteAt(int index)
{
	Nodo<N> * temp = NULL;
	if (!empty())
	{
		temp = inicio;
		if (index == 0) {
			inicio = inicio->getNext();
		}
		else {
			int pos = 0;
			Nodo<N> * prev = NULL;

			while ((pos < index) && (temp->getNext() != NULL)) {
				++pos;
				prev = temp;
				temp = temp->getNext();
			}
                prev->setNext(temp->getNext());
		}
		--tamano;
	}

	return temp;
}

template <class N>
Nodo<N> * ListaEnlazada<N>::deleteAtNodo(Nodo<N> * n)
{
	bool encontrado = false;
	Nodo<N> * temp = inicio;
    int cont = 0;
    
	while (!encontrado && (temp != NULL)) {
		if (temp == n)
		{
			encontrado = true;
		}
        else{
            temp = temp->getNext();
            cont++;
        }
	}
    
	return deleteAt(cont);
}

template <class N>
Nodo<N> * ListaEnlazada<N>::deleteBack()
{
	return deleteAt(tamano);
}

template <class N>
Nodo<N> * ListaEnlazada<N>::deleteFront()
{
	return deleteAt(0);
}

template <class N>
void ListaEnlazada<N>::deleteAll()
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
bool ListaEnlazada<N>::find(Nodo<N> * n)
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

template<class N>
Nodo<N> * ListaEnlazada<N>::elementAt(int index)
{

	if (!empty())
	{
		int pos = 0;
		Nodo<N> * temp = inicio;

		while (pos < index)
		{
			temp = temp->getNext();
			pos++;
		}


		return temp;
	}
	return NULL;
}

template<class N>
Nodo<N> * ListaEnlazada<N>::getInicio(){
    return inicio;
}

template<class N>
void ListaEnlazada<N>::ordena(int n, ListaEnlazada<N> * lista)
{
	//int p;
	N temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (lista->elementAt(j - 1)->getInfo() > lista->elementAt(j)->getInfo())
			{
				//cin >> p;
				temp = lista->elementAt(j - 1)->getInfo();
				//cout << "temp : " << lista->elementAt(j-1)->getInfo() << "en j: ";
				lista->elementAt(j - 1)->setInfo(lista->elementAt(j)->getInfo());
				lista->elementAt(j)->setInfo(temp);
				//cout << j << "  " << lista->elementAt(j)->getInfo() << endl;
			}
		}

	}


	//cout << (*lista);

}

template<class N>
void ListaEnlazada<N>::invierte(int num, ListaEnlazada<N> * lista)
{

	ListaEnlazada<int> * aux = new ListaEnlazada<int>();
	

	for (int i = num - 1; i >= 0; i--)
	{
		aux->insertBack(lista->elementAt(i));
	}

	cout << (*aux);

}

template <class N>
int ListaEnlazada<N>::size()
{
	return tamano;
}

template <class N>
bool ListaEnlazada<N>::empty()
{
	return (tamano == 0);
}


template <typename N>
ostream & operator <<(ostream & os, ListaEnlazada<N> & le)
{
	Nodo<N> * temp = le.inicio;

	while (temp != NULL)
	{
		os << *temp << endl;
		temp = temp->getNext();
	}

	return os;
}

#endif /* defined(__Proyecto_Final_Cubells__Lista__) */