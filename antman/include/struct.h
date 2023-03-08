/*
** EPITECH PROJECT, 2023
** antman
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #define MAX_INDEX_SIZE 11
    #define MAX_OFFSET_SIZE 4
    #define MAX_LITERAL_SIZE 1
    #define BUFF_SIZE (1 << MAX_INDEX_SIZE)
    #define LAHD_SIZE ((1 << MAX_OFFSET_SIZE) + MAX_LITERAL_SIZE)
    #define EOF (-1)

typedef struct lzss {
    int bit_buffer;
    int bit_mask;
    unsigned long codecount;
    unsigned long textcount;
    unsigned long input_size;
    unsigned long input_index;
    unsigned char buffer[BUFF_SIZE * 2];
    char *input_data;
} lzss_t;

typedef struct encode_data {
    int char_i;
    int match_offset;
    int search_range;
    int match_length;
    int match_index;
    int buff_index;
    int buff_start;
    int buff_end;
    int curr_char;
} encode_data_t;

#endif /* !STRUCT_H_ */
