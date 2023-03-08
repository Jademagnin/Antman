/*
** EPITECH PROJECT, 2023
** antman
** File description:
** antman
*/

#include "antman.h"

int antman(char *file_name)
{
    lzss_t *lzss = init_lzss(file_name);
    if (lzss == NULL) return (84);
    return (encode(lzss));
}
