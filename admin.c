#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#define HISTOGRAM_AMOUNT 5

void list_visitors(struct visitor *root)
{
        if (root == NULL) {
                printf("Empty list!\n");
                return;
        }

        struct visitor *pointer = root;
        struct tm *local;
        int day, month, year;

        printf("\n\nVisitantes: \n");

        while (pointer != NULL) {
                local = localtime(&pointer->date);
                day = local->tm_mday;
                month = local->tm_mon + 1;
                year = local->tm_year + 1900;

                printf("------------------------------------------\n");
                printf("Nome: %s | Idade: %d | Data: %02d/%02d/%d\n",
                        pointer->name, pointer->age, day, month, year);

                pointer = pointer->next;
        }

        printf("\n\n");
}

int get_day()
{
        int day;

        printf("Qual dia gostaria de visualizar?\n");

        scanf("%d", &day);

        while (day <= 0 || day > 31) {
                printf("Dia inválido. Tente novamente.\n");
                scanf("%d", &day);
        }

        return day;
}

int get_month()
{
        int month;

        printf("Qual mês gostaria de visualizar?\n");

        scanf("%d", &month);

        while (month <= 0 || month > 12) {
                printf("Mês inválido. Tente novamente.\n");
                scanf("%d", &month);
        }

        return month;
}

void visitors_per_date(struct visitor *root, int choosen_day, int choosen_month)
{
        if (root == NULL) {
                printf("Lista vazia!\n");
                return;
        }

        struct visitor *pointer = root;
        struct tm *local;
        int counter = 0;
        int day, month, year;

        printf("\n\nTotal de visitantes | Mês %d: \n", choosen_month);

        while (pointer != NULL) {
                local = localtime(&pointer->date);
                day = local->tm_mday;
                month = local->tm_mon + 1;
                year = local->tm_year + 1900;

                if (choosen_day > 0) {
                        if (choosen_day == day && choosen_month == month) {
                                counter++;
                                printf("------------------------------------------\n");
                                printf("Nome: %s | Idade: %d | Data: %02d/%02d/%d\n",
                                        pointer->name, pointer->age, day, month, year);
                        }
                } else {
                        if (month == choosen_month) {
                                counter++;
                                printf("------------------------------------------\n");
                                printf("Nome: %s | Idade: %d | Data: %02d/%02d/%d\n",
                                        pointer->name, pointer->age, day, month, year);
                        }
                }

                pointer = pointer->next;
        }

        printf("\nTOTAL: %d visitantes\n\n", counter);
}

void get_histogram(int amount_visitors, struct visitor *root)
{
        int histogram[HISTOGRAM_AMOUNT] = {0};
	char *labels[HISTOGRAM_AMOUNT];
        struct visitor *visitor = root;

        labels[0] = "até 12 anos ";
	labels[1] = "13 - 18 anos";
	labels[2] = "19 - 29 anos";
	labels[3] = "30 - 49 anos";
	labels[4] = "+50 anos    ";

        if (visitor != NULL) {
                for (int j = 0; j < amount_visitors; j++) {
                        int age = visitor->age;

                        if (age <= 12)
                                histogram[0]++;
                        else if (age >= 13 && age <= 18)
                                histogram[1]++;
                        else if (age >= 19 && age <= 29)
                                histogram[2]++;
                        else if (age >= 30 && age <= 49)
                                histogram[3]++;
                        else if (age >= 50)
                                histogram[4]++;

                        visitor = visitor->next;
                }
        }

        printf("\n\nHistograma das idades: \n");
        for (int i = 0; i < HISTOGRAM_AMOUNT; i++) {
                int counter = 0;
                printf("------------------------------------------\n");
		printf("%s | ", labels[i]);

                for (int j = 0; j < histogram[i]; ++j) {
                        printf("#");
                        counter++;
                }

		printf(" (%d)\n", counter);
	}

        printf("\n\n");
}