#include "Atraccion.h"
#include "Juego.h"
#include <iostream>
#include <fstream>


void menu();
int convierteHora(int hora);
Persona * personaEspecial;
void write_text_to_log_file(const std::string &text);


int main(int argc, const char * argv [])
{

    Cola<Persona *> * parque = new Cola<Persona *>();

	Juego * batman = new Juego(parque, 10, 30, "Batman");
    Juego * superman = new Juego(parque, 20,40, "Superman");
    Juego * boomerang = new Juego (parque, 10,20, "Boomerang");
    Juego * medusa = new Juego (parque, 20,15, "Medusa");
    Juego * splash = new Juego (parque, 10,20,"Splash");
    Juego * kilauea = new Juego (parque, 10,26, "Kilauea");
    
    
	for (int t = 600; t < 1200; t = t + 10)
	{
        
        /* Impresión hora */
		cout << "Son las: " << t/60 << ":";
        if (t%60 == 0)
            cout << "00" << endl;
        else
            cout << t%60 << endl;
        
        /* Creación de personas BOT */
        if (t < 720){
            int n = rand() % 60;
            for(int i = 0; i < n;i++){
                parque->enqueue(new Nodo<Persona *>(new Persona(t)));
            }
        }
        if (t >= 720 && t < 840){
            int n = rand() % 40;
            for(int i = 0; i < n;i++){
                parque->enqueue(new Nodo<Persona *>(new Persona(t)));
            }
        }
        if (t >= 840 && t < 1080){
            int n = rand() % 20;
            for(int i = 0; i < n;i++){
                parque->enqueue(new Nodo<Persona *>(new Persona(t)));
            }
        }
        if (t >= 1080 && t <= 1200){
            int n = rand() % 5;
            for(int i = 0; i < n;i++){
                parque->enqueue(new Nodo<Persona *>(new Persona(t)));
            }
        }
        
        
        
            
        

        for (int i = 0; i < 10; i++)
		{
            if (!parque->empty())
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
					if (!parque->empty())
                        batman->EntraColaNormal(parque->dequeue()->getInfo());
				}
			}
			if (i == (t + 5))
			{
				for (int i = 0; i < 10; i++)
				{
					//parque->enqueue(new Nodo<Persona *>(batman->SalJuego()));
				}
			}
		}

		for (int i = 0; i < 10; i++)
		{
			delete parque->dequeue();
		}

	}
    
    delete parque;
    delete batman;
    delete superman;
    delete boomerang;
    delete medusa;
    delete splash;
    delete kilauea;

	system("pause");
	return 0;
}

void menu (){
    cout << "Bienvenido a Six Flags! " << endl;
    cout << "Ingresa tu nombre: " << endl;
    string nombre;
    getline(cin,nombre);
    cin.ignore('\n',12345);
    cout << "Cuál es tu hora de llegada? \n Hint: \n1:05  = 0105\n14:39 = 1439" << endl;
    int horaLlegada;
    cin >> horaLlegada;
    cout << "Cuanto tiempo vas a permanecer en el parque? (horas)" << endl;
    int tiempoPermanencia;
    cin >> tiempoPermanencia;
    tiempoPermanencia = tiempoPermanencia * 60;
    cout << "Cuál es tu presupuesto?" << endl;
    int presupuesto;
    cin >> presupuesto;
    personaEspecial = new Persona(convierteHora(horaLlegada) + tiempoPermanencia,presupuesto,nombre);
}

int convierteHora(int hora){
    int horaArreglada;
    horaArreglada = hora%10;
    hora = hora/10;
    horaArreglada = horaArreglada + (hora%10)*10;
    hora = hora/10;
    horaArreglada = horaArreglada + hora*60;
    return horaArreglada;
}

/* Nada probado lo encontré en internet de como hacer un log file */
void write_text_to_log_file( const std::string &text )
{
    std::ofstream log_file("log_file.txt", std::ios_base::out | std::ios_base::app );
    log_file << text << std::endl;
}
