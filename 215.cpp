#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B;
	long long int table[52][52];
	scanf("%d %d",&A,&B);
	for(int i = 1;i <= A;++i){
		for(int j = 1;j <= i;++j){
			if(i == j) table[i][j] = 1;
			if(j == 1) table[i][j] = 1;
			if(j > 1 && j < i) table[i][j] = table[i - 1][j - 1] + table[i - 1][j]; 
		}
	}
	printf("%lld",table[A][B]);
}
