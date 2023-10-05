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

/**
 * @brief This function checks whether n is a valid value
 *
 * @param n - the proposed dimension of the map
 *
 * @return false - n is not valid
 * @return true - n is valid
 */
bool check_valid_dimensions(int n) {
    if (n > 0 && n <= 100) {
        return true;
    }
    return false;
}

/**
 * @brief This function creates a square, blank map of n dimensions
 *
 * @param my_map_ptr - a pointer to the structure for the map
 * @param n - the dimension of the map
 */
void create_map(struct map_t* my_map_ptr, int n) {
    my_map_ptr->size = n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            my_map_ptr->map[i][j] = ' ';
        }
    }
}

/**
 * @brief This function adds a mark to the map where the turtle just was
 *
 * @param my_map_ptr - a pointer to the structure for the map
 * @param n - the dimension of the map
 */
void add_mark(struct map_t* my_map_ptr, char mark, int x, int y) {
    my_map_ptr->map[x][y] = mark;
}

/**
 * @brief This function prints out the map and includes turtle
 *
 * @param my_map_ptr - a pointer to the structure for the map
 * @param turtle_x - current x coordinate of turtle
 * @param turtle_y - current y coordinate of turtle
 */
void draw(struct map_t* my_map_ptr, int turtle_x, int turtle_y) {
    
    int n = my_map_ptr->size;

    //Print first line of *
    for (int i = 0; i < n + 2; i++) {
        printf("*");
    }

    //Print grid
    for (int i = 0; i < n; i++) {
        printf("\n*");

        for (int j = 0; j < n + 2; j++) {
            //Print X for turtle or the char in the grid
            char path;
            if (j == turtle_x && i == turtle_y) {
                path = 'X';
            } else {
                path = my_map_ptr->map[j][i];
            }
            printf("%c", path);
        }
        printf("*");
    }

    //Print final line of *
    printf("\n");
    for (int i = 0; i < n + 2; i++) {
        printf("*");
    }
    printf("\n");
}