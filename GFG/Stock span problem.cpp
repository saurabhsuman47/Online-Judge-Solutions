#include <bits/stdc++.h>
using namespace std;

//using stack of pairs containing a[i] and res[i]//
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int res[n];
	    stack<pair<int,int>> s;
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
            res[i] = 1 ;
            
            while(!s.empty() && a[i] >= s.top().first){
                res[i] += s.top().second;
                s.pop();
            }
            
	        s.push(make_pair(a[i], res[i]));
	    }
	    
	    for(int i = 0; i < n; i++){
	        cout<<res[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
