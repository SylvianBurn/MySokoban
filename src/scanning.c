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
    data->pos->x_case = malloc(sizeof(int) * (data->pos->nb_cases + 1));
    data->pos->y_case = malloc(sizeof(int) * (data->pos->nb_cases + 1));
    int array = 0;

    for (int x = 0; data->map[x]; x++) {
        for (int y = 0; data->map[x][y]; y++) {
            if (data->map[x][y] == 'O') {
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
    data->pos->x_sto = malloc(sizeof(int) * (data->pos->nb_sto + 1));
    data->pos->y_sto = malloc(sizeof(int) * (data->pos->nb_sto + 1));
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
    find_my_cases(data);
}