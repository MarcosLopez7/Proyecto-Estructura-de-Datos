//
//  Log.cpp
//  Proyecto Final Cubells
//
//  Created by César Millán on 11/29/13.
//  Copyright (c) 2013 César Millán. All rights reserved.
//

#include "Log.h"

using namespace std;

Log::Log(){
    log.open("log.txt");
}

void Log::writeToLog(std::string evento, int hora, std::string NoPersona){
    log << hora/60 << ":" << (hora%60) << " " << "Persona: "<< NoPersona <<" " << evento << endl;
}

void Log::writeToLog(std::string evento){
    log << evento << endl;
}

Log::~Log(){
    log.close();
}