
#include "ft_ls.h"

void parse_options(int argc, char **argv, t_options *options) {
    int opt;

    while ((opt = getopt(argc, argv, "lRart")) != -1) {
        if (opt == 'l')
            options->l = 1;
        else if (opt == 'R')
            options->R = 1;
        else if (opt == 'a')
            options->a = 1;
        else if (opt == 'r')
            options->r = 1;
        else if (opt == 't')
            options->t = 1;
        else {
            fprintf(stderr, "Usage: %s [-lRart] [file ...]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
}
