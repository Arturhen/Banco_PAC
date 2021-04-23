#include "contacorrente.h"
#include <iostream>


void ContaCorrente::sacar(double saque){
	if((saldo - saque - (saldo * taxaDeOperacao)) >= 0) this->saldo = (saldo-saque) - (saldo * taxaDeOperacao);
	else std::cout<<"Ultrapassou o limite de saque."<<std::endl;
}

void ContaCorrente::depositar(double deposito){
	this->saldo = (saldo + deposito) - (saldo * taxaDeOperacao);
}

void ContaCorrente::mostrarDados() const{
	std::cout<<"Saldo: "<<saldo<<std::endl<<"Nmr. da conta: "<<conta<<std::endl<<"Taxa de operacoes: "<<taxaDeOperacao<<std::endl<<"................................................"<<std::endl;
}
