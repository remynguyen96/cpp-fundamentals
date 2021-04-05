/**
  * StudentID: 2059005 - Nguyen Tiet Ngoc Chau
  * Created at: 27/11/2020
  **/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node *pLeft;
  Node *pRight;
};
typedef Node* Tree;

bool isEmpty(Tree tree) {
  return tree == NULL;
}

Tree initialTree() {
  Tree t = NULL;

  return t;
}

Tree createNode(int data) {
  Node* pNode = new Node;

  pNode->data = data;
  pNode->pLeft = pNode->pRight = NULL;

  return pNode;
}

void addNodeToTree(Tree &t, int x) {
  if (isEmpty(t)) {
    t = createNode(x);
    return;
  }

  if (x > t->data) {
    return addNodeToTree(t->pRight, x);
  }

  if (x < t->data) {
    return addNodeToTree(t->pLeft, x);
  }
}

void printTreeByLNR(Tree t) {
  if (t == NULL) return;

  printTreeByLNR(t->pLeft);
  cout << t->data << endl;
  printTreeByLNR(t->pRight);
}

bool searchNode(Tree tree, int key) {
  if (tree == NULL) return false;

  if (key < tree -> data) {
    return searchNode(tree -> pLeft, key);
  } else if (key > tree -> data) {
    return searchNode(tree -> pRight, key);
  }

  return true;
}

int main() {
  ifstream ifs;
  ifs.open("data.txt");

  if (!ifs.is_open()) {
    cout << "Could not open file!"<< endl;
    return 0;
  }

  Tree tree = initialTree();
  string data = "";

  while (!ifs.eof()) {
    getline(ifs, data, ' ');

    int x = static_cast<int>(stof(data));
    addNodeToTree(tree, x);
  }

  printTreeByLNR(tree);

  int key;
  cout << "Please enter number x to find: ";
  cin >> key;

  bool isFind = searchNode(tree, key);

  if (isFind) {
    cout << "Found!" << endl;
  } else {
    cout << "Not Found!" << endl;
  }

  ifs.close();
}