
#include "../includes/ft_ls.h"

int main(int argc, char **argv) {
    t_options options = {0, 0, 0, 0, 0};
    parse_options(argc, argv, &options);

    struct stat path_stat;
    if (optind >= argc) {
        // No directory specified, list current directory
        if (options.R) {
            ft_putstr_fd(".:\n", STDOUT_FILENO);
            recursive_traversal(".", options);
            if (!options.l) ft_putchar_fd('\n', STDOUT_FILENO);

        } else {
            t_file *files = list_directory(".", options);
            sort_files(&files, options);
            if (options.l) {
                print_total_blocks(files);
            }
            while (files) {
                print_file_info(files, options);
                files = files->next;
            }
            if (!options.l) ft_putchar_fd('\n', STDOUT_FILENO);
            free_file_list(files);
        }
    } else {
        // Iterate over the arguments
        for (int i = optind; i < argc; i++) {
            if (stat(argv[i], &path_stat) == 0) {
                if (S_ISDIR(path_stat.st_mode)) {
                    // Argument is a directory
                    if (options.R) {
                        ft_putstr_fd(argv[i], STDOUT_FILENO);
                        ft_putstr_fd(":\n", STDOUT_FILENO);
                        recursive_traversal(argv[i], options);
                        if (!options.l) ft_putchar_fd('\n', STDOUT_FILENO);

                    } else {
                        t_file *files = list_directory(argv[i], options);
                        sort_files(&files, options);
                        if (options.l) {
                            print_total_blocks(files);
                        }
                        while (files) {
                            print_file_info(files, options);
                            files = files->next;
                        }
                        if (!options.l) ft_putchar_fd('\n', STDOUT_FILENO);
                        free_file_list(files);
                    }
                } else {
                    // Argument is a file, not a directory
                    t_file *file = create_file_node(argv[i], &path_stat);
                    print_file_info(file, options);
                    if (!options.l) ft_putchar_fd('\n', STDOUT_FILENO);
                    free(file);
                }
            } else {
                perror(argv[i]);
            }
        }
    }

    return 0;
}
