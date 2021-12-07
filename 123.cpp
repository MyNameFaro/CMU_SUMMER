#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    int sum=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    } 
    if(sum%3>0){
        printf("noob");
        return 0;
    }
    int table[(sum/3)+1][(sum/3)+1];
    for(int l=0;l<=sum/3;++l){
        for(int m=0;m<=sum/3;++m) table[l][m]=false;
    }
    table[0][0]=true;
    for(int i=1;i<=n;++i){
        int tablee[(sum/3)+1][(sum/3)+1];
        for(int l=0;l<=sum/3;++l){
            for(int m=0;m<=sum/3;++m) tablee[l][m]=false;
        }  
        for(int j=0;j<=sum/3;++j){
            for(int k=0;k<=sum/3;++k){
                 
                tablee[j][k]=table[j][k];
                if(j>=arr[i]) tablee[j][k]=tablee[j][k] or table[j-arr[i]][k];
                if(k>=arr[i]) tablee[j][k]=tablee[j][k] or table[j][k-arr[i]];
            }
        }
        for(int l=0;l<=sum/3;++l){
            for(int m=0;m<=sum/3;++m) table[l][m]=tablee[l][m];
        }
    }
    if(table[sum/3][sum/3]){
        printf("mission complete");
    }else{
        printf("noob");
    }
}