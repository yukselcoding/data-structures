#include <iostream>
#include "Node.h"
using namespace std;

template<class T> class DynamicQueue {
  Node<T> *front;
  Node<T> *rear;
public:
  DynamicQueue();
  ~DynamicQueue();
  bool isEmpty();
  void enqueue(int data);
  T dequeue();
  T retrieve();
  void printAllQueue();
  void print();
};

template<class T> DynamicQueue<T>::DynamicQueue() {
  front = nullptr;
  rear = nullptr;
}

template<class T> DynamicQueue<T>::~DynamicQueue() {
  while(!isEmpty())
    dequeue();
}

template<class T> bool DynamicQueue<T>::isEmpty() {
  return front == nullptr && rear == nullptr;
}

template<class T> void DynamicQueue<T>::enqueue(int data) {
  Node<T> *t = new Node<T>();
  t->data = data;
  t->next = nullptr;
  if(isEmpty()) {
    front = rear = t;
    return;
  }
  rear->next = t;
  rear = t;
}

template<class T> T DynamicQueue<T>::retrieve() {
  if(isEmpty())
    std::cout << "Queue is empty." << std::endl;
  else
    return front->data;
}

template<class T> void DynamicQueue<T>::print() {
  cout << retrieve() << endl;
}

template<class T> T DynamicQueue<T>::dequeue() {
  if(isEmpty())
    std::cout << "Queue is empty." << std::endl;
  else {
    Node<T> *tmp = front;
    T data = tmp->data;
    front = front->next;
    delete tmp;
    return data;
  }
}

template<class T> void DynamicQueue<T>::printAllQueue() {
  if(isEmpty())
    std::cout << "Queue is empty." << std::endl;
  else {

    Node<T> *temp = front;
    std::cout << "Queue:";
    while(temp != rear->next) {
      std::cout << " " << temp->data;
      temp = temp->next;
    }
    std::cout << "\n";
  }
}
