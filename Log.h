//
//  Log.h
//  Proyecto Final Cubells
//
//  Created by César Millán on 11/29/13.
//  Copyright (c) 2013 César Millán. All rights reserved.
//

#ifndef __Proyecto_Final_Cubells__Log__
#define __Proyecto_Final_Cubells__Log__

#include <iostream>
#include <fstream>
#include <string>

class Log{
    std::ofstream log;
    
public:
    Log();
    void writeToLog(std::string evento, int hora, std::string NoPersona);
    void writeToLog(std::string evento);
    ~Log();
};


#endif /* defined(__Proyecto_Final_Cubells__Log__) */
