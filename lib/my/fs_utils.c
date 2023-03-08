/*
** EPITECH PROJECT, 2023
** giantman
** File description:
** fs_utils
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "my.h"

int get_file_size(char *filepath)
{
    struct stat st;

    if (stat(filepath, &st) == -1) return (-1);
    return (st.st_size);
}

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) return (NULL);
    int size = get_file_size(filepath);
    if (size == -1) return (NULL);

    char *buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL) return (NULL);
    if (read(fd, buffer, size) == -1) return (NULL);

    return (buffer);
}
