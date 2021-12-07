#include<bits/stdc++.h>
using namespace std;
long long int table[1000002];
int main(){
    int n;
    scanf("%d",&n);
    long long int arr[n+1];
    for(int i=1;i<=n;++i) scanf("%lld",&arr[i]);
    table[1]=max(table[1],arr[1]);
    for(int i=2;i<=n;++i){
        if(i>=2) table[i]=max(table[i],arr[i]+table[i-2]);
        if(i>=1) table[i]=max(table[i],table[i-1]);
    }
    printf("%lld",table[n]);
}