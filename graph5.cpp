#include <bits/stdc++.h>
using namespace std;

int visited[100003];
vector <int> g[100003];

void DFS (int head){
	int i;
	visited[head] = 1;
	cout << head << " ";
	for(i = 0;i < g[head].size() ;i++){
		if(visited[ g[head][i] ] == 0){
			DFS(g[head][i]);
		}
	}
}

void BFS(int head){
	queue <int> q;
	int i;
	int v;
	q.push(head);
	visited[head] = 1;
	while(!q.empty()){
		v = q.front();
		cout << v << " ";
		q.pop();
		for(i = 0;i < g[v].size() ;i++){
			if(visited[ g[v][i] ] == 0){
				visited[ g[v][i] ] = 1;
				q.push( g[v][i] );
			}
		}
	}
}

int main(){
    int n,m;
    int i , j;
    int u ,v;
    cin >> n >> m;
    int s;
    int head;
    for(i = 1;i <= m;i++){
	    cin >> u >> v;
	    g[u].push_back(v);
	    g[v].push_back(u);
    }
    for(i = 1;i <= n;i++){
    	sort(g[i].begin() , g[i].end());
	}
    cin >> head;
    BFS(head);
    //DFS
    
}
