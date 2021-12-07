#include <bits/stdc++.h>
#define R first
#define C second
using namespace std;
long long int n[103][103];

void bfs(int r,int c,long long int k){
	queue <pair <int , int>> q;
	long long int before = n[r][c];
	pair <int ,int> node;
	q.push({r , c});
	n[r][c] = k;
	while(!q.empty()){
		node = q.front();
		q.pop();
		if(n[node.R][node.C + 1]==before){
			n[node.R][node.C+1] = k;
			q.push({node.R , node.C + 1});
		}
		if(n[node.R][node.C - 1]==before){
			n[node.R][node.C - 1] = k;
			q.push({node.R , node.C - 1});
		}
		if(n[node.R + 1][node.C]==before){
			n[node.R + 1][node.C] = k;
			q.push({node.R + 1, node.C});
		}
		if(n[node.R - 1][node.C]==before){
			n[node.R - 1][node.C] = k;
			q.push({node.R - 1, node.C});
		}
	}
}
int main(){
	int M , N;
	int i , j;
	int r , c;
	long long int k;
	scanf("%d %d",&N ,&M);
	for(i = 1;i <= N;++i){
		for(j = 1;j <= M;++j){
			scanf("%lld" , &n[i][j]);
		}
	}
	scanf("%d %d",&r ,&c);
	scanf("%lld",&k);
	if(n[r][c] != k){
		bfs(r , c , k);
	}
	
	for(i = 1;i <= N;++i){
		for(j = 1;j <= M;++j){
			printf("%lld ",n[i][j]);
		}
		printf("\n");
	}
}
