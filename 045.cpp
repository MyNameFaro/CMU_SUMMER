#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , m;
    scanf("%d %d",&n,&m);
    long long int c[n + 1];
    c[0] = 0;
    int a , b , x;
    int i;
    for(i = 1;i <= n;i++){
        cin >> x;
        c[i] = x + c[i - 1];
    }
    for(i = 1;i <= m;i++){
        scanf("%d%d",&a,&b);
        cout << c[b] - c[a - 1] << "\n";
    }
}
