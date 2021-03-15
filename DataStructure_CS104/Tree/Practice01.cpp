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

// Node-Right-Left
void printTreeByNRL(Tree t) {
  if (t == NULL) return;

  cout << t->data << endl;
  printTreeByNRL(t->pRight);
  printTreeByNRL(t->pLeft);
}

// From less to larger
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

// From large to less than
// Right-Node-Left
void printTreeByRNL(Tree t) {
  if (t == NULL) return;

  printTreeByRNL(t->pRight);
  cout << t->data << endl;
  printTreeByRNL(t->pLeft);
}

// Right-Left-Node
void printTreeByRLN(Tree t) {
  if (t == NULL) return;

  printTreeByRLN(t->pRight);
  printTreeByRLN(t->pLeft);
  cout << t->data << endl;
}
// example: 5 7 -2 0 -5 1 6 -3

bool isPrimeNumber(int number) {
  if (number < 2) return false;

  for (int i = 2; i <= number / 2; i++) {
    if (number % i == 0) return false;
  }

  return true;
}

// Left - Node - Right
int amountOfPrimeTree(Tree t) {
  int counter = 0;

  if (t == NULL) return counter;

  amountOfPrimeTree(t->pLeft);

  if (isPrimeNumber(t->data)) {
    counter++;
    cout << "Counter: "<< counter << endl;
    cout << "Prime number = ";
  } else {
        cout << "Counter: "<< counter << endl;
    cout << "Is not prime number = ";
  }

  cout << t->data << endl;

  return amountOfPrimeTree(t->pRight);
}


void menu(Tree &t) {
  system("clear");
  while (true) {
    cout << "\n================= Menu =================";
    cout << "\n1. Enter data";
    cout << "\n2. Export data type by Node-Left-Right";
    cout << "\n3. Export data type by Node-Right-Left";

    cout << "\n4. Export data type by Left-Node-Right";
    cout << "\n5. Export data type by Left-Right-Node";

    cout << "\n6. Export data type by Right-Node-Left";
    cout << "\n7. Export data type by Right-Left-Node";

    cout << "\n8. Export all prime numbers";

    cout << "\n0. End.\n\n";

    int option, quantityPrimeNumbers;
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
        printTreeByNRL(t);
        break;

      case 4:
        printTreeByLNR(t);
        break;
      case 5:
        printTreeByLRN(t);
        break;

      case 6:
        printTreeByRNL(t);
        break;
      case 7:
        printTreeByRLN(t);
        break;

      case 8:
        quantityPrimeNumbers = amountOfPrimeTree(t);
        cout << "Amount of prime numbers are: " << quantityPrimeNumbers << endl;
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
