#include "../includes/ft_ls.h"

void display_usage(char *prog_name) {
    char *usage_message = "Usage: ";
    char *options_message = " [-lRart] [file ...]\n";
    
    ft_putstr_fd(usage_message, STDERR_FILENO);
    ft_putstr_fd(prog_name, STDERR_FILENO);
    ft_putstr_fd(options_message, STDERR_FILENO);
}

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

    ft_putstr_fd("total ", STDOUT_FILENO);
    ft_putnbr_fd(total_blocks, STDOUT_FILENO);
    ft_putchar_fd('\n', STDOUT_FILENO);
}

void print_permissions(struct stat stats) {
    ft_putchar_fd((S_ISDIR(stats.st_mode)) ? 'd' : '-', STDOUT_FILENO);
    ft_putchar_fd((stats.st_mode & S_IRUSR) ? 'r' : '-', STDOUT_FILENO);
    ft_putchar_fd((stats.st_mode & S_IWUSR) ? 'w' : '-', STDOUT_FILENO);
    ft_putchar_fd((stats.st_mode & S_IXUSR) ? 'x' : '-', STDOUT_FILENO);
    ft_putchar_fd((stats.st_mode & S_IRGRP) ? 'r' : '-', STDOUT_FILENO);
    ft_putchar_fd((stats.st_mode & S_IWGRP) ? 'w' : '-', STDOUT_FILENO);
    ft_putchar_fd((stats.st_mode & S_IXGRP) ? 'x' : '-', STDOUT_FILENO);
    ft_putchar_fd((stats.st_mode & S_IROTH) ? 'r' : '-', STDOUT_FILENO);
    ft_putchar_fd((stats.st_mode & S_IWOTH) ? 'w' : '-', STDOUT_FILENO);
    ft_putchar_fd((stats.st_mode & S_IXOTH) ? 'x' : '-', STDOUT_FILENO);
}

// print file info with correct alignment
void print_file_info(t_file *file, t_options options) {
    if (options.l) {
        print_permissions(file->stats);
        ft_putchar_fd(' ', STDOUT_FILENO);

        // Determines maximum width for the number fields
        int link_padding = 2 - number_length(file->stats.st_nlink);
        int size_padding = 7 - number_length((long long)file->stats.st_size);

        while (link_padding-- > 0) ft_putchar_fd(' ', STDOUT_FILENO);
        ft_putnbr_fd(file->stats.st_nlink, STDOUT_FILENO);

        struct passwd *pw = getpwuid(file->stats.st_uid);
        struct group *gr = getgrgid(file->stats.st_gid);

        ft_putchar_fd(' ', STDOUT_FILENO);
        ft_putstr_fd(pw->pw_name, STDOUT_FILENO);
        ft_putchar_fd(' ', STDOUT_FILENO);
        ft_putstr_fd(gr->gr_name, STDOUT_FILENO);

        // Right-align and print the file size
        while (size_padding-- > 0) ft_putchar_fd(' ', STDOUT_FILENO);
        ft_putnbr_fd((long long)file->stats.st_size, STDOUT_FILENO);

        ft_putchar_fd(' ', STDOUT_FILENO);

        char *time_str = ctime(&file->stats.st_mtime);
        time_str[16] = '\0';  // Cut off the year and seconds
        ft_putstr_fd(time_str + 4, STDOUT_FILENO);

        ft_putchar_fd(' ', STDOUT_FILENO);
        ft_putstr_fd(file->name, STDOUT_FILENO);
        ft_putchar_fd('\n', STDOUT_FILENO);
    } else {
        ft_putstr_fd(file->name, STDOUT_FILENO);
        ft_putstr_fd("  ", STDOUT_FILENO);  // Use two spaces for separation
    }
}
