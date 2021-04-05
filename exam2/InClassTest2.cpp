#include <iostream>
#include <queue>
#include <fstream>
#include <string>
using namespace std;

/*
* already have in file
*
bool operator<(string const& a, string const& b) {
    return true;
};
*/
struct NODE {
    string key;
    int height = 1;
    NODE* left;
    NODE* right;
};

NODE* createNode(string data)
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

void RotateLeft(NODE*& P)
{
    NODE* Q = P->right;
    P->right = Q->left;
    P->height = max(height(P->left), height(P->right)) + 1;
    Q->left = P;
    Q->height = max(height(Q->left), height(Q->right)) + 1;
    P = Q;
}

void RotateRight(NODE*& P)
{
    NODE* Q = P->left;
    P->left = Q->right;
    P->height = max(height(P->left), height(P->right)) + 1;
    Q->right = P;
    Q->height = max(height(Q->left), height(Q->right)) + 1;
    P = Q;

}

void Insert(NODE*& root, NODE* p) {
    if (root == nullptr) {
        root = p;
        return;
    }
    if (root->key > p->key)
    {
        Insert(root->left, p);
    }
    else if (root->key < p->key)
    {
        Insert(root->right, p);
    }
    int x = (height(root->left) - height(root->right));
    if (x > 1) {
        if (root->left->key < p->key) {
            // cout << "Trai - Phai";
            RotateLeft(root->left);
        }
        else {
            //cout << "Trai - Trai";
        }
        RotateRight(root);
    }
    else {
        if (x < -1) {
            if (root->right->key < p->key) {
                // cout << "Phai - Phai";
            }
            else {
                // cout << "Phai - Trai";
                RotateRight(root->right);
            }
            RotateLeft(root);
        }
    }
    root->height = max(height(root->left), height(root->right)) + 1;
}

//seach
bool search(NODE* root, string key) {
    if (root == NULL) return false;

    if (key < root->key) {
        return search(root->left, key);
    }
    else if (key > root->key) {
        return search(root->right, key);
    }
    else {
        return true;
    }
}

//3. Xóa một NODE với giá trị cho trước từ một cây AVL cho trước (Chú ý giá trị đó có tồn tại hay không):

int heightUpdate(NODE*& root) {
    if (root == NULL) {
        return 0;
    }
    root->height = max(heightUpdate(root->right), heightUpdate(root->left));
    return root->height + 1;
}

void Remove(NODE*& pRoot, string x)
{
    //th ko tim thay
    if (pRoot == NULL)
    {
        return; //thi thoi
    }
    //tim thay
    if (pRoot->key == x)
    {
        //th leaf
        if (pRoot->left == NULL && pRoot->right == NULL)
        {
            delete pRoot;
            pRoot = NULL; // buoc gan nay quan trong;
        }
        // TH node đó có 1 node con.
        else if (pRoot->left == NULL || pRoot->right == NULL)
        {
            NODE* delNode = pRoot;

            if (pRoot->left != NULL) {
                pRoot = pRoot->left;
            }
            else {
                pRoot = pRoot->right;
            }

            delete delNode;
            delNode = NULL;
        }
        // TH node đó có cả 2 node con.
        else {
            // Tim phan tu the mang la phan tu phai nhat ben trai
            NODE* replaced = pRoot->left;
            // Không có phần tử phải của cây con trái -> lấy node trái liền kề thế mạng.
            if (replaced->right == NULL)
            {
                pRoot->key = replaced->key;
                pRoot->left = replaced->left;

                delete replaced;
                replaced = NULL;
            }
            // Có phần tử phải của cây con trái.
            else {
                NODE* parent = NULL;
                while (replaced->right != NULL) {
                    parent = replaced; // ghi lại node cha
                    replaced = replaced->right; // duyệt lấy node phải nhất
                }

                pRoot->key = replaced->key;

                if (replaced->left != NULL)
                {
                    parent->right = replaced->left;
                }
                else {
                    parent->right = NULL;
                }
                delete replaced;
                replaced = NULL;

            }
        }
        //balance lai cay
        heightUpdate(pRoot);

    }
    //tiep tuc tim
    else if (pRoot->key < x)
    {
        Remove(pRoot->right, x);
    }
    else
    {
        Remove(pRoot->left, x);
    }
}

//debug
void PrintTree(NODE* pRoot)
{
    if (pRoot == NULL) {
        return;
    }

    queue<NODE*> q;
    q.push(pRoot);

    int height = 99999;
    while (!q.empty())
    {
        NODE* node = q.front();
        q.pop();

        if (height > node->height) {
            cout << "\n";
            height = node->height;
        }

        cout << node->key << "-" << node->height << " ";

        if (node->left != NULL)
        {
            q.push(node->left);
        }

        if (node->right != NULL)
        {
            q.push(node->right);
        }
    }
}

NODE* readTree(string file_name)
{
    ifstream inFile;
    //ofstream ouFile;
    string data;

    inFile.open(file_name);
    if (!inFile.is_open())
    {
        cout << "Khong mo duoc file!";
    }

    if (!(inFile >> data))
    {

        cout << "ko co gi de doc ca: " << data;
        return NULL;
    }
    NODE * root = createNode(data);

    while (inFile >> data)
    {
        Insert(root, createNode(data));
    }

    inFile.close();
    return root;
}

void Finder(NODE* pRoot,string in_file_name, string out_file_name)
{
    ifstream inFile;
    ofstream outFile;
    //ofstream ouFile;
    string data;

    inFile.open(in_file_name);
    outFile.open(out_file_name);
    if (!inFile.is_open())
    {
        cout << "Khong mo duoc file!";
    }

    while (inFile >> data)
    {
        outFile << search(pRoot, data) << "\n";
    }
    inFile.close();
    outFile.close();
    return;
}

void remover(NODE* pRoot, string in_file_name) {
    ifstream inFile;
    inFile.open(in_file_name);
    string data;
    if (!inFile.is_open())
    {
        cout << "Khong mo duoc file!";
    }
    while (inFile >> data)
    {
        Remove(pRoot, data);
    }
    inFile.close();
}

void LNR(NODE* pRoot, ofstream* outp)
{
    if (pRoot == NULL) {
        return;
    }

    LNR(pRoot->left, outp);
    *outp << pRoot->key << "\n";
    LNR(pRoot->right, outp);
}

void PrintLNR(NODE* pRoot, string out_file_name) {
    ofstream outFile;
    outFile.open(out_file_name);
    LNR(pRoot,&outFile);
    outFile.close();
}


int main() {
    NODE* tree = readTree("D:/names.txt");
    //DEBUG
    //PrintTree(tree);
    //cout << "test seach: ... " << search(tree,"Azura");
    Finder(tree, "input.txt", "output_1.txt");
    remover(tree, "input.txt");
    PrintLNR(tree, "output_2.txt");
    cout << "complete";
    return 0;
}