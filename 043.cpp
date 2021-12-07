#include <bits/stdc++.h>
using namespace std;
int p[501][501];
int n;
int r;
int main(){
    scanf("%d",&n);
    int i , j;
    for(r = 1;r <= (n + 1)/2;r+=2){
        for(i = r;i <= n - r + 1;i++){
            p[r][i] = 1;
            p[i][r] = 1;
            p[n - r + 1][i] = 1;
            p[i][n - r + 1] = 1;
        }
    }
    for(i = 1;i <= n;i++){
        for(j = 1;j <= n;j++){
            if(p[i][j] == 1){
                printf("*");
            }else{
                printf("-");
            }
        }
        printf("\n");
    }
}
