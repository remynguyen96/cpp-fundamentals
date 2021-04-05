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
  int arr[] = {7, 6, 5, 4, 3, 2, 1};
  // int arr[] = {1, 2, 3, 4, 5, 7, 6};
  // int arr[] = {5, 12, 1, 6, 9, 15, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  bool hasSorted;
  // cout << n << endl;

  // for (int i = 0; i < n - 1; i++) {
  //   hasSorted = true;

  //   for (int j = 0; j < n - i - 1; j++) {
  //     if (arr[j] > arr[j + 1]) {
  //       swap(arr[j], arr[j + 1]);
  //       hasSorted = false;
  //     }
  //   }

  //   printArr(arr, n);
  //   if (hasSorted) break;
  // }

  // Vice Versa
  for (int i = n - 1; i > 0; i--) {
    hasSorted = true;

    for (int j = n - 1; j > n - 1 - i; j--) {
      if (arr[j] > arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
        hasSorted = false;
      }
    }

    printArr(arr, n);

    if (hasSorted) break;
  }

  // for (int i = 0; i < n - 1; i++) {
  //   for (int j = i + 1; j < n; j++) {
  //     if (arr[i] > arr[j]) {
  //       swap(arr[i], arr[j]);
  //     }
  //   }
  //   printArr(arr, n);
  // }

  return 1;
}
