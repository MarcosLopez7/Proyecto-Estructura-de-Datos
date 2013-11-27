#include <iostream>
#include <fstream>
#include "Atraccion.h"
#include "Juego.h"
#include "Snack.h"
#include "Grafo.h"

void menu();
int convierteHora(int hora);
void write_text_to_log_file(const std::string &text);
void meterAJuego(int);
void mandarPersona(Persona *);
void mandarPersonaDependiendo(Persona *, Juego *);
void salDelJuegoYHasEsto(int);

Persona * personaEspecial;
ListaEnlazada<Vertice<Persona *, Juego *> *> * congelamiento = new ListaEnlazada<Vertice<Persona *, Juego *> *>();
Grafo<Atraccion *, int> * caminos = new Grafo<Atraccion *, int>();

Atraccion * entrada = new Atraccion("Entrada");
Juego * batman = new Juego("Batman", 5, 30);
Juego * superman = new Juego("Superman", 2, 40);
Juego * boomerang = new Juego("Boomerang", 8, 20);
Juego * medusa = new Juego("Medusa", 5, 15);
Juego * splash = new Juego("Splash", 10, 20);
Juego * kilauea = new Juego("Kilauea", 3, 26);
Juego * huracan = new Juego("Huracan", 8, 40);
Juego * goKart = new Juego("Go Kart", 10, 10);
Juego * vudu = new Juego("Vudu", 8, 30);
Snack * snack = new Snack("Cafeteria");

Vertice<Atraccion *, int> * v1 = new Vertice<Atraccion *, int>(entrada);
Vertice<Atraccion *, int> * v2 = new Vertice<Atraccion *, int>(batman);
Vertice<Atraccion *, int> * v3 = new Vertice<Atraccion *, int>(superman);
Vertice<Atraccion *, int> * v4 = new Vertice<Atraccion *, int>(boomerang);
Vertice<Atraccion *, int> * v5 = new Vertice<Atraccion *, int>(medusa);
Vertice<Atraccion *, int> * v6 = new Vertice<Atraccion *, int>(splash);
Vertice<Atraccion *, int> * v7 = new Vertice<Atraccion *, int>(kilauea);
Vertice<Atraccion *, int> * v8 = new Vertice<Atraccion *, int>(huracan);
Vertice<Atraccion *, int> * v9 = new Vertice<Atraccion *, int>(goKart);
Vertice<Atraccion *, int> * v10 = new Vertice<Atraccion *, int>(vudu);
Vertice<Atraccion *, int> * v11 = new Vertice<Atraccion *, int>(snack);


