
#ifndef FT_LS_H
#define FT_LS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "./libft.h"


typedef struct s_file {
    char *name;
    struct stat stats;
    struct s_file *next;
} t_file;

typedef struct s_options {
    int l;
    int R;
    int a;
    int r;
    int t;
    int optind;
    char *optarg;
} t_options;

// Function prototypes
t_file *list_directory(const char *path, t_options options);
t_file *create_file_node(const char *name, struct stat *stats);
void parse_options(int argc, char **argv, t_options *options);
void print_file_info(t_file *file, t_options options);
void sort_files(t_file **file_list, t_options options);
void recursive_traversal(const char *path, t_options options);
void free_file_list(t_file *file_list);
void print_total_blocks(t_file *file_list);
void build_fullpath(char *dest, const char *path, const char *filename);
void display_usage(char *prog_name);

#endif
