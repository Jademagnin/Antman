/*
** EPITECH PROJECT, 2023
** giantman
** File description:
** bit_io
*/

#include "giantman.h"

int getbit(lzss_t *lzss, int n)
{
    static int buf = 0, mask = 0;
    int x = 0;

    for (int i = 0; i < n; i++) {
        if (mask == 0 && lzss->textcount > lzss->input_size) return EOF;
        if (mask == 0) {
            buf = lzss->input_data[lzss->textcount++];
            mask = 128;
        }
        x <<= 1;
        x += (buf & mask) != 0;
        mask >>= 1;
    }
    return (x);
}
