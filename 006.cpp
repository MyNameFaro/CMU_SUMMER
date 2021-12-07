#include <bits/stdc++.h>
using namespace std;

int x['A' + 20] , y['A' + 20];


int main(){
	for(int i = 0;i < 4;++i){
		for(int j = 0;j < 4;++j){
			x[(4 * i) + j + 'A'] = j;
			y[(4 * i) + j + 'A'] = i;
		}
	}
	x['.'] = 3;y['.'] = 3;
	string s;
	int sum = 0;
	for(int i = 0;i < 4;++i){
		cin >> s;
		for(int j = 0;j < 4;++j){
			if(s[j] == '.') continue;
			sum += abs(i - y[s[j]]) + abs(j - x[s[j]]);
		}
	}
	printf("%d",sum);
	
}
