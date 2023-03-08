/*
** EPITECH PROJECT, 2023
** antman
** File description:
** error
*/

#include "antman.h"

int is_file_exist(const char *file)
{
    struct stat buffer;
    if (stat(file, &buffer) != 0) {
        write(2, "Error: file not found.\n", 23);
        return (84);
    }
    if (S_ISDIR(buffer.st_mode)) {
        write(2, "Error: file type is expected, not directory.\n", 45);
        return (84);
    }
    return (0);
}

int check_file_type(short type)
{
    if (type < 1 || type > 3) {
        write(2, "Error: invalid file type\n", 25);
        return (84);
    }
    return (0);
}

int check_args_validity(int ac, char **av)
{
    if (ac != 3) {
        write(2, "Invalid number of arguments.\n", 29);
        return (84);
    }

    if (is_file_exist(av[1]) == 84) return (84);
    if (check_file_type(my_atoi(av[2])) == 84) return (84);
    return (0);
}
