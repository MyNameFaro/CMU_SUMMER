#include <bits/stdc++.h>
using namespace std;


int solve(int N){
	int table[N + 2];
	table[0] = 1;
	for(int i = 1;i <= N;++i){
		table[i] = 1;
		for(int j = 1;j < i - 2;++j){
			table[i] += table[j];
		}
	}
	return table[N];
}

int main(){
	int Q;int N;
	scanf("%d",&Q);
	for(int i = 1;i <= Q;++i){
		scanf("%d",&N);
		printf("%d\n",solve(N) + 1);
	}
}
