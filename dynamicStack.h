#include <iostream>
#include "Node.h"
using namespace std;

template<class T> class DynamicStack {
  Node<T> *top;
public:
  DynamicStack();
  ~DynamicStack();
  void push(T data);
  T pop();
  T peek();
  void printAllStack();
  void print();
  bool isEmpty();
  void emptyStack();

};

template<class T> DynamicStack<T>::DynamicStack() {
  top = nullptr;
}

template<class T> DynamicStack<T>::~DynamicStack() {
  while(!isEmpty()) {
    pop();
  }
}

template<class T> void DynamicStack<T>::push(T data) {
  Node<T> *t;
  if(top == nullptr)
    t = new Node<T>(data, nullptr);
  else
    t = new Node<T>(data, top);
  top = t;
}

template<class T> T DynamicStack<T>::pop() {
  if(!isEmpty()) {
    Node<T> *tmp = top;
    T data = tmp->data;
    top = top->next;
    delete tmp;
    return data;
  } else {
    std::cout << "Stack is empty." << std::endl;
  }
}

template<class T> bool DynamicStack<T>::isEmpty() {
  return top == nullptr;
}


template<class T> T DynamicStack<T>::peek() {
  if(!isEmpty())
    return top->data;
  else
    std::cout << "Stack is empty." << std::endl;
}

template<class T> void DynamicStack<T>::print() {
  cout << peek() << endl;
}

template<class T> void DynamicStack<T>::printAllStack() {
  Node<T> *temp = new Node<T>(peek(), top->next);
  if(!isEmpty()) {
      std::cout << "    --Stack--" << std::endl;
      while(temp != nullptr) {
        std::cout << "\t" << temp->data << std::endl;
        temp = temp->next;
      }
  } else {
    std::cout << "Stack is empty." << std::endl;
  }
}
