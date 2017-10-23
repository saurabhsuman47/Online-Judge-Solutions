#include <iostream>
#include <stack>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int gmax = -1;
	    stack<int> s;
	    for(int i = 0; i < n; i++){
	        scanf("%d", &a[i]);
	        if(s.empty())s.push(i);
	        else{
	            if(a[i] > a[s.top()]) s.push(i);
	            else if(a[i] == a[s.top()])continue;
	            else{
	                while(!s.empty() && a[s.top()] >= a[i]){
	                    int t1 = s.top();
	                    s.pop();
	                    int t2 = 0;
	                    if(!s.empty()){t2 = s.top() + 1;}
	                    gmax = max(gmax, (a[t1] * (i - t2)));
	                }
	                s.push(i);
	            }
	        }
	    }
	    while(!s.empty()){
	        int t1 = s.top();
            s.pop();
            int t2 = 0;
            if(!s.empty()){t2 = s.top() + 1;}
            gmax = max(gmax, (a[t1] * (n - t2))); 
	    }
	    cout<<gmax<<endl;
	}
	return 0;
}
