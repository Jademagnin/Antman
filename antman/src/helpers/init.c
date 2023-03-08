/*
** EPITECH PROJECT, 2023
** antman
** File description:
** init
*/

#include "antman.h"

lzss_t *init_lzss(char *input_file)
{
    lzss_t *lzss = malloc(sizeof(lzss_t));
    if (lzss == NULL) return (NULL);
    lzss->bit_buffer = 0;
    lzss->bit_mask = 128;
    lzss->codecount = 0;
    lzss->textcount = 0;
    lzss->input_index = 0;
    lzss->input_data = read_file(input_file);
    if (lzss->input_data == NULL) return (NULL);
    int input_size = get_file_size(input_file);
    if (input_size == -1) return (NULL);
    lzss->input_size = input_size;
    return (lzss);
}

encode_data_t *init_encode_data(void)
{
    encode_data_t *encode_data = malloc(sizeof(encode_data_t));
    if (encode_data == NULL) return (NULL);
    encode_data->char_i = 0;
    encode_data->match_offset = 0;
    encode_data->search_range = 0;
    encode_data->match_length = 0;
    encode_data->match_index = 0;
    encode_data->buff_index = 0;
    encode_data->buff_start = 0;
    encode_data->buff_end = 0;
    encode_data->curr_char = 0;
    return (encode_data);
}
