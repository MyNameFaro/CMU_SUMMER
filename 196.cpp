#include <bits/stdc++.h>
using namespace std;
using pii = pair<int , int>;

int solve(int N){
	int sum = 1;
	int ans = 0;
	while(N > 1){
		while(N % 3 > 0 && N > 3){
			//printf("%d ",N);
			++ans;
			--N;
		}
		while(N % 3 == 0){
			//printf("%d ",N);
			++ans;
			N/=3;
		}
		while(N % 2 == 0){
			//printf("%d ",N);
			++ans;
			N/=2;
		}
	}
	
	//printf("\n");
	return ans;
}

int main(){
	int Q , N;
	scanf("%d",&Q);
	for(int i = 1;i <= Q;++i){
		scanf("%d",&N);
		printf("%d\n",solve(N));
	}
}
