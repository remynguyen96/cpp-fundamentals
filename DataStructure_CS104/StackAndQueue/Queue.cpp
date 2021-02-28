#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* pNext;
};

struct Queue {
  Node* pHead;
  Node* pTail;
};

Node* createNode(int);
Queue* init();
bool isEmpty(Queue* &);
void enqueue(Queue* &, int);
int dequeue(Queue* &);
void printQueue(Queue* &);
int countElements(Queue* &);

void inputDataForQueue(Queue* &queue) {
  int n;
  cout << "Please enter an integer number n = ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;

    cout << "Enter a integer number x[" << i << "] = ";
    cin >> x;
    cout << endl;

    enqueue(queue, x);
  }
}

int main() {
  system("clear");
  Queue* queue = init();

  inputDataForQueue(queue);

  cout << "Total Elements: " << countElements(queue) << endl;

  printQueue(queue);

  return 0;
}

Node* createNode(int data) {
  Node* pNode = new Node;

  if (pNode == NULL) return NULL;

  pNode->data = data;
  pNode->pNext = NULL;

  return pNode;
}

Queue* init() {
  Queue* queue = new Queue;

  queue->pHead = NULL;
  queue->pTail = NULL;

  return queue;
};

bool isEmpty(Queue* &queue) {
  return queue->pHead == NULL;
}

void enqueue(Queue* &queue, int data) {
  Node* pNode = createNode(data);

  if (isEmpty(queue)) {
    queue->pHead = queue->pTail = pNode;
  }

  queue->pTail->pNext = pNode;
  queue->pTail = pNode;
}

int dequeue(Queue* &queue) {
  if (isEmpty(queue)) return 0;

  Node* node = queue->pHead;
  int data = node->data;

  queue->pHead = queue->pHead->pNext;

  delete node;

  return data;
}

void printQueue(Queue* &queue) {
  Node* pNode = queue->pHead;

  while (pNode) {
    cout << pNode->data << endl;
    pNode = pNode->pNext;
  }
}

int countElements(Queue* &queue) {
  Node* pNode = queue->pHead;
  int counter = 0;

  while (pNode) {
    pNode = pNode->pNext;
    counter++;
  }

  return counter;
}