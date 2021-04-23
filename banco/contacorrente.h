#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H
#include "contabancaria.h"
#include "imprimivel.h"

class ContaCorrente:public ContaBancaria,public Imprimivel{
public:
	void sacar(double);
	void depositar(double);
	void mostrarDados() const;
private:
	const float taxaDeOperacao = 0.01;
};

#endif
