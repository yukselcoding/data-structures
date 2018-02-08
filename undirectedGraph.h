#include <iostream>
#include <vector>
using namespace std;


class UndirectedGraph {
private:
  int size;
  vector<vector<int>> adjList;
public:
  UndirectedGraph(int size);
  void createEdges(int v, int w);
  void printGraph();
};

UndirectedGraph::UndirectedGraph(int size) {
  this->size = size;
  this->adjList = vector<vector<int>>(size);
}

void UndirectedGraph::createEdges(int v, int w) {
  adjList[v].push_back(w);
  adjList[w].push_back(v);
}

void UndirectedGraph::printGraph() {
  typename vector<int> :: iterator it;
  for(int i=0; i<size; i++) {
    cout << "Adjacents of " << i << " :";
    if(adjList[i].size() == 0)
      cout << " none.";
    else
      for(it = adjList[i].begin(); it != adjList[i].end(); it++)
        cout << "-> " << (*it);
    cout << endl;
  }
}
