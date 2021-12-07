#include <bits/stdc++.h>
using namespace std;

vector <int> p;
vector <int> sett;

int find(int u){
	if(sett[u] == -1) return u;
	return sett[u] = find(sett[u]);
}

int main(){
	int N , M;
	scanf("%d %d",&N ,&M);
	sett.assign(N + 1,-1);
	p.assign(N + 1,0);
	int u , v;
	for(int i = 1;i <= N;++i) scanf("%d",&p[i]);
	for(int i = 1;i <= M;++i){
		scanf("%d %d",&u ,&v);
		int mu = find(u);
		int mv = find(v);
		if(mu == mv){
			printf("-1\n");
			continue;
		}
		if(p[mu] > p[mv]){
			printf("%d\n",mu);
			p[mu] += (p[mv] / 2);
			sett[mv] = mu;
		}else if(p[mu] < p[mv]){
			printf("%d\n",mv);
			p[mv] += (p[mu] / 2);
			sett[mu] = mv;
		}else if(u > v){
			printf("%d\n",mu);
			p[mu] += (p[mv] / 2);
			sett[mv] = mu;
		}else{
			printf("%d\n",mv);
			p[mv] += (p[mu] / 2);
			sett[mu] = mv;
		}
	}
}
