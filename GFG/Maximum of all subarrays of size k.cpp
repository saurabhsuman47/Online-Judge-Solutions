#include <iostream>
#include <deque>

using namespace std;

//doubly ended queue - deque, at any time the deque contains a decreasing value(increasing index) sequence from the segment of k elements//
int main(){
	int t;
	cin>>t;
	while(t--){
		deque<int> dq;
		int n, k;
		cin>>n>>k;
		int a[n];
		for(int i = 0; i < n ;i++){
			cin>>a[i];
		}
		for(int i = 0; i < k - 1; i++){
			while(!dq.empty() && a[dq.back()] <= a[i]){
			    dq.pop_back();
			}
			dq.push_back(i);
		}
		for(int i = 0; i <= (n - k); i++){
		    while(!dq.empty() && dq.front() < i){
		        dq.pop_front();
		    }
		    while(!dq.empty() && a[dq.back()] <= a[i + k - 1]){
		        dq.pop_back();
		    }
		    dq.push_back(i + k - 1);
		    
		    cout<<a[dq.front()]<<" ";
		}
		cout<<endl;
	}
