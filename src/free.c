/*
** EPITECH PROJECT, 2020
** B-PSU-200-STG-2-1-mysokoban-sylvian.burn
** File description:
** free.c
*/

#include "../include/my.h"
#include "../include/mysokoban.h"

void my_freeing(char **map, data_t *data)
{
    for (int i = 0; i < data->nb_line; i++) {
        free(map[i]);
        map[i] = NULL;
    }
    free(map);
    free(data->buff);
    free(data->pos->x_sto);
    free(data->pos->y_sto);
    free(data->pos->x_case);
    free(data->pos->y_case);
    free(data->pos);
    free(data);
}