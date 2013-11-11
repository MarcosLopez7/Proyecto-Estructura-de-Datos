//
//  Pila.h
//  Pila
//
//  Created by César Millán on 10/10/13.
//  Copyright (c) 2013 César Millán. All rights reserved.
//

#ifndef __Pila__Pila__
#define __Pila__Pila__

#include <iostream>

#include "Nodo.h"

template <class N> class Pila;
template <class N> ostream & operator <<(ostream & os, Pila<N> & s);



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

};

template <class N>
Pila<N>::~Pila()
{
    clear();
}

template <class N>
void Pila<N>::push(Nodo<N> * n)
{
    if (!empty())
    {
        n->setNext(tope);
        tope = n;
    }
    else {
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
        tope=tope->getNext();
        temp->setNext(NULL);
        --tamano;
        
    }
    
    return temp;
}

template <class N>
Nodo<N> * Pila<N>::top()
{
    return tope;
}



template <class N>
void Pila<N>::clear()
{
    if (!empty())
    {
        Nodo<N> * temp;
        
        while (!empty()) {
            temp = pop();
            delete temp;
            
        }
    }
}


template <class N>
int Pila<N>::size()
{
    return tamano;
}

template <class N>
bool Pila<N>::empty()
{
    return (tamano == 0);
}

template <typename N>
ostream & operator <<(ostream & os, Pila<N> & s)
{
    Pila<N> * pila_temp = new Pila<N>();
    Nodo<N> * temp;
    
    while ((temp = s.pop()) != NULL)
    {
        os << *temp << endl;
        pila_temp->push(temp); //checar
    }
    
    //regresar
    while ((temp = pila_temp->pop()) != NULL)
    {
        s.push(temp);
    }
    
    return os;
}

#endif /* defined(__Pila__Pila__) */
