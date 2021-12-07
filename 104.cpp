#include<bits/stdc++.h>
using namespace std;
int table[1000002][5];
int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
    if(n<4){
        printf("GGWP");
        return 0;
    }
    table[0][1]=table[2][3]=2e9;
    table[1][2]=table[3][4]=-2e9;
    for(int j=1;j<=4;++j){
        for(int i=j;i<=n;++i){
            if(j%2==1) table[i][j]=min(arr[i]-table[i-1][j-1] , table[i-1][j]);
            if(j%2==0) table[i][j]=max(arr[i]-table[i-1][j-1] , table[i-1][j]);
            //printf("%d ",table[i][j]);
        }
        //printf("\n");
    }
    printf("%d",table[n][4]);
}