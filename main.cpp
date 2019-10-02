//#include "FileHelper.h"
#include "Grid.h"
#include "Settings.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

void pauseOutput(){
  usleep(1000000); //pause one second
}

void enterOutput(){
  cin.get();
}

void fileOutput(){
  usleep(100000);
  cout << "Added to File." << endl;
}

int main (int argc, char ** argv) {
  Settings s;
  int generation = 0;

  cout << "\nWelcome to Conway's Game of Life!" << endl;
  cout << "------------------------------------------" << endl;
  s.fileSettings();
  s.boundarySettings();
  s.outputSettings();

  ofstream outfile(s.outFile);

  void (*out)();
  if (s.outputSet == 1) {
    out = pauseOutput;
  } else if (s.outputSet == 2) {
    out = enterOutput;
  } else {
    out = fileOutput;
  }

  if (s.fileSet == 1) {
    Grid myGrid(s.inFile, s.boundarySet);
    while (!myGrid.terminate) {
      cout << "Gen " << generation << endl;
      myGrid.printGrid(myGrid.thisGen);
      if (outfile.is_open()) {
        outfile << "Gen " << generation << endl;
        myGrid.printGridToFile(myGrid.thisGen, outfile);
      }
      myGrid.makeNext();
      out();
      generation++;
    }
  } else {
    Grid myGrid(s.dimX, s.dimY, s.density,  s.boundarySet);
    while (!myGrid.terminate) {
      cout << "Gen " << generation << endl;
      myGrid.printGrid(myGrid.thisGen);
      if (outfile.is_open()) {
        outfile << "Gen " << generation << endl;
        myGrid.printGridToFile(myGrid.thisGen, outfile);
      }
      myGrid.makeNext();
      out();
      generation++;
    }
  }
  outfile.close();
  cout << "World has stabilized. Please press 'Enter' to exit the program." << endl;
  cin.get();
  cout << "Thank you for playing Conway's Game of Life!" << endl;

  return 0;
}
