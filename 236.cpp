#include <bits/stdc++.h>
using namespace std;

int L[100002];

int main(){
	
	int n , m;
	
	
	int l , h , r;
	
	int i , j;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d %d",&l ,&r ,&h);
		for(i = l;i < r;++i){
			L[i] = max(L[i] , h);
		}
	}
	for(i = 1;i <= 100002;++i){
		if(L[i] != L[i-1]){
			printf("%d %d\n",i , L[i]);
		}
	}
}
