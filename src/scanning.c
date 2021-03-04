/*
** EPITECH PROJECT, 2020
** B-PSU-200-STG-2-1-mysokoban-sylvian.burn
** File description:
** scanning.c
*/

#include "../include/mysokoban.h"
#include "../include/my.h"


void find_my_player(data_t *data)
{
    for (int x = 0; data->map[x]; x++) {
        for (int y = 0; data->map[x][y]; y++) {
            if (data->map[x][y] == 'P') {
                data->pos->player_x = x;
                data->pos->player_y = y;
            }
        }
    }
}

void find_my_cases(data_t *data)
{
    int array = 0;

    for (int x = 0; data->map[x]; x++) {
        for (int y = 0; data->map[x][y]; y++) {
            if (data->map[x][y] == 'X') {
                data->pos->x_case[array] = x;
                data->pos->y_case[array] = y;
                array++;
            }
        }
    }
    data->pos->x_case[array] = -1;
    data->pos->y_case[array] = -1;
}

void find_my_storages(data_t *data)
{
    int array = 0;

    for (int x = 0; data->map[x]; x++) {
        for (int y = 0; data->map[x][y]; y++) {
            if (data->map[x][y] == 'O') {
                data->pos->x_sto[array] = x;
                data->pos->y_sto[array] = y;
                array++;
            }
        }
    }
    data->pos->x_sto[array] = -1;
    data->pos->y_sto[array] = -1;
}

void find_everything(data_t *data)
{
    find_my_player(data);
    find_my_storages(data);
}

int check_win(data_t *data)
{
    for (int i = 0; data->pos->x_sto[i] != -1; i++) {
        if (data->pos->x_sto[i] != data->pos->x_case[i] ||
            data->pos->y_sto[i] != data->pos->y_case[i])
            return (1);
    }
    return (0);
}