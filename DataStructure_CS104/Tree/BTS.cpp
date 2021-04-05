#include <iostream>
#include <queue>
using namespace std;

struct NODE{
    int key;
    NODE* p_left;
    NODE* p_right;
};

NODE* createNode(int data)
{
    NODE* newNode = new NODE();

    newNode->key = data;
    newNode->p_left = NULL;
    newNode->p_right = NULL;

    return newNode;
}

void NLR(NODE* pRoot)
{
    if(pRoot == NULL){
        return;
    }

    cout << pRoot->key << " ";
    NLR(pRoot->p_left);
    NLR(pRoot->p_right);
}

void LNR(NODE* pRoot)
{
    if(pRoot == NULL){
        return;
    }

    LNR(pRoot->p_left);
    cout << pRoot->key << " ";
    LNR(pRoot->p_right);
}

void LRN(NODE* pRoot)
{
    if(pRoot == NULL){
        return;
    }

    LRN(pRoot->p_left);
    LNR(pRoot->p_right);
    cout << pRoot->key << " ";
}

// them 1 node voi gia tr cho truoc vao bst
void Insert(NODE* &pRoot, int x)
{
    if(pRoot == NULL)
    {
        pRoot = createNode(x);
        return;
    }

    if(pRoot->key > x)
    {
        Insert(pRoot->p_left,x);
    }

    if(pRoot->key < x)
    {
        Insert(pRoot->p_right, x);
    }

    return;
}
// xay dung bst dua vao mang
void BuildBST(NODE* &pRoot, int* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        Insert(pRoot, arr[i]);
    }
}

void LevelOrder(NODE* pRoot)
{
    if(pRoot == NULL){
        return;
    }

    queue<NODE*> q;
    q.push(pRoot);

    while(!q.empty())
    {
        NODE* node = q.front();
        q.pop();
        cout << node->key << " ";

        if(node->p_left != NULL)
        {
            q.push(node->p_left);
        }

        if(node->p_right != NULL)
        {
            q.push(node->p_right);
        }
    }
}

void Remove(NODE* &pRoot, int x)
{
    if(pRoot==NULL)
    {
        return; //Khong tim thay x trong cay;
    }
    //tim thay node co khoa key == x
    if(pRoot->key == x)
    {
        if(pRoot->p_left == NULL && pRoot->p_right == NULL)// TH node đó là lá
        {
            delete pRoot;
            pRoot = NULL; // buoc gan nay quan trong;
        }

        else if(pRoot->p_left == NULL || pRoot->p_right == NULL ) // TH node đó có 1 node con.
        {
            NODE* delNode = pRoot;

            if(pRoot->p_left != NULL){
                pRoot = pRoot->p_left;
            }
            else{
                pRoot = pRoot->p_right;
            }

            delete delNode;
            delNode = NULL;
        }

        else { // TH node đó có cả 2 node con.
            // Tim phan tu the mang la phan tu phai nhat ben trai
            NODE* replaced = pRoot->p_left;

            if(replaced->p_right == NULL) // Không có phần tử phải của cây con trái -> lấy node trái liền kề thế mạng.
            {
                pRoot->key = replaced->key;
                pRoot->p_left = replaced->p_left;

                delete replaced;
                replaced = NULL;
            }

            else{ // Có phần tử phải của cây con trái.
                NODE* parent = NULL;
                while(replaced->p_right != NULL){
                    parent = replaced; // ghi lại node cha
                    replaced = replaced->p_right; // duyệt lấy node phải nhất
                }

                pRoot->key = replaced->key;

                if(replaced->p_left != NULL)
                {
                    parent->p_right = replaced->p_left;
                }
                else{
                    parent->p_right = NULL;
                }
                delete replaced;
                replaced = NULL;

            }
        }

    }

    else if (pRoot->key < x)
    {
        Remove(pRoot->p_right, x);
    }
    else
    {
        Remove(pRoot->p_left, x);
    }
}

void removeTree(NODE* &pRoot){
    if(!pRoot){
        return;
    }

    removeTree(pRoot->p_left);
    removeTree(pRoot->p_right);

    delete pRoot;
    pRoot=NULL;
}
int main()
{
    NODE* BST = NULL;
    int arr[7] = {5,7,3,2,6,8,1};

    BuildBST(BST, arr,7);
    LevelOrder(BST);
    cout << endl;
    Remove(BST,7);
    LevelOrder(BST);
    cout << endl;
    removeTree(BST);
    LevelOrder(BST);
    return 0;
}