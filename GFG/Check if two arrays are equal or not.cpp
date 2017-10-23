#include<iostream>
#include <algorithm>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n], b[n];
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
	    }
	    for(int i = 0; i < n; i++){
	        cin>>b[i];
	    }
	    sort(a, a + n);
	    sort(b, b + n);
	    int flag = 1;
	    for(int i = 0; i < n; i++){
	        if(a[i] != b[i]){flag = 0; break;}
	    }
	    cout<<flag<<endl;
	    
	    
	}
	return 0;
}
