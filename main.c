#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

int main() {
    
        int option;

        menu_head();

        option = get_option();

        switch (option)
        {
        case 1:
                write_userData();
                break;
        case 2:
                printf("Caso 2\n");
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