#ifndef NODE_H
#define NODE_H
/*Generic Node class used in building tree*/
template<class T> class BinaryNode {
public:
  T data;
  BinaryNode *left, *right;
  BinaryNode(T data) {
    left = right = nullptr;
    this->data = data;
  }
};

/*Generic class used in creating single node*/
template<class T> class Node {
public:
  T data;
  Node<T> *next;
  Node(T info, Node<T> *ptr) {
    this->data = info;
    next = ptr;
  }
  Node() {}
  Node(T data) {
    this->data = data;
    next = nullptr;
  }
};
#endif
