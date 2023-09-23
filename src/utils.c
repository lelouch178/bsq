/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** utils functions used for this project
*/

#include "../include/bsq.h"

void place_square_and_print(bsq_t *bsq, int coords[3])
{
    for (int i = 0; i < coords[2]; i++)
        for (int j = 0; j < coords[2]; j++)
            bsq->arr[coords[0] - i][coords[1] - j] = 'x';
    for (int i = 0; i < bsq->rows; i++) {
        write(1, bsq->arr[i], bsq->cols);
        write(1, "\n", 1);
    }
}

void my_write(char const *str, bool flag)
{
    for (unsigned int i = 0 ; str[i]; i++) {
        if (flag == true )
            write(1, &(str[i]), 1);
        else
            write(2, &(str[i]), 1);
    }
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return (0);
    }
    return (1);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (*str != '\0') {
        i++;
        str++;
    }
    return (i);
}

void free_bsq(bsq_t *bsq)
{
    for (int i = 0; i < bsq->rows; i++)
        free(bsq->arr[i]);
    for (int i = 0; i < bsq->rows; i++)
        free(bsq->tmp[i]);
    free(bsq->arr);
    free(bsq->tmp);
    close(bsq->fd);
    free(bsq);
}
