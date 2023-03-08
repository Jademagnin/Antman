/*
** EPITECH PROJECT, 2023
** giantman
** File description:
** decode
*/

#include "giantman.h"

void decode(lzss_t *lzss)
{
    int c = getbit(lzss, 1);
    char buffer[BUFF_SIZE];
    init_buffer(buffer, BUFF_SIZE - LAHD_SIZE);
    while (c != EOF) {
        if (c) {
            write_literal(lzss, buffer);
        } else {
            write_offset(lzss, buffer);
        }
        c = getbit(lzss, 1);
    }
}
