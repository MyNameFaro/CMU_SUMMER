#include<bits/stdc++.h>
using namespace std;
int table[3002][2];
int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    int ans=-2;
    for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            if(arr[j]<arr[i] and table[j][1]>table[i][0]) table[i][0]=table[j][1];
            if(arr[j]>arr[i] and table[j][0]>table[i][1]) table[i][1]=table[j][0];
        }
        ++table[i][0];
        ++table[i][1];
        ans=max(ans,table[i][0]);
        ans=max(ans,table[i][1]);
    }
    printf("%d",ans);
}