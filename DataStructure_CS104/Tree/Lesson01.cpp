#include <iostream>
#include <string>

using namespace std;

struct NODE {
  int data;
  NODE *pLeft;
  NODE *pRight;
};

NODE *createNode(int k) {
	NODE *pNew = new NODE;
	pNew -> data = k;
	pNew -> pLeft = NULL;
  pNew -> pRight = NULL;

	return pNew;
}

NODE *insertNode(NODE *root, int key) {
	if (root == NULL) {
		NODE *pNew = createNode(key);
    return pNew;
  }

	if (key < root -> data) {
		root -> pLeft = insertNode(root -> pLeft, key);
	} else if (key > root -> data) {
		root -> pRight = insertNode(root -> pRight, key);
	}

  return root;
}

void inOrder(NODE *root) {
  if (root == NULL) return;

  inOrder(root -> pLeft);
  inOrder(root -> pRight);

  cout << root -> data;
}

void postOrder(NODE *root) {
  if (root == NULL) return;

  inOrder(root -> pLeft);
  inOrder(root -> pRight);

  cout << root -> data;
}

bool search(NODE *root, int key) {
  if (root == NULL) return false;

  if (key < root -> data) {
    return search(root -> pLeft, key);
  } else if (key > root -> data) {
    return search(root -> pRight, key);
  }

  return true;
}

NODE *minValueNode(NODE *root) {
  NODE *pNode = root;

  while (pNode -> pLeft != NULL) {
    pNode = pNode -> pLeft;
  }

  return pNode;
}

NODE *maxValueNode(NODE *root) {
  NODE *pNode = root;

  while (pNode -> pRight != NULL) {
    pNode = pNode -> pRight;
  }

  return pNode;
}

NODE *deleteNode(NODE *root, int key) {
  if (root == NULL) return root;

  if (key < root -> data) {
    root -> pLeft = deleteNode(root -> pLeft, key);
  } else if (key > root -> data) {
    root -> pRight = deleteNode(root -> pRight, key);
  } else {
    if (root -> pLeft == NULL && root -> pRight == NULL) {
      return NULL;
    } else if (root -> pLeft != NULL && root -> pRight == NULL) {
      return root -> pLeft;
    } else if (root -> pLeft == NULL && root -> pRight != NULL) {
      return root -> pRight;
    } else {
      NODE *pStandfor = minValueNode(root -> pRight) ;
      root -> data = pStandfor -> data;
      root -> pRight = deleteNode(root -> pRight, root -> data);
    }
  }

  return root;
}


int main() {
  system("clear");

  NODE *pNode;

  return 1;
}