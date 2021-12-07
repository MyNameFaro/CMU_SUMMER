#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int arr[n],lis[n],lds[n];
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
		lis[i]=1;lds[i]=1;
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<i;++j){
			if(arr[j]>arr[i] and lis[j]+1>lis[i]) lis[i]=lis[j]+1;
		}
	}
	for(int i=n-1;i>=0;--i){
		for(int j=n-1;j>i;--j){
			if(arr[j]>arr[i] and lds[j]+1>lds[i]) lds[i]=lds[j]+1;
		}
	}
	int ans=0;
	for(int i=0;i<n;++i){
		ans=max(lds[i]+lis[i]-1,ans);
	}
	printf("%d",ans);
}
