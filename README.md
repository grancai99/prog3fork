# Programming Assignment 3 - Ascii Logo ("Draw Turtle Draw!")
## Introduction

Logo is a programming language created by Wally Feurzeig, Seymour Papert, and Cynthia Solomon in 1967.  Its purpose was to teach programming concepts by providing simple instructions to a "turtle" that moved across the screen.  The turtle contained a pen that would draw on the screen as it moved around.

Work on the assignment is to be done ***individually***.  You are welcome to collaborate with class members, but the project must be your own work.

## Background and References

In the original Logo, the programmer controls a "turtle" (drawn as a triangle on the screen) using various commands.  The commands instruct the turtle to move.  As the turtle moves, it has a pen attached to its tail that draws a line.  For example,

- FD n - Move the turtle forward n units
- BK n - Move the turtle backward n units
- RT n - Rotate the turtle right n degrees
- LT n - Rotate the turtle left n degrees
- PU - Raise the pen (pen up) so that it no longer draws as the turtle moves
- PD - Lower the pen (pen down) so that it draws as the turtle moves

If you happen to be lucky enough to have a color monitor there were various commands to change the pen color and background color as well.

Subroutines, loops, and conditionals were also possible as well as saving your program to disk.

For more information on the Logo programming language, consult the MIT archive of the Logo Manual:

