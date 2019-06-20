#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "functions.h"

char *set_name()
{
        char *name;
        printf("Nome: ");
        name = get_string();
        return name;
}

int set_age()
{
        int age;
        printf("Idade: ");
        scanf("%d", &age);

        while (age < 0 || age > 100) {
                printf("Idade inválida. Tente novamente.\n");
                scanf("%d", &age);
        }

        return age;
}

time_t set_date()
{
        time_t date;
        time(&date);
        return date;
}

struct visitor *create_visitor()
{
        struct visitor *visitor = calloc(1, sizeof(struct visitor));
        visitor->next = NULL;

        return visitor;
}

struct visitor *add_visitor(struct visitor *root, char *name, int age, time_t date)
{
        struct visitor *aux, *curr_visitor;
        aux = create_visitor();
        aux->name = name;
        aux->age = age;
        aux->date = date;

        if (root == NULL)
                root = aux;

        else {
                curr_visitor = root;

                while (curr_visitor->next != NULL) {
                        curr_visitor = curr_visitor->next;
                }

                curr_visitor->next = aux;
        }

        return root;
}

struct visitor *set_visitor_data(struct visitor *new_root, int *amount_visitors)
{
        char *name = set_name();
        int age = set_age();
        time_t date = set_date();

        new_root = add_visitor(new_root, name, age, date);
        *amount_visitors += 1;

        printf("\nObrigado! Aproveite sua visita!\n\n");

        return new_root;
}
