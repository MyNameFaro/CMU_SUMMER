#include<bits/stdc++.h>
using namespace std;
long long int table[92];
int main(){
    int n,m;
    table[0]=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<m;++i){
        table[i]+=table[i-1];
    }
    for(int i=m;i<=n;++i){
        table[i]+=table[i-1];
        table[i]+=table[i-m];
    }
    printf("%lld",table[n]);
}