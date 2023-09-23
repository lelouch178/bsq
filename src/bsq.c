/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** main file of this Project
*/

#include "../include/bsq.h"

bsq_t *init_bsq_variables(char const *filepath)
{
    bsq_t *new = malloc(sizeof(bsq_t));
    int fd = open(filepath, O_RDONLY);
    new->rows = get_rows(fd);
    new->cols = get_cols(fd);
    close(fd);
    new->fd = 0;
    new->arr = NULL;
    new->tmp = 0;
    return new;
}

int bsq(char const *filepath)
{
    bsq_t *bsq;
    int coords[3] = {0, 0, 0};

    if (error_case(filepath) == 84)
        return 84;
    bsq = init_bsq_variables(filepath);
    if (bsq->rows == 0 && bsq->cols == 0)
        return 84;
    bsq->fd = open(filepath, O_RDONLY);
    bsq->arr = load_2d_arr_from_file(bsq, filepath);
    bsq->tmp = array_to_binary(bsq);
    find_biggest_square(bsq, coords);
    place_square_and_print(bsq, coords);
    free_bsq(bsq);
    return 0;
}

char *own_map_generation(int len_cols, char *own_map)
{
    char *map = malloc(sizeof(char) * len_cols * len_cols + len_cols);
    int x = 0;
    int y = 0;

    for (int a = 0; a < len_cols; a++) {
        for (int b = 0; b < len_cols; b++) {
            y = own_map[y] == '\0' ? 0 : y;
            map[x] = own_map[y];
            x++, y++;
        }
        map[x] = '\n';
        x++;
    }
    return map;
}

int bsq_generator(char **av)
{
    int fd = open("generate_map", O_WRONLY | O_CREAT, 0644);
    int len_cols = 0;
    int map_bsq = 0;
    char *map = NULL;

    if (error_from_generation(av) == 84)
        return 84;
    len_cols = ABS(my_getnbr(av[1]));
    write(fd, av[1], my_strlen(av[1]));
    write(fd, "\n", 1);
    map = own_map_generation(len_cols, av[2]);
    write(fd, map, len_cols * len_cols + len_cols);
    close(fd);
    map_bsq = bsq("generate_map");
    free(map);
    return map_bsq;
}
