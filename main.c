#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main () {

int user_Option;

while(1) {

system("clear");
menu_head();

user_Option = menu_first();

if (user_Option == 1) {

        system("clear");
        menu_head();
        menu_user();
        break;
} else if (user_Option == 2) {
        system("clear");
        menu_head();
        //admin_form()
} else if (user_Option == 3) {
        exit(0);
} else {
        system("clear");
        printf("Opção Inválida! Tente novamente.\n");
        continue;
}
}
return 0;
}