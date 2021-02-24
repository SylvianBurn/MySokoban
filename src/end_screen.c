/*
** EPITECH PROJECT, 2020
** B-PSU-200-STG-2-1-mysokoban-sylvian.burn
** File description:
** end_screen.c
*/

#include "../include/my.h"
#include "../include/mysokoban.h"

void display_win_ncurses(data_t *data)
{
    char **txt = malloc(sizeof(char *) * 5);
    txt[0] = "You won !\n";
    txt[1] = "\n";
    txt[2] = "Press Q to quit.\n";
    txt[3] = "Press space to restart.\n";
    txt[4] = NULL;

    for (int i = 0; txt[i] != NULL; i++)
        mvprintw((LINES/2 - 2 + i), (COLS / 2) -
        (my_strlen(txt[i]) / 2), txt[i]);-
    refresh();
}

void display_loose_ncurses(data_t *data)
{
    char **txt = malloc(sizeof(char *) * 5);
    txt[0] = "You are stuck. Try again !\n";
    txt[1] = "\n";
    txt[2] = "Press Q to quit.\n";
    txt[3] = "Press space to restart.\n";
    txt[4] = NULL;

    for (int i = 0; txt[i] != NULL; i++)
        mvprintw((LINES/2 - 2 + i), (COLS / 2) -
        (my_strlen(txt[i]) / 2), txt[i]);
    refresh();
}

void display_win(data_t *data)
{
    my_printf("Congratulation, you won !\n");
}

void display_loose(data_t *data)
{
    my_printf("You are stuck. Try again !\n");
}