#include<bits/stdc++.h>
using namespace std;
int table[2002][2002],arr[2002][2002];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) scanf("%d",&arr[i][j]);
    }
    int ans=-2e9;
    for(int i=n;i>=1;--i){
        if(i%2==0){
            for(int j=1;j<=m;++j){
                if(arr[i][j]<0) continue;
                table[i][j]=max(table[i][j],table[i][j-1]);
                table[i][j]=max(table[i][j],table[i+1][j]);
                table[i][j]+=arr[i][j];
                ans=max(table[i][j],ans);
            }
        }else{
            for(int j=m;j>=1;--j){
                if(arr[i][j]<0) continue;
                table[i][j]=max(table[i][j],table[i][j+1]);
                table[i][j]=max(table[i][j],table[i+1][j]);
                table[i][j]+=arr[i][j];
                ans=max(table[i][j],ans);
            }
        }
    }
    printf("%d",ans);
}
