#include <bits/stdc++.h>
using namespace std;

int memo[1003];
bool visit[1003];
vector <int> c;

int f(int a){
	if(a == 0){
		return 0;
	}else if(a < 0){
		return 2e9;
	}
	if(!visit[a]){
		visit[a] = true;
		int ans = 2e9;
		
		for(int i = 0;i < c.size();++i){
			ans = min(ans , f(a - c[i]));
		}
		memo[a] = ans + 1;
	}
	return memo[a];
}

int main(){
	int A , B , C , d;
	int ans = 0;
	int dis;
	scanf(" %d %d",&A ,&B);
	dis = abs(A - B);
	scanf("%d",&C);
	for(int i = 0;i < C;++i){
		scanf("%d",&d);
		c.push_back(d);
	}
	ans = f(dis);
	if(ans >= 2e9){
		printf("-1");
		return 0;
	}
	printf("%d",ans);
	
}
