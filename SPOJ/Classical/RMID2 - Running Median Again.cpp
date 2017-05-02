#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int inf = 1000000007;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
    	priority_queue<int> maxpq;
    	priority_queue<int, vector<int>, greater<int> > minpq;
    	maxpq.push(-1*inf);
    	minpq.push(inf);
    	int n;
	    while(true){
	        scanf("%d",&n);
    	    if(n == 0) break;
    		if(n == -1){
    			printf("%d\n",maxpq.top());
    			maxpq.pop();
    			if(maxpq.size() + 1 == minpq.size()){
    				maxpq.push(minpq.top());
    				minpq.pop();
    			}
    			continue;
    		}
    		
    	    int tmax = maxpq.top();
    	    int tmin = minpq.top();
    	    if(n<=tmax)maxpq.push(n);
    	    else if(n>=tmin)minpq.push(n);
    	    else maxpq.push(n);
    	    if(maxpq.size() == minpq.size() + 2){
    	        minpq.push(maxpq.top());
    	        maxpq.pop();
    	    }
    	    else if(maxpq.size() + 1 == minpq.size()){
    	        maxpq.push(minpq.top());
    	        minpq.pop();
    	    }
    	    
    	    
    	}
	}
	
	return 0;
}
