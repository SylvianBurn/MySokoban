/*
** EPITECH PROJECT, 2020
** B-PSU-200-STG-2-1-mysokoban-sylvian.burn
** File description:
** game.c
*/

#include "../include/my.h"
#include "../include/mysokoban.h"

void move_upward(data_t *data)
{
    if (data->map[data->pos->player_x - 1][data->pos->player_y] == 'X' &&
        data->map[data->pos->player_x - 2][data->pos->player_y] != '#') {
        data->map[data->pos->player_x][data->pos->player_y] = ' ';
        data->map[data->pos->player_x - 1][data->pos->player_y] = 'P';
        data->map[data->pos->player_x - 2][data->pos->player_y] = 'X';
        data->pos->player_x--;
    }
    else if (data->map[data->pos->player_x - 1][data->pos->player_y] != 'X' &&
        data->map[data->pos->player_x - 1][data->pos->player_y] != '#') {
        data->map[data->pos->player_x][data->pos->player_y] = ' ';
        data->map[data->pos->player_x - 1][data->pos->player_y] = 'P';
        data->pos->player_x--;
    }
}

void move_downward(data_t *data)
{
    if (data->map[data->pos->player_x + 1][data->pos->player_y] == 'X' &&
        data->map[data->pos->player_x + 2][data->pos->player_y] != '#') {
        data->map[data->pos->player_x][data->pos->player_y] = ' ';
        data->map[data->pos->player_x + 1][data->pos->player_y] = 'P';
        data->map[data->pos->player_x + 2][data->pos->player_y] = 'X';
        data->pos->player_x++;
    }
    else if (data->map[data->pos->player_x + 1][data->pos->player_y] != 'X' &&
        data->map[data->pos->player_x + 1][data->pos->player_y] != '#') {
        data->map[data->pos->player_x][data->pos->player_y] = ' ';
        data->map[data->pos->player_x + 1][data->pos->player_y] = 'P';
        data->pos->player_x++;
    }
}

void move_left(data_t *data)
{
    if (data->map[data->pos->player_x][data->pos->player_y - 1] == 'X' &&
        data->map[data->pos->player_x][data->pos->player_y - 2] != '#') {
        data->map[data->pos->player_x][data->pos->player_y] = ' ';
        data->map[data->pos->player_x][data->pos->player_y - 1] = 'P';
        data->map[data->pos->player_x][data->pos->player_y - 2] = 'X';
        data->pos->player_y--;
    }
    else if (data->map[data->pos->player_x][data->pos->player_y - 1] != 'X' &&
        data->map[data->pos->player_x][data->pos->player_y - 1] != '#') {
        data->map[data->pos->player_x][data->pos->player_y] = ' ';
        data->map[data->pos->player_x][data->pos->player_y - 1] = 'P';
        data->pos->player_y--;
    }
}

void move_right(data_t *data)
{
    if (data->map[data->pos->player_x][data->pos->player_y + 1] == 'X' &&
        data->map[data->pos->player_x][data->pos->player_y + 2] != '#') {
        data->map[data->pos->player_x][data->pos->player_y] = ' ';
        data->map[data->pos->player_x][data->pos->player_y + 1] = 'P';
        data->map[data->pos->player_x][data->pos->player_y + 2] = 'X';
        data->pos->player_y++;
    }
    else if (data->map[data->pos->player_x][data->pos->player_y + 1] != 'X' &&
        data->map[data->pos->player_x][data->pos->player_y + 1] != '#') {
        data->map[data->pos->player_x][data->pos->player_y] = ' ';
        data->map[data->pos->player_x][data->pos->player_y + 1] = 'P';
        data->pos->player_y++;
    }
}