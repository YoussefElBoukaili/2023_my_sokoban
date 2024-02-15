/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_sokoban
*/

#include "../include/header.h"

int count_height(const char *buffer)
{
    int height = 0;

    for (int k = 0; buffer[k] != '\0'; k++){
        if (buffer[k] == '\n')
            height++;
    }
    return height;
}

int *calculate_widths(const char *buffer, int height)
{
    int *widths = (int *)malloc(sizeof(int) * height);
    int index = 0;

    for (int i = 0; i < height; i++) {
        widths[i] = 0;
        while (buffer[index] != '\n' && buffer[index] != '\0') {
            widths[i]++;
            index++;
        }
        index++;
    }
    return widths;
}

char **store_2d(char *buffer)
{
    int height = count_height(buffer);
    int *widths = calculate_widths(buffer, height);
    char **map = (char **)malloc(sizeof(char *) * (height + 1));
    int index = 0;

    for (int i = 0; i < height; i++) {
        map[i] = (char *)malloc(sizeof(char) * (widths[i] + 1));
        for (int j = 0; j < widths[i]; j++) {
            map[i][j] = buffer[index];
            index++;
        }
        index++;
        map[i][widths[i]] = '\0';
    }
    map[height] = NULL;
    free(widths);
    return map;
}

static long file_size(const char *filepath)
{
    long size;
    struct stat st;

    if (stat(filepath, &st) == -1)
        return 84;
    return st.st_size;
}

char *read_map(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    off_t size = file_size(filepath);
    char *buffer;

    if (fd == -1 || size == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}
