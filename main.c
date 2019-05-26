#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

int main() 
{

        int user_Option;        

        struct visitante *visitantePtr, cadastro;
        visitantePtr = &cadastro;
        FILE *fp;      

        menu_head();

        user_Option = get_option();

        switch (user_Option) {
        case 1:
                fp = fopen("data.bin", "a");

                if (fp == NULL) {
                        printf("Erro ao abrir ao arquivo.\n");
                        exit(-1);
                }

                system("clear");

                menu_head();
                
                printf("Por favor, digite suas informações.\n");                                        
                printf("Nome Completo: ");
                get_lowerName(visitantePtr->nome);

                visitantePtr->idade = get_age();
                
                printf("Cidade: ");
                get_lowerName(visitantePtr->cidade);

                visitantePtr->uf = get_uf();

                printf("Ocupação (Ex. Estudante, Professor, Empresário, etc): ");
                get_lowerName(visitantePtr->ocupacao);
                                        
                printf("Instituição / Empresa: ");
                get_lowerName(visitantePtr->instuicao);

                visitantePtr->jaVisitou = get_frequency();

                if (cadastro.jaVisitou == 1)
                        visitantePtr->ondeConheceu = get_whereMeet();
                                
                fwrite(&visitantePtr, sizeof(struct visitante), 1, fp);
                fclose(fp);

                printf("\nInformações gravadas com sucesso! Obrigado.\n");
                
                break;

        case 2:
                system("clear");
                
                fp = fopen("data.bin", "r");

                if (fp == NULL) {
                        printf("Erro ao abrir ao arquivo.\n");
                        exit(-1);
                }

                fread(&visitantePtr, sizeof(struct visitante), 1, fp);

                printf("Nome: %s;\n", cadastro.nome);
                printf("Idade: %d;\n", cadastro.idade);
                printf("Cidade: %s;\n", cadastro.cidade);
                printf("Uf: %d;\n", cadastro.uf);
                printf("Ocupação: %s;\n", cadastro.ocupacao);
                printf("Instituição: %s;\n", cadastro.instuicao);
                printf("Já visitou: %d;\n", cadastro.jaVisitou);
                printf("Onde conheceu: %d;\n", cadastro.ondeConheceu);
                fclose(fp);                        
                break;

        case 3:                
                system("clear");
                printf("caso 3");
                exit(0);
                break;

        default:
                system("clear\n");
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

        return 0;

}