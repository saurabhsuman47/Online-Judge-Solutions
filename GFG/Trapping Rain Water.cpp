#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int maxl[n];
	    int maxr[n];
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
	    }
	    int temp = 0;
	    for(int i = 0; i < n; i++){
	        temp = max(temp, a[i]);
	        maxl[i] = temp;
	    }
	    temp = 0;
	    for(int i = n - 1; i >= 0; i--){
	        temp = max(temp, a[i]);
	        maxr[i] = temp;
	    }
	    int vol = 0;
	    for(int i = 0; i < n; i++){
	        int t1 = min(maxl[i], maxr[i]);
	        vol += (t1 - a[i]);
	    }
	    cout<<vol<<endl;
	    
	}
	return 0;
}
