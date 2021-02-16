#include <iostream>
#include <cmath>

using namespace std;
// TODO: Handle linked list with 2 pointers

struct NODE {
  int data;
  NODE *pNext;
};

struct LIST {
  NODE *pHead;
  NODE *pTail;
};

void Init(LIST &l) {
  l.pHead = NULL;
  l.pTail = NULL;
}

bool isEmpty(LIST l) {
  return l.pHead == NULL;
}

NODE *createNode(int data) {
  NODE *pNode = new NODE;

  if (pNode == NULL) return NULL;

  pNode -> data = data;
  pNode -> pNext = NULL;

  return pNode;
}

void AddTail(LIST &l, NODE *p) {
  if (l.pHead == NULL) {
    l.pHead = l.pTail = p;
  } else {
    l.pTail -> pNext = p;
    l.pTail = p;
  }
}

void Input(LIST &l) {
  int n;

  cout << "Please enter a number n = ";
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

