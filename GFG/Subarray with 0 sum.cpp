#include<unordered_set>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    unordered_set<int> us;
	    int sum = 0;
	    int t1;
	    int flag = 0;
	    us.insert(0);
	    for(int i = 0; i < n; i++){
	        cin>>t1;
	        if(flag == 1)continue;
	        sum+=t1;
	        if(us.find(sum) == us.end()){
	            us.insert(sum);
	        }
	        else flag = 1;
	    }
	    if(flag == 1)cout<<"Yes"<<endl;
	    else cout<<"No"<<endl;
	}
	return 0;
}
