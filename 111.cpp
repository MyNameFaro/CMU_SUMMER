#include<bits/stdc++.h>
using namespace std;
int table[2002];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int arr[m+1];
	for(int i=1;i<=m;++i) scanf("%d",&arr[i]);
	for(int i=1;i<=n;++i){
		table[i]=-2e9;
		for(int j=1;j<=m;++j){
			if(i-j<0) break;
			table[i]=max(table[i-j]+arr[j],table[i]);
		}
	}
	printf("%d",table[n]);
}
