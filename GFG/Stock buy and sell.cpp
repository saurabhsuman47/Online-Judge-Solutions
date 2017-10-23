#include<iostream>
#include<vector>
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
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
	    }
	    int start = 0, end = 0;
	    vector<int> s;
	    vector<int> e;
	    for(int i = 0; i < n - 1; i++){
	        if(a[i] <= a[i + 1]){
	            end++;
	        }
	        else{
	            if(start != end){
	                s.push_back(start);
	                e.push_back(end);
	            }
	            start = i + 1;
	            end = start;
	        }
	    }
	    if(start != end){
	        s.push_back(start);
            e.push_back(end);
	    }
	    if(s.size() == 0)cout<<"No Profit"<<endl;
	    else{
    	    for(int i = 0; i < s.size(); i++){
    	        cout<<"("<<s[i]<<" "<<e[i]<<")"<<" ";
    	    }
    	    cout<<endl;
	    }
	    
	}
	return 0;
}
