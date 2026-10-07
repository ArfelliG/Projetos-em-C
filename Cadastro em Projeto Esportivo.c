
#include <stdio.h>
#include <windows.h>

#define TF 5

/*
    O Objetivo deste Codigo é fazer o cadastro de usuarios em um projeto esportivo

	Para isso preccisamos: 
	
    - Cadastrar usuarios
    - Dar opcoes de esportes
    - Separar por genero a quantidade de alunos matriculados
    - Separar por esporte
    - Separar por idade: 8-12, 13-15, 16-18 e 18+
*/

struct usuario {
    char nome[100];
    int idade;
    int esporte;
    char genero;
    int selESPORTE;
};

struct usuario u[TF];


void cadastrar() {

    int i;

    for(i = 0; i < TF; i++) {

		
        printf("\n\tUsuario: %d\n", i + 1);

        printf("\n\tNome: ");
        scanf(" %[^\n]", u[i].nome);

        printf("\n\tIdade: ");
        scanf("%d", &u[i].idade);

        printf("\n\tM - Masculino");
        printf("\n\tF - Feminino");
        printf("\n\tGenero: ");
        scanf(" %c", &u[i].genero);

        u[i].esporte = 0;
        u[i].selESPORTE = 0;

        printf("\n\tUsuario cadastrado com sucesso!\n");

        system("pause");
        system("cls");
    }
}



void selecionar_esporte() {

    int i;

    for(i = 0; i < TF; i++) {

        if(u[i].idade == 0) {
            printf("\n\tNenhum usuario cadastrado!\n");
            return;
        }

        if(u[i].idade < 8) {

            printf("\n\tO aluno %s nao possui a idade minima para participar do projeto.\n",
                   u[i].nome);

        } else {

            printf("\n\tAluno: %s\n", u[i].nome);

            printf("\n\t1 - Futebol");
            printf("\n\t2 - Voleibol");
            printf("\n\t3 - Jogos de Tabuleiro");
            printf("\n\t4 - Karate");

            printf("\n\n\tDeseja matricular %s em qual esporte? ",
                   u[i].nome);

            scanf("%d", &u[i].esporte);

            while(u[i].esporte < 1 || u[i].esporte > 4) {

                printf("\n\tOpcao invalida!");
                printf("\n\tDigite novamente: ");
                scanf("%d", &u[i].esporte);
            }

            u[i].selESPORTE = 1;

            printf("\n\tEsporte selecionado com sucesso!\n");
        }

        system("pause");
        system("cls");
    }
}



void sep_generos() {

    int i;
    int contF = 0;
    int contM = 0;

    for(i = 0; i < TF; i++) {

        if(u[i].idade == 0) {
            printf("\n\tNenhum usuario cadastrado!\n");
            return;
        }

        if(u[i].selESPORTE == 1) {

            if(u[i].genero == 'M' || u[i].genero == 'm') {
                contM++;
            }

            if(u[i].genero == 'F' || u[i].genero == 'f') {
                contF++;
            }
        }
    }

    printf("\n\tTotal de meninas: %d", contF);
    printf("\n\tTotal de meninos: %d\n", contM);
}



void sep_esporte() {

    int i;
    int contFut = 0;
    int contVol = 0;
    int contTab = 0;
    int contKar = 0;

    for(i = 0; i < TF; i++) {

        if(u[i].idade == 0) {
            printf("\n\tNenhum usuario cadastrado!\n");
            return;
        }

        if(u[i].selESPORTE == 1) {

            if(u[i].esporte == 1) {
                contFut++;
            }

            if(u[i].esporte == 2) {
                contVol++;
            }

            if(u[i].esporte == 3) {
                contTab++;
            }

            if(u[i].esporte == 4) {
                contKar++;
            }
        }
    }

    printf("\n\tUsuarios matriculados no Futebol: %d", contFut);
    printf("\n\tUsuarios matriculados no Voleibol: %d", contVol);
    printf("\n\tUsuarios matriculados em Jogos de Tabuleiro: %d", contTab);
    printf("\n\tUsuarios matriculados no Karate: %d\n", contKar);
}



void sep_idade() {

    int i;
    int cont8_12 = 0;
    int cont13_15 = 0;
    int cont16_18 = 0;
    int cont18mais = 0;

    for(i = 0; i < TF; i++) {

        if(u[i].idade == 0) {
            printf("\n\tNenhum usuario cadastrado!\n");
            return;
        }

        if(u[i].selESPORTE == 1) {

            if(u[i].idade >= 8 && u[i].idade <= 12) {
                cont8_12++;
            }

            if(u[i].idade >= 13 && u[i].idade <= 15) {
                cont13_15++;
            }

            if(u[i].idade >= 16 && u[i].idade <= 18) {
                cont16_18++;
            }

            if(u[i].idade > 18) {
                cont18mais++;
            }
        }
    }

    printf("\n\tFaixa de 8 a 12 anos: %d usuarios", cont8_12);
    printf("\n\tFaixa de 13 a 15 anos: %d usuarios", cont13_15);
    printf("\n\tFaixa de 16 a 18 anos: %d usuarios", cont16_18);
    printf("\n\tFaixa acima de 18 anos: %d usuarios\n", cont18mais);
}



void menu() {

    printf("\n -=+= BEM-VINDO AO GG SPORTS =+=-");

    printf("\n");
    printf("\n     1 - Cadastro de Usuarios");
    printf("\n     2 - Selecionar Esportes");
    printf("\n     3 - Listar por Genero");
    printf("\n     4 - Listar por Esporte");
    printf("\n     5 - Listar por Faixa Etaria");
    printf("\n     0 - Sair");

    printf("\n");
    printf("\n-=+=- -=+=- -=+=- -=+=- -=+=- -=+=-");
}


int main() {

    int op;

    do {

        menu();

        printf("\nDigite uma opcao: ");
        scanf("%d", &op);

        switch(op) {

            case 1: system("pause");
        			system("cls");
                cadastrar();
                break;

            case 2:system("pause");
        			system("cls");
                selecionar_esporte();
                break;

            case 3:system("pause");
        		   system("cls");
                sep_generos();
                break;

            case 4:system("pause");
        		   system("cls");
                sep_esporte();
                break;

            case 5:system("pause");
                   system("cls");
                sep_idade();
                break;

            case 0:
                printf("\nFinalizando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

        if(op != 0) {
            system("pause");
            system("cls");
        }

    } while(op != 0);

    return 0;
}

