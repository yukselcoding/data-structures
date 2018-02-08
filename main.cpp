#include <iostream>
#include "fixedStack.h"
#include "dynamicStack.h"
#include "fixedQueue.h"
#include "dynamicQueue.h"
#include "linkedList.h"
#include "undirectedGraph.h"
#include "directedGraph.h"
using namespace std;

int main(int argc, char const *argv[]) {

  /*Fixed size stack test*/
  cout << "---------Static Stack----------\n";
  FixedStack<int> *fix_st = new FixedStack<int>(5);
  for(int i=0; i<5; i++)
    fix_st->push(i);
  cout << "peek():";
  fix_st->print();
  cout << "--printAllStack()--\n";
  fix_st->printAllStack();
  cout << "pop():" << fix_st->pop() << endl;
  cout << "***************************\n";
  /*----------------------------------------*/

  /*Dynamic stack test*/
  DynamicStack<int> *dyn_st = new DynamicStack<int>();
  cout << "---------Dynamic Stack----------\n";
  for(int i=0; i<5; i++)
    dyn_st->push(i);
  cout << "peek():";
  dyn_st->print();
  cout << "--printAllStack()--\n";
  dyn_st->printAllStack();
  cout << "pop():" << dyn_st->pop() << endl;
  delete dyn_st;
  cout << "***************************\n";
  /*----------------------------------------*/

  /*Fixed size queue test*/
  cout << "---------Static Queue----------\n";
  FixedQueue<int> *fix_qu = new FixedQueue<int>(5);
  for(int i=0; i<5; i++)
    fix_qu->enqueue(i);
  cout << "retrieve():";
  fix_qu->print();
  cout << "--printAllQueue()--\n";
  fix_qu->printAllQueue();
  cout << "dequeue():" << fix_qu->dequeue() << endl;
  cout << "--dequeue_some()--" << endl;
  int *elements = fix_qu->dequeue_some(2);
  for(int i=0; i<2; i++)
    cout << "\t" << elements[i] << endl;
  cout << "***************************\n";
  /*----------------------------------------*/

  /*Dynamic queue test*/
  cout << "---------Dynamic Queue----------\n";
  DynamicQueue<int> *dyn_qu = new DynamicQueue<int>();
  for(int i=0; i<5; i++)
    dyn_qu->enqueue(i);
  cout << "retrieve():";
  dyn_qu->print();
  cout << "--printAllQueue()--\n";
  dyn_qu->printAllQueue();
  cout << "dequeue():" << dyn_qu->dequeue() << endl;
  cout << "***************************\n";
  /*----------------------------------------*/

  /*Linked List test*/
  cout << "---------Linked List----------\n";
  LinkedList<int> *ll = new LinkedList<int>();
  cout << "addRear()\n";
  for(int i=0; i<5; i++)
    ll->addRear(i);
  ll->printList();
  cout << "addFront()";
  for(int i=5; i<10; i++)
    ll->addFront(i);
  cout << endl;
  ll->printList();
  cout << "deleteFront()" << endl;
  ll->deleteFront();
  ll->printList();
  cout << "deleteRear()" << endl;
  ll->deleteRear();
  ll->printList();
  cout << "deleteNode(6):";
  ll->deleteNode(6);
  cout << endl;
  cout << "deleteNode(1):";
  ll->deleteNode(1);
  cout << endl;
  ll->printList();
  cout << "***************************\n";
  /*----------------------------------------*/
  
    /*Undirected Graph test*/
  cout << "---------Undirected Graph----------\n";
  UndirectedGraph *und_gr = new UndirectedGraph(5);
  und_gr->createEdges(0,1);
  und_gr->createEdges(2,1);
  und_gr->createEdges(3,2);
  und_gr->createEdges(4,2);
  und_gr->createEdges(4,1);
  und_gr->printGraph();
  cout << "***************************\n";
  /*----------------------------------------*/

  /*Directed Graph test*/
  cout << "---------Directed Graph----------\n";
  DirectedGraph *d_gr = new DirectedGraph(5);
  d_gr->createEdges(0,1);
  d_gr->createEdges(2,1);
  d_gr->createEdges(3,2);
  d_gr->createEdges(4,2);
  d_gr->createEdges(4,1);
  d_gr->printGraph();

  return 0;
}
