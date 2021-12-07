#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N;
bool is_bipartire = true;
int component = 0;

vector <int> visited;
vector <vector <int>> G;
lli mod(lli a){
	return a % (1000000007);
}

int bipartire(int s){
	queue <int> q;
	visited[s] = 1;
	q.push(s);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto v:G[u]){
			if(visited[v] == 0){
				visited[v] = visited[u] * -1;
				q.push(v);
			}else if(visited[v] == visited[u]){
				is_bipartire = false;
				return 0;
			}
		}
	}
}

int main(){
	int N , M;
	scanf("%d %d",&N , &M);
	int u , v;
	G.assign(N + 1,vector <int>());
	visited.assign(N + 1,0);
	for(int i = 1;i <= M;++i){
		scanf("%d %d",&u ,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1;i <= N;++i){
		if(visited[i] == 0){
			bipartire(i);
			++component;
		}
	}
	int T;scanf("%d",&T);
	if(T <= 2){
		if(is_bipartire){
			printf("Yes\n");
		}else{
			printf("No");
		} 
	}
	if(T == 2){
		if(is_bipartire){
			for(int i = 1;i <= N;++i){
				if(visited[i] < 0) printf("%d ",i);
			}printf("\n");
			for(int i = 1;i <= N;++i){
				if(visited[i] > 0) printf("%d ",i);
			}
		}
	}
	if(T == 3){
		if(is_bipartire){
			lli ans = 1;
			for(int i = 1;i <= component;++i){
				ans = mod(ans * 2);
				ans = mod(ans);
			}
			printf("%lld",ans);
		}else{
			printf("0");
		} 
	}
}
