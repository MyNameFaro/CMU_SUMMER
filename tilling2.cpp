#include<bits/stdc++.h>
using namespace std;
int table[31][31][31];
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<=30;++i){
        for(int j=0;j<=30;++j){
            for(int k=0;k<=30;++k){
                if(i==0 or j==0 or k==0){
                    table[i][j][k]=1;
                    continue;
                }
                if(i==j and i>0 and k>1){
                    table[i][j][k]+=table[i-1][j-1][k-2];
                }
                if(k==j and j>0 and i>1){
                    table[i][j][k]+=table[i-2][j-1][k-1];
                }
                if(i>1 and j>1 and k>1){
                    table[i][j][k]+=table[i-2][j-2][k-2];
                }
            }
        }
    }
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%d\n",table[n][n][n]);
    }
}