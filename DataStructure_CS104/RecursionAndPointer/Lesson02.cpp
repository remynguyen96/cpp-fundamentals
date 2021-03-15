/**
  * StudentID: Remy Nguyen
  * Created at: 01/23/2020
 **/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int sumOfSquares(int n);
int gcd(int a, int b);
bool isPalindrome(int a[], int n);
int Factorial(int n);
int countDigit(int a, int counter); 
int FIB(int n);

int main() {
  system("clear");

  int n;
  int initialCounter = 0;

  cout << "Please enter a integer number: ";
  cin >> n;

  cout << "Having: " << countDigit(n, initialCounter) << " characters on number " << n << endl;

  return 0;
}

int countDigit(int n, int counter) {
  if (n == 0) return counter;

  return countDigit(n / 10, ++counter);
}

bool isAscending(int* arr, int n) {

}
