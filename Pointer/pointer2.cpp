// clang++ -std=c++17 -stdlib=libc++ -g pointer2.cpp -o bin/main && bin/main
#include <iostream>
#include <string>

using namespace std;

struct Person {
  string name;
  int age;
}; 

Person inputData(Person&);
void displayData(Person);

void inputListData(Person* &, int &);
void displayListData(Person*, int);
void dellocateArray(Person* &);

int main() {
  // Basic Pointer
  // Person *ptr, p;
  // ptr = &p;

  // inputData(p);

  // displayData(*ptr);
  
  // Advance Pointer
  Person *pointerArray;
  int n;

  inputListData(pointerArray, n);

  displayListData(pointerArray, n);

  dellocateArray(pointerArray);
  
  return 0;
}

void dellocateArray(Person* &personArray) {
  cout << "Dellocate: " << personArray << endl;
  delete [] personArray;
}

void inputListData(Person* &personArray, int &n) {
  cout << "Please enter n: ";
  cin >> n;
  cout << endl;
  cout << "Before: " << personArray << endl;

  // Should be recommended
  personArray = new Person[n];
  cout << "After: " << personArray << endl;
  // other method
  // Person *array = new Person[n];
  // array = personArray; // same as personArray = array;

  for (int i = 0; i < n; i++) {
    inputData(personArray[i]); // same as personArray[i], *(personArray + i), *(array + i);
    cout << "\n";
  }
}

Person inputData(Person &p) {
  cout << "Please enter your age: ";
  cin >> p.age;
  cout << endl;

  cout << "Please enter your name: ";
  cin.ignore();
  getline(cin, p.name);
  cout << endl;

  return p;
}

void displayListData(Person *personArray, int n) {
  cout << "\n\t\t\tDisplaying Information." << endl;

  for (int i = 0; i < n; i++) {
    displayData(personArray[i]);
  }
}

void displayData(Person p) {
    cout << "Name: " << p.name << endl;
    cout <<"Age: " << p.age << endl;
    cout << "\n";
}