#include <stdio.h>
#include <windows.h>
#include <string.h>

#define TF 5

/* Sistema Escolar

Esse codigo foi feito utilizando struct e funções para realizar as seguintes operações: 

 Cadastro de alunos
 Cadastro de professores
 Consulta de alunos
 Lançamento de notas
 Cálculo da média dos alunos
 Informar aprovado ou reprovado

*/

struct aluno {
    char nome[100];
    int idade;
    int ra;
    float nota1;
    float nota2;
    float media;
};

struct professor {
    char nome_prof[100];
    int cod;
};

struct disciplina {
    char nome[50];
    int cod;
};

struct aluno a[TF];
struct professor p[TF];
struct disciplina d[TF];

void cadastro_aluno() {

    int i;

    for (i = 0; i < TF; i++) {

        printf("\n\t-=+ Cadastro de Aluno %d +=-\n", i + 1);

        printf("\tDigite o nome do aluno: ");
        scanf(" %[^\n]", a[i].nome);

        printf("\tDigite a idade: ");
        scanf("%d", &a[i].idade);

        printf("\tDigite o RA: ");
        scanf("%d", &a[i].ra);

        a[i].nota1 = 0;
        a[i].nota2 = 0;
        a[i].media = 0;
        system("pause");
        system("cls");
    }

    printf("\n\tAlunos cadastrados com sucesso!\n");
}

void cadastro_prof() {

    int i;

    for (i = 0; i < TF; i++) {

        printf("\n\t-=+ Cadastro de Professor %d +=-\n", i + 1);

        printf("\tDigite o nome do professor: ");
        scanf(" %[^\n]", p[i].nome_prof);

        printf("\tDigite o codigo do professor: ");
        scanf("%d", &p[i].cod);
        system("pause");
        system("cls");
    }

    printf("\n\tProfessores cadastrados com sucesso!\n");
}


void consulta_aluno() {

    int i;
    int procurar;
    int encontrado = 0;

    printf("\n\t-=+ Consulta de Aluno +=-\n");

    printf("\tDigite o RA do aluno: ");
    scanf("%d", &procurar);

    for (i = 0; i < TF; i++) {

        if (procurar == a[i].ra) {

            printf("\n\tAluno encontrado!\n");
            printf("Nome: %s\n", a[i].nome);
            printf("Idade: %d\n", a[i].idade);
            printf("RA: %d\n", a[i].ra);

            encontrado = 1;
            system("pause");
      		system("cls");
        }
    }

    if (encontrado == 0) {
        printf("\n\tNenhum aluno foi encontrado com esse RA.\n");
        system("pause");
        system("cls");
    }
}

void lancamento_notas() {

    int i;

    printf("\n\t-=+ Lancamento de Notas +=-\n");

    for (i = 0; i < TF; i++) {

        if (a[i].ra != 0) {

            printf("\n\tAluno: %s\n", a[i].nome);

            printf("\tDigite a primeira nota: ");
            scanf("%f", &a[i].nota1);

            printf("\tDigite a segunda nota: ");
            scanf("%f", &a[i].nota2);
            system("pause");
        	system("cls");
        }
    }

    printf("\n\tNotas lancadas com sucesso!\n");
}

void calcular_media() {

    int i;

    printf("\n\t-=+ Calculo das Medias +=-\n");

    for (i = 0; i < TF; i++) {

        if (a[i].ra != 0) {

            a[i].media = (a[i].nota1 + a[i].nota2) / 2;

            printf("\nAluno: %s", a[i].nome);
            printf("\nMedia: %.2f\n", a[i].media);
            system("pause");
        	system("cls");
        }
    }
}

void informar_aprovado() {

    int i;

    printf("\n\t-=+ Situacao dos Alunos +=-\n");

    for (i = 0; i < TF; i++) {

        if (a[i].ra != 0) {

            if (a[i].media >= 6) {
                printf("\n\tO aluno %s foi APROVADO!", a[i].nome);
            }
            else {
                printf("\n\tO aluno %s foi REPROVADO!", a[i].nome);
            }
            system("pause");
        	system("cls");
        }
    }

    printf("\n");
}
	
void menu() {

    printf("\n\t+=-=-=-=-+-=-=-=-=-=-=-=-+-=-=-=-=+");
    printf("\n\t           SISTEMA ESCOLAR         ");
    printf("\n\t+=-=-=-=-+-=-=-=-=-=-=-=-+-=-=-=-=+");
    printf("\n\t1 - Cadastro de Alunos");
    printf("\n\t2 - Cadastro de Professores");
    printf("\n\t3 - Consulta de Alunos");
    printf("\n\t4 - Lancamento de Notas");
    printf("\n\t5 - Calcular Medias dos Alunos");
    printf("\n\t6 - Informar Aprovado ou Reprovado");
    printf("\n\t0 - Sair");
    printf("\n\t+=-=-=-=-+-=-=-=-=-=-=-=-+-=-=-=-=+");
}

int main() {

    int op;

    do {

        menu();

        printf("\n\tDigite uma opcao: ");
        scanf("%d", &op);

        switch (op) {

            case 1: system("pause");
        			system("cls");
                cadastro_aluno();
                break;

            case 2: system("pause");
        			system("cls");
                cadastro_prof();
                break;

            case 3:system("pause");
           		   system("cls");
                consulta_aluno();
                break;

            case 4: system("pause");
        			system("cls");
                lancamento_notas();
                break;

            case 5: system("pause");
        			system("cls");
                calcular_media();
                break;

            case 6: system("pause");
        			system("cls");
                informar_aprovado();
                break;

            case 0:
                printf("\n\tFinalizando o programa...\n");
                break;

            default:
                printf("\n\tOpcao invalida!\n");
        }

    } while (op != 0);

    return 0;
}


