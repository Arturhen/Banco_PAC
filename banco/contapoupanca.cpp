#include "contapoupanca.h"
#include <iostream>



void ContaPoupanca::sacar(double saque){
	if(saldo-saque >= limite) this->saldo -= saque;
	else std::cout<<"Ultrapassou o limite de saque."<<std::endl;
}

void ContaPoupanca::depositar(double deposito){
	this->saldo += deposito;
}

void ContaPoupanca::mostrarDados() const{
	std::cout<<"Saldo: "<<saldo<<std::endl<<"Nmr. da conta: "<<conta<<std::endl<<"Credito limite: "<<limite<<std::endl;
}
