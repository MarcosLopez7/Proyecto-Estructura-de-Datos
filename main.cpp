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
    
    //menu();
    /* impresión de prueba */
    //cout << *personaEspecial;
    
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
            int n = rand() % 600;
            for(int i = 0; i < n;i++){
                parque->enqueue(new Nodo<Persona *>(new Persona(t)));
            }
        }
        if (t >= 720 && t < 840){
            int n = rand() % 400;
            for(int i = 0; i < n;i++){
                parque->enqueue(new Nodo<Persona *>(new Persona(t)));
            }
        }
        if (t >= 840 && t < 1080){
            int n = rand() % 200;
            for(int i = 0; i < n;i++){
                parque->enqueue(new Nodo<Persona *>(new Persona(t)));
            }
        }
        if (t >= 1080 && t <= 1200){
            int n = rand() % 50;
            for(int i = 0; i < n;i++){
                parque->enqueue(new Nodo<Persona *>(new Persona(t)));
            }
        }
        
        cout << "Personas en el parque: "<<parque->size()<<endl;
        
        /* Agregar personas bot a filas random */
        int l = rand() % 600;
        for (int i = 0; i<l; ++i) {
            if (!parque->empty()){
                int juegoSeleccionado = rand() % 12;
                
                switch (juegoSeleccionado) {
                    case 0:
                        batman->EntraColaNormal(parque->dequeue()->getInfo());
                        break;
                    case 1:
                        batman->EntraColaVip(parque->dequeue()->getInfo());
                        
                        break;
                    case 2:
                        superman->EntraColaNormal(parque->dequeue()->getInfo());
                        
                        break;
                    case 3:
                        superman->EntraColaVip(parque->dequeue()->getInfo());
                        
                        break;
                    case 4:
                        boomerang->EntraColaNormal(parque->dequeue()->getInfo());
                        
                        break;
                    case 5:
                        boomerang->EntraColaVip(parque->dequeue()->getInfo());
                        
                        break;
                    case 6:
                        medusa->EntraColaNormal(parque->dequeue()->getInfo());
                        
                        break;
                    case 7:
                        medusa->EntraColaVip(parque->dequeue()->getInfo());
                        
                        break;
                    case 8:
                        splash->EntraColaNormal(parque->dequeue()->getInfo());
                        
                        break;
                    case 9:
                        splash->EntraColaVip(parque->dequeue()->getInfo());
                        
                        break;
                    case 10:
                        kilauea->EntraColaNormal(parque->dequeue()->getInfo());
                        
                        break;
                    case 11:
                        kilauea->EntraColaVip(parque->dequeue()->getInfo());
                        
                        break;
                    default:
                        break;
                }
            }
        }
        
       
        /* Checar si es necesario mover las filas y tiempo de espera */
        for (int i = 0; i<6; i++) {
            switch (i) {
                case 0:
                    if (batman->getTiempoF() <= t) {
                        batman->moverColas(t);
                    }
                    cout << "Batman: " << endl;
                    cout << "Tiempo de espera fila noraml: "<<batman->getEsperaNormal()/60<<":"<<batman->getEsperaNormal()%60<<endl;
                    cout << "Tiempo de espera fila VIP: "<<batman->getEsperaVip()/60<<":"<<batman->getEsperaVip()%60 << endl;
                    break;
                case 1:
                    if (superman->getTiempoF() <= t) {
                        superman->moverColas(t);
                    }
                    cout << "Superman: " <<endl;
                    cout << "Tiempo de espera fila noraml: "<<superman->getEsperaNormal()/60<<":"<<superman->getEsperaNormal()%60<<endl;
                    cout << "Tiempo de espera fila VIP: "<<superman->getEsperaVip()/60<<":"<<superman->getEsperaVip()%60 << endl;
                    break;
                case 2:
                    if (boomerang->getTiempoF() <= t) {
                        boomerang->moverColas(t);
                    }
                    cout << "Boomerang: " << endl;
                    cout << "Tiempo de espera fila noraml: "<<boomerang->getEsperaNormal()/60<<":"<<boomerang->getEsperaNormal()%60<<endl;
                    cout << "Tiempo de espera fila VIP: "<<boomerang->getEsperaVip()/60<<":"<<boomerang->getEsperaVip()%60 << endl;
                    break;
                case 3:
                    if (medusa->getTiempoF() <= t) {
                        medusa->moverColas(t);
                    }
                    cout << "Medusa" <<endl;
                    cout << "Tiempo de espera fila noraml: "<<medusa->getEsperaNormal()/60<<":"<<medusa->getEsperaNormal()%60<<endl;
                    cout << "Tiempo de espera fila VIP: "<<medusa->getEsperaVip()/60<<":"<<medusa->getEsperaVip()%60 << endl;
                    break;
                case 4:
                    if (splash->getTiempoF() <= t) {
                        splash->moverColas(t);
                    }
                    cout << "Splash: " <<endl;
                    cout << "Tiempo de espera fila noraml: "<<splash->getEsperaNormal()/60<<":"<<splash->getEsperaNormal()%60<<endl;
                    cout << "Tiempo de espera fila VIP: "<<splash->getEsperaVip()/60<<":"<<splash->getEsperaVip()%60 << endl;
                    break;
                case 5:
                    if (kilauea->getTiempoF() <= t) {
                        kilauea->moverColas(t);
                    }
                    cout << "Kilauea:" << endl;
                    cout << "Tiempo de espera fila noraml: "<<kilauea->getEsperaNormal()/60<<":"<<kilauea->getEsperaNormal()%60<<endl;
                    cout << "Tiempo de espera fila VIP: "<<kilauea->getEsperaVip()/60<<":"<<kilauea->getEsperaVip()%60 << endl;
                    break;
                    
                default:
                    break;
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

/* Nada probado lo encontré en internet de como hacer un log file */
void write_text_to_log_file( const std::string &text )
{
    std::ofstream log_file("log_file.txt", std::ios_base::out | std::ios_base::app );
    log_file << text << std::endl;
}
