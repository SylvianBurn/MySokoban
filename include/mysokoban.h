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

typedef struct s_pos {
    int player_x;
    int player_y;
    int nb_cases;
    int nb_sto;
    int *x_sto;
    int *y_sto;
    int *x_case;
    int *y_case;
} pos_t;

typedef struct s_data {
    char *buff;
    char **map;
    char **map_backup;
    int nb_line;
    int length;
    int longest_line;
    int status;
    pos_t *pos;
} data_t;

int get_nb_line(char *, data_t *);
char **my_str_to_line_array(char *, data_t *);
int check_map(char *, data_t *);
void my_freeing(char **, data_t *);
void print_usage(void);
int find_longest_line(char *);
int game_loop(int, data_t *);
void move_upward(data_t *);
void move_downward(data_t *);
void move_left(data_t *);
void move_right(data_t *);
void find_my_player(data_t *);
void display_win(data_t *);
void display_loose(data_t *);
int detect_end(data_t *);
int check_win(data_t *);
int display_loop(char **, char *, data_t *);
int display(char **, char *, data_t *);
int game_func(data_t *data);
void case_reappear(data_t *data);
void find_my_storages(data_t *data);
void find_my_cases(data_t *data);

#endif /* !MYSOKOBAN_H_ */
