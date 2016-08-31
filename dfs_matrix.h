//DFS

#include<iostream>
#include<stack>
using namespace std;

void dfs(int *arr,int n, int s){
	stack<int >mystack;
	mystack.push(s);
	int visited[n];
	for(int i=0;i<n;i++)
	visited[i]=0;
	while(!mystack.empty()){
	    //cout<<"hello"<<endl;
	    int top=mystack.top();
		mystack.pop();
		visited[top]=1;
		cout<<top<<endl;
		for(int i=0;i<n;i++){
		    //cout<<i;
			//cout<<"here";
			int x=*((arr+top*n)+i);
			if(i!=top && x==1&& visited[i]==0){
			    //cout<<i<<" ";
				mystack.push(i);
			}
		}
	}
}
int main(){
  int arr[][4]={{0,1,1,0},{0,0,1,0},{1,0,0,1},{0,0,0,1}};
    int rows =  sizeof arr / sizeof arr[0]; // 2 rows  
   // cout<<rows;
  int cols = sizeof arr[0] / sizeof(int); // 5 cols
  dfs((int *)arr,rows,0);
  //cout<<"here";
  return 0;
}