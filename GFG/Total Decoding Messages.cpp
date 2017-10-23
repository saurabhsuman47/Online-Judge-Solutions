
#include<iostream>
using namespace std;


int dp[40];
string s;

int solve(int n){
    if((n == 0 && s[n] != '0') || n == -1)return 1;
    if(n < 1)return 0;
    if(dp[n] != -1)return dp[n];
    int ones = (int)(s[n] - '0');
    int tens = (int)(s[n - 1] - '0');
    int num = tens * 10 + ones;
    int result = (s[n] != '0') ? solve(n-1) : 0;
    //cout<<"n "<<n<<" result "<<result<<endl;
    if(num >= 1 && num <= 26 && tens != 0){
        result += solve(n-2);
    }
    dp[n] = result;
    //cout<<"n "<<n<<" result "<<result<<endl;
    return result;
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cin>>s;
	    for(int i = 0; i < 40; i++){
	        dp[i] = -1;
	    }
	    cout<<solve(s.length() - 1)<<endl;
	   // for(int i = 0 ; i < 10 ;i++){
	   //     cout<<dp[i]<<" ";
	   // }
	    
	   // cout<<endl;
	    
	}
	return 0;
}
