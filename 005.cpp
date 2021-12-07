#include <bits/stdc++.h>
using namespace std;

int main(){
	int mn_n = 2e9, day_n;
	int m_j , n_i;
	int mx_m = -2e9, day_m;
	int n , m;
	scanf("%d %d",&n,&m);
	int i , j;
	int a , b , c , d;
	for(i = 1;i <= n;++i){
		scanf("%d %d",&a ,&b);
		if(b < mn_n){
			mn_n = b;
			day_n = a;
			n_i = i;
		}else if(b == mn_n){
			if(a < day_n){
				day_n = a;
				n_i = i;
			}
		}
	}
	for(j = 1;j <= m;++j){
		scanf("%d %d",&c ,&d);
		if(d > mx_m){
			mx_m = d;
			day_m = c;
			m_j = j;
		}else if(d == mx_m){
			if(c > day_m){
				day_m = c;
				m_j = j;
			}
		}
	}
	if(mx_m - mn_n <= 0 || day_m < day_n){
		printf("0");
	}else{
		printf("%d\n",mx_m - mn_n);
		printf("%d %d",n_i , m_j);
	}
}
