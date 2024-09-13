/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** navy.h
*/

#ifndef NAVY_H
    #define NAVY_H
    #define HIT "result: %c%c:hit\n\n"
    #define MISS "result: %c%c:missed\n\n"

typedef struct game_s {
    int line;
    char **map;
    char **map2;
    int pid;
    int player;
    int hit;
    int hit2;
    int alpha;
    int number;
    int usr2;
    int res;
    int distinction;
} game_t;

typedef struct position_s {
    int len;
    int x;
    int y;
    int end_x;
    int end_y;
    int number;
} position_t;

int get_line(char *buff);
int open_map(game_t *game);
int put_position(game_t *game, char *av);
int display(game_t *game);
int which_player(game_t *game, int ac, char **av);
int attack(game_t *game);
int game_while(game_t *game);
int map_modify(game_t *game);
int map_attack(game_t *game, char *pos);

#endif /* NAVY_H */
