/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** error_from_line BSQ
*/

#include "../include/bsq.h"

int file_exist(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        my_write("File doesn't exist\n", false);
        close(fd);
        return 84;
    }
    close(fd);
    return 0;
}

int empty_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[1];
    char buffer[1];

    if (read(fd, buff, 1) == 0) {
        my_write("Error: Empty file\n", false);
        close(fd);
        return 84;
    }
    close(fd);
    fd = open(filepath, O_RDONLY);
    while (read(fd, buffer, 1) != 0 && buffer[0] != '\n') {
        if (read(fd, buffer, 1) == 0) {
            my_write("No character is present\n", false);
            close(fd);
            return 84;
        }
    }
    close(fd);
    return 0;
}

int error_case(char const *filepath)
{
    int fd = 0;
    char *tmp;
    struct stat sb;

    if (file_exist(filepath) == 84 || empty_file(filepath) == 84)
        return 84;
    fd = open(filepath, O_RDONLY);
    if (stat(filepath, &sb) == -1)
        return 84;
    tmp = malloc(sb.st_size);
    read(fd, tmp, sb.st_size);
    if (error_from_line(tmp) == 84)
        return 84;
    return 0;
}
