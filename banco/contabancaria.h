#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

class ContaBancaria{
public:
	virtual void sacar(double);
	virtual void depositar(double);
	void transferir(double, ContaBancaria&);
	int get_conta();
	double get_saldo();
	void set_conta(int);
	void set_saldo(double);
	virtual void mostrarDados() const;
	
protected:
	int conta;
	double saldo=0;

};

#endif