int main(int argc, const char * argv [])
{

	//Cola<Persona *> * parque = new Cola<Persona *>();

	caminos->insertarVertice(v1);
	caminos->insertarVertice(v2);
	caminos->insertarVertice(v3);
	caminos->insertarVertice(v4);
	caminos->insertarVertice(v5);
	caminos->insertarVertice(v6);
	caminos->insertarVertice(v7);
	caminos->insertarVertice(v8);
	caminos->insertarVertice(v9);
	caminos->insertarVertice(v10);
	caminos->insertarVertice(v11);

	caminos->insertarArista(v1, v3, 2); // entrada a superman
	caminos->insertarArista(v3, v1, 2); // superman a entrada
	caminos->insertarArista(v3, v7, 8); // superman a kilauea
	caminos->insertarArista(v7, v3, 8); // kilauea a superman
	caminos->insertarArista(v3, v11, 7); // superman a snack
	caminos->insertarArista(v11, v3, 7); // snack a superman
	caminos->insertarArista(v3, v5, 5); // superman a medusa
	caminos->insertarArista(v5, v3, 5); // medusa a superman
	caminos->insertarArista(v7, v10, 2); // kilauea a Vudu
	caminos->insertarArista(v10, v7, 2); // vudu a kilauea
	caminos->insertarArista(v7, v4, 3); // kilauea a boomerang
	caminos->insertarArista(v4, v7, 3); // boomerang a kilauea
	caminos->insertarArista(v11, v9, 6); // snack a gokart
	caminos->insertarArista(v9, v11, 6); // gokart a snack
	caminos->insertarArista(v5, v8, 2); // medusa a huracan
	caminos->insertarArista(v8, v5, 2); // huracan a medusa
	caminos->insertarArista(v8, v9, 7); // huracan a gokart
	caminos->insertarArista(v9, v8, 7); // gokart a huracan
	caminos->insertarArista(v9, v4, 4); // gokart a boomerang
	caminos->insertarArista(v4, v9, 4); // boomerang a gokart
	caminos->insertarArista(v10, v4, 2); // vudu a boomerang
	caminos->insertarArista(v4, v10, 2); // boomerang a vudu
	caminos->insertarArista(v10, v6, 2); // vudu a splash
	caminos->insertarArista(v6, v10, 2); // splash a vudu
	caminos->insertarArista(v4, v6, 1); // boomerang a splash
	caminos->insertarArista(v6, v4, 1); // splash a boomerang
	caminos->insertarArista(v6, v2, 2); // splash a batman
	caminos->insertarArista(v2, v6, 2); // batman a splash

	//menu();
	/* impresión de prueba */
	//cout << *personaEspecial;

	for (int t = 600; t < 1200; t = t++)
	{

		/* Este for es el que manda en lo que estan en camino en un juego los manda ya directo al juego*/
		for (int i = 0; i < congelamiento->size(); i++)
		{
			congelamiento->elementAt(i)->getInfo()->getInfo()->setCongelamiento(congelamiento->elementAt(i)->getInfo()->getInfo()->getCongelamiento() - 1);
			if (batman == congelamiento->elementAt(i)->getInfo()->getInfo2())
			{
				if (batman->transicion(congelamiento->elementAt(i)->getInfo()->getInfo()))
				{
					congelamiento->deleteAt(i);
					i--;
				}
			}

			if (superman == congelamiento->elementAt(i)->getInfo()->getInfo2())
			{
				if (superman->transicion(congelamiento->elementAt(i)->getInfo()->getInfo()))
				{
					congelamiento->deleteAt(i);
					i--;
				}
			}

			if (boomerang == congelamiento->elementAt(i)->getInfo()->getInfo2())
			{
				if (boomerang->transicion(congelamiento->elementAt(i)->getInfo()->getInfo()))
				{
					congelamiento->deleteAt(i);
					i--;
				}
			}

			if (medusa == congelamiento->elementAt(i)->getInfo()->getInfo2())
			{
				if (medusa->transicion(congelamiento->elementAt(i)->getInfo()->getInfo()))
				{
					congelamiento->deleteAt(i);
					i--;
				}
			}

			if (splash == congelamiento->elementAt(i)->getInfo()->getInfo2())
			{
				if (splash->transicion(congelamiento->elementAt(i)->getInfo()->getInfo()))
				{
					congelamiento->deleteAt(i);
					i--;
				}
			}

			if (kilauea == congelamiento->elementAt(i)->getInfo()->getInfo2())
			{
				if (kilauea->transicion(congelamiento->elementAt(i)->getInfo()->getInfo()))
				{
					congelamiento->deleteAt(i);
					i--;
				}
			}

			if (huracan == congelamiento->elementAt(i)->getInfo()->getInfo2())
			{
				if (huracan->transicion(congelamiento->elementAt(i)->getInfo()->getInfo()))
				{
					congelamiento->deleteAt(i);
					i--;
				}
			}

			if (goKart == congelamiento->elementAt(i)->getInfo()->getInfo2())
			{
				if (goKart->transicion(congelamiento->elementAt(i)->getInfo()->getInfo()))
				{
					congelamiento->deleteAt(i);
					i--;
				}
			}

			if (vudu == congelamiento->elementAt(i)->getInfo()->getInfo2())
			{
				if (vudu->transicion(congelamiento->elementAt(i)->getInfo()->getInfo()))
				{
					congelamiento->deleteAt(i);
					i--;
				}
			}
		}// ESTE ES EL FOR QUE REALMENTE MANDA LOS BOTS A SU POSICION

		/* Este es el if en que cada 10 minutos llega la gente y los mete al camino dependiendo de donde les toque la proxima atraccion*/
		if ((t%10) == 0)
		{
			/* Impresión hora */
			cout << "Son las: " << t / 60 << ":";
			if (t % 60 == 0)
				cout << "00" << endl;
			else
				cout << t % 60 << endl;

			if (t < 660)
			{
				int n = (rand() % 100);
				for (int i = 0; i < n; i++)
				{
					Persona * persona = new Persona(t);
					mandarPersona(persona);
				}
			}
			if (t >= 660 && t < 720)
			{
				int n = rand() % 250;
				for (int i = 0; i < n; i++)
				{
					Persona * persona = new Persona(t);
					mandarPersona(persona);
				}
			}
			if (t >= 720 && t < 840)
			{
				int n = rand() % 400;
				for (int i = 0; i < n; i++)
				{
					Persona * persona = new Persona(t);
					mandarPersona(persona);
				}
			}
			if (t >= 840 && t <= 960)
			{
				int n = rand() % 50;
				for (int i = 0; i < n; i++)
				{
					Persona * persona = new Persona(t);
					mandarPersona(persona);
				}
			}



		
		}// cierre del if que pone los bots en una atracción después de llegar al parque

		/*Este for lo que hace es sacar las personas de los juegos */
		
		for (int i = 0; i < 9; i++) 
		{
			salDelJuegoYHasEsto(i);
		}
		

	}

	//delete parque;
	delete batman;
	delete superman;
	delete boomerang;
	delete medusa;
	delete splash;
	delete kilauea;
	delete entrada;
	delete snack;
	delete huracan;
	delete goKart;
	delete vudu;
	delete caminos;

	system("pause");
	return 0;
}

