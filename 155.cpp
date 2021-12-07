#include <bits/stdc++.h>
using namespace std;
using pii = pair<int ,int>;

vector <int> sett;

int find(int u){
	if(sett[u] == -1) return u;
	return sett[u] = find(sett[u]);
}

stack <pii> E;

int kruscal(){
	int ans = 2e9;
	while(!E.empty()){
		int w = E.size();
		int u = E.top().first ;int v = E.top().second;E.pop();
		if(find(u) != find(v)){
			sett[find(u)] = find(v);
			ans = min(ans , w);
		}else{
			printf("CYCLE\n");
		}
	}
	return ans - 1;
}


int main(){
	int N, M;
	scanf("%d %d",&N ,&M);
	sett.assign(N + 1,-1);
	int u , v;
	for(int i = 1;i <= M;++i){
		scanf("%d %d",&u ,&v);
		E.push({u , v});
	}
	printf("%d",kruscal());
}
