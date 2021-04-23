#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H
#include "contabancaria.h"
#include "imprimivel.h"

class ContaPoupanca:public ContaBancaria,public Imprimivel{
public:

	void sacar(double);
	void depositar(double);
	void mostrarDados() const;
private:
	const float limite = -200;
};

#endif
