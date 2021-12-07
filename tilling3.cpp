#include<bits/stdc++.h>
using namespace std;
long long int table[1001][1001];
long long int mod=1e9+7;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;++i){
        for(int j=max(0,i-1);j<=min(n,i+1);++j){
            if(i==0 and j==0){
                table[i][j]=1;
                continue;
            }
            if(i==j){
                if(i>0 and j>0) table[i][j]+=table[i-1][j-1];
                if(i>0 and j>1) table[i][j]+=table[i-1][j-2];
                if(i>1 and j>0) table[i][j]+=table[i-2][j-1];
                if(i>1 and j>1) table[i][j]+=table[i-2][j-2];
            }else if(i>j){
                if(i>1 and j>0) table[i][j]+=table[i-2][j-1];
                if(i>1 and j>1) table[i][j]+=table[i-2][j-2];
            }else if(i<j){
                if(i>0 and j>1) table[i][j]+=table[i-1][j-2];
                if(i>1 and j>1) table[i][j]+=table[i-2][j-2];
            }
            table[i][j]=table[i][j]%mod;
        }
    }
    printf("%lld",table[n][n]);
}