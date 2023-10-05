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

void ld(struct turtle_t * my_turtle_ptr, struct map_t * my_map_ptr, FILE * file);
void decide_instruction(struct turtle_t * my_turtle_ptr, struct map_t * my_map_ptr, char cmd[2]); //put in header file

/**
 * @brief This function loops through the lines of a file
 * and reads them as command inputs
 *
 * @param my_turtle_ptr - a pointer to the structure for the turtle
 * @param my_map_ptr - a pointer to the structure for the map
 * @param file - the file that contains the input
 */
void ld(struct turtle_t * my_turtle_ptr, struct map_t * my_map_ptr, FILE * file) {
    
    int n, x, y;
    char cmd[2];

    fscanf(file, "%d", &n);
    fscanf(file, "%d", &x);
    fscanf(file, "%d", &y); //TODO: what if return 0
    //printf(failed)

    create_map(my_map_ptr, n);
    set_location(my_turtle_ptr, x, y, n);

    //Source: https://www.geeksforgeeks.org/scanf-and-fscanf-in-c/ 
    while (fscanf(file, "%s", cmd) == 1) {
        printf("%s\n", cmd);
        decide_instruction(my_turtle_ptr, my_map_ptr, cmd);
    }
}

/**
 * @brief This function categorizes the user's input into recognized commands
 * and initiates the appropriate action
 *
 * @param my_turtle_ptr - a pointer to the structure for the turtle
 * @param my_map_ptr - a pointer to the structure for the map
 * @param cmd[2] - a two character string that is the user's input
 */
void decide_instruction(struct turtle_t * my_turtle_ptr, struct map_t * my_map_ptr, char cmd[2]) {
    
    //Source: https://riptutorial.com/c/example/5408/dereferencing-a-pointer-to-a-struct
    int start_x = my_turtle_ptr->x;
    int start_y = my_turtle_ptr->y;

    if (strncmp(cmd, "FD", 2) == 0) {
        my_turtle_ptr->move = FORWARD;
        char mark = move(my_turtle_ptr);

        if (!my_turtle_ptr->penUp)
            add_mark(my_map_ptr, mark, start_x, start_y);
    } else if (strncmp(cmd, "BK", 2) == 0) {
        my_turtle_ptr->move = BACKWARD;
        char mark = move(my_turtle_ptr);

        if (!my_turtle_ptr->penUp)
            add_mark(my_map_ptr, mark, start_x, start_y);
    } else if (strncmp(cmd, "RT", 2) == 0) {
        my_turtle_ptr->rotate = C;
        rotate(my_turtle_ptr);
    } else if (strncmp(cmd, "LT", 2) == 0) {
        my_turtle_ptr->rotate = CC;
        rotate(my_turtle_ptr);
    } else if (strncmp(cmd, "PU", 2) == 0) {
        pen_up(my_turtle_ptr, true);
    } else if (strncmp(cmd, "PD", 2) == 0) {
        pen_up(my_turtle_ptr, false);
    } else {
        printf("Invalid command, please try again\n");
    }

    draw(my_map_ptr, my_turtle_ptr->x, my_turtle_ptr->y);
}


/**
 * @brief Program entry point - Runs the ASCII logo receiving commands from standard input
 */
int main(int argc, char* argv[]) {
    struct turtle_t my_turtle;
    struct map_t my_map;

    int n, x, y;
    char cmd[2];

    //End of file, will end the program under appropriate conditions
    bool eof = false;

    printf("Enter the dimensions of the map: ");
    //Source: https://www.geeksforgeeks.org/scanf-in-c/
    scanf("%d", &n);

    printf("Enter the x and y positions of turtle with space between: ");
    scanf("%d", &x);
    scanf("%d", &y);

    //Verify x, y, and n are all valid. Exit and print error message if they're not
    bool valid_n = check_valid_dimensions(n);
    bool valid_x_y = check_valid_x_y(x, y, n);
    if (!valid_x_y) {
        printf("Error: the start position of the turtle must be greater than 0 and less than the map dimensions");
        eof = true;
    } else if (!valid_n) {
        printf("Error: the map dimensions must be greater than 0 and less than or equal to 100");
        eof = true;
    }

    create_map(&my_map, n);
    set_location(&my_turtle, x, y, n);

    while (!eof) {
        printf("Enter a command for the turtle: ");
        
        int scanf_return = scanf("%s", cmd);
        printf("cd: %s\n", cmd);
        
        if (scanf_return < 0) {
            eof = true;
            printf("End of file reached\n");
            break;
        }

        //If the LD file command is entered, call a function that will loop through the lines
        //Else process the command
        if (strncmp(cmd, "LD", 2) == 0) {
            char file_name[10]; //FIX ME
            printf("Please enter a file name: ");
            scanf("%s", file_name);

            FILE* ptr = fopen(file_name, "r");
            if (ptr == NULL) {
                printf("File does not exist");
                return 0;
            } else {
                ld(&my_turtle, &my_map, ptr);
            }
        } else {
            decide_instruction(&my_turtle, &my_map, cmd);
        }
    }

    //case "", run each funcction


    /*
    The scanf in C returns three types of values:
        >0: The number of values converted and assigned successfully.
        0: No value was assigned.
        <0: Read error encountered or end-of-file(EOF) reached before any assignment was made.
*/

}


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