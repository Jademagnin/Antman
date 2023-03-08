/*
** EPITECH PROJECT, 2023
** giantman
** File description:
** main
*/

#include "giantman.h"

int help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./giantman file file_type\n", 26);
    write(1, "DESCRIPTION\n", 12);
    write(1, "\tfile:\n", 7);
    write(1, "\t\tfile to decompress\n", 21);
    write(1, "\tfile_type:\n", 12);
    write(1, "\t\t1 for text file\n", 18);
    write(1, "\t\t2 for HTML file\n", 18);
    write(1, "\t\t3 for P3 PPM file\n", 20);
    return (0);
}

int main(int ac, char **av)
{
    if (ac > 1 && my_strcmp(av[1], "-h") == 0) return (help());
    if (ac != 3) {
        write(2, "Invalid number of arguments.\n", 29);
        return (84);
    }
    if (check_args_validity(ac, av) == 84) return (84);

    char *file_name = av[1];
    return (giantman(file_name));
}
