#include <time.h>
#define TRUE 1
#define FALSE 0

struct visitor {
        char *name;
        int age;
        time_t date;
        struct visitor *next;
};