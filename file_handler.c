#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"

void write_to_file(struct visitor *root)
{
        FILE *file = fopen("visitors.bin", "wb");
        struct visitor *visitor = root;
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

        if (fclose(file) != 0) {
                printf("Erro ao fechar arquivo.");
                exit(-1);
        }
}

struct visitor *read_from_file(struct visitor *root, int *amount_visitors)
{
        FILE *file = fopen("visitors.bin", "rb");
        struct visitor *visitor = NULL, *aux = NULL;
        int counter = 0;
        char *name = "";        

        if (file != NULL) {
                while (!feof(file)) {                        
                        aux = calloc(1, sizeof(struct visitor));
                        name = calloc(1, 30*sizeof(char));

                        if (!aux || !name)
                                exit(1);

                        if (!fread(aux, sizeof(struct visitor), 1, file))
                                break;

                        fread(name, sizeof(char), 30, file);

                        if (root == NULL) {                                
                                root = calloc(1, sizeof(struct visitor));
                                root = aux;
                                root->name = calloc(1, 30*sizeof(char));
                                strcpy(root->name, name);
                                visitor = root;
                        } else {
                                aux->name = calloc(1, 30*sizeof(char));
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
