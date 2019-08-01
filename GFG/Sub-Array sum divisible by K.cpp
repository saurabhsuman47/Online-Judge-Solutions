using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n, k;
	    cin>>n>>k;
	    int a[n];
	    int sum[n];
	    int modcnt[k];
	    for(int i = 0; i < k; i++){
	        modcnt[i] = 0;
	    }
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
	        if(a[i] < 0)a[i] = ((a[i] + 10000 + k - (10000%k))%k);
	        //cout<<a[i]<<endl;
	        sum[i] = a[i] + ((i > 0)?sum[i - 1]:0);
	        sum[i] = sum[i] % k;
	        modcnt[sum[i]] += 1;
	    }
	    int sol = modcnt[0];
	    for(int i = 0; i < k; i++){
	        if(modcnt[i] >= 2){
	            sol += ((modcnt[i] * (modcnt[i]-1))/2);
	        }
	    }
	    cout<<sol<<endl;
	    
	    
	}
	return 0;
}
