// https://www.geeksforgeeks.org/pointers-c-examples

#include <iostream>
#include <string>

using namespace std;

void SynchronizePointer() {
  int a;
  int *p = &a;

  cout << &a << endl;
  cout << p << endl;

  a = 8;
  cout << *p << endl;
  cout << a << endl;

  *p = 5;
  cout << *p << endl;
  cout << a << endl;
}

// Pass-by-Reference with Pointer Arguments 
void square2(int *n) {
  //Address of n in square2() is the same as n2 in main() 
  cout << "address of n2 in square2(): " << n << "\n"; 
  *n *= *n;
}

//Pass-by-Reference with Reference Arguments 
void square3(int &n) {
  //Address of n in square3() is the same as n3 in main() 
  cout << "address of n3 in square3(): " << &n << "\n"; 
  n *= n;
}

void greek() {
    //Call-by-Reference with Pointer Arguments 
    int n2 = 8; 
    cout << "address of n2 in main(): " << &n2 << "\n"; 
    square2(&n2); 
    cout << "Square of n2: " << n2 << "\n-------------------------------------\n"; 
      
    //Call-by-Reference with Reference Arguments 
    int n3 = 8; 
    cout << "address of n3 in main(): " << &n3 << "\n"; 
    square3(n3); 
    cout << "Square of n3: " << n3 << "\n"; 
}

void pointerForArray() {
  // int val[3] = { 5, 10, 20 };
  // int *ptr;

  // ptr = val; // same as ptr = &val[0];
  // // cout << "Elements of the array are: "; 
  // // cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << "\n"; 

  // for (int i = 0; i < 3; i++) { 
  //   cout << "Value at ptr = " << ptr << "\n"; 
  //   cout << "Value at *ptr = " << *ptr << "\n"; 
  //   // Increment pointer ptr by 1  
  //   ptr++; 
  // } 


  return;
}

int main() {
  SynchronizePointer();
  // greek();
  // pointerForArray();

  // string str1 = "apple";
  // string str2 = "apple";
  // cout << str2.compare(str1) << endl;
  

  return 0;
}