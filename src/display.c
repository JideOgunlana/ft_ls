#include "../includes/ft_ls.h"

// Helper functions to write a string or a character
void ft_putstr(const char *str) {
    write(1, str, strlen(str));
}

void ft_putchar(char c) {
    write(1, &c, 1);
}

// Convert integer to string and return its length
int ft_putnbr(long long n) {
    char buffer[20];
    int i = 19;
    int len = 0;
    int negative = n < 0;

    if (negative)
        n = -n;

    buffer[i--] = '\0';
    if (n == 0) {
        buffer[i--] = '0';
        len++;
    }

    while (n > 0) {
        buffer[i--] = (n % 10) + '0';
        n /= 10;
        len++;
    }

    if (negative) {
        buffer[i--] = '-';
        len++;
    }

    ft_putstr(&buffer[i + 1]);
    return len;
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

    ft_putstr("total ");
    ft_putnbr(total_blocks);
    ft_putchar('\n');
}

void print_permissions(struct stat stats) {
    ft_putchar((S_ISDIR(stats.st_mode)) ? 'd' : '-');
    ft_putchar((stats.st_mode & S_IRUSR) ? 'r' : '-');
    ft_putchar((stats.st_mode & S_IWUSR) ? 'w' : '-');
    ft_putchar((stats.st_mode & S_IXUSR) ? 'x' : '-');
    ft_putchar((stats.st_mode & S_IRGRP) ? 'r' : '-');
    ft_putchar((stats.st_mode & S_IWGRP) ? 'w' : '-');
    ft_putchar((stats.st_mode & S_IXGRP) ? 'x' : '-');
    ft_putchar((stats.st_mode & S_IROTH) ? 'r' : '-');
    ft_putchar((stats.st_mode & S_IWOTH) ? 'w' : '-');
    ft_putchar((stats.st_mode & S_IXOTH) ? 'x' : '-');
}

// Main function to print file info with correct alignment
void print_file_info(t_file *file, t_options options) {
    if (options.l) {
        print_permissions(file->stats);
        ft_putchar(' ');

        // Determines maximum width for the number fields
        int link_padding = 2 - number_length(file->stats.st_nlink);
        int size_padding = 5 - number_length((long long)file->stats.st_size);

        while (link_padding-- > 0) ft_putchar(' ');
        ft_putnbr(file->stats.st_nlink);

        struct passwd *pw = getpwuid(file->stats.st_uid);
        struct group *gr = getgrgid(file->stats.st_gid);

        ft_putchar(' ');
        ft_putstr(pw->pw_name);
        ft_putchar(' ');
        ft_putstr(gr->gr_name);

        // Right-align and print the file size
        while (size_padding-- > 0) ft_putchar(' ');
        ft_putnbr((long long)file->stats.st_size);

        ft_putchar(' ');

        char *time_str = ctime(&file->stats.st_mtime);
        time_str[16] = '\0';  // Cut off the year and seconds
        ft_putstr(time_str + 4);

        ft_putchar(' ');
        ft_putstr(file->name);
        ft_putchar('\n');
    } else {
        ft_putstr(file->name);
        ft_putstr("  ");  // Use two spaces for separation
    }
}
