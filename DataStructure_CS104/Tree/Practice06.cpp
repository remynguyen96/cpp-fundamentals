#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int height;
  int data;
  Node *pLeft, *pRight;
};
typedef Node* Tree;

/* Function protoypes */
bool isEmpty(Tree);
bool isAVLTree(Tree);

Node* createNode(int);
Tree createTree(int [], int);

int getHeight(Tree);
int calculateHeight(Tree);

void addNodeToTree(Tree &, int);
void deleteNode(Tree &, int);
void removeTree(Tree &);

Tree leftRotate(Tree);
Tree rightRotate(Tree);
Tree searchNode(Tree, int);

void preOrder(Tree);

void printGivenLevel(Tree, int);
void printLevelOrder(Tree);

void printLevelOrderUseQueue(Tree);

// Tree cloneTree(Tree tree) {
//   Tree newTree = new Node;

//   if(!isEmpty(tree)) {
//       newTree->height = tree->height;
//       newTree->data = tree->data;
//       newTree->pLeft = cloneTree(tree->pLeft);
//       newTree->pRight = cloneTree(tree->pRight);

//       cout <<"Clone "<< tree->data << endl;
//   }

//   return newTree;
// }

int main() {
  Tree tree = NULL;

  addNodeToTree(tree, 50);

  addNodeToTree(tree, 40);
  addNodeToTree(tree, 70);

  addNodeToTree(tree, 30);
  addNodeToTree(tree, 45);

  addNodeToTree(tree, 60);
  addNodeToTree(tree, 80);

  addNodeToTree(tree, 20);
  addNodeToTree(tree, 85);

  addNodeToTree(tree, 49);
  addNodeToTree(tree, 44);
  addNodeToTree(tree, 43);

  printLevelOrderUseQueue(tree);

  deleteNode(tree, 40);

  cout << "\n\n\n";
  printLevelOrderUseQueue(tree);

  // cout << tree << endl;

  // cout << searchNode(tree, testFindingNode) << endl;

  // cout << "\n\n";

  // preOrder(tree);
  // printLevelOrder(tree);

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
  Tree newTree = tree;

  while (newTree != NULL) {
    if (key < newTree->data) {
      newTree = newTree->pLeft;
    } else if (key > newTree->data) {
      newTree = newTree->pRight;
    } else {
      return newTree;
    }
  }

  return NULL;
}

Tree searchNode2(Tree tree, int key) {
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
  Tree leftOfRightChild = rightChild->pLeft;

  tree->pRight = leftOfRightChild;
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

void removeTree(Tree &tree) {
  if (isEmpty(tree)) return;

  removeTree(tree->pLeft);
  removeTree(tree->pRight);

  delete tree;
  tree = NULL;
}

Tree maxValueNode(Tree tree) {
  Tree current = tree;

  while (current->pRight != NULL) {
    current = current->pRight;
  }

  return current;
}

int getBalance(Node *N) {
  if (N == NULL) return 0;

  return getHeight(N->pLeft) - getHeight(N->pRight);
}

void deleteNode(Tree &tree, int value) {
  if (isEmpty(tree)) return;

  if (value < tree->data) {
    return deleteNode(tree->pLeft, value);
  }

  if (value > tree->data) {
    return deleteNode(tree->pRight, value);
  }

  if (value != tree->data) {
    cout << "Could not found the value " << value <<" to remove at tree" << endl;
    return;
  };

  if (isEmpty(tree->pLeft) || isEmpty(tree->pRight)) {
    Tree temp = !isEmpty(tree->pLeft) ? tree->pLeft : tree->pRight;

    if (isEmpty(temp)) {
      // do not any children
      temp = tree;
      tree = NULL;
    } else {
      // only one child
      *tree = *temp;

      temp = NULL;
      delete temp;
    }
  } else {
    Tree temp = maxValueNode(tree->pLeft);
    tree->data = temp->data;

    deleteNode(tree->pLeft, temp->data);
  }

   if (isEmpty(tree)) return;

   tree->height = calculateHeight(tree);

  int balanceFactor = getHeight(tree->pLeft) - getHeight(tree->pRight);
  // Left Left Case
  if (balanceFactor > 1 && getBalance(tree->pLeft) >= 0) {
    tree = rightRotate(tree);
    return;
  }

  // Left Right Case
  if (balanceFactor > 1 && getBalance(tree->pLeft) < 0) {
    tree->pLeft = leftRotate(tree->pLeft);
    tree = rightRotate(tree);
    return;
  }

  // Right Right Case
  if (balanceFactor < -1 && getBalance(tree->pRight) <= 0) {
    tree = leftRotate(tree);
    return;
  }

  // Right Left Case
  if (balanceFactor < -1 && getBalance(tree->pRight) > 0) {
    tree->pRight = rightRotate(tree->pRight);
    tree = leftRotate(tree);
    return;
  }
}

void preOrder(Tree t) {
  if (t == NULL) return;

  cout << t->data << " ";
  preOrder(t->pLeft);
  preOrder(t->pRight);
}
/*
    50
  /   \
30      70
/ \   / \
20 40 60 80
*/
void printLevelOrder(Tree tree) {
  int h = tree->height;

  for (int i = 0; i < h; i++) {
   printGivenLevel(tree, i);
  }
}

void printGivenLevel(Tree tree, int index) {
  if (isEmpty(tree)) return;

  if (index == 0) {
    cout << tree->data << "(" << tree->height << ") " << endl;
    return;
  }

  printGivenLevel(tree->pLeft, index - 1);
  printGivenLevel(tree->pRight, index - 1);
}

void printLevelOrderUseQueue(Tree tree) {
  if (isEmpty(tree)) return;

  // Create a empty queue;
  queue<Tree> q;

  // Enqueue root and initialize height
  q.push(tree);

  while (!q.empty()) {
    Tree root = q.front();

    cout << root->data << " -- " << root->height << endl;

    q.pop();

    if (!isEmpty(root->pLeft)) {
      q.push(root->pLeft);
    }

    if (!isEmpty(root->pRight)) {
      q.push(root->pRight);
    }
  }
}
