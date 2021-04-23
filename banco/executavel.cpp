#include "executavel.h"
#include "relatorio.h"
#include <iostream>

Executavel::Executavel(int entrada){
	ContaCorrente Artur;
	ContaPoupanca Rafael;
	Relatorio obj_auxiliar;
	Artur.depositar(500);
	Artur.sacar(200);
	Rafael.depositar(500);
	Rafael.sacar(600);
	obj_auxiliar.gerarRelatorio(Artur);
	obj_auxiliar.gerarRelatorio(Rafael);
}
