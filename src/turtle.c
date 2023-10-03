/**
 * @file turtle.c
 * @brief Implementation of ASCII Logo turtle
 *
 * Course: CPE2600
 * Section: 141
 * Assignment: ASCII Logo
 * Name: Caitlyn Grant
 */

#include "turtle.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// struct turtle_t {
//     int x;
//     int y;
//     int facing;
//     bool penUp;
// };

int set_location(struct turtle_t * my_turtle, int x, int y) {
    my_turtle->x = x;
    my_turtle->y = y;
    my_turtle->facing = 0;
    my_turtle->penUp = false;
    
    return 1;
}  

int decide_instruction(char * command/*, int * add_mark(struct map_t * my_map, char mark, int x, int y)*/) {
    //case when: instructions
    //create map on first two

    return 1;
}

char move(struct turtle_t * my_turtle, enum move_dir_t move, int size) {
    printf("turtle go move\n");
    printf("turtle is (%d, %d) and facing %d\n", my_turtle->x, my_turtle->y, my_turtle->facing);

    //Source: https://riptutorial.com/c/example/5408/dereferencing-a-pointer-to-a-struct
    int facing = my_turtle->facing;
    
    if (45 <= facing && facing <= 135)
        (my_turtle->x) += move;
    else if (225 <= facing && facing <= 360)
        (my_turtle->x) -= move;

    if (135 <= facing && facing <= 225)
        (my_turtle->y) += move;
    else if (facing <= 45 || 315 <= facing)
        (my_turtle->y) -= move;

    if (my_turtle->x < 0)
        my_turtle->x = size - 1;
    else if (my_turtle->x >= size)
        my_turtle->x = 0;

    if (my_turtle->y < 0)
        my_turtle->y = size -1;
    else if (my_turtle->y >= size)
        my_turtle->y = 0;

    printf("turtle is (%d, %d) and facing %d\n", my_turtle->x, my_turtle->y, my_turtle->facing);

    if (facing % 180 == 0)
        return '|';
    else if (facing - 45 % 180 == 0)
        return '/';
    else if (facing - 90 % 180 == 0)
        return '-';
    else if (facing - 135 % 180 == 0)
        return '\\';

    //1 for success TODO
    return 1;
}

int rotate(struct turtle_t * my_turtle, enum rotate_dir_t rotate) {
    printf("turlte go rotate\n");
    (my_turtle->facing) += rotate * 45;
    
    if (my_turtle->facing >= 360) {
        (my_turtle->facing) = 0;
    } else if (my_turtle->facing < 0) {
        (my_turtle->facing) = 315;
    }

    //1 for success
    return 1;
}

int pen_up(struct turtle_t * my_turtle, bool up) {
    my_turtle->penUp = up;
    
    //1 for success
    return 1;
}

int ld(char * file_name) {
    //read file line by line, call decide instructions

    return 1;
}