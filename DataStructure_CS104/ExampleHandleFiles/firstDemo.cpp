#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void createTxtFile() {
  system("clear");
  cout << "Please, waiting a few minutes...\n";

  fstream fs;
  fs.open("bin/text.txt", fstream::in | fstream::out | fstream::app);

  fs << "GOOD JOB";
  cout << "Done!\n";
  fs.close();
}

int main() {
  createTxtFile();

  return 0;
}
