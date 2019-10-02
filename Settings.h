#include <iostream>

using namespace std;

class Settings{
  private:


  public:
    int fileSet;
    int outputSet;
    int boundarySet;
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
