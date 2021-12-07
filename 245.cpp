#include <bits/stdc++.h>
using namespace std;

char arr[1002][1002];
string s;
int itr = 0;

void draw(int r1,int c1 , int r2 , int c2 ,char n){
	if(r1 > r2 || c1 > c2) return;
	for(int i = r1;i <= r2;++i){
		for(int j = c1;j <= c2;++j) arr[i][j] = n;
	}
}
void solve(int r1 , int c1,int r2,int c2){
	if(r1 > r2 || c1 > c2) return;
	int mid_r = (r1 + r2)/2;
	int mid_c = (c1 + c2)/2;

	if(s[itr] == '0'){
		++itr;
		draw(r1 ,c1 ,r2 ,c2 , '0');
	}else if(s[itr] == '1'){
		++itr;
		draw(r1 ,c1 ,r2 ,c2 , '1');
		//++itr;
	}else{
		++itr;
		solve(r1 , c1, mid_r , mid_c);
		//++itr;
		solve(r1 , mid_c + 1, mid_r , c2);
		//++itr;
		solve(mid_r + 1 , c1, r2 , mid_c);
		//++itr;
		solve(mid_r + 1 , mid_c + 1 , r2 , c2);
	}
}

int main(){
	int N , M;
	cin >> N >> M;
	cin >> s;
	solve(1 , 1, N , M);
	//cout << itr << endl;
	for(int i = 1;i <= N;++i){
		for(int j = 1;j <= M;++j) printf("%c",arr[i][j]);
		printf("\n");
	}
}
