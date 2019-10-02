#include "Grid.h"
#include "Settings.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

// pause mode
void pauseOutput(){
  usleep(1000000); //pause one second
}
// enter mode
void enterOutput(){
  cin.get();
}
// file output mode
void fileOutput(){
  usleep(100000);
  cout << "Added to File." << endl;
}

//Main method
int main (int argc, char ** argv) {
  Settings s; //setting object
  int generation = 0; //iteration counter

  cout << "\nWelcome to Conway's Game of Life!" << endl;
  cout << "------------------------------------------" << endl;
  s.fileSettings(); //prompts/sets starting grid settings
  s.boundarySettings(); //prompts/sets boundary settings
  s.outputSettings(); //prompts/sets method of output

  //sets up ofstream (in case user wants to output to file)
  ofstream outfile(s.outFile);

  //determines output method
  void (*out)();
  if (s.outputSet == 1) {
    out = pauseOutput;
  } else if (s.outputSet == 2) {
    out = enterOutput;
  } else {
    out = fileOutput;
  }

  //sets up constructor based on starting grid settings
  if (s.fileSet == 1) {
    Grid myGrid(s.inFile, s.boundarySet); //map constructor
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
    Grid myGrid(s.dimX, s.dimY, s.density,  s.boundarySet); //random constructor
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
  outfile.close(); // closes ofstream
  cout << "World has stabilized. Please press 'Enter' to exit the program." << endl;
  cin.get();
  cout << "Thank you for playing Conway's Game of Life!" << endl;

  return 0;
}
