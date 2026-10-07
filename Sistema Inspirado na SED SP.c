#include <stdio.h>
#include <windows.h>
#define MAX 2
#define CAP 2

struct cadastro{
    char nome[100], mae[100], pai[100];
    int idade, rg, cpf, ra;
    int sala_matriculado; 
    int matriculado; 
};

struct sala{
    int numero_sala, capacidade;
    char nome_sala[100];
    int cod;
    int qtd_alunos; 
};


struct cadastro c[MAX];
struct sala s[MAX];

void submenu(){
	
	printf("\n\t=+=+=+=+  -BUSCA-  +=+=+=+=");
	printf("\n\t1- Buscar Por RA");
	printf("\n\t2- Buscar Por Nome");
	printf("\n\t3- Buscar Por Filiacao 1 (Mae)");
	printf("\n\t4- Buscar Por Filiacao 2 (Pai)");
	printf("\n\t5- Buscar Por Documento)");
	
}

void cadastrar_alunos(){
    int i, cont=0;

    for(i=0; i<MAX; i++){
        printf("\n\tNome: ");
        scanf(" %[^\n]", c[i].nome);

        printf("\n\tFiliacao 1(Mae): ");
        scanf(" %[^\n]", c[i].mae);

        printf("\n\tFiliacao 2(Pai): ");
        scanf(" %[^\n]", c[i].pai);

        printf("\n\tIdade: ");
        scanf("%d", &c[i].idade);

        printf("\n\tRG: ");
        scanf("%d",&c[i].rg);

        printf("\n\tCPF: ");
        scanf("%d",&c[i].cpf);

        c[i].ra = cont+1;
        cont++; 
         system("pause");
         system("cls");
    }
}

void matricular_aluno(){
    int i, j, ra_busca, opcao, achou = 0;

    if(s[0].cod == 0){
        printf("\n\tNenhuma Sala Criada, Por favor cadastre uma sala primeiro!\n\n");
        
        return;
    }

    printf("\n\tDigite o RA do aluno que quer matricular: ");
    scanf("%d", &ra_busca);

    for(i=0; i<MAX; i++){
        if(c[i].ra == ra_busca){
            achou = 1;

            if(c[i].matriculado == 1){
                printf("\n\tAluno %s ja esta matriculado!\n", c[i].nome);
                return;
            }

            printf("\n\tSalas disponiveis:\n");
            for(j=1; j<=CAP; j++){
                printf("\t[%d]- %s ( %d / %d vagas usadas )\n", j, s[j].nome_sala, s[j].qtd_alunos, s[j].capacidade);
            }

            printf("\n\tEm que sala deseja matricular o %s: ", c[i].nome);
            scanf("%d", &opcao);

            if(opcao < 1 || opcao > CAP){
                printf("\n\tOpcao invalida!\n");
                return;
            }

            if(s[opcao].qtd_alunos >= s[opcao].capacidade){
                printf("\n\tSala lotada!\n");
                return;
            }

            c[i].sala_matriculado = opcao;
            c[i].matriculado = 1;
            s[opcao].qtd_alunos++;

            printf("\n\tAluno %s matriculado na sala %s com sucesso!\n", c[i].nome, s[opcao].nome_sala);
            break;
        }
        system("pause");
        system("cls");
    }

    if(!achou){
        printf("\n\tRA nao encontrado!\n");
    }
}

   

void criar_sala(){
    int i;
    for(i=1; i<=CAP; i++){
    	
    	printf("\n\tNome da Sala: ");
        scanf(" %[^\n]", s[i].nome_sala);
        
        printf("\n\tCodigo da Sala: ");
        scanf("%d", &s[i].numero_sala);

        printf("\n\tCapacidade da Sala: ");
        scanf("%d", &s[i].capacidade);
        
        system("pause");
        system("cls");
    }
    
    s[0].cod=1;
    
}

