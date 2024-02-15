/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_sokoban
*/

#include "../include/header.h"

static void moveup(coords_t *mov)
{
    if (mov->map[mov->y - 1][mov->x] != '#')
        moveup_crate(mov);
}

void moveup_crate(coords_t *mov)
{
    if (mov->map[mov->y - 1][mov->x] == 'X' &&
        mov->map[mov->y - 2][mov->x] != '#' &&
        mov->map[mov->y - 2][mov->x] != 'X'){
        mov->map[mov->y][mov->x] = ' ';
        mov->map[mov->y - 1][mov->x] = 'P';
        mov->map[mov->y - 2][mov->x] = 'X';
    } else if (mov->map[mov->y - 1][mov->x] != 'X'){
        mov->map[mov->y][mov->x] = ' ';
        mov->map[mov->y - 1][mov->x] = 'P';
    }
    if (mov->b_map[mov->y][mov->x] == 'O' &&
        mov->map[mov->y - 1][mov->x] != '#' &&
        mov->map[mov->y - 1][mov->x] != 'X'){
            mov->map[mov->y][mov->x] = 'O';
        }
}

static void movedown(coords_t *mov)
{
    if (mov->map[mov->y + 1][mov->x] != '#')
        movedown_crate(mov);
}

void movedown_crate(coords_t *mov)
{
    if (mov->map[mov->y + 1][mov->x] == 'X' &&
        mov->map[mov->y + 2][mov->x] != '#' &&
        mov->map[mov->y + 2][mov->x] != 'X'){
        mov->map[mov->y][mov->x] = ' ';
        mov->map[mov->y + 1][mov->x] = 'P';
        mov->map[mov->y + 2][mov->x] = 'X';
    } else if (mov->map[mov->y + 1][mov->x] != 'X'){
        mov->map[mov->y][mov->x] = ' ';
        mov->map[mov->y + 1][mov->x] = 'P';
    }
    if (mov->b_map[mov->y][mov->x] == 'O' &&
        mov->map[mov->y + 1][mov->x] != '#' &&
        mov->map[mov->y + 1][mov->x] != 'X'){
            mov->map[mov->y][mov->x] = 'O';
        }
}

static void moveleft(coords_t *mov)
{
    if (mov->map[mov->y][mov->x - 1] != '#')
        moveleft_crate(mov);
}

void moveleft_crate(coords_t *mov)
{
    if (mov->map[mov->y][mov->x - 1] == 'X' &&
        mov->map[mov->y][mov->x - 2] != '#' &&
        mov->map[mov->y][mov->x - 2] != 'X'){
        mov->map[mov->y][mov->x] = ' ';
        mov->map[mov->y][mov->x - 1] = 'P';
        mov->map[mov->y][mov->x - 2] = 'X';
    } else if (mov->map[mov->y][mov->x - 1] != 'X'){
        mov->map[mov->y][mov->x] = ' ';
        mov->map[mov->y][mov->x - 1] = 'P';
    }
    if (mov->b_map[mov->y][mov->x] == 'O' &&
        mov->map[mov->y][mov->x - 1] != '#' &&
        mov->map[mov->y][mov->x - 1] != 'X'){
            mov->map[mov->y][mov->x] = 'O';
        }
}

static void moveright(coords_t *mov)
{
    if (mov->map[mov->y][mov->x + 1] != '#')
        moveright_crate(mov);
}

void moveright_crate(coords_t *mov)
{
    if (mov->map[mov->y][mov->x + 1] == 'X' &&
        mov->map[mov->y][mov->x + 2] != '#' &&
        mov->map[mov->y][mov->x + 2] != 'X'){
        mov->map[mov->y][mov->x] = ' ';
        mov->map[mov->y][mov->x + 1] = 'P';
        mov->map[mov->y][mov->x + 2] = 'X';
    } else if (mov->map[mov->y][mov->x + 1] != 'X'){
        mov->map[mov->y][mov->x] = ' ';
        mov->map[mov->y][mov->x + 1] = 'P';
    }
    if (mov->b_map[mov->y][mov->x] == 'O' &&
        mov->map[mov->y][mov->x + 1] != '#' &&
        mov->map[mov->y][mov->x + 1] != 'X'){
            mov->map[mov->y][mov->x] = 'O';
        }
}

void movement(coords_t *mov)
{
    switch (mov->ch) {
        case KEY_UP:
            moveup(mov);
            break;
        case KEY_DOWN:
            movedown(mov);
            break;
        case KEY_LEFT:
            moveleft(mov);
            break;
        case KEY_RIGHT:
            moveright(mov);
            break;
        default:
            break;
    }
}
