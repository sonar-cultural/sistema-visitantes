#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

struct visitante
{
        char nome[140];
        int idade;
        char cidade[50];
        int uf;
        char ocupacao[100];
        char instuicao[140];
        int jaVisitou;
        int ondeConheceu;
};

void menu_head()
{
        
        printf("******************************************************\n");
        printf("*             MOBBAC - Sistema de Visitas            *\n");
        printf("******************************************************\n");
        printf("\n");

}

int get_option()
{

        int choice;

        printf("1) Cadastro de Visitante;\n");
        printf("\n");
        printf("2) Painel Administrativo;\n");
        printf("\n");
        printf("3) Sair;\n");
        printf("\n");
        printf("Escolha uma opcão: ");

        scanf("%d", &choice);
        getchar();

        return choice;

}

void get_lowerName(char *ptr)
{

        scanf("%[^\n]s", ptr);
        getchar();

        for (int i = 0; ptr[i] != '\0'; i++) {
                if ((ptr[i] >= 'A') && (ptr[i] <= 'Z')) {
                        ptr[i] = ptr[i] + 32;
                }
        }
}

int get_age()
{

        int tmp, age;

        while (1) {                
                printf("Idade: ");
                scanf("%d", &tmp);
                getchar();

                if ((tmp > 0) && (tmp <= 150)) {
                        age = tmp;                        
                        break;

                } else {
                        system("clear");
                        printf("Erro: Input inválido!\nDigite apenas sua idade atual! \n");
                        delay();
                        continue;
                }
                
        }

        return age;
}

int get_uf()
{

        int tmp, estado;

        while (1) {

                printf("Estado: \n"); 
                printf("\n");               
                printf(" 1) Acre; \n");
                printf(" 2) Alagoas; \n");
                printf(" 3) Amapá; \n");
                printf(" 4) Amazonas; \n");
                printf(" 5) Bahia; \n");
                printf(" 6) Ceará; \n");
                printf(" 7) Distrito Federal; \n");
                printf(" 8) Espírito Santo; \n");
                printf(" 9) Goiás; \n");
                printf("10) Maranhão; \n");
                printf("11) Mato Grosso; \n");
                printf("12) Mato Grosso do Sul; \n");
                printf("13) Minas Gerais; \n");
                printf("14) Pará; \n");
                printf("15) Paraíba; \n");
                printf("16) Paraná; \n");
                printf("17) Pernambuco; \n");
                printf("18) Piauí; \n");
                printf("19) Rio de Janeiro; \n");
                printf("20) Rio Grande do Norte; \n");
                printf("21) Rio Grande do Sul; \n");
                printf("22) Rondônia; \n");
                printf("23) Roraima; \n");
                printf("24) Santa Catarina; \n");
                printf("25) São Paulo; \n");
                printf("26) Sergipe; \n");
                printf("27) Tocantins; \n");
                printf("Digite o número correspodente ao seu estado: ");
                scanf("%d", &tmp);                
                getchar();
                
                if ((tmp > 0) && (tmp <= 27)) {
                        estado = tmp;
                        break;
                } else {
                        system("clear");
                        printf("Erro: Input inválido!\nDigite o número correspondete ao seu estado! \n");
                        delay();
                }
        
        }

        return estado;
}

int get_frequency()
{
        
        int tmp, answer;

        while (1) {

                printf("Você já visitou o MOBBAC antes?\n1) Sim, ou 2) Não: ");                
                scanf("%d", &tmp);
                getchar();

                if ((tmp == 1) || (tmp == 2)) {
                        answer = tmp;                        
                        break;

                } else {
                        system("clear");
                        printf("Erro: Input inválido!\nDigite apenas 1 se você já visitou o MOBBAC antes, ou 2 se essa é a sua primeira visita.\n");
                        delay();
                        continue;
                }
                
        }

        return answer;
}

int get_whereMeet()
{

        int tmp, answer;

        while (1) {

                printf("Onde você nos conheceu? \n"); 
                printf("\n");               
                printf(" 1) Redes sociais; \n");
                printf(" 2) Televisão; \n");
                printf(" 3) Rádio; \n");
                printf(" 4) Revista/Jornais impressos; \n");
                printf(" 5) Parente ou amigos; \n");
                printf(" 6) Faculdade/Escola; \n");
                printf(" 7) Outros; \n");
                printf("Digite o número correspodente a onde você nos conheceu: ");
                scanf("%d", &tmp);                
                getchar();
                
                if ((tmp > 0) && (tmp <= 7)) {
                        answer = tmp;
                        break;

                } else {
                        system("clear");
                        printf("Erro: Input inválido!\nDigite o número correspodente a onde você nos conheceu! \n");
                        delay();                        

                }
        
        }

        return answer;
}