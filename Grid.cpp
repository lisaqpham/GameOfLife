#include "Grid.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Map Given constructor
Grid::Grid(string path, int boundarySetting) {
  ifstream infile(path);
  infile >> rows;
  infile >> cols;
  fileToGrid(infile);
  boundary = boundarySetting;
}

// Random constuctor
Grid::Grid(int x, int y, double d, int boundarySetting) {
  rows = x;
  cols = y;
  density = d;
  randToGrid();
  boundary = boundarySetting;
}

// changes -,X to 0,1
int Grid::charToInt(char c) {
  if (c == 'X') {
    return 1;
  } else {
    return 0;
  }
}

// changes 0,1 to -,X
char Grid::intToChar(int i) {
  if (i == 1) {
    return 'X';
  } else {
    return '-';
  }
}

// converts given text file to int 2d-array
int** Grid::fileToGrid(istream& infile) {
  char c;
  thisGen = new int*[rows];
  for (int i = 0; i < rows; i++) {
    thisGen[i] = new int[cols];
    for (int j = 0; j < cols; j++) {
      infile >> c;
      thisGen[i][j] = charToInt(c);
    }
  }
  return thisGen;
}

// converts 'random mode' settings to int 2d-array
int** Grid::randToGrid() {
  thisGen = new int*[rows];
  for (int i = 0; i < rows; i++) {
    thisGen[i] = new int[cols];
    for (int j = 0; j < cols; j++) {
      thisGen[i][j] = (double)rand()/RAND_MAX < density;
    }
  }
  return thisGen;
}

// prints grid to terminal
void Grid::printGrid(int** grid) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << intToChar(grid[i][j]);
    }
    cout << endl;
  }
}

// prints grid to given out file
void Grid::printGridToFile(int** grid, ofstream& file) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      file << intToChar(grid[i][j]);
    }
    file << endl;
  }
  file.flush();
}

// makes next generation based on current generation
int** Grid::makeNext() {
  nextGen = new int*[rows];
  for (int i = 0; i < rows; i++) {
    nextGen[i] = new int[cols];
    for (int j = 0; j < cols; j++) {
      nextGen[i][j] = rules(i, j);
    }
  }
  if (checkStable()) {
    terminate = 1;
  }
  thisGen = nextGen;
  return nextGen;
}

// rules for Game of Life, returns whether current cell lives or dies
int Grid::rules(int r, int c) {
  if (countNeighbors(r,c) == 2) {
    return thisGen[r][c];
  } else if (countNeighbors(r,c) == 3){
    return 1;
  } else {
    return 0;
  }
}

// counts surrounding neighbor based on boundary setting
int Grid::countNeighbors(int r, int c) {
  neighbors = 0; //initializes neighbor to 0

  if (boundary == 1) { // Classic Mode
    for (int i = -1; i < 2; i++) {
      for (int j = -1; j < 2; j++) {
        if ((r+i) < 0 || (r+i) >= rows || (c+j) < 0 || (c+j) >= cols) {
          neighbors += 0;
        } else {
          neighbors += thisGen[r+i][c+j];
        }
      }
    }
  } else if (boundary == 2) { // Doughnut Mode
    int nr, nc;
    for (int i = -1; i < 2; i++){
      for (int j = -1; j < 2; j++){
        nr = (r + i + rows) % rows;
        nc = (c + j + cols) % cols;
        neighbors += thisGen[nr][nc];
      }
    }
  } else {
    if (r == 0 && c == 0) { // Mirror Mode (brute forced due to time constraint)
      neighbors += 3*(thisGen[r][c]);
      neighbors += 2*(thisGen[r][c+1]);
      neighbors += 2*(thisGen[r+1][c]);
      neighbors += thisGen[r+1][c+1];
    } else if (r == 0 && c == cols - 1)  {
      neighbors += 3*(thisGen[r][c]);
      neighbors += 2*(thisGen[r][c-1]);
      neighbors += 2*(thisGen[r+1][c]);
      neighbors += thisGen[r+1][c-1];
    } else if (r == rows - 1 && c == cols - 1) {
      neighbors += 3*(thisGen[r][c]);
      neighbors += 2*(thisGen[r][c-1]);
      neighbors += 2*(thisGen[r-1][c]);
      neighbors += thisGen[r-1][c-1];
    } else if (r == rows - 1 && c == 0) {
      neighbors += 3*(thisGen[r][c]);
      neighbors += 2*(thisGen[r][c+1]);
      neighbors += 2*(thisGen[r-1][c]);
      neighbors += thisGen[r-1][c+1];
    } else if (r == 0) {
      for (int j = -1; j < 2; j++) {
        neighbors += 2*(thisGen[r][c + j]);
        neighbors += thisGen[r+1][c + j];
      }
    } else if (r == rows - 1) {
      for (int j = -1; j < 2; j++) {
        neighbors += 2*(thisGen[r][c + j]);
        neighbors += thisGen[r-1][c + j];
      }
    } else if (c == 0) {
      for (int i = -1; i < 2; i++) {
        neighbors += 2*(thisGen[r + i][c]);
        neighbors += thisGen[r + i][c+1];
      }
    } else if (c == cols - 1) {
      for (int i = -1; i < 2; i++) {
        neighbors += 2*(thisGen[r + i][c]);
        neighbors += thisGen[r + i][c-1];
      }
    } else {
      for (int i = -1; i < 2 ; i++) {
        for (int j = -1; j < 2; j++) {
          neighbors += thisGen[r+i][c+j];
        }
      }
    }
  }
  // correction: methods for all modes count current cell, so we need to subtract
  neighbors -= thisGen[r][c];
  return neighbors;
}

// checks grid to see if this generation equals next generation aka stabilization
bool Grid::checkStable() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (!(thisGen[i][j] == nextGen[i][j])) {
        return 0;
      }
    }
  }
  return 1;
}
