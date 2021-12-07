#include<bits/stdc++.h>
using namespace std;
bool canvas[1<<12][1<<12];
void draw(int r,int c,int x){
	canvas[r][c]=true;
	if(x==0) return;
	draw(r,c,x-1);
	draw(r+(1<<(x-1)),c-(1<<(x-1)),x-1);
	draw(r+(1<<(x-1)),c+(1<<(x-1)),x-1);
}
int main(){
	int n;
	scanf("%d",&n);
	draw(1,(1<<n),n);
	for(int i=1;i<=(1<<n);++i){
		for(int j=1;j<(1<<(n+1));++j){
			if(canvas[i][j]){
				printf("1");
			}else{
				printf("_");
			}
		}
		printf("\n");
	}
}
