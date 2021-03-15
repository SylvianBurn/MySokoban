/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-bsminishell1-sylvian.burn
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/mysokoban.h"

void case_reappear(data_t *data)
{
    int i = 0;

    for (; data->pos->x_sto[i] != -1 && data->pos->y_sto[i] != -1; i++) {
        if (data->map[data->pos->x_sto[i]][data->pos->y_sto[i]] == ' ')
            data->map[data->pos->x_sto[i]][data->pos->y_sto[i]] = 'O';
    }
}

int get_file(data_t *data, char **av)
{
    int fd = open(av[1], O_RDONLY);
    struct stat buffer;

    if (fd == -1 || stat(av[1], &buffer) == -1)
        return (84);
    data->buff = malloc(sizeof(char) * buffer.st_size + 2);
    if (data->buff == NULL)
        return (84);
    for (int i = 0; i < buffer.st_size + 1; i++)
        data->buff[i] = '\0';
    if (read(fd, data->buff, buffer.st_size) == -1)
        return (84);
    return (0);
}

data_t *init_pos(data_t *data)
{
    data->pos->x_case = malloc(sizeof(int) * (data->pos->nb_cases + 1));
    data->pos->y_case = malloc(sizeof(int) * (data->pos->nb_cases + 1));
    data->pos->x_sto = malloc(sizeof(int) * (data->pos->nb_sto + 1));
    data->pos->y_sto = malloc(sizeof(int) * (data->pos->nb_sto + 1));
    return (data);
}

int game_func(data_t *data)
{
    find_my_player(data);
    find_my_storages(data);
    if (display(data->map, data->buff, data) == 1) {
        my_freeing(data->map, data);
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    data_t *data = malloc(sizeof(data_t));

    data->pos = malloc(sizeof(pos_t));
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_usage();
        free(data);
        return (0);
    }
    if (get_file(data, av) == 84 || check_map(data->buff, data) == 84)
        return (84);
    data = init_pos(data);
    data->map = my_str_to_line_array(data->buff, data);
    data->map_backup = data->map;
    if (game_func(data) == 1)
        return (1);
    my_freeing(data->map, data);
    return (0);
}