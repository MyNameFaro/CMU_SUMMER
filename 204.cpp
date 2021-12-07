#include <bits/stdc++.h>
using namespace std;

int main(){
	int N , M;
	int x;
	scanf("%d %d",&N ,&M);
	int arr[N][M];
	for(int i = 0;i < N;++i){
		for(int j = 0;j < M;++j){
			scanf("%d",&x);
			arr[i][j] = x;
		}
	}
	for(int i = 0;i < N;++i){
		for(int j = 0;j < M;++j){
			scanf("%d",&x);
			arr[i][j] -= x;
		}
	}
	for(int i = 0;i < N;++i){
		for(int j = 0;j < M;++j) printf("%d ",arr[i][j]);
		printf("\n");
	}
}
