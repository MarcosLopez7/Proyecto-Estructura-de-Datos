//
//  Log.h
//  Proyecto Final Estructura de Datos TC1018
//
//  Created by César Millán on 12/1/13.
//  Copyright (c) 2013 César Millán & Marcos López. All rights reserved.
//

#ifndef __Proyecto_Final_Estructura_de_Datos_TC1018__Log__
#define __Proyecto_Final_Estructura_de_Datos_TC1018__Log__

#include <iostream>
#include <fstream>
#include <string>

class Log{
	std::ofstream log;
    
public:
	Log();
	void writeToLog(std::string evento, int hora);
	void writeToLog(std::string evento);
    std::string hora(int t);
	~Log();
};

#endif /* defined(__Proyecto_Final_Estructura_de_Datos_TC1018__Log__) */
