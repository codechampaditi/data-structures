//dfs with adjacency list
//Hello this is anu
// second change branch anu
//this is my code
#include <iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    queue<int >myqueue;
	myqueue.push(s);
	int visited[V];
	for(int i=0;i<V;i++)
	visited[i]=0;
	visited[s]=1;
	list<int>::iterator i;
	while(!myqueue.empty()){
	    //cout<<"hello"<<endl;
	    int top=myqueue.front();
		myqueue.pop();
		visited[top]=1;
		cout<<top<<endl;
		for(i = adj[top].begin(); i != adj[top].end(); ++i)
		    //cout<<i;
			//cout<<"here";
			if(visited[*i]==0){
			    //cout<<i<<" ";
				myqueue.push(*i);
				visited[*i]=1;
	 		}
		}
	}

 
int main(){
    Graph g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(0);
}