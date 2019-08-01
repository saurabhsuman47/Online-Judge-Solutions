using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n <= 5){
	        cout<<n<<endl;
	    }
	    else{
	        n -= 5;
	        n  = n % 8;
	        if(n == 0)cout<<5<<endl;
	        else if(n >= 5) cout<<n - 3<<endl;
	        else{
	            cout<<5 - n<<endl;
	        }
	    }
	}
	return 0;
}
