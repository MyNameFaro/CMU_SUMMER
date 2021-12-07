#include<bits/stdc++.h>
using namespace std;
bool arr[1<<11][1<<11];
void draw(int x,int r,int c){
	if(x==0) return;
	for(int i=0;i<(1<<(x-1));++i){
		arr[r-i][c]=true;
	}
	for(int i=1;i<=(1<<(x-1));++i){
		arr[r-(1<<(x-1))-i+1][c-i]=true;
		arr[r-(1<<(x-1))-i+1][c+i]=true;
	}
	draw(x-1,r-(1<<x),c-(1<<(x-1)));
	draw(x-1,r-(1<<x),c+(1<<(x-1)));
}
int main(){
	int n;
	scanf("%d",&n);
	draw(n,(1<<(n+1))-1,(1<<n));
	for(int i=1;i<(1<<(n+1));++i){
		for(int j=1;j<(1<<(n+1));++j){
			if(arr[i][j]){
				printf("1");
			}else{
				printf("_");
			}
		}
		printf("\n");
	}
}
