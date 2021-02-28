#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>      // std::setprecision

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

void Initial(LIST &);
bool isEmpty(LIST);
NODE *CreateNode(int);
void AddNodeTail(LIST &, NODE *);
void InputIntegerNumber(string, int &);
void InputNode(LIST &, int);
void OutputNode(LIST);
void SortAscendant(LIST);
NODE *FindLargestNode(LIST);

int main() {
  system("clear");

  int n;
  LIST list;

  InputIntegerNumber("n", n);

  InputNode(list, n);

  // FindLargestNode(list);

  SortAscendant(list);

  OutputNode(list);

  return 0;
}

void Initial(LIST &l) {
  l.pHead = NULL;
  l.pTail = NULL;
};

bool isEmpty(LIST l) {
  return l.pHead == NULL;
};

NODE *CreateNode(int data) {
  NODE *pNode = new NODE;

  if (pNode == NULL) return NULL;

  pNode -> data = data;
  pNode -> pNext = NULL;

  return pNode;
};

void AddNodeTail(LIST &l, NODE *p) {
  if (l.pHead == NULL) {
    l.pHead = l.pTail = p;
  } else {
    l.pTail -> pNext = p;
    l.pTail = p;
  }
};

void InputIntegerNumber(string str, int &n) {
  cout << "Please enter an integer number " << str << " = ";
  cin >> n;
  cout << endl;
}

void InputNode(LIST &l, int n) {
  Initial(l);

  for (int i = 0; i < n; i++) {
    int x;
    InputIntegerNumber("x["+ to_string(i) + "]", x);

    NODE *pNode = CreateNode(x);

    if (pNode != NULL) {
      AddNodeTail(l, pNode);
    }
  };
};

void OutputNode(LIST l) {
  NODE *pNode = l.pHead;

  // double f =3.14159;
  // std::cout << std::setprecision(5) << f << '\n';

  int i = 0;
  while (pNode) { // same as pNode != NULL
    cout << setw(8);
    cout << "x[" << i << "] = " << pNode -> data << endl;

    pNode = pNode -> pNext;
    i++;
  }
};

NODE *FindLargestNode(LIST l) {
  NODE *pNode = l.pHead;
  NODE *pLargestNode = l.pHead;

  while (pNode) { // same as pNode != NULL
    if (pLargestNode -> data < pNode -> data) {
      pLargestNode = pNode;
    };

    pNode = pNode -> pNext;
  }

  cout << "Largest number is: " << pLargestNode -> data << endl;
  return pLargestNode;
};

void SortAscendant(LIST l) {
  for (NODE *p = l.pHead; p -> pNext != NULL; p = p -> pNext) {
    for (NODE *q = p -> pNext; q != NULL; q = q -> pNext) {
      if (p -> data  > q -> data) {
        int temp = p -> data;
        p -> data = q -> data;
        q -> data = temp;
      }
    }
  }
};