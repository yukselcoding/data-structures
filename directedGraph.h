#include <iostream>
#include <vector>
using namespace std;


class DirectedGraph {
private:
  int size;
  vector<vector<int>> adjList;
public:
  DirectedGraph(int size);
  void createEdges(int v, int w);
  void printGraph();
};

DirectedGraph::DirectedGraph(int size) {
  this->size = size;
  this->adjList = vector<vector<int>>(size);
}

void DirectedGraph::createEdges(int v, int w) {
  adjList[v].push_back(w);
}

void DirectedGraph::printGraph() {
  typename vector<int> :: iterator it;
  for(int i=0; i<size; i++) {
    cout << "Adjacents of " << i << ":";
    if(adjList[i].size() == 0)
      cout << " none.";
    else
      for(it = adjList[i].begin(); it != adjList[i].end(); it++)
        cout << " ->" << (*it);
    cout << endl;
  }
}
