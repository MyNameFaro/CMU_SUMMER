#include <bits/stdc++.h>
using namespace std;
using lli = long long;
int main(){
	int N , T , x;
	int L , R , V;
	scanf("%d %d",&N , &T);
	vector <lli> qs (N + 2,0);
	for(int i = 1;i <= N;++i){
		scanf("%d",&x);
		qs[i] += x;
		qs[i + 1] -= x;
	}
	for(int i = 1;i <= T;++i){
		scanf("%d %d %d",&L ,&R ,&V);
		qs[L] += V;
		qs[R + 1] -= V;
	}
	for(int i = 1;i <= N;++i){
		qs[i] += qs[i - 1];
		printf("%lld ",qs[i]);
	}
}
