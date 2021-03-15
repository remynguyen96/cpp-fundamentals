#include <iostream>

using namespace std;

void swap(int &x, int &y) {
  x = x + y;

  y = x - y;
  x = x - y;
}

int main() {
  int n = 7;
  int arr[] = {5, 12, 1, 6, 9, 15, 7};

  for (int i = 0; i < n - 1; i++) {
    int min = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[min] > arr[j]) {
        swap(i, j);
      }
    }
  }


  return 1;
}
