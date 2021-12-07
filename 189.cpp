#include <bits/stdc++.h>
using namespace std;
using lli = long long;
int main(){
	/*int num[1000001];
	int i , r = 0 , v = 0;
	for(i = 1;i <= 1000000; i++){
		
	}*/
	int l , r;
	lli sum = 0;
	scanf("%d%d",&l,&r);
	int n;
	for(n = l;n <= r;n++){
		sum += sqrt(n);
	}
	printf("%lld",sum);
}
