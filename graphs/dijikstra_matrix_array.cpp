#include<iostream>
#include<limits.h>
#define v 9
using namespace std;

void dijikstra( int graph[v][v],int s){
   int parent[v];
   int dist[v];
   int visited[v];
   for(int i=0;i<v;i++)
   {
   dist[i]=INT_MAX;
   parent[i]=-1;
   visited[i]=0;
   }
   dist[s]=0;
   visited[s]=1;
   int q=s;;
   while(1){
      cout<<q<<endl;
      visited[q]=1;
      for(int i=0;i<v;i++){
		if(graph[q][i]>0 && !visited[i]){
		  //cout<<i;
		   if(graph[q][i]+dist[q]<dist[i]){
		      //cout<<"here";
		      dist[i]=graph[q][i]+dist[q];
			  parent[i]=q;
		  }
		}
	  }
	  int d=INT_MAX;
	  int p=q;
	  for(int i=0;i<v;i++)
	  {
		 if(!visited[i] && dist[i]<d)
		 {
		   d=dist[i];
		   p=i;
		 }
	  }
	  if(p==q)
	  break;
	  q=p;
   }
   
}
int main()
{
   /* Let us create the example graph discussed above */
   int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijikstra(graph,0);
  
    return 0;
}