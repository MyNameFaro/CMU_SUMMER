#include<bits/stdc++.h>
using namespace std;
int memo[1002][1002];
int arr[1002][1002];
int di[]={-1,0,1,0};
int dj[]={0,-1,0,1};
int n,m;
int solve(int r,int c){
    if(memo[r][c]==0){
        int mx=0;
        for(int i=0;i<4;++i){
            int rr=r+di[i];
            int cc=c+dj[i];
            if((rr<=0 or rr > n or cc<=0 or cc > m)) continue;
            if(arr[rr][cc]==arr[r][c]-1){
                mx=max(mx,solve(rr,cc));
            }
        }
        memo[r][c]=mx+1;
    }
    return memo[r][c];
}
int main(){
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            ans=max(ans,solve(i,j));
        }
    }
    printf("%d",ans);
}