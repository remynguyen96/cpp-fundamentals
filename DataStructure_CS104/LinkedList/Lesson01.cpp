#include <iostream>
#include <cmath>

using namespace std;
// TODO: Handle linked List with one pointer;

struct Node {
  int data;
  Node *pNext;
};

typedef Node* List;

void Init(List &l) {
  l = NULL;
}

bool isEmpty(List l) {
  return l == NULL;
}

Node *createNode(int data) {
  Node *pNode = new Node;

  if (pNode == NULL) return NULL;

  pNode -> data = data;
  pNode -> pNext = NULL;

  return pNode;
}

void printListNode(List List) {
  while (List->data) {
    cout << List->data << endl;
    List = List->pNext;
  }
}

void AddTail(List &l, Node *p) {
  if (l == NULL) {
    l = p;
  } else {
    Node *newPointer = l;

    while (newPointer -> pNext) { // checking newPointer -> pNext != NULL;
      newPointer = newPointer -> pNext;
    }

    newPointer -> pNext = p;
  }
}

void Input(List &l) {
  int n;
  cout << "Please enter number n = ";
  cin >> n;

  Init(l);

  for (int i = 0; i < n; i++) {
    int x;
    cout << "Enter a integer number x[" << i << "] = ";
    cin >> x;
    cout << endl;

    Node *p = createNode(x);

    if (p != NULL) {
      AddTail(l, p);
    }
  }
}

int main() {
  List l;

  Input(l);

  printListNode(l);

  return 0;
}