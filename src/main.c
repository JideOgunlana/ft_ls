
#include "../includes/ft_ls.h"

int main(int argc, char **argv) {
    t_options options = {0, 0, 0, 0, 0};
    parse_options(argc, argv, &options);

    if (optind >= argc) {
        // No directory specified, list current directory
        t_file *files = list_directory(".", options);
        sort_files(&files, options);
        while (files) {
            print_file_info(files, options);
            files = files->next;
        }
        free_file_list(files);
    } else {
        // List directories specified in arguments
        for (int i = optind; i < argc; i++) {
            t_file *files = list_directory(argv[i], options);
            sort_files(&files, options);
            while (files) {
                print_file_info(files, options);
                files = files->next;
            }
            free_file_list(files);
        }
    }

    return 0;
}
