/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** include file for this project
*/

#ifndef BSBSQ_H_
    #define BSBSQ_H_

// =============================== [INCLUDES] =============================== //

    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <stdbool.h>

// =============================== [DEFINES] ================================ //

    #define ABS(value) ((value) < 0) ? - (value) : (value)

// ============================== [STRUCTURES] ============================== //

    typedef struct load_file_t_s {
        int line1_size;
        char *dump;
        char **arr;
    } load_file_t;

    typedef struct bsq_s {
        char **arr;
        int **tmp;
        int rows;
        int cols;
        int fd;
        load_file_t *file;
    } bsq_t;

// ============================= [DECLARATIONS] ============================= //

    int bsq(char const *filepath);
    int bsq_generator(char **av);
    int get_rows(int fd);
    int get_cols(int fd);
    int **array_to_binary(bsq_t *bsq);
    char **load_2d_arr_from_file(bsq_t *bsq, char const *filepath);
    void find_biggest_square(bsq_t *bsq, int coords[3]);
    void place_square_and_print(bsq_t *bsq, int coords[3]);
    int error_from_line(char *tmp);
    int error_case(char const *filepath);
    int error_from_generation(char **av);

    // utils.c
    void my_write(char const *str, bool flag);
    int my_str_isnum(char const *str);
    int my_strlen(char const *str);
    int my_getnbr(char const *str);
    void free_bsq(bsq_t *bsq);

// ========================================================================== //
#endif
