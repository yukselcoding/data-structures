#include <iostream>
#include <cstdlib>
using namespace std;

/*Generic class of Queue, uses a FIXED size.*/
template<class T> class FixedQueue {
private:
  int front, rear;
  T* queue;
  int size;
public:
  FixedQueue(int size);
  T dequeue();
  T retrieve();
  void enqueue(const T &value);
  bool isFull();
  bool isEmpty();
  void print();
  T* dequeue_some(int elementsTodequeue);
  void printAllQueue();
  void *operator new(size_t size);
  void operator delete[](void *p);
};

/*Constructor, used in initialization*/
template<class T> FixedQueue<T>::FixedQueue(int size) {
  this->size = size;
  this->queue = new T[size];
  this->front = this->rear = -1;
}

/*'new' operator is overloaded.*/
template<class T> void* FixedQueue<T>::operator new(size_t size) {
  void *p = malloc(size);
  return p;
}

/*'delete' operator is overloaded.*/
template<class T> void FixedQueue<T>::operator delete[](void *p) {
  free(p);
}

/*Checks if queue is full.*/
template<class T> bool FixedQueue<T>::isFull() {
  return rear == size-1;
}

/*Checks if queue is empty.*/
template<class T> bool FixedQueue<T>::isEmpty() {
  return rear == -1 && front == -1;
}

/*Takes the first element of queue.*/
template<class T> T FixedQueue<T>::dequeue() {
  if(!isEmpty())
    return queue[front++];
  else
    cout << "Queue is empty." << endl;
}

/*Retrieves the first element of queue.*/
template<class T> T FixedQueue<T>::retrieve() {
  if(!isEmpty())
    return queue[front];
  else
    cout << "Queue is empty." << endl;
}

/*Adds element to the queue.*/
template<class T> void FixedQueue<T>::enqueue(const T &value) {
  if(isEmpty())
    front = rear = 0;
  else {
      if(isFull())
        cout << "Queue is full and not resizable." << endl;
      else
        rear++;
  }
  queue[rear] = value;
}

/*Prints the first element of queue.*/
template<class T> void FixedQueue<T>::print() {
  cout << retrieve() << endl;
}

/*Takes some elements, beginning from front of the queue.*/
template<class T> T* FixedQueue<T>::dequeue_some(int elementsTodequeue) {
  T *elements = new T[elementsTodequeue];
  for(int i=0; i<elementsTodequeue; i++)
    elements[i] = dequeue();
  return elements;
}

/*Prints all of the queue.*/
template<class T> void FixedQueue<T>::printAllQueue() {
  if(isEmpty())
    cout << "Queue is empty." << endl;
  else {
    cout << "Queue:";
    for(int i=front; i<=rear; i++)
      cout << " " << queue[i];
    cout << endl;
  }
}
