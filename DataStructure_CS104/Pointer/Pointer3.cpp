#include <iostream>

using namespace std;

int normal_1, normal_2;

void update(int* pointer) {
   *pointer = 10;
   pointer = &normal_2;
   *pointer = 20;
}

int main(void) {
   normal_1 = 1; normal_2 = 2;
   int* pointer = &normal_1;
   update(pointer);
   cout << normal_1 << " " << normal_2 << " " << *pointer << endl; // 10 20 10;
}

//https://vnoi.info/wiki/languages/cpp/pointers.md