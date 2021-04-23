#ifndef BANCO_H
#define BANCO_H
#include <iostream>
#include <vector>
#include "contabancaria.h"
#include "imprimivel.h"

class Banco:public Imprimivel{
public:
	std::vector<ContaBancaria*> contas;
	void inserir(ContaBancaria*);
	void remover(ContaBancaria*);
	ContaBancaria* procurarConta(int);
	void mostrarDados() const;
private:
};

#endif
