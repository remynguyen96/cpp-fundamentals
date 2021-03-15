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
Node* dequeue(Queue* &);
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

  printQueue(queue);

  cout << "Total Elements: " << countElements(queue) << endl;

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

void enqueue(Queue* &queue, Node* node) {
  if (isEmpty(queue)) {
    queue->pHead = queue->pTail = node;
  }

  queue->pTail->pNext = node;
  queue->pTail = node;
}

Node* dequeue(Queue* &queue) {
  if (isEmpty(queue)) return NULL;

  Node* node = queue->pHead;
  queue->pHead = queue->pHead->pNext;

  // in case only one node in queue.
  if (isEmpty(queue)) {
    queue->pTail = NULL;
  }

  return node;
}

void printQueue(Queue* &queue) {
  Queue* newQueue = new Queue;

  while (queue->pHead) {
    Node* node = dequeue(queue);
    enqueue(newQueue, node);

    cout << node->data << endl;
  }

  queue = newQueue;
}

// void printQueue(Queue* &queue) {
//   Node* pNode = queue->pHead;

//   while (pNode) {
//     cout << pNode->data << endl;
//     pNode = pNode->pNext;
//   }

//   delete pNode;
// }

int countElements(Queue* &queue) {
  Node* pNode = queue->pHead;
  int counter = 0;

  while (pNode) {
    pNode = pNode->pNext;
    counter++;
  }

  return counter;
}