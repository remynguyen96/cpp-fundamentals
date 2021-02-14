/**
  * StudentID: 2059005 - Nguyen Tiet Ngoc Chau
 **/

#include <iostream>
#include <cmath>

struct NODE {
  int data;
  NODE *pNext;
};

NODE *createNode(int data) {
  NODE *pNode = new NODE;
  if (pNode == NULL) return NULL;

  pNode -> data = data;
  pNode -> pNext = NULL;

  return pNode;
}

int main() {
  system("clear");

  return 0;
}

