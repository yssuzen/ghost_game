Author: Yavuz Selim Suzen

Description of the program: 

List of files: main.c, building.c, room.c, ghost.c, defs.h, and README.txt

Instructions: For compiling the program, write "gcc -Wall -std=c99 -o main main.c building.c room.c ghost.c -g" in the terminal. After that, write "./main" for running the program. For checking memory leak, 
'valgrind ./main' should be written in the terminal. The user will select '1' for printing rooms, '2' for printing ghosts, '3' for printing ghost by likelihood, or '0' for quitting the program. If user selects 1, the program prints rooms. 
If user selects 2, prints out all the ghosts in the building’s master list in ascending order by ghost ID
If user selects 3, prints out all the ghosts in the building’s master list in descending order by ghost likelihood.
If user selects 0, the program is terminated.

For compiling the program: gcc -Wall -std=c99 -o main main.c building.c, room.c, ghost.c -g
For running the program: ./main
For checking memory leak: valgrind ./main
