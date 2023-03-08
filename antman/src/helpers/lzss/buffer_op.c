/*
** EPITECH PROJECT, 2023
** antman
** File description:
** buffer operations
*/

#include "antman.h"

void init_buffer(lzss_t *lzss, encode_data_t *data)
{
    for (data->char_i = 0; data->char_i < BUFF_SIZE - LAHD_SIZE; data->char_i++)
        lzss->buffer[data->char_i] = ' ';
    for (data->char_i = BUFF_SIZE - LAHD_SIZE; data->char_i < BUFF_SIZE * 2;
        data->char_i++) {
        if (lzss->input_data[lzss->textcount] == '\0')
            break;
        lzss->buffer[data->char_i] = lzss->input_data[lzss->textcount];
        lzss->textcount++;
    }
    data->buff_end = data->char_i;
    data->buff_index = BUFF_SIZE - LAHD_SIZE;
    data->buff_start = 0;
}

void shift_buffer_left(lzss_t *lzss, encode_data_t *data)
{
    for (data->char_i = 0; data->char_i < BUFF_SIZE; data->char_i++)
        lzss->buffer[data->char_i] = lzss->buffer[data->char_i + BUFF_SIZE];
    data->buff_end -= BUFF_SIZE;
    data->buff_index -= BUFF_SIZE;
    data->buff_start -= BUFF_SIZE;
}

void shift_buffer(lzss_t *lzss, encode_data_t *data)
{
    data->buff_index += data->match_index;
    data->buff_start += data->match_index;
    if (data->buff_index < BUFF_SIZE * 2 - LAHD_SIZE) return;

    shift_buffer_left(lzss, data);
    while (data->buff_end < BUFF_SIZE * 2) {
        if (lzss->input_data[lzss->textcount] == '\0') break;
        lzss->buffer[data->buff_end++] = lzss->input_data[lzss->textcount];
        lzss->textcount++;
    }
}
