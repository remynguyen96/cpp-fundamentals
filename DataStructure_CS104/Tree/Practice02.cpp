#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node *pLeft;
  Node *pRight;
};
typedef Node* Tree;

Tree initialTree() {
  Tree t = NULL;

  return t;
};

void addNodeToTree(Tree &t, int x) {
  if (t == NULL) {
    Node* pNode = new Node;

    pNode->data = x;
    pNode->pLeft = pNode->pRight = NULL;

    t = pNode;
    return;
  }

  if (x > t->data) {
    return addNodeToTree(t->pRight, x);
  }

  if (x < t->data) {
    return addNodeToTree(t->pLeft, x);
  }
}

// Node-Left-Right (Pre-order)
void printTreeByNLR(Tree t) {
  if (t == NULL) return;

  cout << t->data << endl;
  printTreeByNLR(t->pLeft);
  printTreeByNLR(t->pRight);
}
// Left-Node-Right (In-order)
void printTreeByLNR(Tree t) {
  if (t == NULL) return;

  printTreeByLNR(t->pLeft);
  cout << t->data << endl;
  printTreeByLNR(t->pRight);
}
// Left-Right-Node (Post-order)
void printTreeByLRN(Tree t) {
  if (t == NULL) return;

  printTreeByLRN(t->pLeft);
  printTreeByLRN(t->pRight);
  cout << t->data << endl;
}

Node* findMax(Tree t) {
  Node* pNode = t;

  while (pNode->pRight) {
    pNode = pNode->pRight;
  }

  return pNode;
}

Node* findMin(Tree t) {
  Node* pNode = t;

  while (pNode->pLeft) {
    pNode = pNode->pLeft;
  }

  return pNode;
}

void menu(Tree &t) {
  system("clear");
  while (true) {
    cout << "\n================= Menu =================";
    cout << "\n1. Enter data";
    cout << "\n2. Export data type by Node-Left-Right";
    cout << "\n3. Export data type by Left-Node-Right";
    cout << "\n4. Export data type by Left-Right-Node";
    cout << "\n5. Find Node Which Max Value";
    cout << "\n6. Find Node Which Min Value";
    cout << "\n7. Delete Node";

    cout << "\n0. End.\n\n";

    int option;
    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
      case 1:
        int x;
        cout << "Enter number of items of array: ";
        cin >> x;
        cout << "\n";

        for (int i = 0; i < x; i++) {
          int k;
          cout << "x[" << i << "] = ";
          cin >> k;
          cout << "\n";

          addNodeToTree(t, k);
        }
        break;

      case 2:
        printTreeByNLR(t);
        break;
      case 3:
        printTreeByLNR(t);
        break;
      case 4:
        printTreeByLNR(t);
        break;

      case 5:
        Node* maxNode = findMax(t);
        cout << "Max value is: " << maxNode->data << endl;
        break;
      case 6:
        Node* minNode = findMin(t);
        cout << "Min value is: " << minNode->data << endl;
        break;

      case 7:
        break;
      case 8:
        break;
      default:
        return;
    }
  }
}

int main() {
  Tree tree = initialTree();
  menu(tree);

  return 1;
}
