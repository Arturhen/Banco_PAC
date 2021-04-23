#include "banco.h"


void Banco::inserir(ContaBancaria* obj){
	contas.push_back(obj);
}

void Banco::remover(ContaBancaria* obj){
	int i;
	for(i = 0; i < contas.size(); i++){
		if (obj->get_conta() == contas[i]->get_conta()){
			contas.erase(contas.begin()+i);
			std::cout<<"A conta foi excluida com Sucesso."<<std::endl;	
		break;
		}
	}
}
ContaBancaria* Banco::procurarConta(int Pconta){
	int i;
	for(i = 0; i < contas.size(); i++){
		if(Pconta==contas[i]->	get_conta()){
			return(contas[i]);	
		}
	}
	return(NULL);			
}

void Banco::mostrarDados() const{
	int i;
	for(i = 0; i < contas.size(); i++){
		std::cout<<"Saldo: "<<contas[i]->get_saldo()<<std::endl<<"Nmr. da conta: "<<contas[i]->get_conta();
		std::cout<<std::endl<< "................................................"<<std::endl;
	}
}
