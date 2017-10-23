#include<iostream>
#include<map>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    map<string, int> count;
	    map<string, int> :: iterator it;
	    string s;
	    while(n--){
	        cin>>s;
	        count[s]++;
	    }
	    int max1 = -1;
	    for(it = count.begin(); it != count.end(); it++){
	        if(it -> second > max1){
	            max1 = it -> second; 
	        }
	    }
	    int max2 = -1;
	    string res;
	    for(it = count.begin(); it != count.end(); it++){
	        if(it -> second > max2 && it -> second < max1){
	            max2 = it -> second; 
	            res = it -> first;
	        }
	    }
	    cout<<res<<endl;
	    
	    
	}
	return 0;
}
