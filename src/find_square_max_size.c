/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** Functions to find the biggest square in the file BSQ
*/

#include "../include/bsq.h"

int min(int x, int y, int z)
{
    int start = x;

    if (start > y)
        start = y;
    if (start > z)
        start = z;
    return start;
}

int get_pos(int coords[3], int i, int j, int **tmp)
{
    if (coords[2] < tmp[i][j]) {
        coords[2] = tmp[i][j];
        coords[0] = i;
        coords[1] = j;
    }
    return coords[2];
}

void find_biggest_square(bsq_t *bsq, int coords[3])
{
    for (int i = 1; i < bsq->rows; i++) {
        for (int j = 1; j < bsq->cols; j++) {
            bsq->tmp[i][j] = (bsq->tmp[i][j] == 1 ? min(bsq->tmp[i][j - 1],
            bsq->tmp[i - 1][j], bsq->tmp[i - 1][j - 1]) + 1 : 0);
        }
    }
    coords[2] = bsq->tmp[0][0];
    for (int i = 0; i < bsq->rows; i++) {
        for (int j = 0; j < bsq->cols; j++) {
            get_pos(coords, i, j, bsq->tmp);
        }
    }
}
