#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
    	string s1, s2;
    	cin>>s1>>s2;
    	int n1 = s1.length();
    	int n2 = s2.length();
    	int i = 0, j = 0;
    	while(i < n1 || j < n2){
    	    if(i < n1){
    	        cout<<s1[i];
    	        i++;
    	    }
    	    if(j < n2){
    	        cout<<s2[j];
    	        j++;
    	    }
    	}
    	cout<<endl;
	}
	return 0;
}
