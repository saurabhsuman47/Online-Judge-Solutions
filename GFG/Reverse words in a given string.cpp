#include <iostream>
#include<cstring>
using namespace std;

char c[2000];

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    s += '.';
	    int n = s.length();
	    int i = 0;
	    int j = 0;
	    while(i < n){
	        if(s[i] !='.'){
	            i++;
	            continue;
	            
	        }
	        else{
	            for(int k = 0; k <= i - j; k++){
	                c[n - i - 1 + k] = s[k + j];
	            }
	            j = i + 1;
	            i++;
	        }
	    } 
	    for(int k = 0; k < n - 1; k++){
	        cout<<c[k];
	    }
	    cout<<endl;
	}
	return 0;
}
