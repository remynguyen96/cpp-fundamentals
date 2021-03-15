#include <iostream>
#include <string>
#include <cmath>

// #define MAX_SIZE 100

using namespace std;

void inputArray(int* &a, int &n);
void printArray(int* a, int n);
void dellocateArray(int* &a);

void sortArray(int *&array, const int n);

int linearSearch(int* a, int n, int key);

int main() {
  // system("clear");

  int *array, n;

  inputArray(array, n);

  sortArray(array, n);

  printArray(array, n);

  // int key;
  // cout << "Please enter key that need to find: ";
  // cin >> key;

  cout << "isPalindrome: " << isPalindrome(array, n) << endl;

  // cout << "Linear Search: " << linearSearch(arr, n) << endl;
  // cout << "Sentine Linear Search: " << sentinelLinearSearch(arr, n) << endl;

  // cout << "Binary Search: " << binarySearch(arr, n, key) << endl;
  // cout << "Recursive Binary Search: " << recursiveBinarySearch(arr, n, key) << endl;

  // dellocateArray(array);
  return 0;
}

void dellocateArray(int *&array) {
  cout << "Starting dellocate array to release memory ...." << endl;
  delete [] array;
}

void printArray(int* array, int n) {
  cout << "--------------------------------------------------------------------------\n";

  for (int i = 0; i < n; i++) {
    // Same as cout << "array[" << i << "] = " << *(array + i) << endl;
    cout << "array[" << i << "] = " << array[i] << endl;
    cout << "\n";
  }
}

void sortArray(int *&array, const int n) {
  int temp;

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (array[i] > array[j]) {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
      }
    }
  }
}

void inputArray(int* &array, int &n) {
  array = new int[n]; // new allocates memory on heap

  cout << "Please enter an integer number n = ";
  do {
    cin >> n;

    if (n < 1) {
      cout << "\nInvalid Number!\n";
    }
  } while (n < 1);
  cout << "\n";

  for (int i = 0; i < n; i++) {
    cout << "array[" << i << "] = ";
    cin >> array[i];
    // Same as cin >> *(array + i);
    cout << "\n";
  }
}

// int binarySearch(int* array, int n, int key) {
//   int midNumber = round(n / 2);

//   if (array[midNumber] < key) {
//     for (int i = 0; i < midNumber; i++) {
//       if (array[i] == key) {
//         return i;
//       }
//     }
//   } else {
//     for (int i = midNumber; i < n; i++) {
//       if (array[i] == key) {
//         return i;
//       }
//     }
//   }

//   return -1;
// }