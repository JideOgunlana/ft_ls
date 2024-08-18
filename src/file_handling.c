
#include "ft_ls.h"

t_file *create_file_node(const char *name, struct stat *stats) {
    t_file *new_file = (t_file *)malloc(sizeof(t_file));
    if (!new_file)
        return NULL;
    new_file->name = strdup(name);
    new_file->stats = *stats;
    new_file->next = NULL;
    return new_file;
}

t_file *list_directory(const char *path, t_options options) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return NULL;
    }

    struct dirent *entry;
    t_file *file_list = NULL;
    t_file *last = NULL;

    while ((entry = readdir(dir)) != NULL) {
        if (!options.a && entry->d_name[0] == '.')
            continue;

        struct stat file_stats;
        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (lstat(fullpath, &file_stats) == -1) {
            perror("lstat");
            continue;
        }

        t_file *new_file = create_file_node(entry->d_name, &file_stats);
        if (!new_file)
            continue;

        if (!file_list)
            file_list = new_file;
        else
            last->next = new_file;

        last = new_file;
    }

    closedir(dir);
    return file_list;
}

void free_file_list(t_file *file_list) {
    t_file *tmp;
    while (file_list) {
        tmp = file_list;
        file_list = file_list->next;
        free(tmp->name);
        free(tmp);
    }
}
