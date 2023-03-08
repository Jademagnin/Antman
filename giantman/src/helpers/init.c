/*
** EPITECH PROJECT, 2023
** giantman
** File description:
** init
*/

#include "giantman.h"

lzss_t *init_lzss(char *input_file)
{
    lzss_t *lzss = malloc(sizeof(lzss_t));
    if (lzss == NULL) return (NULL);
    lzss->textcount = 0;
    lzss->input_index = 0;
    lzss->input_data = read_file(input_file);
    if (lzss->input_data == NULL) return (NULL);
    int input_size = get_file_size(input_file);
    if (input_size == -1) return (NULL);
    lzss->input_size = input_size;
    return (lzss);
}