- [https://dspace.mit.edu/bitstream/handle/1721.1/6226/AIM-313.pdf](https://dspace.mit.edu/bitstream/handle/1721.1/6226/AIM-313.pdf)

## Project Description

For this assignment you will be creating a logo interpreter that will perform a subset of logo commands.  The "screen" will consist of an n x n array grid and the "turtle" will occupy a position within the array.  As the user types commands, the turtle will move to a different position in the grid and potentially draw a character in the array as it moves.  At the end of processing each command you will print out the contents of the grid.  Instead of drawing in pixels, you'll be printing characters to the screen to represent the drawing.

The turtle maintains its current orientation (the direction it is facing).  This orientation can be changed by rotating the turtle left or right.  From there the turtle can move forward or backward.  The turtle can move up, down, left, right, diagonally based on the direction it is facing.  Furthermore, the turtle has a "pen" that makes a mark on the grid as the turtle moves.  This pen may be up or down.  If the pen is down (the default), a mark is made on the grid as the turtle moves.  If the pen is up, the turtle moves but leaves no mark behind it.

Once a mark is made to the grid, it is printed out as follows:

- For each up or down move print a pipe '|' character
- For each left or right move print a dash '-' character
- For each diagonal move print either a slash '/' or backslash '\' depending on the diagonal direction
- To note the current location of the turtle, print an 'X' where the turtle is located
- The current orientation of the turtle is not displayed in the grid

For example, consider the following 5 x 5 screen with the turtle initially located at position (3, 3) (zero indexed, of course) and facing up:

```text
*******
*     *
*     *
*     *
*  X  *
*     *
*******
```

NOTE: the coordinate (0, 0) is the upper left-hand corner of the screen and (d-1, d-1) is the lower right-hand corner of the screen (for a d x d screen).  Higher X coordinates are to the right and higher Y coordinates are down.

If the user tells the turtle to move forward, the resulting screen is:

```text
*******
*     *
*     *
*  X  *
*  |  *
*     *
*******
```

The following is the list of commands that the turtle can understand:

- FD – Move the turtle forward one space in the direction it is facing
- BK – Move the turtle backward one space in the direction it is facing
- RT – Rotate the turtle's orientation to the right 45 degrees
- LT – Rotate the turtle's orientation to the left 45 degrees
- PU – Pen Up – Stop the turtle from drawing as it moves
- PD – Pen Down – Start the turtle drawing as it moves
- LD – Load – Load a set of commands from a file

The screen is limited in size, if the turtle goes off the screen it should wrap back around to the other side.  For example, if the turtle keeps moving forward it should eventually wrap from the top of the screen to the bottom:

```text
*******
*     *
*     *
*  X  *
*  |  *
*     *
*******
```
```text
*******
*     *
*  X  *
*  |  *
*  |  *
*     *
*******
```
```text
*******
*  X  *
*  |  *
*  |  *
*  |  *
*     *
*******
```
```text
*******
*  |  *
*  |  *
*  |  *
*  |  *
*  X  *
*******
```

If the turtle crosses a location that has already been marked, the old mark is replaced with a new one based on the turtle's movement direction and orientation.  Remember, no marks are drawn if the turtle's pen is up.

When your program starts you will prompt the user to enter two values:

1. The dimension n of the screen.  This value must be greater than or equal to zero and less than 100.  If the user enters an incorrect value, print an error message and exit. 
2. The starting location of the turtle: two integers.  The first integer represents the starting column (x coordinate) for the turtle.  The second integer represents the starting row (y coordinate) for the turtle.  These integers must be greater than 0 and less than n.  If the user enters an incorrect value, print an error message and exit.

The turtle's initial orientation is always 'up'.  The turtle's pen is initially down.

From that point on, until the user enters the "end-of-file" character 'CTRL + D', print out the grid and prompt the user for a command.  The user can enter one of the supported commands.  After a command is input, process the command and print out the new grid contents.  If the user enters an invalid command, print a message indicating this to the user, redisplay the current grid, and prompt for another command.

## Project Development

Consider breaking down the project into pieces:

1. Handling user input
2. Maintaining the screen state
3. Drawing the output

To organize your code, separate out the control of the screen, management of the turtle  files separate from ```main.c```.  Make sure you create header files that ```main.c``` can include.

### Sample Output

NOTE: when printing the grid, print asterisks (*) to indicate the edges.

```text
Enter the dimensions of the screen:
9
Enter the turtle's starting location:
3 3
***********
*         *
*         *
*         *
*   X     *
*         *
*         *
*         *
*         *
*         *
***********

Enter a command:
FD

***********
*         *
*         *
*   X     *
*   |     *
*         *
*         *
*         *
*         *
*         *
***********

Enter a command:
RT

***********
*         *
*         *
*   X     *
*   |     *
*         *
*         *
*         *
*         *
*         *
***********
Enter a command:
FD

***********
*         *
*    X    *
*   /     *
*   |     *
*         *
*         *
*         *
*         *
*         *
***********

Enter a command:
FD

***********
*     X   *
*    /    *
*   /     *
*   |     *
*         *
*         *
*         *
*         *
*         *
***********

Enter a command:
FD

***********
*     /   *
*    /    *
*   /     *
*   |     *
*         *
*         *
*         *
*         *
*      X  *
***********

Enter a command:
CTRL + D
```

***NOTE:*** The last line of input is not text but the pressing of the keyboard buttons "control" (CRTL) and "D".  This sends the end of file (EOF) character as input.

### Load From a File (LD Command)

While ASCII logo can be used to draw some neat pictures, the user needs to manually type all the turtle commands.  To fix that, you need to support loading a set of commands from a file.  Here is how it works:

The LD command:

1. The user types the LD command and hits 'Enter'
2. The program prompts the user for the file to load
3. The file contains the dimensions, starting position, and set of commands (one per line).
   
   For example:
   ```text
   7
   3 3
   FD
   RT
   FD
   FD
    ```

4. The program reads the file, processes the commands, and prints the resulting screen
5. The program continues to ask the user for commands 

Sample execution:
```text
Enter the dimensions of the screen:
5
Enter the turtle's starting location:
3 3

*******
*     *
*     *
*     *
*   X *
*     *
*******

Enter a command:
LD
Enter file to load:
myfile

*********
*     X *
*    /  *
*   /   *
*   |   *
*       *
*       *
*       *
*********
 
Enter a command:
CTRL + D
```

***NOTE:*** The last line of input is not text but the pressing of the keyboard buttons "control" (CRTL) and "D".  This sends the end of file (EOF) character as input.

***NOTE:*** Loading a file overwrites the size of the grid, the current drawing, the location of the turtle, and the orientation of the turtle.

***NOTE:*** Prior to processing any commands in the file, the turtle orientation and pen should be set to the default (turtle direction of 'up' and a pen of 'down')

At the end of processing the file, leave the location and orientation of the turtle set based on the commands from the file.

***NOTE:*** You can assume the dimensions, turtle location, and commands in the file are valid.  As such, you will not have to perform any validation when you read the file and will be able to 'execute' the commands as you read them in.  Furthermore, there will be no LD commands in the file so there will be no need to recursively load files.

## Development Requirements

- Use a structure containing a 2D array to represent the screen.
- Separate your screen and turtle code into separate c files, each with their own header files.
  - When creating header files do not forget to use include guards to prevent recursive includes.
- Use pointers to pass the screen structure between functions.
- Remember that the turtle does not modify the marks on the screen when the pen is up.  Do not erase marks when the turtle moves when the pen is up.<br> 
  If the turtle moves to a location of a mark while the pen is up you will need to display an 'X' at the location to indicate the turtle's location but when the turtle moves again, the original mark is restored.  Consider the following example with the turtle facing down and to the right:
  ```text
  *******
  *     *
  * X   *
  * |   *
  * --- *
  *     *
  *******

  Enter a command:
  PU

  *******
  *     *
  * X   *
  * |   *
  * --- *
  *     *
  *******

  Enter a command:
  FD

  *******
  *     *
  *     *
  * |X  *
  * --- *
  *     *
  *******

  Enter a command:
  FD

  *******
  *     *
  *     *
  * |   *
  * --X *
  *     *
  *******

  Enter a command:
  FD

  *******
  *     *
  *     *
  * |   *
  * --- *
  *    X*
  *******
  ```
  Notice that the original '-' is restored after the turtle moves away from the marked location.

### Code Structure

Code must follow style guidelines as defined in the course material.

## Getting Started

The following files have been provided for you in your repository:

- [src/main.c](src/main.c) - Main file for your program - contains program entry point
- [src/turtle.h](src/turtle.h) - Declarations for turtle logic - functions and structure(s)
- [src/screen.h](src/screen.h) - Declarations for screen logic - functions and structure(s)
- [src/turtle.c](src/turtle.c) - To contain implementation of turtle logic
- [src/screen.c](src/screen.c) - To contain implementation of screen logic
- [src/Makefile](src/Makefile) - make file to build the project
- [sample](sample) - Directory containing sample command files

At the top of ***EACH SOURCE FILE*** include a comment block with your name, assignment name, and section number.

***NOTE:*** You ***MUST*** implement the turtle logic and screen logic in their own separate files:

Some sample files that can be used to test ```LD``` have been provided to assist in testing.  They are not exhaustive.  Make sure you test with your own files.

## Hints and Tips

- Using ```scanf``` can be helpful for reading in user input and commands
  - You can assume that all input will be no more than 50 characters in length
- Remember to validate the command.  Your program needs to only support the 7 commands specified.
- Don't forget to add include guards to your header files.
- Checking for end of file (EOF) can be tricky.  The ```man``` page for ```scanf``` describes the return value when end of file is reached.  Use this to your advantage.
- Use structures (```struct```) to your advantage.  Consider using a structure for a screen and a separate structure for the turtle.  This allows you to only have to pass pointers to functions instead of large numbers of parameters.

## Testing and Debugging

### Testing

You ***MUST*** submit test cases to prove that you adequately tested your program.  These should be files consisting of commands (valid and invalid).

### Debugging

See the course debugging tips for using ```gdb``` and ```valgrind``` to help with debugging.

Your program must be free of run-time errors and memory leaks.

## Deliverables

When you are ready to submit your assignment prepare your repository:

- Make sure your name, assignment name, and section number are all files in your submission - in comment block of source file(s)
- Make sure you cite your sources when using resources outside class material.
- Make sure your assignment code is commented thoroughly and follows the coding standard.
- Include in your submission, a set of suggestions for improvement and/or what you enjoyed about this assignment.
- Make sure all files are committed and pushed to the main branch of your repository.

***NOTE***: Do not forget to 'add', 'commit', and 'push' all new files and changes to your repository before submitting.

### Additional Submission Notes

If/when using resources from material outside what was presented in class (e.g., Google search, Stack Overflow, etc.) document the resource used in your submission.  Include exact URLs for web pages where appropriate.

NOTE: Sources that are not original research and/or unreliable sources are not to be used.  For example:

- Wikipedia is not a reliable source, nor does it present original research: [https://en.wikipedia.org/wiki/Wikipedia:Wikipedia_is_not_a_reliable_source](https://en.wikipedia.org/wiki/Wikipedia:Wikipedia_is_not_a_reliable_source)
- ChatGPT is not a reliable source: [https://thecodebytes.com/is-chatgpt-reliable-heres-why-its-not/](https://thecodebytes.com/is-chatgpt-reliable-heres-why-its-not/)

You should ensure that your program compiles without warnings (using -Wall) or errors prior to submitting.  Make sure your code is well documented (inline comments for complex code as well as comment blocks on functions).  Make sure you check your code against the style guidelines.

To submit, copy the URL for your repository and submit the link to Canvas.

## Grading Criteria

- (5 Points) Submitted files follow submission guidelines
    - Only the requested files were submitted
    - Files are contain name, assignment, section
    - Sources outside of course material are cited
- (5 Points) Suggestions
    - List of suggestions for improvement and/or what you enjoyed about this assignment
- (10 Points) Code standard
    - Code compiles without errors or warnings
    - Code is formatted and commented per the course coding standard
- (5 Points) Memory management
    - Code contains no memory leaks
- (25 Points) Submitted test cases
    - Test cases submitted are comprehensive and thoroughly test all required functionality
- (50 Points) Code passes instructor test cases
