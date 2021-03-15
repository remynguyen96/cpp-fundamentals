#include <iostream>
// #include <iomanip>
// #include <ctime>
// #include <cstdlib>

using namespace std;

/* Let us create following BST
    50
  /   \
30      70
/ \   / \
20 40 60 80 */

struct Node {
  int data;
  Node *pLeft, *pRight;
};

typedef Node* Tree;

bool isEmpty(Tree tree) {
  return tree == nullptr;
}

Tree createNode(int data) {
  Tree tree = new Node;

  tree->data = data;
  tree->pLeft = tree->pRight = nullptr;

  return tree;
}

void inOrder(Tree t) {
    if (t == nullptr) return;

    inOrder(t->pLeft);
    cout << t->data << " ";
    inOrder(t->pRight);
}

void addNodeToTree(Tree &tree, int value) {
  if (isEmpty(tree)) {
    tree = createNode(value);
    return;
  }

  int currentValue = tree->data;

  if (currentValue > value) {
    return addNodeToTree(tree->pLeft, value);
  } else {
    return addNodeToTree(tree->pRight, value);
  }
}

void addNodeIteratively(Tree &tree, int value) {
  Tree newNode = createNode(value);

  if (isEmpty(tree)) {
    tree = newNode;
    return;
  }

  Tree newTree = tree;
  Tree y = nullptr;

  while (!isEmpty(newTree)) {
    y = newTree;

    if (newTree->data > value) {
      newTree = newTree->pLeft;
    } else {
      newTree = newTree->pRight;
    }
  }

  if (isEmpty(y)) {
    y = newNode;
  }

  if (y->data > value) {
    y->pLeft = newNode;
  } else {
    y->pRight = newNode;
  }
}

// rotate right
// Node* q = p -> left;
// p->left = q->right
// q->right = p;
//  p = q;

int main() {
  Tree tree = nullptr;
  Tree tree2 = nullptr;

  int x;
  cout << "Enter number of items of array: ";
  // cin >> x;
  x = 5;
  cout << x << "\n";

  srand(time(nullptr));
  for (int i = 0; i < x; i++) {
    int k;
    cout << "x[" << i << "] = ";
    // cin >> k;
    k = rand() % (100 + 1);
    cout << k << "\n";

    addNodeToTree(tree, k);
    addNodeIteratively(tree2, k);
  }

  inOrder(tree);
  cout << "\n\n---------------------------------\n\n";
  inOrder(tree2);

  return 1;
}