void menu(){
	cout << "Bienvenido a Six Flags! " << endl;
	cout << "Ingresa tu nombre: " << endl;
	string nombre;
	getline(cin, nombre);
	cout << "Cuál es tu hora de llegada? \nHint: \n1:05  = 0105\n14:39 = 1439" << endl;
	int horaLlegada;
	cin >> horaLlegada;
	cout << "Cuanto tiempo vas a permanecer en el parque? (horas)" << endl;
	int tiempoPermanencia;
	cin >> tiempoPermanencia;
	tiempoPermanencia = tiempoPermanencia * 60;
	cout << "Cuál es tu presupuesto?" << endl;
	int presupuesto;
	cin >> presupuesto;
	personaEspecial = new Persona(convierteHora(horaLlegada) + tiempoPermanencia, presupuesto, nombre);
}

int convierteHora(int hora){
	int horaArreglada;
	horaArreglada = hora % 10;
	hora = hora / 10;
	horaArreglada = horaArreglada + (hora % 10) * 10;
	hora = hora / 10;
	horaArreglada = horaArreglada + hora * 60;
	return horaArreglada;
}

/* Nada probado lo encontré en internet de como hacer un log file */
void write_text_to_log_file(const std::string &text)
{
	std::ofstream log_file("log_file.txt", std::ios_base::out | std::ios_base::app);
	log_file << text << std::endl;
}

