
#include "../includes/ft_ls.h"

void build_fullpath(char *dest, const char *path, const char *filename) {
    // Clear the destination buffer
    ft_memset(dest, 0, 1024);

    size_t path_len = strlen(path);
    ft_memcpy(dest, path, path_len);

    if (path[path_len - 1] != '/') {
        dest[path_len] = '/';
        path_len++;
    }

    // Append the filename to the destination
    // size_t dest_size = sizeof(dest) + sizeof(path_len);
    ft_strcpy(dest + path_len, filename);
}

t_file *create_file_node(const char *name, struct stat *stats) {
    t_file *new_file = (t_file *)malloc(sizeof(t_file));
    if (!new_file)
        return NULL;
    new_file->name = ft_strdup(name);
    if (!new_file->name)
        return NULL;
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

        build_fullpath(fullpath, path, entry->d_name);
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

    // printf("Before free list\n");
    while (file_list) {
        tmp = file_list;
        file_list = file_list->next;
        // printf("In free list: %s", tmp->name);
        free(tmp->name);
        free(tmp);
    }
    free(file_list);
    // printf("After free list\n");

}
