#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"

void write_to_file(struct visitor *root)
{
        FILE *file = fopen("visitors.bin", "wb");
        struct visitor *visitor = root, *pointer;
        int counter = 0;

        if (!file || !root)
                exit(1);

        while (visitor != NULL) {
                fwrite(&*visitor, sizeof(struct visitor), 1, file);
                fwrite(visitor->name, sizeof(char), 30, file);
                visitor = visitor->next;
                counter++;
        }

        printf("%d items gravados com sucesso.\n", counter);

        if (fclose(file)) {
                printf("Erro ao fechar arquivo.");
                exit(-1);
        }
}

struct visitor *read_from_file(struct visitor *root, int *amount_visitors)
{
        FILE *file = fopen("visitors.bin", "rb");
        struct visitor *visitor, *aux;
        int counter = 0;
        char *name;

        if (file != NULL) {
                while (!feof(file)) {
                        aux = malloc(sizeof(struct visitor));
                        name = malloc(30*sizeof(char));

                        if (!fread(aux, sizeof(struct visitor), 1, file))
                                break;

                        fread(name, sizeof(char), 30, file);

                        if (root == NULL) {
                                root = malloc(sizeof(struct visitor));
                                root = aux;
                                root->name = malloc(30*sizeof(char));
                                strcpy(root->name, name);
                                visitor = root;
                        }

                        else {
                                aux->name = malloc(30*sizeof(char));
                                strcpy(aux->name, name);
                                visitor->next = aux;
                                visitor = visitor->next;
                        }

                        counter++;
                        free(name);
                }

                *amount_visitors = counter;
                visitor->next = NULL;

        } else {
                printf("Arquivo vazio.\n\n");
                exit(-1);
        }

        return root;
}
