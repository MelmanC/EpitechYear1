/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** amazed.h
*/

#ifndef AMAZED_H_
    #define AMAZED_H_

typedef struct map_s {
    char **map;
    int nb_robot;
    int line_next;
} map_t;

typedef struct maze_s {
    int start;
    int pass_start;
    int end;
    int pass_end;
    int nb_rooms;
    int is_tunnel;
} maze_t;

typedef struct algo_s {
    int *visited;
    int *path;
    int path_idx;
} algo_t;

typedef struct paths_s {
    int *path;
    int len;
    int ratio;
    int nb_robots;
    int arrived;
} paths_t;

typedef struct all_s {
    map_t *map;
    maze_t *maze;
    algo_t *algo;
    paths_t **paths;
    int error;
    int arr_idx;
    int **matrix;
} all_t;

int open_file(all_t *all);
int begin_parser(all_t *all);
char **remove_comment(char **file);
int display_need(all_t *all);
int amazed(void);
int **create_matrix(int size);
int update_matrix(all_t *all, int x, int y);
void display_matrix(int **matrix);
int get_robots(all_t *all);
void get_rooms(all_t *all, int i);
int find_all_paths(all_t *all);
int dfs(all_t *all, int node);
int bubble_sort_arr(all_t *all);
int clear_path(all_t *all);
int set_inf_path(all_t *all);
int display_moove(all_t *all);

#endif /* AMAZED_H_ */
