#ifndef MENU_H
#define MENU_H
#include "banco.h"
#include "contacorrente.h"
#include "contapoupanca.h"
#include <iostream>
#include "relatorio.h"

class Menu
{
public:
    Banco Geral;
    Menu(int); 
    double perguntar(std::string pergunta);
private:
};

#endif