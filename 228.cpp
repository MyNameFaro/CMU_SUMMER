#include <bits/stdc++.h>
using namespace std;

char key(int n){
	if(n == 0){
		return 'd';
	}else if(n == 1){
		return 'f';
	}else if(n == 2){
		return 'j';
	}else{
		return 'k';
	}
}

int main(){
	int N;
	scanf("%d",&N);
	char a[N + 1][5];
	for(int i = N - 1;i>= 0;--i){
		scanf(" %s",a[i]);
	}
	printf("at t=%d\n",0);
	for(int n = 0;n < 4;++n){
		if(a[0][n] == '#'){
			printf("down %c\n",key(n));
		}
	}
	for(int t = 1;t < N;++t){
		printf("at t=%d\n",t);
		for(int n = 0;n < 4;++n){
			if(a[t][n] != a[t - 1][n]){
				if(a[t][n] == '#'){
					printf("down %c\n",key(n));
				}else if(a[t][n] == '-'){
					printf("up %c\n",key(n));
				}
			}
		}
	}
	printf("at t=%d\n",N);
	for(int n = 0;n < 4;++n){
		if(a[N - 1][n] == '#'){
			printf("up %c\n",key(n));
		}
	}
}
