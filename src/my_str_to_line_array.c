/*
** EPITECH PROJECT, 2020
** B-PSU-200-STG-2-1-bsmysokoban-sylvian.burn
** File description:
** my_str_to_line_array.c
*/

#include "../include/my.h"
#include "../include/mysokoban.h"

int find_longest_line(char *str)
{
    int line_length = 0;
    int line = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n')
            line_length++;
        else {
            if (line_length > line)
                line = line_length;
            line_length = 0;
        }
    }
    return (line);
}

int get_nb_line(char *buf, data_t *data)
{
    data->nb_line = 1;

    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] == '\n')
            data->nb_line++;
    return (data->nb_line);
}

char **my_malloc(char *buff, char **tab, int nb_line)
{
    for (int i = 0; i < nb_line; i++) {
        tab[i] = malloc(sizeof(char) * (find_longest_line(buff) + 1));
    }
    return (tab);
}

char **str_to_line_array2(char *buff, char **tab, data_t *data)
{
    int x = 0;
    int y = 0;
    int i = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '\n' || buff[i] == '\0') {
            tab[x][y] = '\0';
            x++;
            y = 0;
            i++;
        }
        if (buff[i] != '\n' || buff[i] != '\0') {
            tab[x][y] = buff[i];
            i++;
            y++;
        }
    }
    tab[x][y] = '\0';
    tab[x + 1] = NULL;
    return (tab);
}

char **my_str_to_line_array(char *buff, data_t *data)
{
    char **tab = malloc(sizeof(char *) * (get_nb_line(buff, data) + 1));

    data->longest_line = find_longest_line(buff);
    tab = my_malloc(buff, tab, (data->nb_line + 1));
    tab = str_to_line_array2(buff, tab, data);
    return (tab);
}