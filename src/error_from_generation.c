/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** generator_handling_error
*/

#include "../include/bsq.h"

int error_generation_characters(char *av)
{
    for (int j = 0; av[j] != '\0'; j ++) {
        if ((av[j] != '.' && av[j] != 'o' && av[j] != '"')) {
            my_write("Character differs from 'o' and '.'\n", false);
            return 84;
        }
    }
    return 0;
}

int error_from_generation(char **av)
{
    if (av[2][0] == '\0') {
        my_write("Empty generation\n", false);
        return 84;
    }
    for (int i = 2; av[i] != NULL; i++) {
        if (error_generation_characters(av[i]) == 84)
            return 84;
    }
    if (my_str_isnum(av[1]) == 0) {
        my_write("Only positive number are taken into account\n", false);
        return 84;
    }
    return 0;
}
