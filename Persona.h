#include <iostream>
using namespace std;

class Persona
{
public: 
  Persona();
  Persona(int, int, int, int);
  ~Persona();
  void setDinero(int);
  void setEntrada(int);
  void setSalida(int);
  void setHambre(int);
  
  int getDinero();
  int getEntrada();
  int getSalida();
  int getHambre();
  
  friend ostream & operator <<(ostream & os, Persona & le);

private:
  int dinero;
  int entrada;
  int salida;
  int hambre;

};
