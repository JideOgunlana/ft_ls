
#include "../includes/ft_ls.h"

int main(int argc, char **argv) {
    t_options options = {0, 0, 0, 0, 0};
    parse_options(argc, argv, &options);

    if (optind >= argc) {
        // No directory specified, list current directory
        if (options.R) {
            recursive_traversal(".", options);
        } else {
            t_file *files = list_directory(".", options);
            sort_files(&files, options);

            // Print total blocks if -l option is used
            if (options.l) {
                print_total_blocks(files);
            }

            while (files) {
                print_file_info(files, options);
                files = files->next;
            }
            if (!options.l) printf("\n");  // Print new line if -l is not used
            free_file_list(files);
        }
    } else {
        // List directories specified in arguments
        for (int i = optind; i < argc; i++) {
            if (options.R) {
                recursive_traversal(argv[i], options);
            } else {
                t_file *files = list_directory(argv[i], options);
                sort_files(&files, options);

                // Print total blocks if -l option is used
                if (options.l) {
                    print_total_blocks(files);
                }

                while (files) {
                    print_file_info(files, options);
                    files = files->next;
                }
                if (!options.l) printf("\n");  // Print new line if -l is not used
                free_file_list(files);
            }
        }
    }

    return 0;
}

