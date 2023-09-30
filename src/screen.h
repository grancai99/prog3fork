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

enum path_char_t{PIPE =0, DASH, F_SLASH, B_SLASH};

struct map_t {
    int size;
    int map[100][100];
};

int createMap(/*idk*/);

int draw(struct map_t * my_map, int turtle_x, int turtle_y);

#endif