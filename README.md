*This project has been created as part of the 42 curriculum by <pifonsec>*

DESCRIPTION : 

The goal of this project is to implement the function get_next_line.

get_next_line reads a file line by line and returns the next line each time the function is called.
Each call to the function returns a single line from the given file descriptor, until the end of the file is reached.

This project focuses on:

-File descriptors
-Static variables
-Memory allocation and management
-Buffer handling
-Efficient reading from files

INSTRUCTIONS : 

To compile the project:
make

To remove object files:
make clean

To remove object files and the executable (if applicable):
make fclean

To recompile everything:
make re

How It Works :

The function reads from a file descriptor using a buffer of size BUFFER_SIZE.
It stores unfinished data using a static variable.
Each call extracts and returns one complete line (including the newline character, if present).
Reading stops when the end of file (EOF) is reached or an error occurs.

RESSOURCES :

Project planning and visualization were created using Miro:
https://miro.com/app/board/uXjVGd0JNV4=/

AI tools were used to assist with debugging and better understanding certain concepts during development.
