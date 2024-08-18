
#include "ft_ls.h"

void swap_files(t_file *a, t_file *b) {
    char *temp_name = a->name;
    struct stat temp_stats = a->stats;

    a->name = b->name;
    a->stats = b->stats;

    b->name = temp_name;
    b->stats = temp_stats;
}

void sort_files(t_file **file_list, t_options options) {
    if (!*file_list)
        return;

    t_file *i, *j;

    for (i = *file_list; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            int cmp = 0;

            if (options.t) {
                cmp = j->stats.st_mtime - i->stats.st_mtime;
            } else {
                cmp = strcmp(i->name, j->name);
            }

            if (options.r)
                cmp = -cmp;

            if (cmp > 0)
                swap_files(i, j);
        }
    }
}
