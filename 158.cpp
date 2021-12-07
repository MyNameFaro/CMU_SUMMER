#include<bits/stdc++.h>
using namespace std;
long long opr(char c,long long val){
    if(c=='-' or c=='–') return val*(long long)-1;
    return val;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    char c[n+1];
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
        if(i==n) break;
        scanf(" %c",&c[i]);
    }
    long long table1[n+1][n+1],table2[n+1][n+1];
    //MIN
    for(int r=1;r<=n;++r){
        for(int l=r;l>=1;--l){
            if(l==r){
                table1[l][r]=table2[l][r]=arr[l];
                continue;
            }
            table1[l][r]=2e18;
            table2[l][r]=-2e18;
            for(int k=l;k<r;++k){
                table1[l][r]=min(table1[l][r] , table1[l][k] + opr(c[k],table2[k+1][r]));
                table1[l][r]=min(table1[l][r] , table1[l][k] + opr(c[k],table1[k+1][r]));
                table2[l][r]=max(table2[l][r] , table2[l][k] + opr(c[k],table2[k+1][r]));
                table2[l][r]=max(table2[l][r] , table2[l][k] + opr(c[k],table1[k+1][r]));
            }
        }
    }
    printf("%lld ",table1[1][n]);
    printf("%lld",table2[1][n]);
}