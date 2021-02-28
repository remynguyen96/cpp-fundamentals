#include <iostream>
#include <cmath>

using namespace std;
// TODO: Handle linked list with one pointer;

struct NODE {
  int data;
  NODE *pNext;
};

typedef NODE* LIST;

void Init(LIST &l) {
  l = NULL;
}

bool isEmpty(LIST l) {
  return l == NULL;
}

NODE *createNode(int data) {
  NODE *pNode = new NODE;

  if (pNode == NULL) return NULL;

  pNode -> data = data;
  pNode -> pNext = NULL;

  return pNode;
}

void AddTail(LIST &l, NODE *p) {
  if (l == NULL) {
    l = p;
  } else {
    NODE *newPointer = l;

    while (newPointer -> pNext) { // checking newPointer -> pNext != NULL;
      newPointer = newPointer -> pNext;
    }

    newPointer -> pNext = p;
  }
}

void Input(LIST &l) {
  int n;
  cout << "Please enter number n = ";
  cin >> n;

  Init(l);

  for (int i = 0; i < n; i++) {
    int x;
    cout << "Enter a integer number x[" << i << "] = ";
    cin >> x;
    cout << endl;

    NODE *p = createNode(x);

    if (p != NULL) {
      AddTail(l, p);
    }
  }
}

int main() {
  system("clear");

  LIST l;
  Input(l);

  return 0;
}