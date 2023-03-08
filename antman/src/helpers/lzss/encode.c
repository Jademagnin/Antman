/*
** EPITECH PROJECT, 2023
** antman
** File description:
** encode
*/

#include "antman.h"

void find_match_length(lzss_t *lzss, encode_data_t *data)
{
    data->match_offset = 1;
    while (data->match_offset < data->search_range) {
        if (lzss->buffer[data->char_i + data->match_offset] !=
            lzss->buffer[data->buff_index + data->match_offset])
            break;
        data->match_offset++;
    }
    if (data->match_offset > data->match_index) {
        data->match_length = data->char_i;
        data->match_index = data->match_offset;
    }
}

void find_longest_match(lzss_t *lzss, encode_data_t *data)
{
    data->search_range = (LAHD_SIZE <= data->buff_end - data->buff_index)
                            ? LAHD_SIZE
                            : data->buff_end - data->buff_index;
    data->match_length = 0;
    data->match_index = 1;
    data->curr_char = lzss->buffer[data->buff_index];
    for (data->char_i = data->buff_index - 1; data->char_i >= data->buff_start;
        data->char_i--) {
        if (lzss->buffer[data->char_i] != data->curr_char) continue;
        find_match_length(lzss, data);
    }
}

int encode(lzss_t *lzss)
{
    encode_data_t *data = init_encode_data();
    if (data == NULL) return (84);

    init_buffer(lzss, data);
    while (data->buff_index < data->buff_end) {
        find_longest_match(lzss, data);
        write_output(lzss, data);
        shift_buffer(lzss, data);
    }
    flush_bit_buffer(lzss);
    return (0);
}
