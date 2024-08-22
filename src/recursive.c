#include "../includes/ft_ls.h"

void recursive_traversal(const char *path, t_options options) {
    t_file *files = list_directory(path, options);
    if (!files) {
        return;
    }

    sort_files(&files, options);

    t_file *current = files;

    if (options.l) {
        print_total_blocks(current);
    }
    while (current) {
        print_file_info(current, options);
        current = current->next;
    }

    // Reset pointer to head for recursion
    current = files;

    while (current) {
        if (options.R && S_ISDIR(current->stats.st_mode) &&
            ft_strncmp(current->name, ".", ft_strlen(current->name)) != 0 &&
            ft_strncmp(current->name, "..", ft_strlen(current->name)) != 0) {

            if (!options.l)
                ft_putchar_fd('\n', STDOUT_FILENO);

            char new_path[1024];
            build_fullpath(new_path, path, current->name);
            ft_putchar_fd('\n', STDOUT_FILENO);
            ft_putstr_fd(new_path, STDOUT_FILENO);
            ft_putchar_fd(':', STDOUT_FILENO);
            ft_putchar_fd('\n', STDOUT_FILENO);

            // Recursive call to list subdirectory
            recursive_traversal(new_path, options);
        }
        current = current->next;
    }

    free_file_list(files);
}
