/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** error_from_file BSQ
*/

#include "../include/bsq.h"

int first_line_number_checking(char *tmp)
{
    int i = 0;

    for (; tmp[i] != '\n'; i++) {
        if (tmp[i] < '0' || tmp[i] > '9')
            return 84;
    }
    return 0;
}

int check_all_line_equal(char *tmp)
{
    int i = 0;
    int len = 0;
    int clen = 0;

    for (; tmp[i] != '\n'; i++);
    for (i++; tmp[i] != '\n'; i++)
        len++;
    for (i++; tmp[i] != 0; i++) {
        clen++;
        if (tmp[i] == '\n' && (len != clen - 1))
            return 84;
        if (tmp[i] == '\n')
            clen = 0;
    }
    return 0;
}

int check_number_of_line(char *tmp)
{
    int row = 0;
    int i = 0;
    int counter = 0;

    for (; tmp[i] != '\n'; i++)
        row = my_getnbr(tmp);
    for (i++; tmp[i] != 0; i++) {
        if (tmp[i] == '\n')
            counter ++;
    }
    if (row != counter)
        return 84;
    return 0;
}

int error_from_line(char *tmp)
{
    if (first_line_number_checking(tmp) == 84) {
        my_write("First line must be filled with numbers only\n", false);
        return 84;
    }
    if (check_all_line_equal(tmp) == 84) {
        my_write("Number of cols not equal\n", false);
        return 84;
    }
    if (check_number_of_line(tmp) == 84) {
        my_write("Number of lines not equal\n", false);
        return 84;
    }
    return 0;
}
