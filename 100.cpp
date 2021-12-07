#include <bits/stdc++.h>
using namespace std;

int n;
int m;


int main(){
	cin >> n;
	cin >> m;
	long int table[n + 1][m + 1];
	long int tabu[n + 2][m + 2];
	int i , j;
	int x;
	for(i = 1;i <= n;i++){
		for(j = 1;j <= m;j++){
			scanf("%ld",&table[i][j]);
		}
	}
	for(i = 0;i <= n + 1;i++){
		for(j = 0;j <= m + 1;j++){
			tabu[i][j] = 2e9;
		}
	}
	for(i = n;i >= 1;i--){
		for(j = m;j >= 1;j--){
			if(i == n && j == m){
				tabu[i][j] = table[i][j];
			}else{
				tabu[i][j] = table[i][j] + min(tabu[i + 1][j] , tabu[i][j + 1]);
			}
		}
	}
	printf("%ld",tabu[1][1]);
}
