#include "Atraccion.h"
#include "Juego.h"
#include <iostream>

int main(int argc, const char * argv [])
{



	Juego * batman = new Juego(0, 0, "batman");

	Cola<Persona *> * parque = new Cola<Persona *>();

	for (int t = 600; t < 1200; t = t + 10)
	{

		cout << "PRUEBA\n";

		for (int i = 0; i < 10; i++)
		{

			Persona * personon = new Persona(t);
			Nodo<Persona *> * nodulon = new Nodo<Persona *>(personon);
			parque->enqueue(nodulon);
		}

		for (int i = 0; i < 10; i++)
		{

			batman->EntraColaNormal(parque->dequeue()->getInfo());
		}

		batman->setTiempoI(t);
		batman->setTiempoF(t + 5);

		for (int i = batman->getTiempoI(); i <= batman->getTiempoF(); i++)
		{
			if (i == t)
			{
				for (int i = 0; i < 10; i++)
				{
					batman->EntraJuego(batman->SalColaNormal());
				}
			}
			if (i == (t + 5))
			{
				for (int i = 0; i < 10; i++)
				{
					parque->enqueue(new Nodo<Persona *>(batman->SalJuego()));
				}
			}
		}

		for (int i = 0; i < 10; i++)
		{
			delete parque->dequeue();
		}

	}

	system("pause");
	return 0;
}