void ficha_aluno(){

	int i,ra_busca, opcao, doc_procurar, rg_busca, cpf_busca;
	char nome_buscar[100], mae_buscar[100], pai_buscar[100];
	
	
	submenu();
	printf("\nQual metodo de busca deseja efetuar: ");
	scanf("%d", &opcao);
	
	if(opcao == 1){ 
		printf("\n\tDigite o RA do aluno que quer procurar: ");
    	scanf("%d", &ra_busca);
    	 for(i=0; i<MAX; i++){
        	if(c[i].ra == ra_busca){
				printf("\n\tNome: %s", c[i].nome);
				printf("\n\tIdade: %d", c[i].idade);
				printf("\n\tFiliacao 1: %s", c[i].mae);
				printf("\n\tFiliacao 2: %s", c[i].pai);
				printf("\n\tRG: %d", c[i].rg);
				printf("\n\tCPF: %d", c[i].cpf);
				printf("\n\tRA: %d", c[i].ra);
				system("pause");
       			system("cls");
			}
		
		}
	}
	if(opcao == 2){ 
		printf("\n\tDigite o NOME do aluno que quer procurar: ");
    	scanf(" %[^\n]", nome_buscar);
    	for(i=0; i<MAX; i++){
    	
			if(strcmp(c[i].nome, nome_buscar) == 0){
				printf("\n\tNome: %s", c[i].nome);
				printf("\n\tIdade: %d", c[i].idade);
				printf("\n\tFiliacao 1: %s", c[i].mae);
				printf("\n\tFiliacao 2: %s", c[i].pai);
				printf("\n\tRG: %d", c[i].rg);
				printf("\n\tCPF: %d", c[i].cpf);
				printf("\n\tRA: %d", c[i].ra);
				system("pause");
      			system("cls");
			}
		}
	}
	if(opcao == 3){ 
	printf("\n\tDigite o Nome da MAE do aluno que quer procurar: ");
    	scanf(" %[^\n]", mae_buscar);
    	for(i=0; i<MAX; i++){
    	
			if(strcmp(c[i].mae, mae_buscar) == 0){
				printf("\n\tNome: %s", c[i].nome);
				printf("\n\tIdade: %d", c[i].idade);
				printf("\n\tFiliacao 1: %s", c[i].mae);
				printf("\n\tFiliacao 2: %s", c[i].pai);
				printf("\n\tRG: %d", c[i].rg);
				printf("\n\tCPF: %d", c[i].cpf);
				printf("\n\tRA: %d", c[i].ra);
				system("pause");
      			system("cls");				
			}
		}
	}
	if(opcao == 4){ 
		printf("\n\tDigite o Nome da PAI do aluno que quer procurar: ");
    		scanf(" %[^\n]", pai_buscar);
    	for(i=0; i<MAX; i++){
    	
			if(strcmp(c[i].pai, pai_buscar) == 0){
				printf("\n\tNome: %s", c[i].nome);
				printf("\n\tIdade: %d", c[i].idade);
				printf("\n\tFiliacao 1: %s", c[i].mae);
				printf("\n\tFiliacao 2: %s", c[i].pai);
				printf("\n\tRG: %d", c[i].rg);
				printf("\n\tCPF: %d", c[i].cpf);
				printf("\n\tRA: %d", c[i].ra);
				system("pause");
      			system("cls");	
			}
		}
	}
	if(opcao == 5){ 
		
		printf("\n\tPor qual documento deseja procurar:\n\t1- RG\n\t2- CPF");
		scanf("%d", &doc_procurar);
		
		if(doc_procurar == 1){
			
			printf("\n\tDigite o RG do aluno que quer procurar: ");
    		scanf("%d", &rg_busca);
    	 	for(i=0; i<MAX; i++){
        		if(c[i].rg == rg_busca){
					printf("\n\tNome: %s", c[i].nome);
					printf("\n\tIdade: %d", c[i].idade);
					printf("\n\tFiliacao 1: %s", c[i].mae);
					printf("\n\tFiliacao 2: %s", c[i].pai);
					printf("\n\tRG: %d", c[i].rg);
					printf("\n\tCPF: %d", c[i].cpf);
					printf("\n\tRA: %d", c[i].ra);
					system("pause");
      				system("cls");			
				}
		
			}
		}
		if(doc_procurar == 2){
			
			printf("\n\tDigite o CPF do aluno que quer procurar: ");
    		scanf("%d", &cpf_busca);
    	 	for(i=0; i<MAX; i++){
        		if(c[i].cpf == cpf_busca){
					printf("\n\tNome: %s", c[i].nome);
					printf("\n\tIdade: %d", c[i].idade);
					printf("\n\tFiliacao 1: %s", c[i].mae);
					printf("\n\tFiliacao 2: %s", c[i].pai);
					printf("\n\tRG: %d", c[i].rg);
					printf("\n\tCPF: %d", c[i].cpf);
					printf("\n\tRA: %d", c[i].ra);
					system("pause");
      				system("cls");				
				}
		
			}
			
		}		
		
	}
	if(opcao >5 || opcao <1){
		printf("\n\tDigite um numero valido!");
	}
	
	
	

}


void menu(){
    printf("\n\t -=+=- BEM VINDOS -=+=-");
    printf("\n\t ");
    printf("\n\t 1- Cadastra Alunos");
    printf("\n\t 2- Cadastrar Sala");
    printf("\n\t 3- Matricular Aluno");
    printf("\n\t 4- Ficha do Aluno(Consulta)");
    printf("\n\t 0- Sair");
    printf("\n\t ");
    printf("\n\t-=+=---=+=---=+=---=+=-");
}

int main(){
    int op;

    do{
        menu();
        printf("\n\tEscolha uma opcao: ");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:  system("pause");
        		     system("cls");
			cadastrar_alunos();
                break;
            case 2:  system("pause");
        			 system("cls");
					 criar_sala();
                break;
            case 3:  system("pause");
        			 system("cls");
					 matricular_aluno();
                break;
            case 4:  system("pause");
        			 system("cls");
				     ficha_aluno();
                break;
            case 0: printf("\n\tFinalizando...");
                break;
            default: printf("\n\tEscolha uma opcao valida!");
                break;
        }
    }while(op!=0);

    return 0;
}
