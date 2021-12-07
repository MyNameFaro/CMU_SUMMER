#include <bits/stdc++.h>
using namespace std;

int preorder(int x , int N){
	printf(" %d",x);
	if(2*x <= N) preorder(2*x ,N);
	if(2*x + 1 <= N) preorder(2*x + 1 , N);
}

int main(){
	int Q;scanf("%d",&Q);
	for(int i = 1;i <= Q;++i){
		int N;
		scanf("%d",&N);
		printf("Case #%d:",i);
		preorder(1 , N);
		printf("\n");
	}
}
