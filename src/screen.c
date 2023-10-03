/**
 * @file screen.c
 * @brief Implementation of ASCII Logo screen
 *
 * Course: CPE2600
 * Section: 141
 * Assignment: ASCII Logo
 * Name: Caitlyn Grant
 */

#include "screen.h"
#include <stdio.h>

// enum path_char_t{PIPE =0, DASH, F_SLASH, B_SLASH};

// struct map_t {
//     int size;
//     int map[][];
// };

int create_map(struct map_t * my_map, int n) {
    my_map->size = n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            my_map->map[i][j] = ' ';
        }
    }

    return 1;
}

int add_mark(struct map_t * my_map, char mark, int x, int y) {
    my_map->map[x][y] = mark;

    return 1;
}

int draw(struct map_t * my_map, int turtle_x, int turtle_y) {
    
    int n = my_map->size;

    for (int i = 0; i < n + 2; i++) {
        printf("*");
    }

    for (int i = 0; i < n; i++) {
        printf("\n*");

        for (int j = 0; j < n + 2; j++) {
            char path;
            if (j == turtle_x && i == turtle_y) {
                path = 'X';
            } else {
                path = my_map->map[j][i];
            }
            printf("%c", path);
        }
        printf("*");
    }

    printf("\n");
    for (int i = 0; i < n + 2; i++) {
        printf("*");
    }
    printf("\n");

    return 1;
}