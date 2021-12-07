#include <bits/stdc++.h>
using namespace std;

int N;

int bfs(int s , vector <vector <int>> &G , vector <bool> &visited){
	int ans = 1;
	queue <int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto v:G[u]){
			if(!visited[v]){
				visited[v] = true;
				++ans;
				q.push(v);
			}
		}
	}
	return ans;
}
vector <vector <int>> find_component(vector <vector <int>> &G){
	vector <bool> visited (N + 1,false);
	vector <vector <int>> component;vector <int> C;
	for(int n = 1;n <= N;++n){
		if(!visited[n]){
			queue <int> q;
			q.push(n);
			visited[n] = true;
			C.push_back(n);
			while(!q.empty()){
				int u = q.front();q.pop();
				for(auto v:G[u]){
					if(!visited[v]){
						visited[v] = true;
						C.push_back(v);
						q.push(v);
					}
				}
			}
			//for(auto x:C) printf("%d ",x);
			//printf("\n");
			component.push_back(C);
			C.clear();
		}
	}
	return component;
	
}

int main(){
	int M , C;
	scanf("%d %d %d",&N ,&M ,&C);
	int u , v , w;
	int ans = 0;
	vector <vector <int>> G (N + 1,vector <int>());
	vector <vector <int>> H (N + 1,vector <int>());
	for(int i = 1;i <= M;++i){
		scanf("%d %d %d",&u ,&v ,&w);
		if(w <= C){
			H[u].push_back(v);
			H[v].push_back(u);
		}
		if(w < C){
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	vector <bool> visited (N + 1,false);
	vector <vector <int>> component = find_component(H);
	for(int i = 0;i < component.size() ; ++i){
		vector <int> compute;
		for(auto n:component[i]){
			if(!visited[n]){
				compute.push_back(bfs(n , G , visited));
			}
		}
		for(int j = 0;j < compute.size();++j){
			for(int k = j + 1;k < compute.size();++k){
				ans += (compute[j] * compute[k]);
			}
		}
		compute.clear();
	}
	printf("%d",ans);
}
