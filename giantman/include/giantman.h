/*
** EPITECH PROJECT, 2023
** giantman
** File description:
** giantman
*/

#ifndef GIANTMAN_H_
    #define GIANTMAN_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include "struct.h"
    #include "my.h"

int giantman(char *file_name);
void decode(lzss_t *lzss);
int check_args_validity(int ac, char **av);
int getbit(lzss_t *lzss, int n);
lzss_t *init_lzss(char *input_file);
void init_buffer(char buffer[], int size);
void write_offset(lzss_t *lzss, char buffer[]);
void write_literal(lzss_t *lzss, char buffer[]);

#endif /* !GIANTMAN_H_ */
