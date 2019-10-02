#include <iostream>

using namespace std;

class Settings{
  public:
    int fileSet, outputSet, boundarySet;
    int dimX, dimY;
    double density;
    string inFile, outFile;

    Settings();
    void randomSet();
    void mapSet();
    int fileSettings();
    int outputSettings();
    int boundarySettings();

};
