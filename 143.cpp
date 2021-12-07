#include <bits/stdc++.h>
using namespace std;
using pii = pair<int ,int>;

vector <int> visited;
vector <vector <int>> G;
int N;

int max_dis = -1;
int U , V;


int find_path(){
	priority_queue <pii ,vector <pii> ,greater<pii>> pq;
	vector <int> dis (N + 1,2e9);
	vector <bool> inset(N + 1,false);
	dis[U] = 0;
	pq.push({dis[U] , U});
	while(!pq.empty()){
		int u = pq.top().second;pq.pop();
		if(u == V) break;
		if(inset[u]) continue;
		inset[u] = true;
		for(auto v:G[u]){
			if(dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1;
				pq.push({dis[v] , v});
			}
		}
	}
	//FIND WAY
	int u = V;
	while(dis[u] > 0 && u != U){
		for(auto v:G[u]){
			if(dis[v] == dis[u] - 1){
				printf("%d ",u);
				u = v;
				break;
			}
		}
	}printf("%d ",u);
	
	 
}
int find_level(int u){
	//printf("%d ",u);
	int cc = 0;
	priority_queue<pii> level_sort;
	for(auto v : G[u]){
		if(visited[v]== -1){
			visited[v] = visited[u] + 1;
			int vi = find_level(v);
			level_sort.push({visited[vi] , vi});
			++cc;
		}
		
	}
	if(cc == 0) return u;
	if(level_sort.size() == 1){
		int v1 = level_sort.top().second;level_sort.pop();
		int new_max_dis = visited[v1] - visited[u] + 1;
		if(new_max_dis > max_dis){
			max_dis = new_max_dis;
			U = u;V = v1;
		}
		return v1;
	}
	int v1 = level_sort.top().second;level_sort.pop();
	int v2 = level_sort.top().second;level_sort.pop();
	int new_max_dis = visited[v1] + visited[v2] - (2 * visited[u]) + 1;
	
	if(new_max_dis > max_dis){
		max_dis = new_max_dis;
		U = v1; V = v2;
	}
	return v1;
}

int main(){
	scanf("%d",&N);
	if(N == 1){
		printf("1\n");printf("1");
		return 0;
	}
	G.assign(N + 1,vector <int> ());
	visited.assign(N + 1,-1);
	int u , v;
	for(int i = 1;i < N;++i){
		scanf("%d %d",&u , &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	visited[1] = 0;
	find_level(1);
	printf("%d\n",max_dis);
	find_path();
}
