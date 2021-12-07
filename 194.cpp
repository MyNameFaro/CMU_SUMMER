#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;scanf("%d",&N);
	double sum = 0.0;
	for(int i = 1;i <= N;++i){
		char c;
		int w , h , r;
		double ans = 0.0;
		scanf(" %c",&c);
		if(c == 'C'){
			scanf("%d",&r);
			ans = 3.14 * (double) (r*r);
		}else if(c == 'R'){
			scanf("%d %d",&w , &h);
			ans = (double) (w * h);
		}else{
			scanf("%d %d",&w , &h);
			ans = 0.5 * (double) (w * h);
		}
		printf("%.2lf\n",ans);
		sum = sum + ans;
	}printf("%.2lf\n",sum);
}
