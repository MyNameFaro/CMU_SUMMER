#include <bits/stdc++.h>
using namespace std;

int ques[11][11];
int ans[11][11];
bool done = false;
int Round = 1;

bool check_C(int R ,int C,int num){
	for(int i = 1;i <= 9;++i){
		if(ans[R][i] == num || ques[R][i] == num){
			return false;
		}
	}
	return true;
}
bool check_R(int R ,int C,int num){
	for(int i = 1;i <= 9;++i){
		if(ans[i][C] == num || ques[i][C] == num){
			return false;
		}
	}
	return true;
}
bool check_box(int R ,int C,int num){
	int a = 3*((R - 1)/3) + 1;
	int b = 3*((C - 1)/3) + 1;
	for(int i = a;i <= a+2;++i){
		for(int j = b;j <= b + 2;++j){
			if(ans[i][j] == num || ques[i][j] == num){
				return false;
			}
		}
	}
	return true;
}

void print(){
		FILE *file;
		file = fopen("142_3.txt","a");
		fprintf(file,"Board %d\n",Round);
		for(int i = 1;i <= 9;++i){
			for(int j = 1;j <= 9;++j){
				fprintf(file,"%d ",ans[i][j]);
			}
			fprintf(file,"\n");
		}
		Round++;
		fclose(file);
}

void f(int R,int C){
	if(C == 10){
		++R;
		if(R == 10 && C == 10){
			//printf("Board %d\n",Round);
			print();
			//Round++;
			done = true;
			return;
		}
		C = 1;
	}
	int num;
	if(ques[R][C] != 0 && !done){
		ans[R][C] = ques[R][C];
		f(R,C + 1);
		ans[R][C] = 0;
	}else if(!done){
		for(num = 1;num <= 9;++num){
			if(check_C(R , C , num) && check_R(R , C , num) && check_box(R , C , num)){
				ans[R][C] = num;
				f(R,C + 1);
				ans[R][C] = 0;
			}
		}
	}
	
}

int main(){
	string s;
	//FILE *file;
	//file = fopen("142_2.txt","w");
	for(int R = 1;R <= 100;++R){
		//cin >> s;
		for(int i =1;i <= 9;++i){
			for(int j = 1;j <= 9;++j){
				scanf("%d",&ques[i][j]);
			}
		}
		done = false;
		f(1 , 1);
		for(int i = 1;i <= 9;++i){
			for(int j = 1;j <= 9;++j){
				ans[i][j] = 0;
			}
			//fprintf(file,"\n");
		}
	}
}
