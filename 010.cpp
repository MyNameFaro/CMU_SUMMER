#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int s[n],d[n];
	int i;
	int ans , num;
	int c = 0;
	for(i = 0;i < n;++i){
		scanf("%d %d",&s[i],&d[i]);
	}
	num = s[0];
	while(c < n){
		if(num - s[c] % d[c] == 0){
			ans = num;
			++c;
		}
		++num;
		
	}
	printf("%d",ans);
}
