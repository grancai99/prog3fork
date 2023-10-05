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

/**
 * @brief This function checks whether x and y are valid values
 *
 * @param x - the proposed turtle x coordinate
 * @param y - the proposed turtle y coordinate
 * @param n - the proposed dimension of the map
 *
 * @return false - n is not valid
 * @return true - n is valid
 */
bool check_valid_x_y(int x, int y, int n) {
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

/**
 * @brief This function sets the default values for the turtle
 *
 * @param my_turtle_ptr - a pointer to the structure for the turtle
 * @param my_map_ptr - a pointer to the structure for the map
 * @param x - the initial x coordinate
 * @param y - the initial y coordinate
 * @param n - the dimensions of the map
 */
void set_location(struct turtle_t *my_turtle_ptr, int x, int y, int n) {
    my_turtle_ptr->x = x;
    my_turtle_ptr->y = y;
    my_turtle_ptr->facing = 0;
    my_turtle_ptr->penUp = false;
    my_turtle_ptr->boundaries = n;
    my_turtle_ptr->move = 1;
    my_turtle_ptr->rotate = 1;
}  

/**
 * @brief This function moves the turtle based off commands FD and BK
 *
 * @param my_turtle_ptr - a pointer to the structure for the turtle
 * 
 * @return char - the character that should go on the map where the turtle just was
 */
char move(struct turtle_t *my_turtle_ptr) {

    //Based off the direction the turtle is facing, change appropriate x and y coordinates for movement
    int facing = my_turtle_ptr->facing;
    if (45 <= facing && facing <= 135) {
        (my_turtle_ptr->x) += my_turtle_ptr->move;
    } else if (225 <= facing && facing <= 360) {
        (my_turtle_ptr->x) -= my_turtle_ptr->move;
    }

    if (135 <= facing && facing <= 225) {
        (my_turtle_ptr->y) += my_turtle_ptr->move;
    } else if (facing <= 45 || 315 <= facing) {
        (my_turtle_ptr->y) -= my_turtle_ptr->move;
    }

    //If the turtle is out of bounds, wrap around
    int boundaries = my_turtle_ptr->boundaries;
    if (my_turtle_ptr->x < 0) {
        my_turtle_ptr->x = boundaries - 1;
    } else if (my_turtle_ptr->x >= boundaries) {
        my_turtle_ptr->x = 0;
    }

    if (my_turtle_ptr->y < 0) {
        my_turtle_ptr->y = boundaries - 1;
    } else if (my_turtle_ptr->y >= boundaries) {
        my_turtle_ptr->y = 0;
    }

    //Based off the direction the turtle is facing, return the proper character
    //that goes in the square the turtle just left
    if (facing == 0 || facing == 180) {
        return '|';
    } else if (facing == 45 || facing == 225) {
        return '/';
    } else if (facing == 90 || facing == 270) {
        return '-';
    } else if (facing == 135 || facing == 315) {
        return '\\';
    }

    return ' ';
}

/**
 * @brief This function rotates the turtle based off commands RT and LT
 *
 * @param my_turtle_ptr - a pointer to the structure for the turtle
 */
void rotate(struct turtle_t *my_turtle_ptr) {
    //Change the turtle's facing direction
    (my_turtle_ptr->facing) += my_turtle_ptr->rotate * 45;
    
    //If turtle turns past 0 or past 360, reset around
    if (my_turtle_ptr->facing >= 360) {
        (my_turtle_ptr->facing) = 0;
    } else if (my_turtle_ptr->facing < 0) {
        (my_turtle_ptr->facing) = 315;
    }
}

/**
 * @brief This function sets the turtle's pen up or down
 *
 * @param my_turtle_ptr - a pointer to the structure for the turtle
 * @param up - whether the pen should be set to up or down
 */
void pen_up(struct turtle_t *my_turtle_ptr, bool up) {
    my_turtle_ptr->penUp = up;
}