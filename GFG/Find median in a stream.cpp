#include <iostream>
#include <queue>
using namespace std;
int inf = 10000000;
int main() {
	//code
	priority_queue<int> maxpq;
	priority_queue<int, vector<int>, greater<int> > minpq;
	maxpq.push(-1*inf);
	minpq.push(inf);
	int n;
	cin>>n;
	while(n--){
	    int t;
	    cin>>t;
	    int tmax = maxpq.top();
	    int tmin = minpq.top();
	    if(t<=tmax)maxpq.push(t);
	    else if(t>=tmin)minpq.push(t);
	    else maxpq.push(t);
	    if(maxpq.size() == minpq.size() + 2){
	        minpq.push(maxpq.top());
	        maxpq.pop();
	    }
	    else if(maxpq.size() + 1 == minpq.size()){
	        maxpq.push(minpq.top());
	        minpq.pop();
	    }
	    
	    if(maxpq.size() == minpq.size()){
	        cout<<(maxpq.top()+minpq.top())/2<<endl;
	    }
	    else{
	        cout<<maxpq.top()<<endl;
	    }
	}
	return 0;
}
