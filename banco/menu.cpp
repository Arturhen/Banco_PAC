#include "menu.h"
#include <string.h>
#include <math.h>

Menu::Menu(int z){
    int a;
    int b;
    int c;
    int pause;
    int numero;
    double primeirosaldo;
    int numremover;
    int Containformada;
    int NcontaReceber;
    ContaCorrente* contacorrente = new ContaCorrente();
    ContaPoupanca* contapoupanca = new ContaPoupanca();
    ContaBancaria* ContaRemover;
    ContaBancaria* Contadousuario;
    ContaBancaria* ContaReceber;
    ContaBancaria* ContaUnica;
    Relatorio Relatorio1;
    int sair,home;
    double saque;
    double deposito;
    double transferencia;



    do{
        do{
            system("cls");
            std::cout<<"*****************                 *****************"<<std::endl;
            std::cout<<"*****************  SEJA BEM VINDO *****************"<<std::endl;
            std::cout<<"*****************                 *****************"<<std::endl;
            a = perguntar("Selecione uma das opcoes:\n1- Criar conta\n2- Selecionar conta\n3- Remover conta\n4- Gerar relatorio\n5- Finalizar\n");
            if(a < 1 || a > 5) std::cout<<"Digite uma tecla valida."<<std::endl;
        }while(a < 1 || a > 5);
        switch(a){
            case 1:
                do{
                    c = perguntar("Voce deseja criar uma conta poupanca ou corrente?\n1 Para Conta corrente\n2 para conta Poupanca\n3 Para voltar ao menu\n");
                    if(c < 1 || c > 3) std::cout<<"Digite uma tecla valida."<<std::endl;
                }while(c < 1 || c > 3);
                do{
                    do{
                        numero = perguntar("Qual o numero da conta?\n");
                        if(numero <=0) std::cout << "Digite um numero maior do que zero." << std::endl;
                    }while(numero <=0);
                        ContaUnica = Geral.procurarConta(numero);
                        if(ContaUnica != NULL) std::cout<<"O numero de conta ja esta cadastrado. Tente outro"<<std::endl;
                }while(ContaUnica != NULL);
                do{
                    primeirosaldo = perguntar("Qual o saldo da sua conta?\n");
                    if(primeirosaldo < 0) std::cout<<std::endl<<"Informe um saldo maior ou igual a zero"<<std::endl;
                }while(primeirosaldo < 0);
                switch(c){
                    case 1:
                        contacorrente->set_conta(numero);
                        contacorrente->set_saldo(primeirosaldo);
                        Geral.inserir(contacorrente);
                        contacorrente = new ContaCorrente();
                    break;
                    case 2:
                        contapoupanca->set_saldo(primeirosaldo);
                        contapoupanca->set_conta(numero);
                        Geral.inserir(contapoupanca);
                        contapoupanca = new ContaPoupanca();
                    break;
                    case 3:
                        home=1;
                    break;
                }
                std::cout<<std::endl<<"Conta criada com Sucesso"<<std::endl;
                system("pause");
                home=1;
            break;
            case 2:
                do
                {
                    Containformada = perguntar("Informe o numero da conta\nSe quiser voltar ou nao tiver uma conta digite 0\n");
                    Contadousuario=Geral.procurarConta(Containformada);
                    if (Contadousuario == NULL && Containformada!=0)
                        std::cout<<"A conta informada nao existe."<<std::endl<<"Digite uma conta valida"<<std::endl;
                }while(Contadousuario == NULL && Containformada!=0);
                if(Containformada!=0){
                    do
                    {
                        home=0;
                        system("cls");
                        b = perguntar("O que deseja realizar na conta selecionada?\n1- Depositar\n2- Sacar\n3- Transferir\n4- Gerar relatorio\n5- Voltar ao menur anterior\n");
                        switch(b)
                        {
                        case 1 :
                            do
                            {
                                deposito=0;
                                deposito = perguntar("Qual o valor que voce deseja depositar?\nSe desejar nao depositar digite 0 e volte para o menu anterior\n");
                                if (deposito>0){
                                    Contadousuario->depositar(deposito);
                                }
                                else if(deposito<0){
                                    std::cout<<"Digite um valor de deposito positivo"<<std::endl;
                                }
                            } while (deposito<0);
                        break;
                    case 2 :
                        do
                        {
                            saque=0;
                            saque = perguntar("Qual o valor que voce deseja sacar?\nSe desejar nao sacar digite 0 e volte para o menu anterior\n");
                            if (saque>0){
                                Contadousuario->sacar(saque);
                                std::cout << std::endl;
                                system("pause");
                            }
                            else if(saque<0){
                                std::cout<<"Digite um valor para sacar positivo"<<std::endl;
                            }
                        }while (saque<0);
                    break;
                case 3:
                    do 
                    {
                        transferencia=0;
                        transferencia = perguntar("Qual o valor que voce deseja transferir?\nSe desejar nao transferir digite 0 e volte para o menu anterior\n");
                        if (transferencia>0){
                            NcontaReceber = perguntar("informe o numero da conta que recebera o dinheiro\n");
                            ContaReceber=Geral.procurarConta(NcontaReceber);
                            if (ContaReceber != NULL){
                                Contadousuario->transferir(transferencia, *ContaReceber);
                            }
                            else {
                                std::cout<<"A conta nao existe."<<std::endl;
                            }
                            std::cout << std::endl;
                            system("pause");
                        }
                        else if (transferencia<0){
                            std::cout<<"Digite um valor de transferencia positivo"<<std::endl;
                        }
                    } while (transferencia<0);
                    break;
                case 4:
                    Contadousuario->mostrarDados();
                    system("pause");
                    break;
                case 5:
                    home=1;
                    break;
                default:
                    std::cout<<"DIGITE UMA TECLA VALIDA"<<std::endl;
                    system("pause");
                    break;
                }
                } while (home != 1);
            }
            home = 1;
            break;
            case 3:
                numremover = perguntar("Qual o numero da conta voce deseja remover\n");
                ContaRemover=Geral.procurarConta(numremover);
                if (ContaRemover != NULL) Geral.remover(ContaRemover);
                else std::cout<<"Esta conta nao existe."<<std::endl;
                system("pause");
                home=1;
            break;
            case 4:
                Geral.mostrarDados();
                system("pause");
                home=1;
            break;
            case 5:
                do{
                    sair = perguntar("Voce tem certeza que quer sair ?\n1-Sim\n2-Nao,voltar ao menu\n");
                    if(sair < 1 || sair > 2) std::cout<<"Digite uma tecla valida."<<std::endl;
                }while(sair < 1 || sair > 2);
                if (sair==1) home = 0;
                else if(sair == 2) home=1;
            break;
        }
    }while(home==1);
}

