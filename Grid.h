#include <iostream>

using namespace std;

class Grid{
  private:
    int rows, cols;
    double density;
    int boundary;

  public:
    int** thisGen;
    int** nextGen;
    int neighbors = 0;
    bool terminate = 0;

    Grid();
    Grid(string path, int boundarySetting);
    Grid(int x, int y, double d, int boundarySetting);
    ~Grid();

    int charToInt(char c);
    char intToChar(int i);
    int** fileToGrid(istream& infile);
    int** randToGrid();
    void printGrid(int** grid);
    void printGridToFile(int** grid, ofstream& file);
    int** makeNext();
    int rules(int r, int c);
    int countNeighbors(int r, int c);
    bool checkStable();

};
