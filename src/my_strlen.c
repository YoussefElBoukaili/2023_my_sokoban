/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** string lenght
*/

#include "../include/header.h"

int my_strlen(char *str)
{
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}
