#include <iostream>
#include <cmath>

using namespace std;

struct Node {
  int height;
  int data;
  Node *pLeft, *pRight;
};

typedef Node* Tree;

bool isEmpty(Tree tree) {
  return tree == nullptr;
}

Tree cloneTree(Tree tree) {
  Tree newTree = new Node;

  if(!isEmpty(tree)) {
      newTree->height = tree->height;
      newTree->data = tree->data;
      newTree->pLeft = cloneTree(tree->pLeft);
      newTree->pRight = cloneTree(tree->pRight);

      cout <<"Clone "<< tree->data << endl;
  }

  return newTree;
}

Tree createNode(int data) {
  Tree node = new Node();

  node->data = data;
  node->height = 0;
  node->pLeft = node->pRight = NULL;

  return node;
}

void inOrder(Tree t) {
    if (t == NULL) return;

    inOrder(t->pLeft);
    cout << t->data << " ";
    inOrder(t->pRight);
}

int calculateHeight(Tree tree) {
  if (isEmpty(tree)) return -1;
  // if (isEmpty(tree->pLeft) && isEmpty(tree->pRight)) return 0;

  return tree->height;
}

int getBalanced(Tree tree) {
  if (isEmpty(tree)) return 0;

  int leftHeight = calculateHeight(tree->pLeft);
  int rightHeight = calculateHeight(tree->pRight);

  // value <= 1. It means the tree is balanced
  return abs(leftHeight - rightHeight);
}

void leftRotate(Tree &tree) {

}

void rightRotate(Tree &tree) {


}


// 80 16 93 24 98

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

// 80 16 93 24 98

// 80 root without stack, height = 0;

// 16 left
// with root is 80, leftheight is 0, rightheight is -1, currentHeight is 0
// height at root = 0 + 1
// balanceFactor at root = 0 - (-1) = 1;

// 93 right
// with root is 80, leftheight is 0, rightheight is 0, currentHeight is 0
// height at root = 0 + 1
// balanceFactor at root =  0 - 0 = 0;

// 24 left
// with root is 16, leftheight is -1, rightheight is 0, currentHeight is 0
// height at root = 0 + 1 = 1
// balanceFactor at root = |-1 - 0| = 1;

// with root is 80, leftheight is 1, rightheight is 0, currentHeight is 0
// height at 16 root = 1 + 1 = 2
// balanceFactor at root = 1 - 0 =  1;

// 98 right
// with root is 93, leftheight is -1, rightheight is 0, currentHeight is 0
// height at root = 1 + 0 = 1
// balanceFactor at root = |- 1 - 0| =  1;

// with root is 80, leftheight is 1, rightheight is 1, currentHeight is 1
// height at 16 root = 1 + 1 = 2
// balanceFactor at root = 1 - 1 =  0;

  int currentHeight = max(calculateHeight(tree->pLeft), calculateHeight(tree->pRight));
  tree->height = currentHeight + 1;

  int balanceFactor = getBalanced(tree);

  if (balanceFactor <= 1) return;

  cout << "stack:: root factor: " << balanceFactor << endl;
  int leftBalanceFactor = getBalanced(tree->pLeft);
  int rightBalanceFactor = getBalanced(tree->pRight);

  cout << "stack:: left factor: " << leftBalanceFactor << endl;
  cout << "stack:: right factor: " << rightBalanceFactor << endl;

  cout << "value: " << value << endl;
  cout << "left: " << tree->data << endl;
  cout << "right: " << tree->data << endl;

  if (value < tree->data) {
    // right rotate
    cout << "Right rotate" << endl;
  }

  if (value > tree->data) {
      // left rotate
    cout << "left rotate" << endl;
  }

  return;


    // Left Left Case
    // if (balance > 1 && key < node->left->key)
    //     return rightRotate(node);

    // Right Right Case
    // if (balance < -1 && key > node->right->key)
    //     return leftRotate(node);

}


Tree createNode2(int data) {
  Tree node = new Node();

  node->data = data;
  node->height = 1;
  node->pLeft = node->pRight = NULL;

  return node;
}

void rotateLeft(Tree tree) {
  Tree newTree = tree->pLeft;


}

void rotateRight(Tree tree) {
  Tree newTree = tree->pRight;


}

int calculateHeight2(Tree tree) {
  if (isEmpty(tree)) return 0;

  return tree->height;
}

void addNodeToTree2(Tree &tree, int value) {
  if (isEmpty(tree)) {
    tree = createNode2(value);
    return;
  }

  if (value < tree->data) {
    addNodeToTree2(tree->pLeft, value);
  } else if (value > tree->data) {
    addNodeToTree2(tree->pRight, value);
  } else {
    return;
  }

  int leftHeight = calculateHeight2(tree->pLeft);
  int rightHeight = calculateHeight2(tree->pRight);
  int x = leftHeight - rightHeight;

  if (x > 1) {
    cout << "rotation" << endl;
  }

  cout << rightHeight << endl;
  cout << leftHeight << endl;

  tree->height = max(leftHeight, rightHeight) + 1;
}


// rotate right
// Node* q = p -> left;
// p->left = q->right
// q->right = p;
//  p = q;

int main() {
  Tree tree = NULL;

  // int x;
  // cout << "Enter number of items of array: ";
  // x = 15;
  // cout << x << "\n";

  // srand(time(NULL));
  // for (int i = 0; i < x; i++) {
  //   int k;
  //   cout << "x[" << i << "] = ";
  //   k = rand() % (100 + 1);
  //   cout << k << "\n";

  //   addNodeToTree(tree, k);
  // }

  // addNodeToTree(tree, 80);
  // addNodeToTree(tree, 16);
  // addNodeToTree(tree, 93);
  // addNodeToTree(tree, 24);
  // addNodeToTree(tree, 98);

  addNodeToTree2(tree, 80);
  addNodeToTree2(tree, 16);
  addNodeToTree2(tree, 24);


  inOrder(tree);

  return 1;
}