#include <bits/stdc++.h>
using namespace std;

set <tuple <int , int , int , int>> ans;

tuple <int , int , int , int> t;
int main(){
	
	
	printf("ONE\n");
	int a , b , c , d;
	for(a = 1;a <= 180;++a){
		for(b = 1;b <= 180;++b){
			for(c = 1;c <= 180;++c){
				if((a + b + c) % (a*b*c - 1) == 0){
					printf("%d %d %d\n",a,b,c);
					//ans.insert(make_tuple(a ,b ,c ,(a + b + c) / (a*b*c - 1)));
				}
			}
		}
	}
	printf("HEY");

}
