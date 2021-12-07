#include<bits/stdc++.h>
using namespace std;
unsigned long long table[102][102][10002];
int arr[102][102];
int n,m;
int main(){
    int q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&arr[i][j]);
        } 
    }
    for(int k=arr[n][m];k<=10000;++k){
        for(int i=n;i>=1;--i){
            for(int j=m;j>=1;--j){
                if(i==n and j==m and k==arr[n][m]){
                    table[i][j][k]=1;
                    continue;
                }
                if(k<arr[i][j]) continue;
                table[i][j][k]+=table[i][j+1][k-arr[i][j]];
                table[i][j][k]+=table[i+1][j][k-arr[i][j]];
            }
        }
    }
    for(int i=1;i<=q;++i){
        int x;
        scanf("%d",&x);
        if(x<=0){
            printf("0\n");
            continue;
        }
        printf("%llu\n",table[1][1][x]);
    }
}