/*
** EPITECH PROJECT, 2023
** antman
** File description:
** bit_io
*/

#include "antman.h"

void flush_bit_buffer(lzss_t *lzss)
{
    if (lzss->bit_mask != 128) {
        write(1, &lzss->bit_buffer, 1);
        lzss->codecount++;
    }
}

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

void write_bit(lzss_t *lzss, int bit)
{
    if (bit == 1) lzss->bit_buffer |= lzss->bit_mask;
    if ((lzss->bit_mask >>= 1) == 0) {
        write(1, &lzss->bit_buffer, 1);
        lzss->bit_buffer = 0;
        lzss->bit_mask = 128;
        lzss->codecount++;
    }
}

void write_output(lzss_t *lzss, encode_data_t *data)
{
    int mask;
    if (data->match_index <= MAX_LITERAL_SIZE) {
        mask = 256;
        write_bit(lzss, 1);
        while (mask >>= 1) write_bit(lzss, (data->curr_char & mask) ? 1 : 0);
    } else {
        mask = BUFF_SIZE;
        int x = data->match_length & (BUFF_SIZE - 1);
        int y = data->match_index - 2;
        write_bit(lzss, 0);
        while (mask >>= 1) write_bit(lzss, (x & mask) ? 1 : 0);
        mask = (1 << MAX_OFFSET_SIZE);
        while (mask >>= 1) write_bit(lzss, (y & mask) ? 1 : 0);
    }
}
