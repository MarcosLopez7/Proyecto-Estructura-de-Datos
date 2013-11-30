//#include "Atraccion.h"
//#include "Juego.h"
#include "Parque.h"
//#include "Grafo.h"
#include <iostream>
#include <fstream>


void menu();
void hora (int t);
int convierteHora(int hora);
Persona * personaEspecial;
void write_text_to_log_file(const std::string &text);


int main(int argc, const char * argv [])
{
    Parque * parque = new Parque;
    
    parque->crearJuegos();
    parque->crearGrapho();
    
    //menu();
    /* impresión de prueba */
    //cout << *personaEspecial;
    
	for (int t = 600; t < 1200; t++)
	{
        if (t%10 == 0){
            hora(t);
            parque->crearBots(t);
        }
        
        parque->checarCongelamiento();
        parque->moverFilas(t);
        
        }
    
	return 0;
}

void menu (){
    cout << "Bienvenido a Six Flags! " << endl;
    cout << "Ingresa tu nombre: " << endl;
    string nombre;
    getline(cin,nombre);
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

void hora (int t){
    cout << "Son las: " << t/60 << ":";
    if (t%60 == 0)
        cout << "00" << endl;
    else
        cout << t%60 << endl;
}

/* Nada probado lo encontré en internet de como hacer un log file */
void write_text_to_log_file( const std::string &text )
{
    std::ofstream log_file("log_file.txt", std::ios_base::out | std::ios_base::app );
    log_file << text << std::endl;
}
