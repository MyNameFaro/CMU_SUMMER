#include <bits/stdc++.h>
using namespace std;

int visited[100003];
vector <int> g[100003];
int component;

int BFS(int head , int aim){
	queue <pair <int , int> > q;
	int i;
	pair <int , int> v;
	q.push(make_pair(head , 0)); //(HEAD < DEEP)
	visited[head] = 1;
	while(!q.empty()){
		v = q.front();
		if(v.first == aim){
			cout << v.second << endl;
			return 0;
		}
		q.pop();
		for(i = 0;i < g[v.first].size() ;i++){
			if(visited[ g[v.first][i] ] == 0){
				visited[ g[v.first][i] ] = 1;
				q.push(make_pair( g[v.first][i] , v.second + 1));
			}
		}
	}
}

bool success(int n){
	int i;
	for(i = 1;i <= n;i++){
		if(visited[i] == 0){
			return false;
		}
	}
	return true;
}

int find_unvisited(int n){
	int i;
	for(i = 1;i <= n;i++){
		if(visited[i] == 0){
			return i;
		}
	}
}

int main(){
    int n,m;
    int i , j;
    int u ,v;
    cin >> n >> m;
    int s;
    int t;
    int head;
    for(i = 1;i <= m;i++){
	    cin >> u >> v;
	    g[u].push_back(v);
	    g[v].push_back(u);
    }
    for(i = 1;i <= n;i++){
    	sort(g[i].begin() , g[i].end());
	}
	cin >> t;
	for(i = 0;i < t;i++){
		cin >> u >> v;
		BFS(u , v);
	}
    //DFS
    
}
