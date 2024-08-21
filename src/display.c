#include "../includes/ft_ls.h"


// Calculate the length of a number
int number_length(long long n) {
    int len = 0;
    if (n == 0)
        return 1;
    while (n) {
        n /= 10;
        len++;
    }
    return len;
}

void print_total_blocks(t_file *file_list) {
    int total_blocks = 0;

    while (file_list) {
        total_blocks += file_list->stats.st_blocks;
        file_list = file_list->next;
    }
    total_blocks /= 2;

    ft_putstr_fd("total ", 1);
    ft_putnbr_fd(total_blocks, 1);
    ft_putchar_fd('\n', 1);
}

void print_permissions(struct stat stats) {
    ft_putchar_fd((S_ISDIR(stats.st_mode)) ? 'd' : '-', 1);
    ft_putchar_fd((stats.st_mode & S_IRUSR) ? 'r' : '-', 1);
    ft_putchar_fd((stats.st_mode & S_IWUSR) ? 'w' : '-', 1);
    ft_putchar_fd((stats.st_mode & S_IXUSR) ? 'x' : '-', 1);
    ft_putchar_fd((stats.st_mode & S_IRGRP) ? 'r' : '-', 1);
    ft_putchar_fd((stats.st_mode & S_IWGRP) ? 'w' : '-', 1);
    ft_putchar_fd((stats.st_mode & S_IXGRP) ? 'x' : '-', 1);
    ft_putchar_fd((stats.st_mode & S_IROTH) ? 'r' : '-', 1);
    ft_putchar_fd((stats.st_mode & S_IWOTH) ? 'w' : '-', 1);
    ft_putchar_fd((stats.st_mode & S_IXOTH) ? 'x' : '-', 1);
}

// Main function to print file info with correct alignment
void print_file_info(t_file *file, t_options options) {
    if (options.l) {
        print_permissions(file->stats);
        ft_putchar_fd(' ', 1);

        // Determines maximum width for the number fields
        int link_padding = 2 - number_length(file->stats.st_nlink);
        int size_padding = 5 - number_length((long long)file->stats.st_size);

        while (link_padding-- > 0) ft_putchar_fd(' ', 1);
        ft_putnbr_fd(file->stats.st_nlink, 1);

        struct passwd *pw = getpwuid(file->stats.st_uid);
        struct group *gr = getgrgid(file->stats.st_gid);

        ft_putchar_fd(' ', 1);
        ft_putstr_fd(pw->pw_name, 1);
        ft_putchar_fd(' ', 1);
        ft_putstr_fd(gr->gr_name, 1);

        // Right-align and print the file size
        while (size_padding-- > 0) ft_putchar_fd(' ', 1);
        ft_putnbr_fd((long long)file->stats.st_size, 1);

        ft_putchar_fd(' ', 1);

        char *time_str = ctime(&file->stats.st_mtime);
        time_str[16] = '\0';  // Cut off the year and seconds
        ft_putstr_fd(time_str + 4, 1);

        ft_putchar_fd(' ', 1);
        ft_putstr_fd(file->name, 1);
        ft_putchar_fd('\n', 1);
    } else {
        ft_putstr_fd(file->name, 1);
        ft_putstr_fd("  ", 1);  // Use two spaces for separation
    }
}
