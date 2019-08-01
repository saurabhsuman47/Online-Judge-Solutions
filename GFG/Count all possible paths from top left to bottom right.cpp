using namespace std;
typedef long long ll;
int main()
 {
	//code
	int t;
	cin>>t;
	ll dp[100][100];
	for(int i = 0; i < 100; i++){
        dp[0][i] = 1;
        dp[i][0] = 1;
    }
    for(int i = 1; i < 100; i++){
        for(int j = 1; j < 100; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000007;
        }
    }
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    cout<<dp[n-1][m-1]<<endl;
	}
	return 0;
}
