/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_sokoban
*/

#include "../include/header.h"

int check_er(coords_t *all, int ac)
{
    for (int i = 0; all->buffer[i] != '\0'; i++){
        if (all->buffer[i] != ' ' && all->buffer[i] != '#'
        && all->buffer[i] != 'O'
        && all->buffer[i] != 'X' && all->buffer[i] != 'P' &&
        all->buffer[i] != '\n')
            return 84;
    }
    return 0;
}

void free_mem(coords_t *all)
{
    free(all->buffer);
    for (int i = 0; all->map[i] != NULL; i++){
        free(all->map[i]);
    }
    free(all->map);
    for (int i = 0; all->b_map[i] != NULL; i++){
        free(all->b_map[i]);
    }
    free(all->b_map);
}
