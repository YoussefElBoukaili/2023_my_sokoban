/*
** EPITECH PROJECT, 2023
** my
** File description:
** my header
*/

#ifndef HEADER_H_
    #define HEADER_H_
    #include <ncurses.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <sys/stat.h>

typedef struct coords_s {
    int x;
    int y;
    char *buffer;
    char **map;
    char **b_map;
    int ch;
} coords_t;

int my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb);

int my_strlen(char *str);

int mini_printf(const char *format, ...);

int switch_flag(const char *format, va_list ap);

static void reset_map(coords_t *all);

static int init_scr(coords_t *all, char **av);

static int desc(int ac, char **av);

void getpos_p(coords_t *all, int i, int j);

void checkpos_p(coords_t *all);

void printing_map(char **map);

void loop(coords_t *all);

int check_er(coords_t *all, int ac);

void free_mem(coords_t *all);

static void moveup(coords_t *mov);

void moveup_crate(coords_t *mov);

static void movedown(coords_t *mov);

void movedown_crate(coords_t *mov);

static void moveleft(coords_t *mov);

void moveleft_crate(coords_t *mov);

static void moveright(coords_t *mov);

void moveright_crate(coords_t *mov);

void movement(coords_t *mov);

static int update_width(int width, int index, char curr_char);

int count_height(const char *buffer);

int *calculate_widths(const char *buffer, int height);

char **store_2d(char *buffer);

static long file_size(const char *filepath);

char *read_map(const char *filepath);

#endif /* MY_HEADER_ */
