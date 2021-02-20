/*
** EPITECH PROJECT, 2020
** B-PSU-200-STG-2-1-mysokoban-sylvian.burn
** File description:
** error.c
*/

#include "include/my.h"
#include "include/mysokoban.h"

void print_usage(void)
{
    my_printf("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map file repr");
    my_printf("esenting the warehouse map, containing '#' for walls,\n");
    my_printf("         'P' for the player,");
    my_printf(" 'X' for boxes and 'O' for storage locations.\n");
}

int check_map(char *buff)
{
    for(int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] != ' ' && buff[i] != '#' && buff[i] != '\n' &&
        buff[i] != 'X' && buff[i] != 'P' && buff[i] != 'O') {
            write(2, "File containing forbiden characters\n", 37);
            return (84);
        }
    }
    return (0);
}