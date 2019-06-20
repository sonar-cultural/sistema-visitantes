#include "main.h"

int main()
{
        int option, amount_visitors, loop = TRUE;
        int month = 0, day = 0;
        struct visitor *root = NULL;
        root = read_from_file(root, &amount_visitors);

        while (loop) {
                menu();

                scanf("%d", &option);

                switch (option) {
                case 1:
                        root = set_visitor_data(root, &amount_visitors);
                        break;
                case 2:
                        list_visitors(root);
                        break;
                case 3:
                        month = get_month();
                        visitors_per_date(root, 0, month);
                        break;
                case 4:
                        day = get_day();
                        month = get_month();
                        visitors_per_date(root, day, month);
                        break;
                case 5:
                        get_histogram(amount_visitors, root);
                        break;
                case 6:
                        loop = FALSE;
                        break;
                default:
                        printf("Opção inválida! Tente novamente.\n");
                        break;
                }
        }

        write_to_file(root);
        free_pointer(root);

        return 0;
}