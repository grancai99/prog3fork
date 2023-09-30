/**
 * @file turtle.c
 * @brief Implementation of ASCII Logo turtle
 *
 * Course: CPE2600
 * Section: 141
 * Assignment: ASCII Logo
 * Name: Caitlyn Grant
 */

#include <stdbool.h>
#include "turtle.h"

// enum move_dir_t{BACKWARD =-1, FORWARD =1}; //do i keep these here
// enum rotate_dir_t{CC =-1, C =1};


// struct turtle_t {
//     int x;
//     int y;
//     int facing;
//     bool penUp;
// };

int decide_instruction(char * command) {
    //case when: instructions
    //create map on first two

    return 1;
}

int move(struct turtle_t * my_turtle, enum move_dir_t move) {
    //take the turtle direction facing, then either change x or y, forward or back
    //remember diagonals!!

    //if pendown, call function add mark!!

    //1 for success
    return 1;
}

int rotate(struct turtle_t * my_turtle, enum rotate_dir_t rotate) {
    //turtle.facing += rotate * 45
    //>360 go to 0

    //1 for success
    return 1;
}

int pen_up(struct turtle_t * my_turtle, bool up) {
    //of (up) trutle.pen = up, else down

    //1 for success
    return 1;
}

int ld(char * file_name) {
    //read file line by line, call decide instructions

    return 1;
}