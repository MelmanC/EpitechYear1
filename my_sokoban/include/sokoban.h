/*
** EPITECH PROJECT, 2023
** PSU-100
** File description:
** sokoban.h
*/

#ifndef SOKOBAN_H
    #define SOKOBAN_H

typedef struct player_s {
    int x;
    int y;
    int onO;
    int compteur;
    int cmpo;
    int cmpx;
    int cmptd;
    int line;
    int start_x;
    int start_y;
    int is_al;
} player_t;

int is_win(char **map, char **map_ini, player_t *player);
int count_o(char **map);
int open_map(char *av);
int move_player(player_t *player, char **map, char *buff);
int get_line(char *buff);
char **right(player_t *player, char **map);
char **left(player_t *player, char **map);
char **go_up(player_t *player, char **map);
char **down(player_t *player, char **map);
int is_defeat(char **map, player_t *player);
int is_valid(char **map, player_t *player);
int width(char **map);
int count_x(char **map);
char **is_on_o(char **map, char **map_ini);
char **copy_map(int lines, char *buff, char **map);

#endif /* SOKOBAN_H */
