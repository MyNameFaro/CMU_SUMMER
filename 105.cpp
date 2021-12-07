#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,s;
    scanf("%d%d",&n,&s);
    int arr[n+1];
    for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
    if(s>10000 or s<=0){
        printf("No\n");
        return;
    }
    vector <bool> tablee(s+2,false);
    tablee[0]=true;
    for(int j=1;j<=n;++j){
        vector <bool> table(s+2,false);
        for(int i=0;i<=s;++i){
            table[i]=tablee[i];
            if(i-arr[j]>=0) table[i]=table[i] or tablee[i-arr[j]];
        }
        tablee=table;
    }
    if(tablee[s]){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
}