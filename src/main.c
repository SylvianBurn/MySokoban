/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-bsminishell1-sylvian.burn
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/mysokoban.h"

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

int display_loop(char **map, char *buff, data_t *data)
{
    char *msg = "Please enlarge the terminal.\n";

    while (1) {
        clear();
        if (LINES < data->nb_line || COLS < find_longest_line(buff))
            mvprintw(LINES/2, (COLS/2) - (my_strlen(msg) / 2), msg);
        else {
            for (int i = 0; map[i] != NULL; i++)
                mvprintw((LINES/2 - (data->nb_line / 2) + i), (COLS / 2) -
                (my_strlen(map[i]) / 2), map[i]);
            refresh();
        }
        if (game_loop(getch(), data) == 1)
            break;
        if (detect_end(data) == 1)
            return (1);
    }
    return (0);
}

int display(char **map, char *buff, data_t *data)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    if (display_loop(map, buff, data) == 1) {
        endwin();
        return (1);
    }
    endwin();
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
    find_my_player(data);
    if (display(data->map, data->buff, data) == 1) {
        my_freeing(data->map, data);
        return (1);
    }
    my_freeing(data->map, data);
    return (0);
}