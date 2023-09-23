/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** Function that returns a number,
** sent to the function as a string.
*/

#include "../include/bsq.h"

static int get_sign(char const *str, int len)
{
    int sign = 1;
    int is_ok = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '-') {
            sign *= -1;
            continue;
        }
        if (str[i] == '+')
            continue;
        if (is_ok == 0 && !(str[i] >= '0' && str[i] <= '9')) {
            return (0);
        } else {
            is_ok = 1;
        }
        if (i + 1 <= len && (str[i + 1] < '0' || str[i + 1] > '9'))
            break;
    }
    return (sign);
}

static int get_result(const char *str, unsigned int *result, int i, int len)
{
    if (str[i] >= '0' && str[i] <= '9') {
        *result += str[i] - 48;
        if (i + 1 <= len && (str[i + 1] < '0' || str[i + 1] > '9'))
            return (1);
        if (i + 1 != len) {
            *result *= 10;
        }
    }
    return 0;
}

static int last_check(unsigned int result, int sign, int i, char const *str)
{
    if (sign > 0 && result >= 214748364 && str[i] - 48 > 7) {
        return 1;
    }
    if (sign < 0 && result >= 214748364 && str[i] - 48 > 8) {
        return 1;
    }
    if (result >= 2147483650) {
        return 1;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    unsigned int result = 0;
    int sign = 0;
    int len = my_strlen(str);

    sign = get_sign(str, len);
    if (sign == 0)
        return (0);
    for (int i = 0; str[i]; i++) {
        if (last_check(result, sign, i, str) == 1)
            return (0);
        if (get_result(str, &result, i, len) == 1)
            break;
    }
    return (result * sign);
}
