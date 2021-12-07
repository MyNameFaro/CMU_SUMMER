#include <bits/stdc++.h>
using namespace std;

int arr[28]; //define arr[R][C]
int ans;

bool check(int &N , int &K ,int X ,int k){
	if(k <= N - K + X && X >= k){
		return true;
	}
	return false;
}
void solve(int &N , int &K ,int x){
	if(x == N + 1){
		++ans;
		cout << ans << endl;
		return;
	}
	for(int k = 1;k <= K;++k){
		if(check(N , K ,x, k)){
			arr[x] = k;
			solve(N , K , x + 1);
			arr[x] = 0;
		}
	}
}


void func(){
	int N , K;
	ans = 0;
	scanf("%d %d",&N , &K);
	solve(N , K ,1);
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int t = 1;t <= T;++t){
		func();
	}
}


