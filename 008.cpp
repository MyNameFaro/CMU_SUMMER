#include <bits/stdc++.h>
using namespace std;

bool checkprime(int n){
	if(n % 2 == 0){
		return false;
	}
	for(int i = 3;i <= sqrt(n);i+=2){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

vector <int> primelist(int n){
	vector<int> pl;
	pl.push_back(2);
	for(int i = 3;i <= n;++i){
		if(checkprime(i)){
			pl.push_back(i);
		}
	}
	return pl;
}

int main(){
	int n;
	int k = 0;
	scanf("%d",&n);
	vector <int> pl = primelist(n);
	vector <int> facc;
	for(int i = 0;i < pl.size();++i){
		if(n % pl[i] == 0){
			++k;
			while(n % pl[i] == 0){
				facc.push_back(pl[i]);
				n /= pl[i];
			}
		}
	}
	for(int i = 0;i < facc.size();++i){
		printf("%d",facc[i]);
		if(i != facc.size() - 1){
			printf("x");
		}
	}
	printf("\n%d",k);
}
