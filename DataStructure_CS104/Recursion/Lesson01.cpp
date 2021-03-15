#include <iostream>
#include <string>
#include <cmath>

#define MAX_SIZE 100

using namespace std;

void inputArray(int* &a, int &n);
void printArray(int* a, int n);
void dellocateArray(int* &a);
void sortArray(int *&array, int n);
int findMin(int* a, int n);
int findMaxModulus(int* a, int n);
bool isAscending(int* a, int n);
int sumOfArray(int* a, int n);
bool isPrimeNumber(int number);
int countPrime(int* arr, int n);
void ReverseArray(int* &a, int n);
int linearSearch(int* a, int n, int key);
int sentinelLinearSearch(int* a, int n, int key);
int binarySearch(int *array, int n, int key);
int recursiveBinarySearch(int* a, int left, int right, int key);

// bool isPalindrome(int array[], int n, int i = 0) {
//   // cout << i << endl;
//   // cout << array[i] << "--------------" << n - i - 1 << "-----" << array[n - i - 1] << endl;
//   if (array[i] != array[n - i - 1]) {
//     return false;
//   }

//   return isPalindrome(array, n, ++i);
// }

// bool isPalindrome(int *array[], int n) {
//   if (n < 2) return true;

//   printArray(array, n);

//   if (array[i] != array[n - 1]) {
//     return false;
//   }

//   return isPalindrome(array + 1, n - 2);
// }

int main() {
  system("clear");

  int *arr;
  int n;


  inputArray(arr, n);

  int key;
  cout << "Please enter key that need to find: ";
  cin >> key;

  // printArray(arr, n);
  // cout << "isPalindrome: " << isPalindrome(arr, n) << endl;
  // cout << "Smallest number is: " << findMin(arr, n) << endl;
  // cout << "Largest number is: " << findMaxModulus(arr, n) << endl;
  // cout << "Checking number of array ascending or not : " << isAscending(arr, n) << endl;
  // cout << "Sum is: " << sumOfArray(arr, n) << endl;
  // cout << "The quantity of prime number are: " << countPrime(arr, n) << endl;
  // cout << "Reverse Array : " << ReverseArray(arr, n) << endl;
  // cout << "Linear Search: " << linearSearch(arr, n) << endl;
  // cout << "Sentine Linear Search: " << sentinelLinearSearch(arr, n) << endl;
  // cout << "Binary Search: " << binarySearch(arr, n, key) << endl;
  // cout << "Recursive Binary Search: " << recursiveBinarySearch(arr, n, key) << endl;

  dellocateArray(arr);
  return 0;
}

void dellocateArray(int *&array) {
  delete [] array;
}

void sortArray(int *&array, int n) {
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

void inputArray(int* &arr, int &n) {
  cout << "Please enter an integer number n = ";

  do {
    cin >> n;

    if (n < 1) {
      cout << "\nInvalid Number!\n";
    }
  } while (n < 1);
  cout << "\n";

  // arr = new int[n];
  int *array = new int[n];
  arr = array;

  for (int i = 0; i < n; i++) {
    cout << "array[" << i << "] = ";
    cin >> *(array + i); // same as array[i]
    cout << "\n";
  }

  sortArray(array, n);
  dellocateArray(array);
}

void printArray(int *array, int n) {
  cout << "-------------------------------------\n";

  for (int i = 0; i < n; i++) {
    cout << "array[" << i << "] = " << *(array + i) << endl; // array[i]
    cout << "\n";
  }
}

int binarySearch(int* array, int n, int key) {
  int midNumber = round(n / 2);

  if (array[midNumber] < key) {
    for (int i = 0; i < midNumber; i++) {
      if (array[i] == key) {
        return i;
      }
    }
  } else {
    for (int i = midNumber; i < n; i++) {
      if (array[i] == key) {
        return i;
      }
    }
  }

  return -1;
}

int findMin(int* arr, int n) {
  int smallest = arr[0];

  for (int i = 0; i < n; i++) {
    if (arr[i] < smallest) {
      smallest = arr[i];
    }
  }

  return smallest;
}

int findMaxModulus(int* arr, int n) {
  int largest = abs(arr[0]);

  for (int i = 0; i < n; i++) {
    int absoluteCurrentNumber = abs(arr[i]);

    if (absoluteCurrentNumber > largest) {
      largest = absoluteCurrentNumber;
    }
  }

  return largest;
}

bool isAscending(int* arr, int n) {
  for (int i = n - 1; i > 0; i--) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }

  return true;
}

int sumOfArray(int* arr, int n) {
  int sum = arr[0];
  for (int i = 1; i < n; i++) {
    sum += arr[i];
  }

  return sum;
}


// bool isPrimeNumber(int number) {
//   if (number < 2) {
//     return false;
//   } else {
//     int counter = 0;

//     for (int i = 1; i <= number; i++) {
//       if (number % i == 0) {
//         counter++;
//       }
//     }

//     if (counter == 2) {
//       return true;
//     }

//     return false;
//   }
// }

// int countPrime(int* arr, int n) {
//   int count = 0;


//   for (int i = 0; i < n; i++) {
//     if (isPrimeNumber(arr[i])) {
//       count++;
//     }
//   }

//   return count;
// }

// int recursiveBinarySearch(int* array, int left, int right, int key) {
//   int midNumber = round(n / 2);

//   if (array[midNumber] < key) {
//     recursiveBinarySearch(array, left, right, key);
//     for (int i = 0; i < midNumber; i++) {
//       if (array[i] == key) {
//         return i;
//       }
//     }
//   } else {
//     recursiveBinarySearch(array, left, right, key);
//     for (int i = midNumber; i < n; i++) {
//       if (array[i] == key) {
//         return i;
//       }
//     }
//   }

//   return -1;
// }
