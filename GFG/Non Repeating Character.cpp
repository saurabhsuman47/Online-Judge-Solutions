#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int count[26];
	    int first_occur[26];
	    for(int i = 0; i < 26; i++){
	        count[i] = 0;
	    }
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    for(int i = 0; i < n; i++){
	        if(count[s[i] - 'a'] == 0){
	            first_occur[s[i] - 'a'] = i;
	        }
	        count[s[i] - 'a']++;
	    }
	    int temp = 101;
	    int result = -1;
	    for(int i = 0; i < 26; i++){
	        if(count[i] == 1){
	            if(first_occur[i] < temp){
	                temp = first_occur[i];
	                result = i;
	            }
	        }
	    }
	    if(result == -1){
	        cout<<result<<endl;
	    }
	    else{
	        cout<<(char)(result + 'a')<<endl;
	    }
	}
	return 0;
}
