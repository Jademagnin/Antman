/*
** EPITECH PROJECT, 2023
** giantman
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
    unsigned long textcount;
    unsigned char buffer[BUFF_SIZE * 2];
    unsigned long input_index;
    unsigned long input_size;
    char *input_data;
} lzss_t;

#endif /* !STRUCT_H_ */
