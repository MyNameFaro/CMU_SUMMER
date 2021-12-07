#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> G (101 , vector <int> ());
vector <int> memo (101 , -1);
vector <int> type (101 , -1);

int solve(int u){
	int v1 , v2 , v3;
	if(memo[u] == -1){
		if(type[u] == 2){
			v1 = G[u][0];
			v2 = G[u][1];
			memo[u] = min(solve(v1) , solve(v2));
		}else if(type[u] == 3){
			v1 = G[u][0];
			v2 = G[u][1];
			memo[u] = max(solve(v1) , solve(v2));
		}else if(type[u] == 4){
			v1 = G[u][0];
			v2 = G[u][1];
			if(solve(v1) == solve(v2)){
				memo[u] = 0;
			}else{
				memo[u] = 1;
			}
		}else if(type[u] == 5){
			v1 = G[u][0];
			memo[u] = (solve(v1) + 1) % 2;
		}else if(type[u] == 6){
			v1 = G[u][0];
			v2 = G[u][1];
			v3 = G[u][2];
			if(solve(v1) == 0){
				memo[u] = solve(v2);
			}else{
				memo[u] = solve(v3);
			}
		}
	}
	return memo[u];
}

int main(){
	int w , g , q;
	int u , v1 , v2 , v3;
	cin >> w >> g >> q;
	string s;
	for(int t = 1;t <= w + g;++t){
		cin >> u;
		cin >> s;
		if(s == "INPUT"){
			type[u] = 1;
		}else if(s == "AND"){
			type[u] = 2;
			cin >> v1 >> v2;
			G[u].push_back(v1);
			G[u].push_back(v2);
		}else if(s == "OR"){
			type[u] = 3;
			cin >> v1 >> v2;
			G[u].push_back(v1);
			G[u].push_back(v2);
		}else if(s == "XOR"){
			type[u] = 4;
			cin >> v1 >> v2;
			G[u].push_back(v1);
			G[u].push_back(v2);
		}else if(s == "NOT"){
			type[u] = 5;
			cin >> v1;
			G[u].push_back(v1);
		}else{
			type[u] = 6;
			cin >> v1 >> v2 >> v3;
			G[u].push_back(v1);
			G[u].push_back(v2);
			G[u].push_back(v3);
		}
	}
	for(int qq = 1;qq <= q;++qq){
		memo.assign(101 , -1);
		for(int ww = 0;ww < w;++ww) scanf("%d",&memo[ww]);
		for(int i = w;i < w + g;++i){
			printf("%d ",solve(i));
		}
		printf("\n");
	}
}
