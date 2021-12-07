#include<bits/stdc++.h>
using namespace std;
using pii=pair<long long,long long>;
using lli=long long;
int main(){
	int n;
	scanf("%d",&n);
	lli dp1[n+1][n+1];
	pii dp2[n+1][n+1];
	for(int i=1;i<=n;++i){
		scanf("%lld%lld",&dp2[i][i].first,&dp2[i][i].second);
	}
	for(int i=n;i>=1;--i){
		dp1[i][i]=0;
		for(int j=i+1;j<=n;++j){
			dp1[i][j]=2e18;
			for(int k=i;k<j;++k){
				if(dp1[i][j]>dp1[i][k]+dp1[k+1][j]+(dp2[i][k].first*dp2[i][k].second*dp2[k+1][j].second) and dp2[i][k].second==dp2[k+1][j].first){
					dp1[i][j]=dp1[i][k]+dp1[k+1][j]+(dp2[i][k].first*dp2[i][k].second*dp2[k+1][j].second);
					dp2[i][j].first=dp2[i][k].first;
					dp2[i][j].second=dp2[k+1][j].second;
				}
			}
		}
	}
	printf("%lld",dp1[1][n]);	
}
