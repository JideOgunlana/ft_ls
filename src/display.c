
#include "ft_ls.h"

void print_permissions(struct stat stats) {
    printf( (S_ISDIR(stats.st_mode)) ? "d" : "-");
    printf( (stats.st_mode & S_IRUSR) ? "r" : "-");
    printf( (stats.st_mode & S_IWUSR) ? "w" : "-");
    printf( (stats.st_mode & S_IXUSR) ? "x" : "-");
    printf( (stats.st_mode & S_IRGRP) ? "r" : "-");
    printf( (stats.st_mode & S_IWGRP) ? "w" : "-");
    printf( (stats.st_mode & S_IXGRP) ? "x" : "-");
    printf( (stats.st_mode & S_IROTH) ? "r" : "-");
    printf( (stats.st_mode & S_IWOTH) ? "w" : "-");
    printf( (stats.st_mode & S_IXOTH) ? "x" : "-");
}

void print_file_info(t_file *file, t_options options) {
    if (options.l) {
        print_permissions(file->stats);
        printf(" %ld", file->stats.st_nlink);

        struct passwd *pw = getpwuid(file->stats.st_uid);
        struct group *gr = getgrgid(file->stats.st_gid);
        printf(" %s %s", pw->pw_name, gr->gr_name);
        printf(" %5lld", (long long)file->stats.st_size);

        char *time_str = ctime(&file->stats.st_mtime);
        time_str[16] = '\0'; // Format time
        printf(" %s", time_str + 4); // Print time after month

        printf(" %s\n", file->name);
    } else {
        printf("%s\n", file->name);
    }
}
