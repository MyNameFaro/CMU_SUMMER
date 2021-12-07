#include <bits/stdc++.h>
using namespace std;
bool check(string a,string b){
	if(a[0] == b[0] || a[1] == b[1]){
		return true;
	}
	return false;
}

int main(){
	int N;
	scanf("%d",&N);
	string ch;
	stack <string> M;
	int itr = 0;
	bool move = true;
	bool finish = false;
	vector <stack <string>> R;
	for(int i = 0;i < N;++i){
		cin >> ch;
		M.push(ch);
		R.push_back(M);
		M.pop();
	}

		while(true){
			//cout << itr << endl;
			//printf("%d\n",R.size());
			//for(int i = 0;i < R.size();++i){
				//printf("%d ",R[i].size());
			//}
			//printf("\n");
			if(itr == R.size()){
				break;
			}
			if(itr > 2){
				if ( check(R[itr - 3].top() , R[itr].top()) ){
					R[itr - 3].push(R[itr].top());
					//cout << R[itr].top() << "\n";
					R[itr].pop();
					if(R[itr].empty()){
						R.erase(find(R.begin() , R.end() , R[itr]));
					}
					itr -= 3;
					continue;
				}
			}
			if(itr > 0){
				if ( check(R[itr - 1].top() , R[itr].top()) ){
					//cout << R[itr].top() << "\n";
					R[itr - 1].push(R[itr].top());
					R[itr].pop();
					if(R[itr].empty()){
						R.erase(find(R.begin() , R.end() , R[itr]));
					}
					--itr;
					continue;
				}
			}	
			++itr;
		}
	//OUTPUT
	printf("%d\n",R.size());
	for(int i = 0;i < R.size();++i){
		printf("%d ",R[i].size());
	}
}
