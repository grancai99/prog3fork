/**
 * @file main.c
 * @brief Program entry point for ASCII Logo
 *
 * Course: CPE2600
 * Section: 141
 * Assignment: ASCII Logo
 * Name: Caitlyn Grant
 */

#include "turtle.h"
#include "screen.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief Program entry point - Runs the ASCII logo receiving commands from standard input
 */
int main(int argc, char* argv[]) {
    enum move_dir_t turtle_move;
    enum rotate_dir_t turtle_rotate;

    struct turtle_t my_turtle;
    struct map_t my_map;

    int n, x, y;
    char cmd[2];

    bool eof = false;

    //Source: https://www.geeksforgeeks.org/scanf-in-c/
    printf("Enter the dimensions of the map: ");
    scanf("%d", &n);

    printf("Enter the x and y positions of turtle with space between: ");
    scanf("%d", &x);
    scanf("%d", &y);

    create_map(&my_map, n);
    set_location(&my_turtle, x, y);


    printf("n: %d, x: %d, y: %d\n", n, x, y);

    while (!eof) {
        printf("Enter a command for the turtle: ");
        
        int scanf_return = scanf("%s", cmd);
        printf("cd: %s\n", cmd);
        
        if (scanf_return < 0) {
            eof = true;
            printf("End reached\n");
            break; //does this work
        }
        
        int start_x = my_turtle.x;
        int start_y = my_turtle.y;

        if (strncmp(cmd, "FD", 2) == 0) {
            turtle_move = FORWARD;
            char mark = move(&my_turtle, turtle_move, my_map.size);

            if (!my_turtle.penUp)
                add_mark(&my_map, mark, start_x, start_y);
        } else if (strncmp(cmd, "BK", 2) == 0) {
            turtle_move = BACKWARD;
            char mark = move(&my_turtle, turtle_move, my_map.size);

            if (!my_turtle.penUp)
                add_mark(&my_map, mark, start_x, start_y);
        } else if (strncmp(cmd, "RT", 2) == 0) {
            turtle_rotate = C;
            rotate(&my_turtle, turtle_rotate);
        } else if (strncmp(cmd, "LT", 2) == 0) {
            turtle_rotate = CC;
            rotate(&my_turtle, turtle_rotate);
        } else if (strncmp(cmd, "PU", 2) == 0) {
            pen_up(&my_turtle, true);
        } else if (strncmp(cmd, "PD", 2) == 0) {
            pen_up(&my_turtle, false);
        } else if (strncmp(cmd, "LD", 2) == 0) {
            char file_name[10]; //FIX ME
            printf("Please enter a file name: ");
            scanf("%s", file_name);
            ld(file_name);
        } else {
            printf("didn't catch anything\n");
        }

        draw(&my_map, my_turtle.x, my_turtle.y);
    }

    //case "", run each funcction


    /*
    The scanf in C returns three types of values:
        >0: The number of values converted and assigned successfully.
        0: No value was assigned.
        <0: Read error encountered or end-of-file(EOF) reached before any assignment was made.
*/

}

//TODO: possibly pass in function pointer to the add_mark????



/**
* @file myassignmentfile.c
* @brief Short description of my assignment file
*
* Course: CPE2600
* Section: 011
* Assignment: Awesome Game
* Name: John Smith
*
* Algorithm:
* - Retrieve the input file name from the command line arguments
* - Ensure the file name exists and is valid
* - Open the file
* - Read the file to retrieve user data and configuration settings
* -
* - etc.
* -
*/