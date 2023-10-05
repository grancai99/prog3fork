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

/**
* @brief - Structure to manage the turtle
* @property x - current x coordinate
* @property y - current y coordinate
* @property facing - current degree turtle is facing (0 to 360)
* @property penUp - whether the turtle's pen is up or down
* @property move_dir_t - whether turtle is moving fd or bk
* @property rotate_dir_t - whether turtle is rotating rt or lt
*/
struct turtle_t {
    int x;
    int y;
    int facing;
    bool penUp;
    int boundaries;
    enum move_dir_t move;
    enum rotate_dir_t rotate;
};

bool check_valid_x_y(int x, int y, int n);

void set_location(struct turtle_t *my_turtle_ptr, int x, int y, int n);

char move(struct turtle_t *my_turtle_ptr);

void rotate(struct turtle_t *my_turtle_ptr);

void pen_up(struct turtle_t *my_turtle_ptr, bool up);

#endif