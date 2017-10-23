#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n, k;
	    cin>>n;
	    int a[n];
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
	    }
	    cin>>k;
	    sort(a, a+n);
	    int temp = INT_MIN;
	    int res = 0;
	    for(int i = 0; i < n; i++){
	        if(temp < a[i]){
	            res += a[i];
	            temp = a[i];
	            k--;
	            if(k == 0){
    	            break;
    	        }
	        }
	    }
	    
	    cout<<res<<endl;
	}
	return 0;
}
