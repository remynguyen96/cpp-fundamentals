#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* pNext;
};

struct Stack {
  Node* top;
};

Stack* init();
bool isEmpty(Stack* &stack);
Node* createNode(int data);
void print(Stack* &stack);
void push(Stack* &stack, Node* node);
int pop(Stack* &stack);
int countElements(Stack* &stack, int counter);

void inputStack(Stack* &stack) {
  int n;
  cout << "Please enter number n = ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;

    cout << "Enter a integer number x[" << i << "] = ";
    cin >> x;
    cout << endl;

    Node *p = createNode(x);

    if (p != NULL) {
      push(stack, p);
    }
  }
}

int main() {
  system("clear");
  Stack* stack = init();

  inputStack(stack);

  cout << "Total Elements: " << countElements(stack, 0) << endl;

  print(stack);

  return 0;
}

Stack* init() {
  Stack* stack = new Stack;
  stack->top = NULL;

  return stack;
}

bool isEmpty(Stack* &stack) {
  return stack->top == NULL;
}

Node* createNode(int data) {
  Node *pNode = new Node;

  if (pNode == NULL) return NULL;

  pNode -> data = data;
  pNode -> pNext = NULL;

  return pNode;
}

void push(Stack* &stack, Node *node) {
  if (isEmpty(stack)) {
    stack->top = node;
  } else {
    node->pNext = stack->top;
    stack->top = node;
  }
}

int pop(Stack* &stack) {
  if (isEmpty(stack)) return 0;

  Node *node = stack->top;

  int data = node->data;

  stack->top = stack->top->pNext;

  delete node;

  return data;
}

void print(Stack* &stack) {
  if(isEmpty(stack)) return;

  int data = pop(stack);
  cout << data << endl;

  print(stack);

  Node* node = createNode(data);
  push(stack, node);
}

int countElements(Stack* &stack, int counter) {
  if(isEmpty(stack)) return counter;

  int data = pop(stack);

  counter++;
  int result = countElements(stack, counter);

  Node* node = createNode(data);
  push(stack, node);

  return result;
}