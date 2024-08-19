
#include "../includes/ft_ls.h"

int strcmp_lower(char* name_a, char* name_b)
{
    int length = strlen(name_a);
    char c_a[length + 1];

    for (int i = 0; i < length; i++)
    {
        if (name_a[i] <= 'Z' || name_a[i] >= 'A')
            c_a[i] = tolower((char)name_a[i]);
    }
    c_a[length] = '\0';

    length = strlen(name_b);
    char c_b[length + 1];
    for (int i = 0; i < length; i++) {
        if (name_b[i] <= 'Z' || name_b[i] >= 'A')
            c_b[i] = tolower((char)name_b[i]);
    }
    c_b[length] = '\0';

    return strcmp(c_a, c_b);
}

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
                // Sort by time if -t is specified
                cmp = j->stats.st_mtime - i->stats.st_mtime;
            } else {
                // Default: Sort alphabetically
                cmp = strcmp_lower(i->name, j->name);
            }

            // Reverse the sorting if -r is specified
            if (options.r)
                cmp = -cmp;

            if (cmp > 0)
                swap_files(i, j);
        }
    }
}
