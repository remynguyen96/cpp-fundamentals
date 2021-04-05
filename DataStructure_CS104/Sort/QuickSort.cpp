#include <iostream>

using namespace std;

void swap(int *xp, int *yp) {
  *xp = *xp + *yp;

  *yp = *xp - *yp;
  *xp = *xp - *yp;
}

void printArr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ---- ";
  }
  cout << endl;
}

int main() {
  // int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int arr[] = {5, 12, 1, 6, 9, 15, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < n - 1; i++) {
    int min = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[min] > arr[j]) {
        min = j;
      }
    }

    swap(arr[min], arr[i]);

    printArr(arr, n);
  }

  return 1;
}
