/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** Load a 2d array from a file.
** Convert an array into a binary array.
*/

#include "../include/bsq.h"

int get_size_of_first_line(char const* filepath)
{
    int fd_first_line = open(filepath, O_RDONLY);
    char *first_line;
    int len_firstline = 1;
    struct stat sb;

    stat(filepath, &sb);
    first_line = malloc(sb.st_size);
    read(fd_first_line, first_line, sb.st_size);
    len_firstline = 1;
    for (int i = 0; first_line[i] != '\n'; i++)
        len_firstline++;
    close(fd_first_line);
    free(first_line);
    return len_firstline;
}

load_file_t *init_file(const char *filepath, bsq_t *bsq)
{
    load_file_t *new_file = malloc(sizeof(load_file_t));

    new_file->line1_size = get_size_of_first_line(filepath);
    new_file->dump = malloc(sizeof(char *) * new_file->line1_size);
    new_file->arr = malloc(sizeof(char *) * (bsq->rows + 1));
    read(bsq->fd, new_file->dump, new_file->line1_size);
    free(new_file->dump);
    return new_file;
}

char **load_2d_arr_from_file(bsq_t *bsq, char const *filepath)
{
    bsq->file = init_file(filepath, bsq);
    for (int i = 0; i < bsq->rows; i++) {
        bsq->file->arr[i] = malloc(sizeof(char) * (bsq->cols + 2));
        bsq->file->arr[i][bsq->cols + 1] = '\0';
    }
    bsq->file->arr[bsq->rows] = NULL;
    for (int i = 0; i < bsq->rows; i++)
        read(bsq->fd, bsq->file->arr[i], bsq->cols + 1);
    return bsq->file->arr;
}

int **array_to_binary(bsq_t *bsq)
{
    int **binary_array = malloc(sizeof(int *) * (bsq->rows));
    int row = 0;
    int col = 0;

    for (int i = 0; i < bsq->rows; i++)
        binary_array[i] = malloc(sizeof(int) * (bsq->cols));
    for (; row < bsq->rows; row++) {
        for (; col < bsq->cols; col++)
            binary_array[row][col] = ((bsq->arr[row][col] == '.') ? 1 : 0);
        col = 0;
    }
    return binary_array;
}
