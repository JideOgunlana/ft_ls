
#include "ft_ls.h"

void recursive_traversal(const char *path, t_options options) {
    t_file *files = list_directory(path, options);
    sort_files(&files, options);

    while (files) {
        print_file_info(files, options);
        if (options.R && S_ISDIR(files->stats.st_mode) && 
            strcmp(files->name, ".") != 0 && strcmp(files->name, "..") != 0) {

            char new_path[1024];
            snprintf(new_path, sizeof(new_path), "%s/%s", path, files->name);
            printf("\n%s:\n", new_path);
            recursive_traversal(new_path, options);
        }
        files = files->next;
    }

    free_file_list(files);
}
