#include<bits/stdc++.h>
using namespace std;
using lli = long long;
int main(){
	lli n,c;
	scanf("%lld%lld",&n,&c);
	lli table[n+1];
	lli arr[n+1];
	for(int i=1;i<=n;++i) scanf("%lld",&arr[i]);
	for(int i=1;i<=n;++i){
		table[i]=(arr[1]-arr[i])*(arr[1]-arr[i]);
		for(int j=1;j<i;++j){
			table[i]=min(table[i],table[j] + c + ((arr[j+1]-arr[i])*(arr[j+1]-arr[i])));
		}
	}
	printf("%lld",table[n]+c);
}
