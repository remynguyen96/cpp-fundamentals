/**
  * StudentID: 2059005 - Nguyen Tiet Ngoc Chau
 **/

#include <iostream>
#include <string>
#include <cmath>
#include <fstream> 
#include <vector>
#include <sstream>

using namespace std;

struct Examinee {
  string id;
  float math;
  float literature;
  float physic;
  float chemistry;
  float biology;
  float history;
  float geography;
  float civicEducation;
  float naturalScience;
  float socialScience;
  float foreignLanguage;
};

struct Point {
  string test;
  float test2;
};

// vector<string> split(string str, string delimiter) {
//     size_t pos_start = 0, pos_end, delim_len = delimiter.length();
//     string token;
//     vector<string> res;

//     while ((pos_end = str.find(delimiter, pos_start)) != string::npos) {
//         token = str.substr (pos_start, pos_end - pos_start);
//         pos_start = pos_end + delim_len;
//         res.push_back (token);
//     }

//     res.push_back (str.substr (pos_start));
//     return res;
// }
void openFile(ifstream &ifs, string file);
Examinee readExaminee(string lineInfo);
vector<Examinee> readExamineeList(string fileName);
void writeTotal(vector<Examinee> examineeList, string outFileName);
string parseValue(string value);

int main() {
  system("clear");

  vector<Examinee> examineeList = readExamineeList("data/data.txt");

  writeTotal(examineeList, "data/result.txt");

  return 0;
}

void openFile(ifstream &ifs, string file) {
  ifs.open(file);

  if (!ifs.is_open()) {
    cout << "Something went wrong that could not open file!\n";
    cout << "Please try again!\n";
    return;
  }
}

string parseValue(string value) {
  return value.empty() ? "0" : value;
}

Examinee readExaminee(string lineInfo) {
  Examinee examinee; 
  stringstream stream(lineInfo);
  string info;
  vector<string> dataFields;

  while (getline(stream, info, ',')) {
    dataFields.push_back(info);
  }

  examinee.id = parseValue(dataFields[0]);
  examinee.math = stof(parseValue(dataFields[2]));
  examinee.literature = stof(parseValue(dataFields[3]));
  examinee.physic = stof(parseValue(dataFields[4]));
  examinee.chemistry = stof(parseValue(dataFields[5]));
  examinee.biology = stof(parseValue(dataFields[6]));
  examinee.history = stof(parseValue(dataFields[7]));
  examinee.geography = stof(parseValue(dataFields[8]));
  examinee.civicEducation = stof(parseValue(dataFields[9]));
  examinee.naturalScience = examinee.physic + examinee.chemistry + examinee.biology;
  examinee.socialScience = examinee.history + examinee.geography + examinee.civicEducation;
  examinee.foreignLanguage = stof(parseValue(dataFields[12]));

  // for(int index = 0; index <= dataFields.size(); index++)	{
  //   string value = dataFields[index];
  //   value = value.empty() ? "0" : value;

  //   if (index == 0) {
  //     examinee.id = value;
  //   } else if (index >= 2 && index <= 12) {
            
  //     switch(index) {
  //       case 2:
  //         examinee.math = stof(value);
  //         break;
  //       case 3:
  //         examinee.literature = stof(value);
  //         break;
  //       case 4:
  //         examinee.physic = stof(value);
  //         break;
  //       case 5:
  //         examinee.chemistry = stof(value);
  //         break;
  //       case 6:
  //         examinee.biology = stof(value);
  //         break;
  //       case 7:
  //         examinee.history = stof(value);
  //         break;
  //       case 8:
  //         examinee.geography = stof(value);
  //         break;
  //       case 9:
  //         examinee.civicEducation = stof(value);
  //         break;
  //       case 10:
  //         examinee.naturalScience = examinee.physic + examinee.chemistry + examinee.biology;
  //         break;
  //       case 11:
  //         examinee.socialScience = examinee.history + examinee.geography + examinee.civicEducation;
  //         break;  
  //       default:
  //         examinee.foreignLanguage = stof(value);
  //         break;
  //     }
  //   }
  // }

  return examinee;
}

vector<Examinee> readExamineeList(string fileName) {
  vector<Examinee> examineeList; 
  ifstream ifs;
  openFile(ifs, fileName);

  string ignoreFirstLine = "";
  getline(ifs, ignoreFirstLine);

  while(!ifs.eof()) {
    string lineInfo = "";
    getline(ifs, lineInfo);
    examineeList.push_back(readExaminee(lineInfo));
  }

  ifs.close();
  
  return examineeList;
}

void writeTotal(vector<Examinee> examineeList, string outFileName) {
  ofstream ofs;
  ofs.open(outFileName);

  if (!ofs.is_open()) {
    cout << "Something went wrong that could not open file!\n";
    cout << "Please try again!\n";
    return;
  }

  ofs << "ThongTinID" << "\tTongDiem\n";

  for (int i = 0; i < examineeList.size(); i++) {
    float total = examineeList[i].math + examineeList[i].literature + examineeList[i].foreignLanguage + examineeList[i].naturalScience + examineeList[i].socialScience;

    ofs << examineeList[i].id << "\t\t";
    ofs << total << "\n";
  }

  ofs.close();
}