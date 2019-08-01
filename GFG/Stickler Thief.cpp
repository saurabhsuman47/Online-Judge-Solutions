#include<vector>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    vector<int> myv;
	    int n;
	    cin>>n;
	    int t1;
	    for(int i = 0; i < n; i++){
	        cin>>t1;
	        myv.push_back(t1);
	    }
	    vector<int> sol;
	    sol.push_back(myv[0]);
	    sol.push_back(max(myv[0], myv[1]));
	    for(int i = 2; i < n; i++){
	        sol.push_back(max(sol[i-1], sol[i - 2] + myv[i]));
	    }
	    cout<<sol[n-1]<<endl;
	}
	return 0;
}
