#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

char *get_string()
{
        int size = 1, next_character = 0;
        char character;
        char *string = malloc(size * sizeof(char));

        getchar();

        while (TRUE) {
                character = getchar();
                if (character == '\n')
                        break;
                string = realloc(string, ++size * sizeof(char));
                string[next_character++] = character;
        }
        return string;
}