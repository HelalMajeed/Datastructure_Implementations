/* @AUTHOR:HELAL ***  @DATE:2022-AUG-19  ***  SUB:GRAPH-DATA-STRUCTU */

/* Lets imagine this graph(undirected graph):
		
		0
	   / \
	  1---2
	   \ /
	    3
		
* And lets implement it using vector
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void insertEdge(vector<int> adjacent[], int u, int v) {
	adjacent[u].push_back(v);
	adjacent[v].push_back(u);
}

void printGraph(vector<int> adjacent[], int size) {
	for(int vertex = 0; vertex < size; vertex++) {
		cout << vertex;
		for(auto v : adjacent[vertex]) {
			cout << "->" << v;
		}
		cout << endl;
	}
}

int main() {
	int size = 4;
	// size is the number of vertecies
	
	vector<int> adjacent[size];
	// vector will represent the adjacency matricies

	insertEdge(adjacent, 0, 1);
	insertEdge(adjacent, 0, 2);
	insertEdge(adjacent, 1, 3);
	insertEdge(adjacent, 2, 3);
	// add edges
	
	printGraph(adjacent, size);
	/*
	  printing the graph will be:

	  0->1->2
	  1->0->3
	  2->0->3
	  3->1->2

	  and that means:
	  0 related to 1 and 2
	  and vice versa
	  3 related to 1 and 2
	  and vice versa

    	*/

	return(0);
}
