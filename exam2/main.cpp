/**
  * StudentID: 2059005 - Nguyen Tiet Ngoc Chau
  * Created at: 04/04/2021
  **/

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;
/*
Hãy cài đặt cây AVL theo yêu cầu sau:
1) Dữ liệu được lấy tuần tự từ tập tin names.txt
2) Kiểm tra 1 từ khóa có tồn tại trong cây AVL hay không?
Đọc 1 file input.txt có format tương tự names.txt.
Xuất kết quả ra file output_1.txt với dạng: 0 1
Trong đó 0 là kết quả (không tìm thấy) của từ khóa tìm kiếm thứ nhất trong tập tin input.txt,
1 là kết quả (tìm thấy) của từ khóa tìm kiếm thứ hai trong tập tin input.txt

3) Xóa các node trong cây AVL. Đầu vào là tập tin input.txt tương tự câu 2.
Xóa các từ khóa trong tập tin input.txt
và In các khóa trong cây AVL sau khi đã xóa hết theo LNR ra file output2_txt với format tương tự file names.txt
*/

struct Node {
  int height;
  string data;
  Node *pLeft, *pRight;
};

typedef Node* Tree;

/* Function protoypes for AVL*/
bool isEmpty(Tree);
bool isAVLTree(Tree);

Node* createNode(int);

int getHeight(Tree);
int calculateHeight(Tree);

void addNodeToTree(Tree &, int);
void removeNode(Tree &, int);

Tree leftRotate(Tree);
Tree rightRotate(Tree);

void printLevelOrderUseQueue(Tree);
/* Function protoypes for handling files*/
void createFile() {

}

// void printDataFromFile(Tree &tree, string fileName, ofstream &ofs) {
//   ifstream ifs;
//   ifs.open(fileName);

//   if (!ifs.is_open()) {
//     cout << "Could not open file!"<< endl;
//     return;
//   }

//   string data = "";

//   while (!ifs.eof()) {
//     getline(ifs, data, '\n'); // same as getline(ifs, data);
//     ofs << data;
//     ofs << "\n";

//     addNodeToTree(tree, data);
//   }

//   ifs.close();
// }

// int findKeywordOnFile(string keyword) {

// }

// void delete_line(const char *file_name, string name) {
//   ifstream ifs;
//   ifs.open(file_name);

//   ofstream ofs;
//   ofs.open("temp.txt", ofstream::out);

//   string data = "";
//   while (ifs >> data) {
//     if (data.compare(name) != 0) {
//       ofs << data;
//       ofs << "\n";
//     }
//   }

//   ifs.close();
//   ofs.close();

//   remove(file_name);
//   rename("temp.txt", file_name);
// }

int main() {
  Tree tree = NULL;
  ofstream ofs;

  ofs.open("input.txt");

  if (!ofs.is_open()) {
    cout << "Could not open file!"<< endl;
    return 0;
  }

  printDataFromFile(tree, "names.txt", ofs);
  // printLevelOrder(tree);

  ofs << "End";
  ofs.close();
  // delete_line("names.txt", "Xenia");
  // delete_line("input.txt", "Xenia");

  return 0;
}

Tree createNode(string data) {
  Node* pNode = new Node();

  pNode->data = data;
  pNode->pLeft = NULL;
  pNode->pRight = NULL;
  pNode->height = 1;

  return pNode;
}

bool isEmpty(Tree tree) {
  return tree == nullptr;
}

int getHeight(Tree tree) {
  if (isEmpty(tree)) return 0;

  return tree->height;
}

int calculateHeight(Tree tree) {
  if (isEmpty(tree)) return 0;

  return max(getHeight(tree->pLeft), getHeight(tree->pRight)) + 1;
}

int getBalanced(Tree tree) {
  if (isEmpty(tree)) return 0;

  int leftHeight = getHeight(tree->pLeft);
  int rightHeight = getHeight(tree->pRight);

  return leftHeight - rightHeight;
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
  Tree rightOfLeftChild = leftChild->pRight;

  leftChild->pRight = tree;
  tree->pLeft = rightOfLeftChild;

  tree->height = calculateHeight(tree);
  leftChild->height = calculateHeight(leftChild);

  return leftChild;
}

bool isAVLTree(Tree tree) {
  int balanceFactor = getBalanced(tree);

  return abs(balanceFactor) <= 1 ? true : false;
}

void addNodeToTree(Tree &tree, string data) {
  if (isEmpty(tree)) {
    tree = createNode(data);
    return;
  }

  if (data.compare(tree->data) < 0) {
    addNodeToTree(tree->pLeft, data);
  } else if (data.compare(tree->data) > 0) {
    addNodeToTree(tree->pRight, data);
  } else {
    return;
  }

  tree->height = calculateHeight(tree);

  int balanceFactor = getBalanced(tree);

  if (isAVLTree(tree)) return;

  if (!isEmpty(tree->pLeft) && !tree->pLeft->data.empty() && balanceFactor > 1) {
    if (data.compare(tree->pLeft->data) < 0) {
      tree = rightRotate(tree);
    }

    if (data.compare(tree->pLeft->data) > 0) {
      tree->pLeft = leftRotate(tree->pLeft);
      tree = rightRotate(tree);
    }
  }

  if (!isEmpty(tree->pRight) && !tree->pRight->data.empty() && balanceFactor < -1) {
    if (data.compare(tree->pRight->data) > 0) {
      tree = leftRotate(tree);
    }

    if (data.compare(tree->pRight->data) < 0) {
      tree->pRight = rightRotate(tree->pRight);
      tree = leftRotate(tree);
    }
  }
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