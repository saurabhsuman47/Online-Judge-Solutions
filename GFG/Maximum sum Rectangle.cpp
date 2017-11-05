#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    vector<vector<int>> a;
	    vector<vector<int>> rowsum;
	    int m,n;
	    cin>>m>>n;
	    vector<int> temp;
	    vector<int> temp1;
	    int tsum = 0;
	    int t1;
	    for(int i = 0; i < m; i++){
	        temp.clear();
	        temp1.clear();
	        tsum = 0;
	        for(int j = 0; j < n; j++){
	            cin>>t1;
	            tsum += t1;
	            temp.push_back(t1);
	            temp1.push_back(tsum);
	        }
	        a.push_back(temp);
	        rowsum.push_back(temp1);
	    }
	   
	    int sol = -1000000;
	    tsum = 0;
	    for(int i = 0; i < n; i++){
	        for(int j = i; j < n; j++){
	            tsum = 0;
	            for(int k = 0; k < m; k++){
	                if(i==0)tsum += rowsum[k][j];
	                else tsum += (rowsum[k][j] - rowsum[k][i-1]);
	                sol = max(sol,tsum);
	                if(tsum < 0)tsum = 0;
	            }
	        }
	    }
	    cout<<sol<<endl;
	}
	return 0;
}