void mandarPersona(Persona * persona)
{
	switch (rand() % 9)
	{
	case 0:
		{
			persona->setCongelamiento(caminos->dijkstra(v1, caminos->busquedaVertice(batman)));
			Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, batman);
			Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
			congelamiento->insertFront(nodulon);
		}
		break;
	case 1:
		{
			persona->setCongelamiento(caminos->dijkstra(v1, caminos->busquedaVertice(superman)));
			Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, superman);
			Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
			congelamiento->insertFront(nodulon);
		}
		break;
	case 2:
		{
			persona->setCongelamiento(caminos->dijkstra(v1, caminos->busquedaVertice(boomerang)));
			Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, boomerang);
			Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
			congelamiento->insertFront(nodulon);
		}
		break;
	case 3:
		{
			persona->setCongelamiento(caminos->dijkstra(v1, caminos->busquedaVertice(medusa)));
			Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, medusa);
			Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
			congelamiento->insertFront(nodulon);
		}
		break;
	case 4:
		{
			persona->setCongelamiento(caminos->dijkstra(v1, caminos->busquedaVertice(splash)));
			Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, splash);
			Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
			congelamiento->insertFront(nodulon);
		}
		break;
	case 5:
		{
			persona->setCongelamiento(caminos->dijkstra(v1, caminos->busquedaVertice(kilauea)));
			Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, kilauea);
			Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
			congelamiento->insertFront(nodulon);
		}
		break;
	case 6:
		{
			persona->setCongelamiento(caminos->dijkstra(v1, caminos->busquedaVertice(huracan)));
			Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, huracan);
			Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
			congelamiento->insertFront(nodulon);
		}
		break;
	case 7:
		{
			persona->setCongelamiento(caminos->dijkstra(v1, caminos->busquedaVertice(goKart)));
			Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, goKart);
			Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
			congelamiento->insertFront(nodulon);
		}
		break;
	case 8:
		{
			persona->setCongelamiento(caminos->dijkstra(v1, caminos->busquedaVertice(vudu)));
			Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, vudu);
			Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
			congelamiento->insertFront(nodulon);
		}
		break;
	default:
		break;
	}

}

void mandarPersonaDependiendo(Persona * persona, Juego * j)
{

	switch (rand() % 9)
	{
	case 0:
		{
			if (j != batman)
			{
				persona->setCongelamiento(caminos->dijkstra(caminos->busquedaVertice(j),caminos->busquedaVertice(batman)));
				Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, batman);
				Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
				congelamiento->insertFront(nodulon);
			}
			else
				mandarPersonaDependiendo(persona, j);
		}
		break;
	case 1:
		{
			if (j != superman)
			{
				persona->setCongelamiento(caminos->dijkstra(caminos->busquedaVertice(j), caminos->busquedaVertice(superman)));
				Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, superman);
				Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
				congelamiento->insertFront(nodulon);
			}
			else
				mandarPersonaDependiendo(persona, j);
		}
		break;
	case 2:
		{
			if (j != boomerang)
			{
				persona->setCongelamiento(caminos->dijkstra(caminos->busquedaVertice(j), caminos->busquedaVertice(boomerang)));
				Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, boomerang);
				Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
				congelamiento->insertFront(nodulon);
			}
			else
				mandarPersonaDependiendo(persona, j);
		}
		break;
	case 3:
		{
			if (j != medusa)
			{
				persona->setCongelamiento(caminos->dijkstra(caminos->busquedaVertice(j), caminos->busquedaVertice(medusa)));
				Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, medusa);
				Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
				congelamiento->insertFront(nodulon);
			}
			else
				mandarPersonaDependiendo(persona, j);
		}
		break;
	case 4:
		{
			if (j != splash)
			{
				persona->setCongelamiento(caminos->dijkstra(caminos->busquedaVertice(j), caminos->busquedaVertice(splash)));
				Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, splash);
				Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
				congelamiento->insertFront(nodulon);
			}
			else
				mandarPersonaDependiendo(persona, j);
		}
		break;
	case 5:
		{
			if (j != kilauea)
			{
				persona->setCongelamiento(caminos->dijkstra(caminos->busquedaVertice(j), caminos->busquedaVertice(kilauea)));
				Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, kilauea);
				Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
				congelamiento->insertFront(nodulon);
			}
			else
				mandarPersonaDependiendo(persona, j);
		}
		break;
	case 6:
		{
			if (j != huracan)
			{
				persona->setCongelamiento(caminos->dijkstra(caminos->busquedaVertice(j), caminos->busquedaVertice(huracan)));
				Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, huracan);
				Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
				congelamiento->insertFront(nodulon);
			}
			else
				mandarPersonaDependiendo(persona, j);
		}
		break;
	case 7:
		{
			if (j != goKart)
			{
				persona->setCongelamiento(caminos->dijkstra(caminos->busquedaVertice(j), caminos->busquedaVertice(goKart)));
				Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, goKart);
				Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
				congelamiento->insertFront(nodulon);
			}
			else
				mandarPersonaDependiendo(persona, j);
		}
		break;
	case 8:
		{
			if (j != vudu)
			{
				persona->setCongelamiento(caminos->dijkstra(caminos->busquedaVertice(j), caminos->busquedaVertice(vudu)));
				Vertice<Persona *, Juego *> * vertice = new Vertice<Persona *, Juego *>(persona, vudu);
				Nodo<Vertice<Persona *, Juego *> *> * nodulon = new Nodo<Vertice<Persona *, Juego *> *>(vertice);
				congelamiento->insertFront(nodulon);
			}
			else
				mandarPersonaDependiendo(persona, j);
		}
		break;
	default:
		break;
	}

}

