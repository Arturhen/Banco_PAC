#include "contabancaria.h"
#include <iostream>

void ContaBancaria::mostrarDados()const{}

void ContaBancaria::sacar(double saque){
	if((saldo - saque) >= 0) this->saldo -= saque;
}

void ContaBancaria::depositar(double deposito){
	this->saldo += deposito;
}

void ContaBancaria::transferir(double transferencia, ContaBancaria& obj){
	double saldo_original = saldo;
	sacar(transferencia);
	if(saldo < saldo_original){
		obj.depositar(transferencia);
		std::cout<<"Transferencia realizada"<<std::endl;//!
	}
	else std::cout<<"Nao foi possivel realizar a transferencia"<<std::endl;
}

int ContaBancaria::get_conta(){
    return this->conta;
}

double ContaBancaria::get_saldo(){
    return this->saldo;
}

void ContaBancaria::set_conta(int conta){
    this->conta=conta;
}

void ContaBancaria::set_saldo(double saldo){
    this->saldo=saldo;
}