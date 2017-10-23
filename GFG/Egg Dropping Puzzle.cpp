#include<iostream>
using namespace std;

int dp[11][51];
void init(int n, int k){
    for(int i = 0 ; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = -1;
        }
    }
}

int solve(int n, int k){
    //cout<<n<<" "<<k<<endl;
    if(n == 1)return k;
    if(k == 0 || k == 1)return k;
    if(dp[n][k] != -1)return dp[n][k];
    int result = 1000;
    for(int i = 1; i <= k; i++){
        int temp = 1 + max(solve(n - 1, i - 1), solve(n, k - i));
        if(temp < result){
            result = temp;
        }
    }
    dp[n][k] = result;
    return result;
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n, k;
	    cin>>n>>k;
	    init(n, k);
	    cout<<solve(n, k)<<endl;
	}
	return 0;
}
