#include<bits/stdc++.h>
using namespace std;
int table[1002][1002],qs[1002][1002];
int mod=1e9+7;
int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    int arr[n+1];
    for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
    for(int i=0;i<=n;++i) table[0][i]=1;

    for(int j=1;j<=p;++j){
        for(int i=1;i<=n;++i){
            int w=j;
            while(w>=0){
                table[j][i]+=table[w][i-1];
                table[j][i]%=mod;
                w-=arr[i];
            }
            //printf("%d ",table[j][i]);
        }
        //printf("\n");
    }
    printf("%d",table[p][n]);
}