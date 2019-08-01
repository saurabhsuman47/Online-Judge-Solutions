using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	int a[40][40];
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m ;j++){
	            cin>>a[i][j];
	        }
	    }
	    int i = 0, j = m - 1;
	    int sol = 0;
	    while(i < n && j >= 0){
	        if(a[i][j] == 1){
	            sol = i;
	            j--;
	        }
	        else{
	            i++;
	        }
	    }
	    cout<<sol<<endl;
	}
	return 0;
}
