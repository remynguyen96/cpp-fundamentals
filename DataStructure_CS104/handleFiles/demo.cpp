#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

using namespace std;

struct Student {
  string name;
  int math;
  float literature;
  float physic;
};

int main() {
  system("clear");

  ifstream ifs; 
  ifs.open("mocks/data.txt");

  if (!ifs.is_open()) {
    cout << "Could not open file!"<< endl;
    return 0; 
  }

  string ignore_line = ""; 

  getline(ifs, ignore_line);

  string name = "";
  string math = "";
  string literature = "";
  string physic = "";
  vector<Student> listStudents; 
  Student student;

  while (!ifs.eof()) {
    getline(ifs, name, ';');
    getline(ifs, math, ';');
    getline(ifs, literature, ';');
    getline(ifs, physic, ';');

    student.name = name;
    // student.math = stof(math);
    student.math = (int)stof(math);
    student.literature = stof(literature);

    student.physic = stof(physic);

    listStudents.push_back(student);
  }

  ifs.close();
  
  ofstream ofs;
  ofs.open("bin/result.txt");

  if (!ofs.is_open()) {
    cout << "Could not open file!" << endl;

    return 0;
  }

  ofs << "Ten;Tong\n";

  for (int i = 0; i < listStudents.size(); i++) {
    ofs << listStudents[i].name << ';';
    ofs << listStudents[i].math + listStudents[i].literature << ";";
    ofs << listStudents[i].physic << "\n";
  }

  ofs.close();
}