//BFS

#include<iostream>
#include<queue>
using namespace std;

void bfs(int *arr,int n, int s){
	queue<int >myqueue;
	myqueue.push(s);
	int visited[n];
	for(int i=0;i<n;i++)
	visited[i]=0;
	visited[0]=1;
	while(!myqueue.empty()){
	    //cout<<"hello"<<endl;
	    int top=myqueue.front();
		myqueue.pop();
		
		cout<<top<<endl;
		for(int i=0;i<n;i++){
		    //cout<<i;
			//cout<<"here";
			int x=*((arr+top*n)+i);
			if(i!=top && x==1&& visited[i]==0){
			    //cout<<i<<" ";
				myqueue.push(i);
				visited[i]=1;
			}
		}
	}
}
int main(){
  int arr[][4]={{0,1,1,0},{0,0,1,0},{1,0,0,1},{0,0,0,1}};
    int rows =  sizeof arr / sizeof arr[0]; // 2 rows  
   // cout<<rows;
  int cols = sizeof arr[0] / sizeof(int); // 5 cols
  bfs((int *)arr,rows,0);
  //cout<<"here";
  return 0;
}