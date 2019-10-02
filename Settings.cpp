#include "Settings.h"
#include <iostream>
#include <fstream>

using namespace std;

// setting constructor
Settings::Settings() {
  dimX = 0;
  dimY = 0;
  density = 0;
  inFile = "";
  outFile = "";
}

// Starting Grid Settings
int Settings::fileSettings(){
  cout << "\nHow would you like to set up your world?" << endl;
  cout << "   1: Setup using a map file" << endl;
  cout << "   2: Random setup" << endl;
  cout << "Please enter a number: ";

  cin >> fileSet;
  if (fileSet == 1){
    mapSet();
  } else if (fileSet == 2) {
    randomSet();
  } else {
    cout << "Please try again" << endl;
    fileSettings();
  }
}

// Random Setting
void Settings::randomSet() {
  cout << "\nYou chose Random." << endl;
  cout << "Please specify the number of rows/columns and the population density: " << endl;
  cout << "# of Rows? ";
  cin >> dimX;
  cout << "# of Cols? ";
  cin >> dimY;
  cout << "Population Density? " << endl;
  cout << "   Please input a number within (0-1]: ";
  cin  >> density;
}

// Map Setting
void Settings::mapSet() {
  cout << "\nYou chose Map." << endl;
  cout << "Please specify the file path: " << endl;
  cin  >> inFile;
}

// Output Setting (what happens between iterations)
int Settings::outputSettings(){
  cout << "\nGreat! Before we start, please configure your output settings." << endl;
  cout << "Would you like to: " << endl;
  cout << "   1: Have a brief pause between each generation output" << endl;
  cout << "   2: Press 'Enter' to display the next generation" << endl;
  cout << "   3: Output all generations to a file" << endl;
  cout << "Please enter a number: ";

  cin >> outputSet;
  cin.ignore();
  if (outputSet == 1){
    cout << "You chose Brief Pause." << endl;
    return outputSet;
  } else if (outputSet == 2) {
    cout << "You chose Enter." << endl;
    return outputSet;
  } else if (outputSet == 3){
    cout << "You chose File Output. Please enter the file path you wish to output to: ";
    cin >> outFile;
    return outputSet;
  } else {
    cout << "Please try again" << endl;
    outputSettings();
  }
}

// Boundary Settings
int Settings::boundarySettings(){
  cout << "\nHow would you like to set up your boundaries?" << endl;
  cout << "Choose a mode: " << endl;
  cout << "   1: Classic Mode" << endl;
  cout << "     - all locations off the grid considered empty" << endl;
  cout << "   2: Doughnut Mode" << endl;
  cout << "     - grid is wrapped around itself horizontally and vertically" << endl;
  cout << "   3: Mirror Mode" << endl;
  cout << "     - locations off the grid are reflections of the edges" << endl;
  cout << "Please enter a number: ";

  cin >> boundarySet;
  if (boundarySet == 1){
    cout << "You chose Classic." << endl;
    return boundarySet;
  } else if (boundarySet == 2) {
    cout << "You chose Doughnut." << endl;
    return boundarySet;
  } else if (boundarySet == 3){
    cout << "You chose Mirror." << endl;
    return boundarySet;
  } else {
    cout << "Please try again" << endl;
    boundarySettings();
  }
}
