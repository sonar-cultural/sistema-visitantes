#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

char *get_string()
{
        int size = 1, next_character = 0;
        char character;
        char *string = malloc(size * sizeof(string));

        getchar();

        while (TRUE) {
                character = getchar();
                if (character == '\n')
                        break;
                string = realloc(string, ++size * sizeof(string));
                string[next_character++] = character;
        }

        return string;
}

void free_pointer(struct visitor *root)
{
        if (root->next != NULL)
                free_pointer(root->next);

        if (root->name != NULL)
                free(root->name);

        if (root != NULL)
                free(root);
}