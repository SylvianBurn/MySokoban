/*
** EPITECH PROJECT, 2020
** B-PSU-200-STG-2-1-mysokoban-sylvian.burn
** File description:
** error.c
*/

#include "../include/my.h"
#include "../include/mysokoban.h"

void print_usage(void)
{
    my_printf("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map file repr");
    my_printf("esenting the warehouse map, containing '#' for walls,\n");
    my_printf("         'P' for the player,");
    my_printf(" 'X' for boxes and 'O' for storage locations.\n");
}

int check_nb_boxes(char *str, data_t *data)
{
    int nb = 0;
    data->pos->nb_cases = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == 'X') {
            nb++;
            data->pos->nb_cases++;
        }
    }
    if (nb == 0) {
        write(2, "No boxes found in the map.\n", 28);
        return (-1);
    }
    return (nb);
}

int check_nb_storage(char *str, data_t *data)
{
    int nb = 0;
    data->pos->nb_sto = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == 'O') {
            nb++;
            data->pos->nb_sto++;
        }
    }
    if (nb == 0) {
        write(2, "No storage locations found in the map.\n", 40);
        return (-1);
    }
    return (nb);
}

int check_nb_players(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'P')
            nb++;
    }
    if (nb > 1) {
        write(2, "Too many players.\n", 19);
        return (84);
    }
    else
        return (0);
}

int check_map(char *buff, data_t *data)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] != ' ' && buff[i] != '#' && buff[i] != '\n' &&
        buff[i] != 'X' && buff[i] != 'P' && buff[i] != 'O') {
            write(2, "File containing forbiden characters\n", 37);
            return (84);
        }
    }
    if (check_nb_players(buff) == 84) {
        return (84);
    }
    if (check_nb_boxes(buff, data) != check_nb_storage(buff, data)) {
        write(2, "Number of boxes and storage locations doesn't match.\n", 54);
        return (84);
    }
    return (0);
}