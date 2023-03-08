/*
** EPITECH PROJECT, 2023
** antman
** File description:
** antman
*/

#ifndef ANTMAN_H_
    #define ANTMAN_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include "struct.h"
    #include "my.h"

int antman(char *file_name);
int encode(lzss_t *lzss);
lzss_t *init_lzss(char *input_file);
encode_data_t *init_encode_data(void);
int getbit(lzss_t *lzss, int n);
void flush_bit_buffer(lzss_t *lzss);
void write_bit(lzss_t *lzss, int bit);
void write_bits(lzss_t *lzss, int value, int num_bits);
void write_output(lzss_t *lzss, encode_data_t *data);
void init_buffer(lzss_t *lzss, encode_data_t *data);
void shift_buffer_left(lzss_t *lzss, encode_data_t *data);
void shift_buffer(lzss_t *lzss, encode_data_t *data);
int check_args_validity(int ac, char **av);

#endif /* !ANTMAN_H_ */
