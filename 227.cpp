#include <bits/stdc++.h>
using namespace std;

vector <int> n, p;
int pay;
int q , s ,k;
int memo[1001][1001];

int f(int x,int y){
    if(memo[x][y] == 0){
        int mx = 0, i ,a;
        for(i = 0;i < k;i++){
            if(x >= n[i]){
                a = f(x - n[i] , y + p[i]);
                mx = max(mx , a);
            }
        }
        mx = max(mx , y);
        memo[x][y] = mx;
    }
    return memo[x][y];
}

int main(){
    scanf("%d %d %d",&q,&s,&k);
    int i ,x , y;
    pay = q*s;
    for(i = 1;i <= k;i++){
        scanf("%d%d",&x,&y);
        n.push_back(x);
        p.push_back(y);
    }
    printf("%d",pay - f(q , 0));
}
