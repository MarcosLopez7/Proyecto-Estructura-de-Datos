#include <iostream>
using namespace std;

template <class T> class Nodo;
template <typename T> ostream & operator <<(ostream & os, Nodo<T>  & n);

template <class T>
class Nodo {
	T info;
	Nodo<T> * siguiente;

public:
	Nodo(T i)
	{
		info = i;
		siguiente = NULL;
	}

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

	friend ostream & operator << <>(ostream & os, Nodo<T>  & n);
};

template <typename T>
ostream & operator <<(ostream & os, Nodo<T>  & n)
{
	os << n.info;
	return os;
}
