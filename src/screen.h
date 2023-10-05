/**
 * @file screen.h
 * @brief Declarations for ASCII Logo screen
 *
 * Course: CPE2600
 * Section: 141
 * Assignment: ASCII Logo
 * Name: Caitlyn Grant 
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <stdbool.h>

/**
* @brief - Structure to do hold the map of turtle tracks
* @property size - dimensions of square map
* @property map[][] - 2D array that holds the path chars left by turtle
*/
struct map_t {
    int size;
    char map[100][100]; //TODO: how to make smaller, dynamic memory if time EXTRA CREDIT he will check no memory leaks w/ val..
};

bool check_valid_dimensions(int n);

void create_map(struct map_t* my_map_ptr, int n);

void add_mark(struct map_t* my_map_ptr, char mark, int x, int y);

void draw(struct map_t* my_map_ptr, int turtle_x, int turtle_y);

#endif