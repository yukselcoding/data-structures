#include <iostream>
#include "Node.h"
using namespace std;

template<class T> class LinkedList {
  Node<T> *head;
public:
  LinkedList();
  void addFront(T data);
  void addRear(T data);
  void deleteFront();
  void deleteRear();
  void deleteNode(T data);
  void printList();
};

template<class T> LinkedList<T>::LinkedList() {
  head = nullptr;
}

template<class T> void LinkedList<T>::addFront(T data) {
  Node<T> *newNode = new Node<T>(data);
  if(head == nullptr)
    head = newNode;
  else {
    newNode->next = head;
    head = newNode;
  }
}

template<class T> void LinkedList<T>::addRear(T data) {
  Node<T> *newNode = new Node<T>(data);
  if(head == nullptr)
    head = newNode;
  else {
    Node<T> *iter = head;
    while(iter->next)
      iter = iter->next;
    iter->next = newNode;
  }
}

template<class T> void LinkedList<T>::printList() {
  Node<T> *iter = head;
  if(head == nullptr)
    cout << "List is empty." << endl;
  else {
    cout << "List:";
    while(iter) {
      cout << " " << iter->data;
      iter = iter->next;
    }
    cout << endl;
  }
}

template<class T> void LinkedList<T>::deleteFront() {
  if(head == nullptr)
    cout << "List is empty." << endl;
  else {
    Node<T> *iter = head;
    head = head->next;
    delete iter;
  }
}

template<class T> void LinkedList<T>::deleteRear() {
  if(head == nullptr)
    cout << "List is empty." << endl;
  else {
    Node<T> *preiter = head;
    Node<T> *iter = preiter;
    while(iter->next) {
      preiter = iter;
      iter = iter->next;
    }
    if(preiter == iter)
      head = nullptr;
    delete preiter->next;
    preiter->next = nullptr;
  }
}

template<class T> void LinkedList<T>::deleteNode(T data) {
    if(head == nullptr)
      cout << "List is empty." << endl;

    else if(head->data == data) {
      Node<T> *iter = head;
      head = head->next;
      delete iter;
    }

    else {
      Node<T> *preiter = nullptr;
      Node<T> *iter = head;
      int found = 0;
      while(iter && iter->data != data) {
        preiter = iter;
        iter = iter->next;
      }
      if(iter == nullptr)
        cout << "There is no such node." << endl;

      preiter->next = iter->next;
      delete iter;
    }
}
