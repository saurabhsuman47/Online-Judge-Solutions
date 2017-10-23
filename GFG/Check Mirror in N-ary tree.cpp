#include <iostream>
#include <vector>
using namespace std;

//make adjacency lists and compare edges for each nodes- count should be same and order reverse//
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n, m;
	    cin>>n>>m;
	    vector<int> v1[16];
	    vector<int> v2[16];
	    for(int i = 0; i < m; i++){
	        int t1, t2;
	        cin>>t1>>t2;
	        v1[t1].push_back(t2);
	    }
	    for(int i = 0; i < m; i++){
	        int t1, t2;
	        cin>>t1>>t2;
	        v2[t1].push_back(t2);
	    }
	    int result = 1;
	    for(int i = 1; i <= n; i++){
	        if(v1[i].size() != v2[i].size()){
	            result = 0;
	            break;
	        }
	        int t1 = v1[i].size();
	        if(t1 == 0)continue;
	        for(int j = 0; j <= (t1 - 1)/2; j++){
	            if(v1[i][j] != v2[i][t1 - 1 - j]){
	                result = false;   
	                break;
	            }
	        }
	    }
	    cout<<result<<endl;
	    
	}
}
