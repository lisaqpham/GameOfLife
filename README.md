# GameOfLife

### 1. IDENTIFYING INFORMATION
  * Full Names: Lisa Pham and Meghana Shastri
  * Student ID: Lisa = 2338933; Meghana = 2317343
  * Chapman Email: Lisa = thupham@chapman.edu; Meghana = shastri@chapman.edu
  * Course Number and Section: CPSC 350 section 2
  * Assignment or Exercise Number: Assignment 2

### 2. A LIST OF ALL SOURCE FILED SUBMITTED FOR THIS ASSIGNMENT
  * main.cpp
  * Grid.h
  * Grid.cpp
  * Settings.h
  * Settings.cpp
  * t.txt
  * glider.txt
  * Makefile
  * README.md

### 3. A DESCRIPTION OF ANY KNOWN COMPILE OR RUNTIME ERRORS, CODE LIMITATIONS, OR DEVIATIONS FROM ASSIGNMENT SPECIFICATIONS (IF APPLICABLE)
  * No file checking (file existence, file opened, etc.)
  * Mirror Method was brute forced due to time constraint
  * usleep() is used instead of system(“pause”)

### 4. A LIST OF ALL REFERENCES USED TO COMPLETE THE ASSIGNMENT, INCLUDING PEERS (IF APPLICABLE)
  * Arshia Sharma - helped with simplifying the code by breaking down the classes instead of having only 1 or 2 classes
  * Charlie Liu - helped with how to populate the board and how to count the neighbors, helped with reading input file
  * Matthew Raymond - helped with the sleep function and how to use that for the pause option in the simulation
  * Function Pointer Reference - https://isocpp.org/wiki/faq/pointers-to-members
  * Glider Shape - https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
  * Debugging - https://www.geeksforgeeks.org/c-classes-and-objects/
  https://stackoverflow.com/

### 5. INSTRUCTIONS FOR RUNNING THE ASSIGNMENT
  * 1. Run ‘make all’ from terminal
  * 2. Run ‘./assignment2.out’
  * 3. Follow the instructions given by the program
    - Files are included if the user chooses to set up using a map:
    - t.txt : map setup given in the instructions
    - glider.txt : glider configuration on a 10x10
