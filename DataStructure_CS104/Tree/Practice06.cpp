#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int height;
  int data;
  Node *pLeft, *pRight;
};

typedef Node* Tree;

bool isEmpty(Tree);
bool isAVLTree(Tree);

Node* createNode(int);
Tree createTree(int [], int);

int getHeight(Tree);
int calculateHeight(Tree);

void addNodeToTree(Tree &, int);
void removeNode(Tree &, int);

Tree leftRotate(Tree);
Tree rightRotate(Tree);
Tree searchNode(Tree, int);

void LevelOrder(Tree);
void preOrder(Tree);

int main() {
  Tree tree = NULL;

  int x;
  cout << "Enter number of items of array: ";
  x = 3;
  cout << x << "\n";

  srand(time(NULL));

  int testFindingNode = 0;

  for (int i = 0; i < x; i++) {
    int k;
    cout << "x[" << i << "] = ";
    k = rand() % (100 + 1);
    cout << k << "\n";

    if (i == 0) testFindingNode = k;

    addNodeToTree(tree, k);
  }

  // cout << searchNode(tree, testFindingNode) << endl;

  cout << "\n\n";

  preOrder(tree);

  return 1;
}

bool isEmpty(Tree tree) {
  return tree == nullptr;
}

bool isAVLTree(Tree tree) {
  int balanceFactor = getHeight(tree->pLeft) - getHeight(tree->pRight);

  return (balanceFactor > 1 || balanceFactor < -1) ? false : true;
}

Node* createNode(int data) {
  Tree node = new Node();

  node->data = data;
  node->height = 1;
  node->pLeft = node->pRight = NULL;

  return node;
}

Tree createTree(int arr[], int n) {
  Tree tree = new Node();

  for (int i = 0; i < n; i++) {
    addNodeToTree(tree, arr[i]);
  }

  return tree;;
}

int getHeight(Tree tree) {
  if (isEmpty(tree)) return 0;

  return tree->height;
}

int calculateHeight(Tree tree) {
  if (isEmpty(tree)) return 0;

  return max(getHeight(tree->pLeft), getHeight(tree->pRight)) + 1;
}

Tree searchNode(Tree tree, int key) {
  if (isEmpty(tree)) return NULL;

  if (key < tree->data) {
    return searchNode(tree->pLeft, key);
  } else if (key > tree->data) {
    return searchNode(tree->pRight, key);
  }

  if (tree->data == key) return tree;

  return NULL;
}

Tree leftRotate(Tree tree) {
  Tree rightChild = tree->pRight;
  Tree leftChildOfRight = rightChild->pLeft;

  tree->pRight = leftChildOfRight;
  rightChild->pLeft = tree;

  tree->height = calculateHeight(tree);
  rightChild->height = calculateHeight(rightChild);

  return rightChild;
}

Tree rightRotate(Tree tree) {
  Tree leftChild = tree->pLeft;
  Tree rightChildOfLeft = leftChild->pRight;

  tree->pLeft = rightChildOfLeft;
  leftChild->pRight = tree;

  tree->height = calculateHeight(tree);
  leftChild->height = calculateHeight(leftChild);

  return leftChild;
}

void addNodeToTree(Tree &tree, int value) {
  if (isEmpty(tree)) {
    tree = createNode(value);
    return;
  }

  if (value < tree->data) {
    addNodeToTree(tree->pLeft, value);
  } else if (value > tree->data) {
    addNodeToTree(tree->pRight, value);
  } else {
    return;
  }

  int balanceFactor = getHeight(tree->pLeft) - getHeight(tree->pRight);

  if (balanceFactor > 1 && value < tree->pLeft->data) {
    tree = rightRotate(tree);
  }

  if (balanceFactor > 1 && value > tree->pLeft->data) {
    tree->pLeft = leftRotate(tree->pLeft);
    tree = rightRotate(tree);
  }

  if (balanceFactor < -1 && value > tree->pRight->data) {
    tree = leftRotate(tree);
  }

  if (balanceFactor < -1 && value < tree->pRight->data) {
    tree->pRight = rightRotate(tree->pRight);
    tree = leftRotate(tree);
  }

  tree->height = calculateHeight(tree);
}

void removeNode(Tree &tree, int value) {

}

void preOrder(Tree t) {
  if (t == NULL) return;

  cout << t->data << " ";
  preOrder(t->pLeft);
  preOrder(t->pRight);
}

void LevelOrder(Tree tree) {

}