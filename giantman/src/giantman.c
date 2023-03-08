/*
** EPITECH PROJECT, 2023
** antman
** File description:
** giantman
*/

#include "giantman.h"

int giantman(char *file_name)
{
    lzss_t *lzss = init_lzss(file_name);
    if (lzss == NULL) return (84);
    decode(lzss);
    return (0);
}
