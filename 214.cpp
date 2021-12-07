#include <bits/stdc++.h>
using namespace std;

vector <int> arr;
int X;

int bs(int L , int R , int n){
	if(L > R) return X + 1; 
	if(L == R){
		if(arr[L] + n == X){
			return arr[L];
		}return X + 1;
	}
	int mid = (L + R)/2;
	if(arr[mid] + n < X){
		bs(mid + 1,R,n);
	}else if(arr[mid] + n > X){
		bs(L,mid,n);
	}else{
		return arr[mid];
	}
}

int main(){
	int N;scanf("%d %d",&N,&X);
	int ans_1 , ans_2 , mx = -2e9;
	arr.assign(N + 1,0);
	for(int i = 1;i <= N;++i){
		scanf("%d",&arr[i]);
		if(arr[i] * 2 == X) arr[i] = arr[i - 1];
	}
	for(int i = N;i >= 1;--i){
		if(arr[i] + bs(1 , i - 1 , arr[i]) == X){
			ans_1 = min(X - arr[i] , arr[i]);
			ans_2 = X - ans_1;
			printf("%d %d" , ans_1 ,ans_2);
			return 0;
		}
	}
	//printf("%d %d",ans_2,ans_1);
}
