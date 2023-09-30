/**
 * @file turtle.h
 * @brief Declarations for ASCII Logo turtle
 *
 * Course: CPE2600
 * Section: 141
 * Assignment: ASCII Logo
 * Name: Caitlyn Grant
 */

#ifndef TURTLE_H
#define TURTLE_H

#include <stdbool.h>


enum move_dir_t{BACKWARD =-1, FORWARD =1};
enum rotate_dir_t{CC =-1, C =1};

struct turtle_t {
    int x;
    int y;
    int facing;
    bool penUp;
};

int decide_instruction(char * command);

int move(struct turtle_t * my_turtle, enum move_dir_t move);

int rotate(struct turtle_t * my_turtle, enum rotate_dir_t rotate);

int pen_up(struct turtle_t * my_turtle, bool up);

int ld(char * fileName);

#endif