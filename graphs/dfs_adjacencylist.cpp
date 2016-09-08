//dfs with adjacency list
#include <iostream>
#include<list>
#include<stack>
using namespace std;
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void DFS(int s);  // prints BFS traversal from a given source s
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

void Graph::DFS(int s)
{
    stack<int >mystack;
	mystack.push(s);
	int visited[V];
	for(int i=0;i<V;i++)
	visited[i]=0;
	list<int>::iterator i;
	while(!mystack.empty()){
	    //cout<<"hello"<<endl;
	    int top=mystack.top();
		mystack.pop();
		visited[top]=1;
		cout<<top<<endl;
		for(i = adj[top].begin(); i != adj[top].end(); ++i)
		    //cout<<i;
			//cout<<"here";
			if(visited[*i]==0){
			    //cout<<i<<" ";
				mystack.push(*i);
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
    g.DFS(0);
}