double Menu::perguntar(std::string pergunta){
    char valor[15], parte_decimal[20], parte_inteira[20], r, c;
    char* separador;
    std::string numeral;
    do{
        strcpy(parte_decimal, "");
        r='n';
        do{
            std::cout << pergunta;
            std::cin >> valor;
            if(valor[0] == '.'){
                std::cout << "O primeiro algarismo deve ser diferente de '.'." << std::endl;
                system("pause");
                system("cls");
            }
        }while(valor[0] == '.');
        numeral = valor;
        separador = strtok(valor, ".");
        strcpy(parte_inteira, separador);
        separador = strtok(NULL, ".");
        while(separador != NULL){
            strcat(parte_decimal, separador);
            separador = strtok(NULL, ".");
        }
        strcpy(valor,"");
        strcpy(valor,parte_inteira);
        strcat(valor,parte_decimal);
        if(valor[0] == '-' || (valor[0] >= 48 && valor[0] <= 57)){
            for(int i = 1; i < strlen(valor); i++){
                if((valor[i] < 48 || valor[i] > 57) && valor[i] != '.'){
                    r = 's';
                    break;
                }
            }
        }
        else r = 's';
        if(r == 's'){
            std::cout << "Digite um valor que possa ser aceito." << std::endl;
            system("pause");
            system("cls");
        }
    }while(r == 's');
    if(strcmp(parte_decimal,"")==0){
        return atoi(valor);
    }
    else{
        return (atoi(parte_inteira) + atoi(parte_decimal)/pow(10,strlen(parte_decimal)));
    }   
}