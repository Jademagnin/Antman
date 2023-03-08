/*
** EPITECH PROJECT, 2023
** giantman
** File description:
** buffer_op
*/

#include "giantman.h"

void init_buffer(char buffer[], int size)
{
    for (int i = 0; i < size; i++) buffer[i] = ' ';
}

void write_char(char c, char buffer[])
{
    static int r = BUFF_SIZE - LAHD_SIZE;
    write(1, &c, 1);
    buffer[r++] = c;
    r &= (BUFF_SIZE - 1);
}

void write_literal(lzss_t *lzss, char buffer[])
{
    int c = getbit(lzss, 8);
    if (c == EOF) return;

    write_char(c, buffer);
}

void write_offset(lzss_t *lzss, char buffer[])
{
    int i = getbit(lzss, MAX_INDEX_SIZE);
    if (i == EOF) return;
    int j = getbit(lzss, MAX_OFFSET_SIZE);
    if (j == EOF) return;

    for (int k = 0; k <= j + 1; k++) {
        int c = buffer[(i + k) & (BUFF_SIZE - 1)];
        write_char(c, buffer);
    }
}
