/*
** EPITECH PROJECT, 2020
** B-PSU-200-STG-2-1-bsmysokoban-sylvian.burn
** File description:
** mysokoban.h
*/

#ifndef MYSOKOBAN_H_
#define MYSOKOBAN_H_

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_data {
    char *buff;
    char **map;
    int nb_line;
    int length;
} data_t;

int get_nb_line(char *, data_t *);
char **my_str_to_line_array(char *, data_t *);
int check_map(char *);
void my_freeing(char **, data_t *);
void print_usage(void);

#endif /* !MYSOKOBAN_H_ */
