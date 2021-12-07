#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	double ans = 1.0;
	scanf("%d",&N);
	printf("1");
	for(int i = 2;i <= N;++i){
		printf("+(1/%d)",i);
		ans = ans + (1.0 / (double) i);
	}
	printf("=%.2lf",ans);
}
