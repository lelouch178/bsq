/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** Find the number of rows and cols on the file.
*/

#include "../include/bsq.h"

int get_rows(int fd)
{
    char buffer[1] = {0};
    char nb[11] = {0};

    if (fd == -1)
        return 0;
    for (int i = 0; read(fd, buffer, 1) != 0 && buffer[0] != '\n'; i++)
        nb[i] = buffer[0];
    return ABS(my_getnbr(nb));
}

int get_cols(int fd)
{
    char buff[1] = {0};
    int result = 0;

    while (read(fd, buff, 1) != 0 && buff[0] != '\n')
        result++;
    return result;
}
