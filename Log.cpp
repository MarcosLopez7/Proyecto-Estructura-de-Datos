//
//  Log.cpp
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#include "Log.h"

using namespace std;

Log::Log(){
	log.open("log.txt");
}

void Log::writeToLog(std::string evento, int tiempo){
	log << hora(tiempo) <<endl<< evento << endl<<endl;
}

void Log::writeToLog(std::string evento){
	log << evento << endl;
}

string Log::hora(int t){
    string hora;
	hora = "Son las: " + to_string(t / 60) + ":";
	if (t % 60 == 0)
		hora += "00";
    else if(t%60 < 10)
        hora += "0" + to_string(t%60);
	else
		hora += to_string(t % 60);
    
    return hora;
}

Log::~Log(){
	log.close();
}