
#include "../includes/ft_ls.h"

int ft_getopt(int argc, char *argv[], const char *optstring, t_options *options) {
    static int optpos = 0;
    static char *current_opt = NULL;

    if (options->optind >= argc || argv[options->optind][0] != '-')
        return -1;

    if (argv[options->optind][0] == '-' && argv[options->optind][1] == '\0')
        return -1;

    if (optpos == 0) {
        current_opt = argv[options->optind];
        optpos++;
    }

    char opt = current_opt[optpos++];

    if (opt == '\0') {
        optpos = 0;
        (options->optind)++;
        return ft_getopt(argc, argv, optstring, options);
    }

    if (ft_strchr(optstring, opt) == NULL) {
        ft_putstr_fd("Unknown option ", STDERR_FILENO);
        ft_putchar_fd('\'', STDERR_FILENO);
        ft_putchar_fd(opt, STDERR_FILENO);
        ft_putchar_fd('\'', STDERR_FILENO);
        ft_putchar_fd('\n', STDERR_FILENO);
        return '?';
    }

    return opt;
}

void parse_options(int argc, char **argv, t_options *options) {
    int opt;

    while ((opt = ft_getopt(argc, argv, "lRart", options)) != -1) {
        switch (opt) {
            case 'l':
                options->l = 1; 
                break;
            case 'R':
                options->R = 1;
                break;
            case 'a':
                options->a = 1;
                break;
            case 'r':
                options->r = 1;
                break;
            case 't':
                options->t = 1;
                break;
            default:
                display_usage(argv[0]);
                exit(EXIT_FAILURE);
            break;
        }
    }
}
