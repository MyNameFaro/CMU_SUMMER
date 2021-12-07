#include <bits/stdc++.h>
using namespace std;
using pii = pair<int , int>;

int main(){
	int N;scanf("%d",&N);
	vector <vector <pii>> G (N + 1,vector <pii> ());
	int w;
	for(int u = 1;u <= N;++u){
		for(int v = u + 1;v <= N;++v){
			scanf("%d",&w);
			G[u].push_back({v , w});
			G[v].push_back({u , w});
		}
	}
	priority_queue <pii , vector<pii> , greater<pii>> pq;
	vector <int> dis (N + 1,2e9);
	vector <bool> visited(N + 1,false);
	dis[1] = 0;
	pq.push({dis[1] , 1});
	while(!pq.empty()){
		int u = pq.top().second;pq.pop();
		if(visited[u]) continue;
		visited[u] = true;
		for(auto vw:G[u]){
			int v = vw.first;int w = vw.second;
			if(dis[v] > dis[u] + w && !visited[v]){
				dis[v] = dis[u] + w;
				pq.push({dis[v] , v});
			}
		}
	}
	printf("%d",dis[N]);
}
