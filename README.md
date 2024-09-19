# ft_ls
Writing the UNIX ls command in C with options "-t, -l, -r, -a and -R"

#### Valgrind `cmd` to test for leaks
```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose path/to/ft_ls
```