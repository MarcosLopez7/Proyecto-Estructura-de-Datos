//
//  Nodo.h
//  t6c1e1
//
//  Created by Vicente Cubells Nonell on 26/09/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __t6c1e1__Nodo__
#define __t6c1e1__Nodo__

#include <iostream>
using namespace std;



template <class T> class Nodo;

template <typename T> ostream & operator <<(ostream & os,   Nodo<T>  & n);


template <class T>
class Nodo {
    T info;
    Nodo<T> * siguiente;
    
    

public:
    Nodo(T i):info(i),siguiente(NULL)
    {
    }
    
    Nodo():siguiente(NULL){}
    
    T getInfo()
    {
        return info;
    }
    
    void setInfo(T value)
    {
        info = value;
    }
    
    Nodo<T> * getNext()
    {
        return siguiente;
    }
    
    void setNext(Nodo<T> * value)
    {
        siguiente = value;
    }
    
    friend ostream & operator << <>(ostream & os,   Nodo<T>  & n);
};

template <typename T>
ostream & operator <<(ostream & os,   Nodo<T>  & n)
{
    os << n.info;
    return os;
}



#endif /* defined(__t6c1e1__Nodo__) */