void salDelJuegoYHasEsto(int i)
{
	switch (i)
	{
	case 0:
		{
			if (!batman->getActivado())
			{
				while (!batman->getArriba()->empty())
				{
					mandarPersonaDependiendo(batman->getArriba()->pop()->getInfo(), batman);
				}
				batman->moverColas();
			}
			else
				batman->setTiempo(batman->getTiempo()-1);
		}
		break;
	case 1:
		{
			if (!superman->getActivado())
			{
				while (!superman->getArriba()->empty())
				{
					mandarPersonaDependiendo(superman->getArriba()->pop()->getInfo(), superman);
				}
				superman->moverColas();
			}
			else
				superman->setTiempo(batman->getTiempo() - 1);
		}
		break;
	case 2:
		{
			if (!boomerang->getActivado())
			{
				while (!boomerang->getArriba()->empty())
				{
					mandarPersonaDependiendo(boomerang->getArriba()->pop()->getInfo(), boomerang);
				}
				boomerang->moverColas();
			}
			else
				boomerang->setTiempo(boomerang->getTiempo() - 1);
		}
		break;
	case 3:
		{
			if (!medusa->getActivado())
			{
				while (!medusa->getArriba()->empty())
				{
					mandarPersonaDependiendo(medusa->getArriba()->pop()->getInfo(), medusa);
				}
				medusa->moverColas();
			}
			else
				medusa->setTiempo(medusa->getTiempo() - 1);
		}
		break;
	case 4:
		{
			if (!splash->getActivado())
			{
				while (!splash->getArriba()->empty())
				{
					mandarPersonaDependiendo(splash->getArriba()->pop()->getInfo(), splash);
				}
				splash->moverColas();
			}
			else
				splash->setTiempo(splash->getTiempo() - 1);
		}
		break;
	case 5:
		{
			if (!kilauea->getActivado())
			{
				while (!kilauea->getArriba()->empty())
				{
					mandarPersonaDependiendo(kilauea->getArriba()->pop()->getInfo(), kilauea);
				}
				kilauea->moverColas();
			}
			else
				kilauea->setTiempo(kilauea->getTiempo() - 1);
		}
		break;
	case 6:
		{
			if (!huracan->getActivado())
			{
				while (!huracan->getArriba()->empty())
				{
					mandarPersonaDependiendo(huracan->getArriba()->pop()->getInfo(), huracan);
				}
				huracan->moverColas();
			}
			else
				huracan->setTiempo(huracan->getTiempo() - 1);
		}
		break;
	case 7:
		{
			if (!goKart->getActivado())
			{
				while (!goKart->getArriba()->empty())
				{
					mandarPersonaDependiendo(goKart->getArriba()->pop()->getInfo(), goKart);
				}
				goKart->moverColas();
			}
			else
				goKart->setTiempo(goKart->getTiempo() - 1);
		}
		break;
	case 8:
		{
			if (!vudu->getActivado())
			{
				while (!vudu->getArriba()->empty())
				{
					mandarPersonaDependiendo(vudu->getArriba()->pop()->getInfo(), vudu);
				}
				vudu->moverColas();
			}
			else
				vudu->setTiempo(vudu->getTiempo() - 1);
		}
		break;
	default:
		break;
	}
}

void meterAJuego(int t)
{
	
}
