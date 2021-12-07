#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli quick_pow(lli N , int x){
	int degree = 1;
	lli ans = (lli) N;
	while(degree * 2 < x){
		ans = ans * ans;
		degree *= 2;
	}	
	while(degree < x){
		ans *= (lli) N;
		++degree;
	}
	//printf("%lld\n",ans);
	return ans;
}
int bs(int L , int R , lli N , int x){
	if(L >= R){
		return L;
	}
	lli mid = (L + R)/2;
	//printf("%lld %lld\n", quick_pow(mid , x) , N);
	if(quick_pow(mid , x) < N){
		bs(mid + 1,R , N , x);
	}else if(quick_pow(mid , x) > N){
		bs(L , mid , N , x);
	}else{
		return mid;
	}
}

int main(){
	lli N ; int X;
	scanf("%lld %d",&N ,&X);
	if(X == 1){
		printf("%lld",N);
		return 0;
	}
	int R;
	switch(X){
		case 2:
			R = 44721400;
			break;
		case 3:
			R = 125992;
			break;
		case 4:
			R = 6687;
			break;
		case 5:
			R = 1148;
			break;
		case 6:
			R = 354;
			break;
		case 7:
			R = 153;
			break;
		case 8:
			R = 81;
			break;
		case 9:
			R = 50;
			break;
		case 10:
			R = 34;
			break;
		case 11:
			R = 24;
			break;
		case 12:
			R = 18;
			break;
		case 13:
			R = 15;
			break;
	}
	printf("%d" , bs(1 , R , N , X));
}
