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
    DFS(head);
    //DFS
    
}
