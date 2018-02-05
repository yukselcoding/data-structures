#include <iostream>
#include <cstdlib>
using namespace std;

/*Generic class of Stack, uses a FIXED size.*/
template<class T> class FixedStack {
private:
  int top;
  T *stack;
  int size;

public:
  FixedStack(int size);
  void push(T value);
  T pop();
  T peek();
  bool isEmpty();
  bool isFull();
  void *operator new(size_t size);
  void operator delete[](void *p);
  void print();
  void printAllStack();
};

/*Constructor, used in initialization*/
template<class T> FixedStack<T>::FixedStack(int size) {
  this->size = size;
  this->stack = new T[size];
  this->top = -1;
}

/*Prints the top element of Stack.*/
template<class T> void FixedStack<T>::print() {
  cout << peek() << endl;
}

/*Prints all elements of Stack.*/
template<class T> void FixedStack<T>::printAllStack() {
  cout << "   --Stack--" << endl;
  for(int i=top; i>=0; i--)
    cout << "\t" << stack[i] << endl;
}

/*'new' operator is overloaded.*/
template<class T> void* FixedStack<T>::operator new(size_t size) {
  void *p = malloc(size);
  return p;
}

/*'delete' operator is overloaded.*/
template<class T> void FixedStack<T>::operator delete[](void *p) {
  free(p);
}

/*Checks if stack is empty.*/
template<class T> bool FixedStack<T>::isEmpty() {
  return top == -1;
}

/*Checks if stack is full.*/
template<class T> bool FixedStack<T>::isFull() {
  return top == size - 1;
}

/*Pushes an element to the stack.*/
template<class T> void FixedStack<T>::push(T value) {
  if(!isFull())
    stack[++top] = value;
  else
    cout << "Stack is full and not resizable." << endl;
}

/*Takes the top element of stack.*/
template<class T> T FixedStack<T>::pop() {
  if(!isEmpty())
    return stack[top--];
  else
    cout << "Stack is empty." << endl;
}

/*Returns the top element.*/
template<class T> T FixedStack<T>::peek() {
  if(!isEmpty())
    return stack[top];
  else
    cout << "Stack is empty." << endl;
}
