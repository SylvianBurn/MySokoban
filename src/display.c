/*
** EPITECH PROJECT, 2020
** B-PSU-200-STG-2-1-mysokoban-sylvian.burn
** File description:
** display.c
*/

#include "../include/my.h"
#include "../include/mysokoban.h"

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
        find_my_cases(data);
        if (game_loop(getch(), data) == 1)
            break;
        if (detect_end(data) == 1)
            return (1);
        case_reappear(data);
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