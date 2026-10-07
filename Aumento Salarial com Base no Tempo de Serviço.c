#include <stdio.h>
#include <windows.h>
#include <string.h>
#define TF 5
	/*
	O Objetivo deste codigo, é criar um mini sistema de aumento salarial, com base no Valor informado pelo usuario!
	
	O funcionário receberá aumento de acordo com o tempo:

	Tempo de serviço	Aumento
	Menos de 2 anos	5%
	2 a 5 anos	10%
	Mais de 5 anos	20%

	Porém, funcionários com mais de 10 anos de serviço também receberão uma gratificação de R$ 1.500.

	*/

typedef struct{
	
	char nome[100], cargo[100];
	float tmp_servico ;			
}funcionario;

typedef struct{
	
	float salario, reaj, salario_final, gratificacao;
	int control;
}pagamento;

funcionario f[TF];
pagamento p[TF];

void cadastrar(){
	int i;
	
	for(i=0; i<TF; i++){
		
		printf("\n\tNome: ");
   		scanf(" %[^\n]", &f[i].nome);
		printf("\n\tCargo: ");
   		scanf(" %[^\n]", &f[i].cargo);
   		printf("\n\tSalario: ");
   		scanf("%f", &p[i].salario);
   		printf("\n\tTempo de servico (Em Anos): ");
   		scanf("%f", &f[i].tmp_servico);
   		printf("\n\t");
   		system("pause");
		system("cls");
	}

}

void calcular(){
	
	int i;
	if(p[i].salario != 0){
		for(i=0; i<TF; i++){
	
		
		
			if(f[i].tmp_servico <= 2){
				p[i].reaj = (p[i].salario * 5)/100;
				p[i].salario_final = p[i].salario + p[i].reaj;
				printf("\n\tSalario Final no Valor de %.2f", p[i].salario_final);
				printf("\n\tPara saber todas as informacoes do reajuste do Salario do Funcionario %s utilize a opcao 3 do Menu!\n", f[i].nome);
				
			}
			else if(f[i].tmp_servico > 2 && f[i].tmp_servico <=5){
				p[i].reaj = (p[i].salario * 10)/100;
				p[i].salario_final = p[i].salario + p[i].reaj;
				printf("\n\tSalario Final no Valor de %.2f", p[i].salario_final);
				printf("\n\tPara saber todas as informacoes do reajuste do Salario do Funcionario %s utilize a opcao 3 do Menu!\n", f[i].nome);
							
			}
			else if(f[i].tmp_servico > 5 && f[i].tmp_servico <=10){
				p[i].reaj = (p[i].salario * 20)/100;
				p[i].salario_final = p[i].salario + p[i].reaj;
				printf("\n\tSalario Final no Valor de %.2f", p[i].salario_final);
				printf("\n\tPara saber todas as informacoes do reajuste do Salario do Funcionario %s utilize a opcao 3 do Menu!\n", f[i].nome);
				
			}
			else if(f[i].tmp_servico > 10){
				p[i].gratificacao = 1500;
				p[i].reaj = (p[i].salario * 20)/100;
				p[i].salario_final = p[i].salario + p[i].reaj + p[i].gratificacao;
				printf("\n\tSalario Final no Valor de %.2f", p[i].salario_final);
				printf("\n\tPara saber todas as informacoes do reajuste do Salario do Funcionario %s utilize a opcao 3 do Menu!\n", f[i].nome);
				
			}
		
		
		
		}
	}else
			printf("\n\tVoce precisa Cadastrar primeiro!\n");
		
		
	
	p[0].control = 1;
}

void pesquisar(){
	
	int i,op;
	char procurar_n[50], procurar_c[50];
	

		
		if(p[0].control == 1){
			
			printf("\n\t1- Nome       \n\t2- Cargo       \n\tQual metodo de pesquisa deseja utilizar: ");
			scanf("%d", &op);
			
			if(op == 1){
				
				printf("\n\tDigite o NOME para consultar: ");
				scanf(" %[^\n]", &procurar_n);
				for(i=0; i<TF; i++){
					if(strcmp(procurar_n, f[i].nome) == 0){
					
						printf("\n\tNome: %s", f[i].nome);
						printf("\n\tCargo: %s", f[i].cargo);
						printf("\n\tTempo de Servico: %.2f Anos", f[i].tmp_servico);
						printf("\n\tSalario Antigo: %.2f Reais", p[i].salario);
						printf("\n\tReajuste: %.2f Reais", p[i].reaj);
						if(p[i].gratificacao != 0){
							printf("\n\tGratificacao: %.2f Reais", p[i].gratificacao);
						}
						printf("\n\tSalario Atual: %.2f Reais\n", p[i].salario_final);
						system("pause");
						system("cls");
					}
				}	
			}
			else if(op == 2){
				
				printf("\n\tDigite o CARGO no qual deseja consultar: ");
				scanf(" %[^\n]", &procurar_c);
				
				if(strcmp(procurar_c, f[i].cargo) == 0){
					for(i=0; i<TF; i++){
						printf("\n\tNome: %s", f[i].nome);
						printf("\n\tCargo: %s", f[i].cargo);
						printf("\n\tTempo de Servico: %.2f Anos", f[i].tmp_servico);
						printf("\n\tSalario Antigo: %.2f Reais", p[i].salario);
						printf("\n\tReajuste: %.2f Reais", p[i].reaj);
					
						if(p[i].gratificacao != 0){
							printf("\n\tGratificacao: %.2f Reais\n", p[i].gratificacao);
						}
						printf("\n\tSalario Atual: %.2f Reais\n", p[i].salario_final);
						system("pause");
						system("cls");
					}
				}
			}
			else
				printf("\n\tNumero Invalido!\n");
			
			
			
	
		}else
			printf("\n\tVoce precisa Calcular o Aumento primeiro!\n");
		
	
	
}

void menu(){
	printf("\n\t1- Cadastrar Funcionario");
	printf("\n\t2- Calcular Aumento");
	printf("\n\t3- Pesquisar Funcionario");
	printf("\n\t0- Sair");
}
main(){
	
	int op;
	
	
	do{
		menu();
		printf("\n\tEscolha uma opcao: ");
			scanf("%d", &op);
		switch(op){
			
			case 1: cadastrar();
				break;
			case 2: calcular();
				break;
			case 3: pesquisar();
				break;
			case 0: printf("\n\tFinalizando...");
				break;
		
		}
		
	}while(op!=0);
	
}
