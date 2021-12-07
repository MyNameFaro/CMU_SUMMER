#include <bits/stdc++.h>
using namespace std;
using lli = long long;
int main(){
	lli x;
	int N; cin >> N;
	priority_queue <lli> maxheap;
	priority_queue <lli , vector <lli> , greater<lli>> minheap;
	
	minheap.push(2e9); 
	maxheap.push(-2e9);
	
	vector <lli> ans;
	
	for(int i = 1;i <= N;++i){
		cin >> x;
		if(x >= maxheap.top() && x <= minheap.top()){
			if(maxheap.size() > minheap.size()){
				minheap.push(x);
			}else{
				maxheap.push(x);
			}
		}else if(x >= maxheap.top() && x >= minheap.top()){
			if(maxheap.size() > minheap.size()){
				minheap.push(x);
			}else{
				maxheap.push(minheap.top());
				minheap.pop();
				minheap.push(x);
			}
		}else if(x <= maxheap.top() && x <= minheap.top()){
			if(maxheap.size() > minheap.size()){
				minheap.push(maxheap.top());
				maxheap.pop();
				maxheap.push(x);
			}else{
				maxheap.push(x);
			}
		}
		if(maxheap.size() > minheap.size()){
			ans.push_back(maxheap.top());
		}else{
			ans.push_back((maxheap.top() + minheap.top()) / 2);
		} 
	}
	for(auto a:ans) cout << a << " ";
}
