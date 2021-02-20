/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-bsminishell1-sylvian.burn
** File description:
** main.c
*/

#include "include/my.h"
#include "include/mysokoban.h"

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

int display(char **map, char *buff, data_t *data)
{
    WINDOW *boite;

    initscr();
    while(1) {
        clear();
        for (int i = 0; map[i] != NULL; i++)
            mvprintw((LINES/2 - (data->nb_line / 2) + i), (COLS / 2) - (my_strlen(map[i]) / 2), map[i]);
        refresh();
        if(getch() != 410)
            break;
    }
    endwin();
    free(boite);
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_usage();
        return (0);
    }
    data_t *data = malloc(sizeof(data_t));
    if (get_file(data, av) == 84 || check_map(data->buff) == 84)
        return (84);
    data->map = my_str_to_line_array(data->buff, data);
    display(data->map, data->buff, data);
    my_freeing(data->map, data);
    return (0);
}