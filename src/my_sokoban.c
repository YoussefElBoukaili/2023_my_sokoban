/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_sokoban
*/

#include "../include/header.h"

static void reset_map(coords_t *all)
{
    for (int i = 0; all->map[i] != NULL; i++){
        for (int j = 0; all->map[i][j] != '\0'; j++){
            all->map[i][j] = all->b_map[i][j];
        }
    }
}

static int init_scr(coords_t *all, char **av)
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    all->buffer = read_map(av[1]);
    if (all->buffer == NULL)
        return 84;
    all->map = store_2d(all->buffer);
    all->b_map = store_2d(all->buffer);
}

static int desc(int ac, char **av)
{
        mini_printf("USAGE :\n");
        mini_printf("          ./my_sokoban map\n");
        mini_printf("DESCRIPTION : \n");
        mini_printf("           map file representing the warehouse map, ");
        mini_printf("containing '#' for walls,\n");
        mini_printf("           'P' for the player, 'X' for boxes ");
        mini_printf("and 'O' for storage locations.\n");
}

void getpos_p(coords_t *all, int i, int j)
{
    if (all->map[i][j] == 'P'){
        all->x = j;
        all->y = i;
    }
}

void checkpos_p(coords_t *all)
{
    for (int i = 0; all->map[i] != NULL; i++){
        for (int j = 0; all->map[i][j] != '\0'; j++){
            getpos_p(all, i, j);
        }
    }
}

void printing_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        mvprintw(i, 0, "%s\n", map[i]);
}

void loop(coords_t *all)
{
    checkpos_p(all);
    movement(all);
    clear();
    printing_map(all->map);
    all->ch = getch();
    if (all->ch == 32)
        reset_map(all);
    refresh();
}

int main(int ac, char **av)
{
    coords_t all;

    if (ac != 2)
        return 84;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'){
        desc(ac, av);
        return 0;
    }
    if (init_scr(&all, av) == 84)
        return 84;
    while (all.ch != KEY_BACKSPACE){
        loop(&all);
    }
    endwin();
    free_mem(&all);
    return 0;
}
