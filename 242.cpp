#include <bits/stdc++.h>
using namespace std;

int memo[4][4][10002];
string s;

int tid(char c){
	if(c == 'L') return 2;
	if(c == 'D') return 3;
	if(c == 'R') return 0;
	return 1;
}

int solve(int a , int b , int n){
	if(n == s.size()) return 0;
	if(memo[a][b][n] == -1){
		memo[a][b][n] = 0;
		int next = tid(s[n]);
		if(next != a) memo[a][b][n] = max(memo[a][b][n] , solve(a , next , n + 1));
		if(next != b) memo[a][b][n] = max(memo[a][b][n] , solve(next , b , n + 1));
		if(next == a || next == b) memo[a][b][n] = max(memo[a][b][n] , 1 + solve(a , b , n + 1));
		
	}
	return memo[a][b][n];
}

void func(){
	for(int i = 0;i < 4;++i){
		for(int j = 0;j < 4;++j){
			for(int k = 0;k < 10002;++k) memo[i][j][k] = -1;
		}
	}
	cin >> s;
	printf("%d\n",solve(2 , 0 , 0));
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t= 1;t <= T;++t) func();
}
