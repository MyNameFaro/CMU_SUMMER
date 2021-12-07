#include<bits/stdc++.h>
using namespace std;
using lli=long long;
int main(){
	int n;
	lli d;
	scanf("%d %lld",&n,&d);
	lli x;
	vector<lli>arr;
	for(int i=0;i<n;++i){
		scanf("%lld",&x);
		arr.push_back(x);
	} 
	sort(arr.begin(),arr.end());
	lli ans=0;
	for(int i=0;i<n;++i){
		int j=upper_bound(arr.begin(),arr.end(),arr[i]+d)-arr.begin()-1;
		ans+=(j-i);
	}
	printf("%lld",ans);
}
