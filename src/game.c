/*
** EPITECH PROJECT, 2020
** B-PSU-200-STG-2-1-mysokoban-sylvian.burn
** File description:
** game.c
*/

#include "../include/my.h"
#include "../include/mysokoban.h"

int my_restart(data_t *data)
{
    data->map = data->map_backup;
    return (0);
}

int game_loop(int key, data_t *data)
{
    switch (key) {
        case KEY_UP:
            move_upward(data);
            break;
        case KEY_DOWN:
            move_downward(data);
            break;
        case KEY_LEFT:
            move_left(data);
            break;
        case KEY_RIGHT:
            move_right(data);
            break;
        case KEY_BACKSPACE:
            return (1);
            break;
        case ' ':
            my_restart(data);
            break;
    }
    return (0);
}

int check_targets(char **map)
{
    int x = 0;

    for (int y = 0; map[x][y] != '\0'; y++) {
        if (map[x][y] == '\n')
            x++;
        if (map[x][y] == 'O')
            return (1);
    }
    return (0);
}

int check_if_blocked(char **map)
{
    int x = 0;

    for (int y = 0; map[x][y]; y++) {
        if (map[x][y] == '\0')
            x++;
        if (map[x][y] == 'X') {
            if ((map[x - 1][y] == '#' && map[x - 1][y - 1] == '#' &&
                map[x][y - 1] == '#') || (map[x - 1][y] == '#' &&
                map[x - 1][y + 1] == '#' && map[x][y + 1] == '#') ||
                (map[x + 1][y] == '#' && map[x + 1][y + 1] == '#' &&
                map[x][y + 1] == '#') || (map[x + 1][y] == '#' &&
                map[x + 1][y - 1] == '#' && map[x][y - 1] == '#'))
                return (-1);
        }
    }
    return (0);
}

int detect_end(data_t *data)
{
    // if (data->pos->x_backup == 0 && check_targets(data->map) == 0) {
    //     display_win(data);
    //     return (0);
    // }
    if (check_if_blocked(data->map) != 0) {
        display_loose(data);
        return (1);
    }
}