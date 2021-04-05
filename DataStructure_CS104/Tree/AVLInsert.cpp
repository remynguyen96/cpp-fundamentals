#include <iostream>
using namespace std;

struct NODE{
    int key;
    int height = 1;
    NODE* left;
    NODE* right;
};

NODE *createNode(int data)
{
    NODE* newNode = new NODE();
    newNode->key = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

int height(NODE* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

void RotateLeft(NODE *&P)
{
    NODE* Q = P->right;
    P->right = Q->left;
    P->height = max(height(P->left),height(P->right))+1;
    Q->left = P;
    Q->height = max(height(Q->left),height(Q->right))+1;
    P = Q;
}

void RotateRight(NODE *&P)
{
    NODE* Q = P->left;
    P->left = Q->right;
    P->height = max(height(P->left),height(P->right))+1;
    Q->right = P;
    Q->height = max(height(Q->left),height(Q->right))+1;
    P = Q;

}
void Insert(NODE* &root, NODE*p){
    if (root == nullptr){
        root = p;
        return;
    }
    if(root->key > p->key)
    {
        Insert(root->left, p);
    }
    else if(root->key < p->key)
    {
        Insert(root->right,p);
    }
    int x = (height(root->left)-height(root->right));
    if (x > 1) {
        if (root->left->key < p->key) {
            // cout << "Trai - Phai";
            RotateLeft(root->left);
        } else {
            //cout << "Trai - Trai";
        }
        RotateRight(root);
    } else {
        if (x < -1) {
        if (root->right->key < p->key) {
            // cout << "Phai - Phai";
        } else {
            // cout << "Phai - Trai";
            RotateRight(root->right);
        }
        RotateLeft(root);
    }
    }
    root->height = max(height(root->left),height(root->right))+1;
}

NODE* createTree(int *arr, int n)
{
    NODE* root = nullptr;
    for(int i =0;i<n;i++)
    {
        NODE *newNode = createNode(arr[i]);
        Insert(root, newNode);
    }
    return root;
}


int main(){
    int arr[8] = {1,2,3,4,5,6,7,8};

    NODE *tree = createTree(arr, 8);
    return 0;
}