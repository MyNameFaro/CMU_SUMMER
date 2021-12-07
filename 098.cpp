#include<bits/stdc++.h>
using namespace std;
int qs[4000][4000];
int n,m;
int query(int r1,int c1,int r2,int c2){
	--r1;--c1;
	return qs[r2][c2]-qs[r2][c1]-qs[r1][c2]+qs[r1][c1];
}
bool solve(int l){
	int ll=l-1;
	for(int i=l;i<=n;++i){
		for(int j=l;j<=m;++j){
			if(query(i-ll,j-ll,i,j)==l*l) return true;
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&qs[i][j]);
			qs[i][j]+=qs[i-1][j];
			qs[i][j]+=qs[i][j-1];
			qs[i][j]-=qs[i-1][j-1];
		}
	}
	int ans=-1;
	int l=0;int r=min(n,m);
	while(l<=r){
		int mid=(l+r)/2;
		if(solve(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d",ans);
}
