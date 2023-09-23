/*
** EPITECH PROJECT, 2022
** B-CPE-110-NCE-1-1-bsq-adrien.lachambre
** File description:
** main
*/

#include "../include/bsq.h"

int main(int ac, char **av)
{
    if (ac < 2 || ac > 3)
        return 84;
    if (ac == 2)
        return bsq(av[1]);
    else if (ac == 3)
        return bsq_generator(av);
}
