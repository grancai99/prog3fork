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

// enum path_char_t{SPACE =0, PIPE, F_SLASH, DASH, B_SLASH};

/**
* @brief - Structure to do something with values
* @property value1 - the first property of the structure
* @property value2 - the second property of the structure
*/
struct map_t {
    int size;
    char map[100][100]; //TODO: how to make smaller, dynamic memory if time EXTRA CREDIT he will check no memory leaks w/ val..
    //use char instead of int, 1/4 the memory
};

int create_map(struct map_t * my_map, int n);

int add_mark(struct map_t * my_map, char mark, int x, int y);

int draw(struct map_t * my_map, int turtle_x, int turtle_y);

#endif