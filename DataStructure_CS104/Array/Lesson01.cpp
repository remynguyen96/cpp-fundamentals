#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void inputArray(int* &a, int &n);
void printArray(int* a, const int n);
void dellocateArray(int* &a);

void sortArray(int *&array, const int n);
void reverseArray(int* &a, const int n);

int sumOfArray(int* a, const int n);
bool isAscendingArray(int* a, const int n);
int findMinNumber(int* a, const int n);
int findMaxNumber(int* a, const int n);

bool isPrimeNumber(const int number);
int countPrime(int* arr, int n);

int main() {
  system("clear");

  int *array, n;

  inputArray(array, n);

  // sortArray(array, n);

  // reverseArray(array, n);

  // printArray(array, n);

  // cout << "Smallest number is: " << findMinNumber(array, n) << endl;

  // cout << "Largest number is: " << findMaxNumber(array, n) << endl;

  // cout << "Checking number of array ascending or not : " << isAscendingArray(array, n) << endl;

  // cout << "Sum is: " << sumOfArray(array, n) << endl;

  cout << "The quantity of prime number are: " << countPrime(array, n) << endl;

  dellocateArray(array);
  return 0;
}

void dellocateArray(int *&array) {
  cout << "\nStarting dellocate array to release memory ...." << endl;
  delete [] array;
}

void printArray(int* array, const int n) {
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

int findMinNumber(int* arr, const int n) {
  int smallest = arr[0];

  for (int i = 0; i < n; i++) {
    if (arr[i] < smallest) {
      smallest = arr[i];
    }
  }

  return smallest;
}

int findMaxNumber(int* arr, const int n) {
  int largest = abs(arr[0]);

  for (int i = 0; i < n; i++) {
    int absoluteCurrentNumber = abs(arr[i]);

    if (absoluteCurrentNumber > largest) {
      largest = absoluteCurrentNumber;
    }
  }

  return largest;
}

bool isAscendingArray(int* arr, const int n) {
  for (int i = n - 1; i > 0; i--) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }

  return true;
}

int sumOfArray(int* arr, const int n) {
  int sum = arr[0];
  for (int i = 1; i < n; i++) {
    sum += arr[i];
  }

  return sum;
}


void reverseArray(int* &array, const int n) {
  int* tempArray = new int[n];

  for (int i = 0; i < n; i++) {
    tempArray[i] = array[n - 1 - i];
  }

  array = tempArray;
}

bool isPrimeNumber(const int number) {
  if (number < 2) return false;

  for (int i = 2; i <= number / 2; i++) {
    if (number % i == 0) return false;
  }

  return true;
}

int countPrime(int* array, const int n) {
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (isPrimeNumber(array[i])) {
      count++;
    }
  }

  return count;
}