#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int a , b;
    int q , i;
    scanf("%d",&q);
    for(i = 1;i <= q;i++){
        scanf("%lld %lld",&a,&b);
        if(a <= b){
            printf("%lld \n", ((b * (b+1)) - (a * (a-1))) / 2);
        }else{
            printf("0\n");
        }
    }
}
