# GameOfLife

1. IDENTIFYING INFORMATION
  a. Full Names: Lisa Pham and Meghana Shastri
  b. Student ID: Lisa = 2338933; Meghana = 2317343
  c. Chapman Email: Lisa = thupham@chapman.edu; Meghana = shastri@chapman.edu
  d. Course Number and Section: CPSC 350 section 2
  e. Assignment or Exercise Number: Assignment 2

2. A LIST OF ALL SOURCE FILED SUBMITTED FOR THIS ASSIGNMENT
  a. main.cpp
  b. Grid.h
  c. Grid.cpp
  d. Settings.h
  e. Settings.cpp
  f. t.txt
  g. glider.txt
  h. Makefile
  i. README.md

3. A DESCRIPTION OF ANY KNOWN COMPILE OR RUNTIME ERRORS, CODE LIMITATIONS, OR DEVIATIONS FROM ASSIGNMENT SPECIFICATIONS (IF APPLICABLE)
  a. No file checking (file existence, file opened, etc.)
  b. Mirror Method was brute forced due to time constraint
  c. usleep() is used instead of system(“pause”)

4. A LIST OF ALL REFERENCES USED TO COMPLETE THE ASSIGNMENT, INCLUDING PEERS (IF APPLICABLE)
  a. Arshia Sharma - helped with simplifying the code by breaking down the classes instead of having only 1 or 2 classes
  b. Charlie Liu - helped with how to populate the board and how to count the neighbors, helped with reading input file
  c. Matthew Raymond - helped with the sleep function and how to use that for the pause option in the simulation
  d. Function Pointer Reference - https://isocpp.org/wiki/faq/pointers-to-members
  e. Glider Shape - https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
  f. Debugging - https://www.geeksforgeeks.org/c-classes-and-objects/
  https://stackoverflow.com/

5. INSTRUCTIONS FOR RUNNING THE ASSIGNMENT
  a. Run ‘make all’ from terminal
  b. Run ‘./assignment2.out’
  c. Follow the instructions given by the program
    - Files are included if the user chooses to set up using a map:
    - t.txt : map setup given in the instructions
    - glider.txt : glider configuration on a 10x10
