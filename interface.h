#include <stdio.h>
#include "functions.h"

void menu_head() {
    
printf("******************************************************\n");
printf("*            MOBBAC - Sistema de Cadastro            *\n");
printf("******************************************************\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");

}

int menu_first() {

int userOption;

printf("1 - Cadastro de Usuário;\n");
printf("\n");
printf("2 - Painel Administrativo;\n");
printf("\n");
printf("3 - Sair;\n");
printf("\n");
printf("Escolha uma opção: ");

scanf("%d", &userOption);

return userOption;

}

void menu_user() {

char ondeConheceu[140], nome[100], instituicao[50], cidade[20],ocupacao[20], uf[2];
int idade; 

printf("Nome Completo:\n");
scanf("%c\n", nome);
printf("Idade:\n");
scanf("%d\n", &idade);
printf("Cidade:\n");
scanf("%c\n", cidade);
printf("UF:\n");
scanf("%c\n", uf);
printf("Ocupação:\n");
scanf("%c", ocupacao);

}